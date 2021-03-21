#include "pool_controler_atmega.h"
#include "pool_controler.cpp"

PoolControlerAtmega::PoolControlerAtmega()
{
    estate = 0;
	
    sw = false; //in
    pump = false; //out
    heater = false; //out
    timeout = false; //no
    reset = false; //in
    low = false; //out
	
	//Define in's and out's
	set_bit(DDRB, pump_bit);
	set_bit(DDRB, heater_bit);
	set_bit(DDRB, low_bit);
	rst_bit(DDRB, sw_bit);
	rst_bit(DDRB, reset_bit);
	
	//Initiate Out bits
	rst_bit(PORTB, pump_bit);
	rst_bit(PORTB, heater_bit);
	rst_bit(PORTB, low_bit);
	
}

void PoolControlerAtmega::inputSW()
{
    if(test_bit(PINB, sw_bit))
	{
		sw = true;
	}
	else sw = false;
}

//TODO: Finish FSW
void PoolControlerAtmega::FSM()
{
    switch (estate)
    {
    case 0: //RESET

        timeout = true;
        pump = false;
        heater = false;
        low = false;
		
		rst_bit(PORTB, pump_bit);
		rst_bit(PORTB, heater_bit);
		rst_bit(PORTB, low_bit);

        //Next Estate
        if (reset)
        {
            estate = 1;
            break;
        }
        else
        {
            estate = 0;
            break;
        }
    case 1: //INIT

        reset = false;
        timeout = false;
        pump = true;
        heater = true;
		
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
	             low = true;
				 set_bit(PORTB, low_bit);
             }
			
			time.coutTimer();
			PoolControlerAtmega::displayTimer();
			_delay_ms(60000);
			
			
            set_bit(PCMSK0, PCINT5); //Enable interrupt of reset_bit
            set_bit(PCICR, PCIE0); // Need to enable for interrupt
              
            sei(); //Initiate check service routine
              
			//TODO Solve the ISR routine inside a class
			  
            if(estate == 1)
            {
				break;
            }
			 
			estate = 4;
        }
		rst_bit(PORTB, low_bit);
        break;

    case 3: //ON2 - 30min config

        //Next Estate:
        time.setTimer(30);
        while (time.getTime() > 0)
        {
			if (time.getTime() < 5)
			{
				low = true;
				set_bit(PORTB, low_bit);
			}
			
            time.coutTimer();
            PoolControlerAtmega::displayTimer();
            _delay_ms(60000);
			
            //! Need TO test!
			 
			set_bit(PCMSK0, PCINT5); //Enable interrupt of reset_bit
			set_bit(PCICR, PCIE0); // Need to enable for interrupt
			 
			sei(); //Initiate check service routine
			 
			//TODO Solve the ISR routine inside a class
			
			if(estate == 1)
			{
				break; 
			}
			 
			estate = 4;
        }
		rst_bit(PORTB, low_bit);
        break;
    case 4: //OFF1

        timeout = true;
        heater = false;
        low = false;
		
		rst_bit(PORTB, heater_bit);

        //Next Estate
        estate = 5;
        break;
    case 5: //OFF2

        //Next Estate:
        time.setTimer(1);
        while (time.getTime() > 0)
        {
            time.coutTimer();
            _delay_ms(60000);
        }
        pump = false;
		rst_bit(PORTB, pump_bit);
        estate = 0;
        break;

    default:
        estate = 0;
        break;
    }

} 

void PoolControlerAtmega::Inputs()
{
    switch (estate)
    {
	    case 0: //RESET
			if(test_bit(PINB, reset_bit)) //Wait until PINB is pressed
			{
				reset = true;
			}
			else reset = false;
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

void PoolControlerAtmega::Outputs()
{
    switch (estate)
    {
	    case 0: //RESET
			
			//Next Estate
			break;
	    case 1: //INIT

			//Next Estate
			break;
	    case 2: //ON1

			//Next Estate
			break;
	    case 3: //ON2

			//Next Estate
		    break;
	    case 4: //OFF1

			//Next Estate
			break;
	    case 5: //OFF2

	    //Next Estate
	    default:
			break;
    }
}

void PoolControlerAtmega::setEstate(int newEstate)
{
	estate = newEstate;
}

void PoolControlerAtmega::displayTimer()
{
	//TODO Create driver to display Timer
}

//Interrupt Service routine
//ISR(PCINT0_vect)
//{
	//PoolControlerAtmega.setEstate(1);
//}