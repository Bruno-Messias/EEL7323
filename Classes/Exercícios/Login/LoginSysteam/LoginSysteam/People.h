#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>

using namespace std;

class Pessoa {
	int day, month, year;
	string name;
public:
	inline void setBirthday(unsigned int day, unsigned int month, unsigned int year);
	inline void setName(string name);
	inline void readBirthday(unsigned int& day, unsigned int& month, unsigned int& year);
	inline string getName();
};

inline string Pessoa::getName() {
	return name;
}

inline void Pessoa::setBirthday(unsigned int day, unsigned int month, unsigned int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

inline void Pessoa::setName(string newName) {
	name = newName;
}

inline void Pessoa::readBirthday(unsigned int& day, unsigned int& month, unsigned int& year) {
	day = this->day;
	month = this->month;
	year = this->year;
}

class Aluno: public Pessoa {
	int matr, matrProf;
	unsigned int dia, mes, ano, hora;
	float n1,n2;
public:
	inline void setMatr(int matr);
	inline void setN1(float nota1);
	inline void setN2(float nota2);
	inline int getMatr();
	inline float getN1();
	inline float getN2();
	inline float calcMedia();
	inline void setData(unsigned int dia, unsigned int mes, unsigned int ano, unsigned int hora);
	inline void setProf(int matrProf);
};

inline void Aluno::setMatr(int matr) {
	this->matr = matr;
}
inline void Aluno::setN1(float n1) {
	this->n1 = n1;
}
inline void Aluno::setN2(float n2) {
	this->n2 = n2;
}
inline int Aluno::getMatr() {
	return matr;
}
inline float Aluno::getN1() {
	return n1;
}
inline float Aluno::getN2() {
	return n2;
}
inline float Aluno::calcMedia() {
	return (n1 + n2) / 2;
}
inline void Aluno::setData(unsigned int dia, unsigned int mes, unsigned int ano, unsigned int hora) {
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
	this->hora = hora;
}
inline void Aluno::setProf(int matrProf) {
	this->matrProf = matrProf;
}

class Professor: public Pessoa {
	int matr;
public:
	inline void setMatr(int matr);
	inline int getMatr();
};

inline void Professor::setMatr(int matr) {
	this->matr = matr;
}

inline int Professor::getMatr() {
	return matr;
}

#endif // !PEOPLE_H