
#include "List.h"

#include <string>

class DataLog {

public:
    List lista;
    int serial_port;

    DataLog() {}
    ~DataLog() {}

    int setInit();
    int readLog();
    void addLog(char*);
};

    // add close(serial_port);