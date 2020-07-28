#include <iostream>

using namespace std;

void Troca(int *a, int *b){
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;

}


int main(){
    int x, y;

    std::cin >> x;
    std::cin >> y;

    //Chamando a função "troca";

    Troca(&x, &y);

    std:: cout << x << " " << y << std::endl;
}