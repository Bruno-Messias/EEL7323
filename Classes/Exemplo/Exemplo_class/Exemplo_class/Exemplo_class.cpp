/* File test_SystemUser.cpp

   Eduardo Augusto Bezerra <Eduardo.Bezerra @ eel.ufsc.br>

   Departamento de Engenharia Elétrica, CTC, UFSC

   Agosto de 2012.

   Descricao: Programa de teste para a classe SystemUser.

*/

#include <iostream>
#include "SystemUser.cpp"

using namespace std;

int main() {
	SystemUser usuario1, usuario2;
	string aux_user;
	char aux_level;
	string aux_passwd;
	cout << "User name? ";
	cin >> aux_user;
	cout << endl << "Password? ";
	cin >> aux_passwd;
	cout << endl << "Access level (A to E)? ";
	cin >> aux_level;

	usuario1.setUserName(aux_user);
	usuario1.setPassword(aux_passwd);
	usuario1.setAccessLevel(aux_level);

	usuario2.setUserName("Eduardo Bezerra");
	usuario2.setPassword("1234567890");
	usuario2.setAccessLevel('D');

	// usuario1 = usuario2;

	cout << endl << "----------------------" << endl;
	cout << "User name: " << usuario1.getUserName() << endl;
	cout << "Password: " << usuario1.getPassword() << endl;
	cout << "Access Level: " << usuario1.getAccessLevel() << endl;
	cout << endl << "----------------------" << endl;
	cout << "User name: " << usuario2.getUserName() << endl;
	cout << "Password: " << usuario2.getPassword() << endl;
	cout << "Access Level: " << usuario2.getAccessLevel() << endl;
}