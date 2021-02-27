#include "People.h"
#include "ClockCalendar.cpp"

#define n 100

class VetAluno {
    Aluno vAlunos[n];
    bool valido[n];
public:
    VetAluno();
    void listaVet();
    void inclui(string name, unsigned int day,unsigned int month, unsigned int year, int matr, float n1, float n2,
                unsigned int changedDay, unsigned int changedMonth, unsigned int changedYear, unsigned int changedHour);
    void exclui(int matr);
    void consulta(int matr);
    void altera(int matr);
};