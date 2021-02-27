#include "People.h"

#define n 100

class VetAluno {
    Aluno vAlunos[n];
    bool valido[n];
public:
    VetAluno();
    void listaVet();
    void inclui(int matr, float n1, float n2);
    void exclui(int matr);
    void consulta(int matr);
    void altera(int matr);
};