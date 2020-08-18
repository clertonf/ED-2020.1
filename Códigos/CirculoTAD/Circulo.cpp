#include <iostream>
#include <cmath>
#include "Ponto.h"
#include "Circulo.h"

using namespace std;

// criar um círculo;

Circulo::Circulo(float r, Ponto p){
    raio = r;
    center.setX(p.getX());
    center.setY(p.getY());
}
// atribuir novo valor ao raio do círculo;
void Circulo::setRaio(float r){
    raio = r;
}

// mudar as coordenadas do centro do círculo;
void Circulo::setX(float v){
    center.setX(v);
}
// obter o valor da coordenada x ou y do centro do círculo;
void Circulo::setY(float v){
    center.setY(v);
}
// obter o comprimento do raio do círculo;
float Circulo::getRaio(){
    return raio;
}

Ponto Circulo::getCentro(){
    return center;
}
// calcular a área do círculo;
float Circulo::area(){

    return M_PI * (raio * raio);
}

// verificar se um ponto está no interior do círculo;
bool Circulo::interior(Ponto p){
    //Diz se tá dentro do circulo ou não
    //dist = distancia

    double dist = center.distancia(p);
    if (raio >= dist){
        return true;
    }

    return false;
}

// liberar memória alocada na criação do tipo de dado círculo.
Circulo::~Circulo(){
    // delete this
    cout << "círculo destruído" << endl;
}
