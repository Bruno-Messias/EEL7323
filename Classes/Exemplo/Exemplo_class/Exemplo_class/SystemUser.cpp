/* File SystemUser.cpp

Eduardo Augusto Bezerra <Eduardo.Bezerra @ eel.ufsc.br>

Departamento de Engenharia Elétrica, CTC, UFSC

Agosto de 2012.

Descricao: Definicao das funcoes membro para os "headers" declarados na classe SystemUser

*/

#include "SystemUser.h"
using namespace std;

SystemUser::SystemUser() {
	userName = "";
	password = "";
	accessLevel = 'X';
}
SystemUser::~SystemUser() {
	userName = "";
	password = "";
	accessLevel = 'X';
}
void SystemUser::setUserName(string newUserName) {
	userName = newUserName;
}
void SystemUser::setPassword(string newPassword) {
	password = newPassword;
}
void SystemUser::setAccessLevel(char newAccessLevel) {
	accessLevel = newAccessLevel;
}
string SystemUser::getUserName() {
	return userName;
}
string SystemUser::getPassword() {
	return password;
}
char SystemUser::getAccessLevel() {
	return accessLevel;
}