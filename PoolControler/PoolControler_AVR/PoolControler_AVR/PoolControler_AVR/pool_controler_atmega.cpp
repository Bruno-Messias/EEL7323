#include "pool_controler_atmega.h"
#include "pool_controler.cpp"

PoolControlerAtmega::PoolControlerAtmega()
{
    estate = 0; // control the actual estate
	
	sw = false; //in
	init = false; //for check log
	
	//-- Define in's and out's --
	set_bit(DDRB, pump_bit);
	set_bit(DDRB, heater_bit);
	set_bit(DDRB, low_bit);
	rst_bit(DDRB, sw_bit);
	rst_bit(DDRB, reset_bit);
	
	// -- Initiate Out bits --
	rst_bit(PORTB, pump_bit);
	rst_bit(PORTB, heater_bit);
	rst_bit(PORTB, low_bit);
	
	//-- Disable Interrupts --
	rst_bit(PCMSK0, PCINT0);		//Disable interrupt of reset_bit
	rst_bit(PCICR, PCIE0);			// Disable Interrupt
	
	led.MAX7219_INIT();				//Initiate MAx7239
	
	/* -- Only for debugging --*/
	pump = false; //out
	heater = false; //out
	timeout = false; //no
	reset = false; //in
	low = false; //out
}

void PoolControlerAtmega::inputSW() //Test for admin choose
{
    if(test_bit(PINB, sw_bit))
	{
		sw = true;
	}
	else sw = false;
}

void PoolControlerAtmega::FSM() //Logic for next estate 
{
    switch (estate)
    {
    case 0: //RESET

		/* -- Only for debugging --*/
        timeout = true;
        pump = false;
        heater = false;
        low = false;
		
		/* Setting estate output */
		rst_bit(PORTB, pump_bit);
		rst_bit(PORTB, heater_bit);
		rst_bit(PORTB, low_bit);

        //Next Estate
        if (reset) //TODO: implement interrupt base eliminate the next estate logic and input -> goto while logic
        {
            estate = 1;
			init = true //For check log
            break;
        }
        else
        {
            estate = 0;
            break;
        }
		
    case 1: //INIT

        init = false;
		
		/* -- Only for debugging --*/
		reset = false;
        timeout = false;
        pump = true;
        heater = true;
		
		/* Setting estate output */
		set_bit(PORTB, pump_bit);
		set_bit(PORTB, heater_bit);
		rst_bit(PORTB, low_bit);

        //Next Estate:
        if (sw)
        {
            estate = 3;
            break;
        }
        else
        {
            estate = 2;
            break;
        }
    case 2: //ON1 - 60min config

        //Next Estate:
        time.setTimer(60);
        while (time.getTime() > 0 )
        {
			
             if (time.getTime() < 5)
             {
	             low = true;					//! For debug
				 set_bit(PORTB, low_bit);		//Enable Low Signal
             }
			
			time.coutTimer();						//Advance Timer
			cc.advance();							// Advance Clock
			PoolControlerAtmega::displayTimer();	//Send Timer via SPI for display
			_delay_ms(minute);
			
			//-- Setting the interrupt
            set_bit(PCMSK0, PCINT0);	//Enable interrupt of reset_bit
            set_bit(PCICR, PCIE0);		//Need to enable for interrupt
              
            sei();						//Initiate check service routine
			
			if(flag)					//Check for interrupt
			{
				break;
			}
			
        }
		rst_bit(PCMSK0, PCINT0);		//Disable interrupt of reset_bit
		rst_bit(PCICR, PCIE0);			//Disable Interrupt
		rst_bit(PORTB, low_bit);		//Disable low signal
		estate = 4;
        break;

    case 3: //ON2 - 30min config

        //Next Estate:
        time.setTimer(30);					//Set timer for 30 minutes
        while (time.getTime() > 0) 
        {
			if (time.getTime() < 5)			//Check for low timer alert
			{
				low = true;					//! For debug
				set_bit(PORTB, low_bit);	//Enable low signal
			}
            time.coutTimer();				//Advance Timer
			cc.advance();					//Advance Clock
            PoolControlerAtmega::displayTimer();
            _delay_ms(minute);
			
			//-- Setting the interrupt
			set_bit(PCMSK0, PCINT0);		//Enable interrupt of reset_bit
			set_bit(PCICR, PCIE0);			// Need to enable for interrupt
			 
			sei();							//Initiate check service routine
			
			if(flag)						//Adding flag to stop Timer
			{
				break;
			}
			
        }
		rst_bit(PORTB, low_bit);		//Disable low signal
		rst_bit(PCMSK0, PCINT0);		//Disable interrupt of reset_bit
		rst_bit(PCICR, PCIE0);			// Disable Interrupt
		estate = 4;
        break;
    case 4: //OFF1

       /* -- Only for debugging --*/
	    timeout = true;
        heater = false;
        low = false;
		
		/* Setting estate output */
		rst_bit(PORTB, heater_bit);

        //Next Estate
        estate = 5;
        break;
    case 5: //OFF2

        //Next Estate:
        time.setTimer(1);		//Set Timer for 1 minute
        while (time.getTime() > 0)	
        {
            time.coutTimer();	//Advance Timer
			cc.advance();		//Advance Clock
            _delay_ms(minute);
        }
		
        pump = false;	//! For debug
		
		/* Setting estate output */
		rst_bit(PORTB, pump_bit);
        estate = 0;
        break;

    default:
        estate = 0;
        break;
    }

} 

//TODO Delete this functions
void PoolControlerAtmega::Inputs()
{
    switch (estate)
    {
	    case 0: //RESET
			if(test_bit(PINB, reset_bit)) //Wait until reset pin is pressed
			{
				reset = true;
			}
			break;
		case 1: //INIT
			//Next Estate
			break;
	    case 2: //ON1
			break;
	    case 3: //ON2
			//Next Estate
			break;
	    case 4: //OFF1
			//Next Estate
			break;
	    case 5: //OFF2
			//Next Estate
			break;
	    default:
			break;
    }
}

//TODO delete this function
void PoolControlerAtmega::Outputs() { }

void PoolControlerAtmega::setEstate(int newEstate)
{
	estate = newEstate;
}

void PoolControlerAtmega::displayTimer()
{
	value = time.getTime();
	
	led.MAX7219_displayNumber(value);
}

unsigned char PoolControlerAtmega::checkLog()
{
	if(estate == 4 && (!flag))
	{
		return 'a';
	}
	if else(flag)
	{
		return 'c';
	}
	if else(init)
	{
		return 'b';
	}
	else return 'd';
	
	
}

ISR(PCINT0_vect) //Interrupt Service Routine
{
	flag = true;
}



