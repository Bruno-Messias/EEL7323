#ifndef CLASSES_H
#define CLASSES_H

#include <windows.h>
#include <iostream>

#define sec 1000

class Data
{
public:
	Data();
	~Data();
	void coutAno();
	void coutMes();
	void coutDia();
	int getAno();
	int getMes();
	int getDia();
	void setAno(int);
	void setMes(int);
	void setDia(int);
private:
	int ano, mes, dia;
};

Data::Data()
{
	ano = 1;
	mes = 1;
	dia = 1;
}

Data::~Data()
{
	ano = 1;
	mes = 1;
	dia = 1;
}

void Data::coutAno() {
	ano++;
}
void Data::coutMes() {
	if (mes < 11)
		mes++;
	else {
		Data::coutAno();
		mes = 1;
	}
}
void Data::coutDia() {
	if (ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0) { //ano bissexto
		if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
			if (dia < 30)
				dia++;
			else {
				Data::coutMes();
				dia = 1;
			}
		}
		if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
			if (dia < 29)
				dia++;
			else {
				Data::coutMes();
				dia = 1;
			}
		}
		if (mes == 2) {
			if (dia < 28)
				dia++;
			else {
				Data::coutMes();
				dia = 1;
			}
		}
	}
	else {
		if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
			if (dia < 30)
				dia++;
			else {
				Data::coutMes();
				dia = 1;
			}
		}
		if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
			if (dia < 29)
				dia++;
			else {
				Data::coutMes();
				dia = 1;
			}

		}
		if (mes == 2)
			if (dia < 27)
				dia++;
			else {
				Data::coutMes();
				dia = 1;
			}
	}
}

int Data::getAno() {
	return ano;
}
int Data::getMes() {
	return mes;
}
int Data::getDia() {
	return dia;
}

void Data::setAno(int newAno) {
	ano = newAno;
}
void Data::setMes(int newMes) {
	mes = newMes;
}
void Data::setDia(int newDia) {
	dia = newDia;
}

class Hora : public Data
{
public:
	Hora();
	~Hora();
	void coutHora();
	void coutMinuto();
	void coutSegundo();
	int getHora();
	int getMinuto();
	int getSegundo();
	void setHora(int);
	void setMinuto(int);
	void setSegundo(int);
private:
	int hora, minuto, segundo;
};

Hora::Hora()
{
	hora = 0;
	minuto = 0;
	segundo = 0;
}
Hora::~Hora()
{
	hora = 0;
	minuto = 0;
	segundo = 0;
}

void Hora::coutHora() {
	if (hora < 23)
		hora++;
	else {
		Data::coutDia();
		hora = 0;
	}
}
void Hora::coutMinuto() {
	if (minuto < 59)
		minuto++;
	else {
		Hora::coutHora();
		minuto = 0;
	}
}
void Hora::coutSegundo() {
	if (segundo < 59)
		segundo++;
	else {
		Hora::coutMinuto();
		segundo = 0;
	}
}

int Hora::getHora() {
	return hora;
}
int Hora::getMinuto() {
	return minuto;
}
int Hora::getSegundo() {
	return segundo;
}

void Hora::setHora(int newHora) {
	hora = newHora;
}
void Hora::setMinuto(int newMinuto) {
	minuto = newMinuto;
}
void Hora::setSegundo(int newSegundo) {
	segundo = newSegundo;
}

class Calendar : public Hora {
public:
	void coutCalendar();
	void showCalendar();
	void setCalendar();
private:
	int newAno, newMes, newDia, newHora, newMinuto, newSegundo;
};

void Calendar::coutCalendar() {
	Hora::coutSegundo();
}

void Calendar::showCalendar() {
	std::cout << "Data:" << Calendar::getDia() << "|" << Calendar::getMes() << "|" << Calendar::getAno() << std::endl;
	std::cout << "Hora:" << Calendar::getHora() << ":" << Calendar::getMinuto() << ":" << Calendar::getSegundo() << std::endl;
	std::cout << "----------------------------------------------------------------------------------------------------------" << std::endl;
}

void Calendar::setCalendar() {
	std::cout << "Ano:" << std::endl;
	std::cin >> newAno;
	Calendar::setAno(newAno);
	std::cout << "Mes:" << std::endl;
	std::cin >> newMes;
	Calendar::setMes(newMes);
	std::cout << "Dia:" << std::endl;
	std::cin >> newDia;
	Calendar::setDia(newDia);
	std::cout << "Hora:" << std::endl;
	std::cin >> newHora;
	Calendar::setHora(newHora);
	std::cout << "Minuto:" << std::endl;
	std::cin >> newMinuto;
	Calendar::setMinuto(newMinuto);
	std::cout << "Segundo:" << std::endl;
	std::cin >> newSegundo;
	Calendar::setSegundo(newSegundo);

	std::cout << "-----------------------------" << std::endl;
}
#endif // !CLASSES_H
