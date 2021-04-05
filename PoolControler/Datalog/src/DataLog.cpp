#include "include/DataLog.h"

void DataLog::read()
{
    string line;
    ifstream db;

    db.open("db/list.sl");

    if(db.is_open())
    {
        while (getline(db,line,'\0'))
        {
            cout << line << endl;
        }
    }
    else {
        cout << "Cannot open the file" << endl;
    }

    db.close();
}
