#include <iostream>
#include "Ponto.h"
#include "Circulo.h"

using namespace std;

int main(){ 
    Ponto p1 = Ponto(3, 5);
    Ponto p2 = Ponto(931, 332);
    Circulo c1 = Circulo(3, p1);

    cout << c1.area() << endl;

    if (c1.interior(p2))
    {
        cout << "O ponto está dentro do círculo" << endl;
    }
    else
    {
        cout << "O ponto está fora" << endl;
    }

    return 0;
}