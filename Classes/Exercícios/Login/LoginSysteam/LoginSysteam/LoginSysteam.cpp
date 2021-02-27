/*
 *
 * Autor: Bruno Cayres Mesias
 *        <brunocmessias@hotmail.com>
 *
 * UFSC, CTC, EEL
 * Date: 27/02/2021
 *
 * Description: This program has been proposed in order to exercice
 *              the following concepts:
 *                 - Multiple Inheritance
 *                 - Constructors
 *                 - Output formatting (setw and setfill)
 *                 - Makefile
 *
 * Implemented inheritance:
 * -----------------------
 *
 *       Clock           Calendar
 *           \             /
 *            \           /
 *            ClockCalendar
 *                  |
 *                  |
 *                main
 * Files:
 * -----
 * Clock.h
 * Clock.cpp
 * Calendar.h
 * Calendar.cpp
 * ClockCalendar.h
 * ClockCalendar.cpp
*/

#include <time.h>
#include <iostream>
#include <string>

#include "CadastroAlunos.cpp"
#include "ClockCalendar.cpp"

using namespace std;

int main()
{
	ClockCalendar cc(2021, 27, 2, 9, 34, 40, true);

	bool secondAdvanced = false;
    bool isPM;
	time_t now, elapsed;
	double seconds;
    int opcao, matr;
    unsigned int dia, mes, ano, chDay, chMonth, chYear, chHour,min,sec;
    float n1, n2;
    string nome;
    VetAluno CadAlunos;

	while (true) {
		secondAdvanced = false;
		time(&now);
		while (!secondAdvanced) {
			time(&elapsed);
			seconds = difftime(elapsed, now);
			if (seconds == 1) {
				secondAdvanced = true;
				cc.advance();
			}
            cout << "Programa de cadastro";
            //Mostra todas as opções
            cout << "\n1. Login" << endl;
            cout << "2. Logout" << endl;
            cout << "3. Incluir aluno" << endl;
            cout << "4. Excluir aluno" << endl;
            cout << "5. Alterar aluno" << endl;
            cout << "6. Consultar aluno" << endl;
            cout << "7. Listar alunos" << endl;
            cout << "8. Incluir professor" << endl;
            cout << "9. Excluir professor" << endl;
            cout << "10.Alterar professor" << endl;
            cout << "11.Consultar professor" << endl;
            cout << "12.Listar Professor" << endl;
            cout << "Digite a opcao desejada: ";
            cin >> opcao;
            //Switch para direcionar a escolha aos metodos da classe CadAlunos
            switch (opcao) {
               case 1:
                    break;
               case 2:

                   break;
               case 3:
                   cout << "\nDigite a matricula: "; cin >> matr;
                   cout << "Digite o Nome: "; cin >> nome;
                   cout << "DIgite a data de Nascimento(dia|mes|ano): "; cin >> dia; cin >> mes; cin >> ano;
                   cout << "Digite a nota 1: "; cin >> n1;
                   cout << "Digite a nota 2: "; cin >> n2;

                   cc.readClock(chHour, min, sec,isPM);
                   cc.readCalendar(chYear, chMonth, chDay);

                   CadAlunos.inclui(nome, dia, mes, ano,matr, n1, n2, chDay,chMonth,chYear,chHour);
                   break;
               case 4:
                   cout << "\nDigite a matricula do aluno a excluir: "; cin >> matr;
                   CadAlunos.exclui(matr);
                   break;
               case 5:
                   cout << "\nDigite a matricula do aluno a alterar: "; cin >> matr;
                   CadAlunos.altera(matr);
                   break;
               case 6:
                   cout << "\nDigite a matricula do aluno a consultar: "; cin >> matr;
                   CadAlunos.consulta(matr);
                   break;
               case 7:
                   cout << "\nOpcao listar turma, listando:\n";
                   CadAlunos.listaVet();
                   break;
               case 8:
                   break;
               case 9:
                   break;
               case 10:
                   break;
               case 11:
                   break;
               case 12:
                   break;
               default:
                    cout << "\nA opcao digitada nao existe! Tente novamente. \n\n";
             }
		}
	}
	// buffer flush 
	cout.flush();
	return 0;

}