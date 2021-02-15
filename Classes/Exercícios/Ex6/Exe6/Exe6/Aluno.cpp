/*	Aluno.cpp
*	Author: Bruno C. Messias
*	Date: 15/02/21
*/

#include "Aluno.h"

Aluno::Aluno() {
	matricula =	0;
	nome = "";
	nota1 = 0;
	nota2 = 0;
}

Aluno::~Aluno() {
	matricula = 0;
	nome = "";
	nota1 = 0;
	nota2 = 0;
}

void Aluno::setNota1(float newNota1) {
	nota1 = newNota1;
}

void Aluno::setNota2(float newNota2) {
	nota2 = newNota2;
}

void Aluno::setNome(std::string newNome) {
	nome = newNome;
}
	
float Aluno::getNota1() {
	return nota1;
}

float Aluno::getNota2() {
	return nota2;
}

float Aluno::getMedia() {
	float media = (Aluno::getNota1() + Aluno::getNota2())/2;
	return media;
}

std::string Aluno::getNome() {
	return nome;
}
void Aluno::setMatricula(int newMatricula) {
	matricula = newMatricula;
}

int Aluno::getMatricula() {
	return matricula;
}