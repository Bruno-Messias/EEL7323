/*	Exe6.cpp : This file contains the 'main' function. Program execution begins and ends there.
	Author: Bruno C. Messias
	Date: 15/02/21
*/


#include <iostream>

#include "Aluno.cpp"

const int MAX = 20;

int main() {

    bool fim = false;
    int aux_matricula;
    float aux_nota;
    std::string newNome;
    int opcao, posicao;

    Aluno cadastroAlunos[MAX];

    while (!fim) {

        std::cout << "Sistema de controle de alunos" << std::endl;
        std::cout << "[1] Consulta aluno" << std::endl;
        std::cout << "[2] Listar todos alunos" << std::endl;
        std::cout << "[3] Excluir aluno" << std::endl;
        std::cout << "[4] Alterar aluno" << std::endl;
        std::cout << "[5] Incluir aluno" << std::endl;
        std::cout << "[6] Sai do programa" << std::endl;
        std::cout << "Entre com a opcao desejada: ";
        std::cin >> opcao;
        
        switch (opcao) {
        case 1: //Consulta aluno
            std::cout << "Matricula? ";
            std::cin >> aux_matricula;

            posicao = -1;

            for (int i = 0; i < MAX; i++)
                if (aux_matricula == cadastroAlunos[i].getMatricula())
                    posicao = i;

            if (posicao != -1) {
                std::cout << "\n Nome: " << cadastroAlunos[posicao].getNome() << std::endl;
                std::cout << "Matricula: " << cadastroAlunos[posicao].getMatricula() << std::endl;
                std::cout << "Nota 1: " << cadastroAlunos[posicao].getNota1() << std::endl;
                std::cout << "Nota 2: " << cadastroAlunos[posicao].getNota2() << std::endl;
                std::cout << "Media: \n" << cadastroAlunos[posicao].getMedia() << std::endl;
            }
            else
                std::cout << "\n Matricula nao econtrada. \n" << std::endl;

            break;

        case 2: //Listar todos alunos
            for (int i = 0; i < MAX; i++)
            {
                if (cadastroAlunos[i].getNome() != "")
                    std::cout << "\nNome: " << cadastroAlunos[i].getNome() << std::endl;

                else 
                    break;
             };

            std::cout << "\n ------ Fim da Lista ----- \n" << std::endl;

            break;

        case 3: //Excluir aluno
            std::cout << "Matricula? ";
            std::cin >> aux_matricula;

            posicao = -1;

            for (int i = 0; i < MAX; i++)
                if (aux_matricula == cadastroAlunos[i].getMatricula())
                    posicao = i;

            if (posicao != -1)
                cadastroAlunos[posicao].~Aluno();
              
            else
                std::cout << "\n Matricula nao econtrada. \n" << std::endl;

            break;

        case 4: //Alterar aluno
            std::cout << "Matricula? ";
            std::cin >> aux_matricula;

            posicao = -1;

            for (int i = 0; i < MAX; i++)
                if (aux_matricula == cadastroAlunos[i].getMatricula())
                    posicao = i;

            if (posicao != -1) {
                std::cout << "Novo Nome: " << std::endl;
                std::cin >> newNome;
                cadastroAlunos[posicao].setNome(newNome);

                std::cout << "Nova Nota 1: " << std::endl;
                std::cin >> aux_nota;
                cadastroAlunos[posicao].setNota1(aux_nota);

                std::cout << "Nova Nota 2: " << std::endl;
                std::cin >> aux_nota;
                cadastroAlunos[posicao].setNota2(aux_nota);
            }
            else
                std::cout << "\n Matricula nao econtrada. \n" << std::endl;

            break;

        case 5: //Incluir aluno
            for (int i = 0; i < (MAX+1); i++)
            {
		if (i == 20) {
                    std::cout << "\n ------ Não Há vagas -----\n" << std::endl;
                    break;
                }
		    
                if (cadastroAlunos[i].getNome() == "") {

                    std::cout << "Nome: " << std::endl;
                    std::cin >> newNome;
                    cadastroAlunos[i].setNome(newNome);

                    std::cout << "Matricula:" << std::endl;
                    std::cin >> aux_matricula;
                    cadastroAlunos[i].setMatricula(aux_matricula);

                    std::cout << "Nota 1: " << std::endl;
                    std::cin >> aux_nota;
                    cadastroAlunos[i].setNota1(aux_nota);

                    std::cout << "Nota 2: " << std::endl;
                    std::cin >> aux_nota;
                    cadastroAlunos[i].setNota2(aux_nota);

                    break;
                }
            };

            break;

        case 6: //Sai do programa
            fim = true;
            break;

        default:
            std::cout << "Nenhuma opção selecionada, tente novamente" << std::endl;
            break;
        }

    }
    return 0;
}
