//Exercicio 1 em sobrecarga de Operadores

#include <iostream>
using namespace std;

class Vetor {
public:
    int x,y;
    Vetor(int x, int y) : x(x), y(y) { }

    friend void operator>> (istream& c, Vetor& v);

    Vetor operator+(const Vetor& other) const {
        return Vetor(x + other.x, y + other.y);
    }
};

void operator>> (istream& c, Vetor& v) {

    c >> v.x >> v.y;
}

ostream& operator<<(ostream& stream, const Vetor& other) {

    stream << other.x << "," << other.y;
    return stream;
}

int main() {

    Vetor var1(0, 0);
    Vetor var2(2, 4);

    cout << var1 << endl;
    cout << var2 << endl;
    
    cout << "Digite um valor inteiro: ";
    cin >> var1;

    cout << var1 << endl;
    Vetor var3 = var1 + var2;
    cout << var3 << endl;

}