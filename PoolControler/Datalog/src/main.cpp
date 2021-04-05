

#include "DataLog.h"

using namespace std;

int main()
{
    DataLog test;
    test.setInit();
    while(1)
    {
        test.readLog();
    }

    close(test.serial_port);

    return 0;
}