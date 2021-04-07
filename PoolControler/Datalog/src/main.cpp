

#include "DataLog.h"

using namespace std;

int main()
{
    DataLog host;
    host.setInit();
    
    //Output Loop to control the print system
    while(1)
    {   
        host.displayMenu();
        //Inner Loop for the system
        while (1)
        {
            host.readLog();
            host.interruptFunction();
            if (host.flag)
            {
                host.flag = false;
                usleep(30010);
                break;
            }
        }
    }

    close(host.serial_port);

    return 0;
}