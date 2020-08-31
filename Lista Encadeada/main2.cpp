#include <iostream>
#include "List2.h"
 
using namespace std;

int main() { 
    
    cout << "informe quantos elementos vai ter na lista: " << endl;
    List *list = new List();
    int medida;
    cin >> medida;

    cout << "digite os elementos" << endl;
    for(int i = 0; i < medida; i++){
        int elem;
        cin >> elem; 
        list->add(elem); 
    }
    
    List *listOther = list->copy();
    cout << "copia da lista criada" << endl;

    int valor, posicao;
    
    cout << "lista atual: ";
    list->print();
    cout << "diga qual posicao deseja remover o elemento: " << endl;
    cin >> posicao;
    list->removeNodeAt(posicao);

    cout << "lista atual: ";
    list->print();
    cout << "elemento a ser inserido:"  << endl;
    cin >> valor;
    cout << "a posicao anterior a dele:  " << endl;
    cin >> posicao;
    list->insertAfter(valor, posicao);
    cout << "lista atualizada apos a insercao: ";
    list->print();
    
    int vector[valor];
    for(int i = 0; i < 5; i++){
        vector[i] = i;
    }

    list->copyArray(vector, valor);

    if(list->equal(listOther)){
        cout << "lista igual" << endl;
    }
    else{
        cout << "lista diferente" << endl;
    }
    
    list->print();
    list->concatenate(listOther);
    delete listOther;
    list->reverse();

    cout << "digite o elemento para remover da lista:" << endl;
    cin >> valor;
    list->removeAll(valor);
    
    cout << "resultado da lista: ";
    list->print();
    delete list;
    return 0;
}
