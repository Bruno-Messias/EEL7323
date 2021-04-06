

#include "DataLog.h"

using namespace std;

int main()
{
    DataLog host;
    host.setInit();
    
    while(1)
    {
        host.readLog();
        host.displayMenu();
        host.interruptFunction();
    }

    close(host.serial_port);

    return 0;
}