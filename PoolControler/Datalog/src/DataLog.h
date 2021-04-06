
#include "List.h"

#include <string>

class DataLog {
    string log;
public:
    List lista;
    int serial_port;

    DataLog() {}
    ~DataLog() {}

    int setInit();
    int readLog();
    void conversionLog(string read_log);
    void addLog(int id, string year_s, string month_s, string day_s, string hour_s, string min_s, string sec_s, char event);
};

    // add close(serial_port);