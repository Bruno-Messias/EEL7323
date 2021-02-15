/* File SystemUser.h

   Eduardo Augusto Bezerra <Eduardo.Bezerra @ eel.ufsc.br>

   Departamento de Engenharia Elétrica, CTC, UFSC

   Agosto de 2012.

   Descricao: Definicao dos "headers" (interface) para a classe SystemUser

*/

#include <string>
using namespace std;

class SystemUser {
    string userName;
    string password;
    char accessLevel;
public:
    SystemUser();
    ~SystemUser();
    void setUserName(string newUserName);
    void setPassword(string newPassword);
    void setAccessLevel(char newAccessLevel);
    string getUserName();
    string getPassword();
    char getAccessLevel();
};
