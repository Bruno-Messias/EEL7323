/*	Aluno.h
*	Author: Bruno C. Messias
*	Date: 15/02/21
*/

#include<string>

class Aluno {
        int matricula;
        std::string nome;
        float nota1;
        float nota2;
    public:
        Aluno();
        ~Aluno();
        void setNota1(float);
        void setNota2(float);
        void setNome(std::string);
        float getNota1();
        float getNota2();
        float getMedia();
        std::string getNome();
        void setMatricula(int);
        int getMatricula();
};
