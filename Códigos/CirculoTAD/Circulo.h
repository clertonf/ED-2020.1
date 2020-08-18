#ifndef CIRCULO_H
#define CIRCULO_H
#include <iostream>
#include <cmath>
#include "Ponto.h"

// o construtor Circulo(float raio, Ponto centro): cria um cı́rculo cujo centro é um atributo do tipo Ponto e raio é um float;

class Circulo{

private:
    double raio;
    Ponto center;

public:
    // cria um cı́rculo cujo centro é um atributo do tipo Ponto e raio é um float;
    Circulo(float raio, Ponto centro);

    // atribui novo valor ao raio do cı́rculo;
    void setRaio(float r);

    // atribui novo valor à coordenada x;
    void setX(float v);

    // atribui novo valor à coordenada y;
    void setY(float v);

    // obtém o raio.
    float getRaio();

    // obtém o centro.
    Ponto getCentro();

    // calcula a área do cı́rculo.
    float area();

    // verifica se o Ponto p está dentro do cı́rculo;
    bool interior(Ponto p);

    // Libera memória alocada, se for necessário.
    ~Circulo();
};

#endif