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
	rst_bit(PCMSK0, PCINT0);				//Disable interrupt of reset_bit
	rst_bit(PCICR, PCIE0);					// Disable Interrupt
	
	led.MAX7219_INIT();						//Initiate MAx7239
	cc.setCalendar(2021,4,1,0,0,0);			//Set ClockCalendar for 1/4/2021 00:00:00
}

void PoolControlerAtmega::inputSW() //Test for Admin choose
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

		/* Setting estate output */
		rst_bit(PORTB, pump_bit);
		rst_bit(PORTB, heater_bit);
		rst_bit(PORTB, low_bit);
		
		//-- Setting the interrupt
		set_bit(PCMSK0, PCINT0);		//Enable interrupt of reset_bit
		set_bit(PCICR, PCIE0);			// Need to enable for interrupt
		
		sei();						//Initiate check service routine
		
		while(1)
		{
			if(flag)
			{
				init = true;
				break;
			}
			cc.advance();				// Advance Clock
			_delay_ms(secs);
		}
		
    case 1: //INIT

        init = false;
		
		rst_bit(PCMSK0, PCINT0);		//Disable interrupt of reset_bit
		rst_bit(PCICR, PCIE0);			//Disable Interrupt
		
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
	
		//TODO: ADD control of coutTime for only minute 

        //Next Estate:
        time.setTimer(60);
        while (time.getTime() > 0 )
        {
			
             if (time.getTime() < 5)
             {
				 set_bit(PORTB, low_bit);			//Enable Low Signal
             }
			
			time.coutTimer();						//Advance Timer
			cc.advance();							// Advance Clock
			PoolControlerAtmega::displayTimer();	//Send Timer via SPI for display
			_delay_ms(secs);
			
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

		//TODO: ADD control of coutTime for only minute

        //Next Estate:
        time.setTimer(30);							//Set timer for 30 minutes
        while (time.getTime() > 0) 
        {
			if (time.getTime() < 5)					//Check for low timer alert
			{
				set_bit(PORTB, low_bit);			//Enable low signal
			}
            time.coutTimer();						//Advance Timer
			cc.advance();							//Advance Clock
            PoolControlerAtmega::displayTimer();	//Send Timer via SPI for display
            _delay_ms(secs);
			
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

		/* Setting estate output */
		rst_bit(PORTB, heater_bit);

        //Next Estate
        estate = 5;
        break;
    case 5: //OFF2

        //Next Estate:
        time.setTimer(1);				//Set Timer for 1 minute
        while (time.getTime() > 0)	
        {
            time.coutTimer();			//Advance Timer
			cc.advance();				//Advance Clock
            _delay_ms(secs);
        }
		
		/* Setting estate output */
		rst_bit(PORTB, pump_bit);
        estate = 0;
        break;

    default:
        estate = 0;
        break;
    }

} 
	
void PoolControlerAtmega::setEstate(int newEstate)
{
	estate = newEstate;
}

void PoolControlerAtmega::displayTimer()
{
	value = time.getTime();				//Get time  for display in max7219 driver
	led.MAX7219_displayNumber(value);	//Send Value to MAX7219 driver via SPI
	
}

void PoolControlerAtmega::checkLog()
{
	if(estate == 5)					//Check for timeout
	{
		event = 'a';
	}
	else if(estate == 0 && flag)	//Check reset timer
	{
		event = 'c';
	}
	else if(init)					//Check for initialization of system
	{
		event = 'b';
	}
	
}

ISR(PCINT0_vect) //Interrupt Service Routine
{
	flag = true;
}



