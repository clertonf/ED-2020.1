#include <iostream>
#include "List2.h"
#include <climits>
using namespace std;

struct Node {
    int value;
    Node *next;
};

// Construtor
List::List() {
    head = new Node;
    head->next = nullptr;
}

// Adiciona o inteiro x ao final da lista
void List::add(int x) {
    Node *novo = new Node;
    novo->value = x;
    novo->next = nullptr;
    Node *aux = head; 
    while(aux->next != nullptr) 
        aux = aux->next;
    aux->next = novo;
}

void List::clear() {
    head->next = clearRecursive(head->next);
}

Node *List::clearRecursive(Node *node) {
    if(node == nullptr) // Caso base: lista vazia
        return nullptr;
    else { // Caso geral
        node->next = clearRecursive(node->next); // 1: remover todo mundo que vem depois
        delete node; // 2: remove o no atual
        return nullptr; // 3: retorna nulo para o no que vem antes de voce
    }
}

List::~List() {
    clear();
    delete head;
}


void List::print() {
    printRecursive(head->next);
    cout << endl;
}

void List::printRecursive(Node *node) {
    if(node == nullptr) // Caso base: não tenho nó pra imprimir
        return;
    else {
        std::cout << node->value << " ";
        printRecursive(node->next);
    }
}

void List::printReverso() {
    printRecursiveReverso(head->next);
    cout << endl;
}

void List::printRecursiveReverso(Node *node) {
    if(node == nullptr) // Caso base: não tenho nó pra imprimir
        return;
    else {
        printRecursiveReverso(node->next);
        std::cout << node->value << " ";    
    }
}

bool List::isEmpty() {
    return (head->next == nullptr);
}

int List::size() {
    int soma = 0;
    Node *aux = head->next;
    while(aux != nullptr) {
        soma++;
        aux = aux->next;
    }
    return soma;
}

// Operacao auxiliar: retorna o antecessor do no 
// com valor x, ou nullptr caso x nao esteja presente 
Node *List::search(int x) {
   
    if(head->next == nullptr) return nullptr; // lista vazia
    Node *aux = head;
    while((aux->next != nullptr) && (aux->next)->value != x) {
        aux = aux->next;
    }
    return ((aux->next == nullptr) ? nullptr : aux);
}

void List::remove(int x) {
   
    Node *ant = search(x);
    if(ant != nullptr) {
        Node *noRem = ant->next;
        ant->next = noRem->next;
        delete noRem;
    }
}

//Remove da lista todas as ocorrências do inteiro x.
void List::removeAll( int x ){
   
    if(head->next == nullptr){ 
        cout << "lista vazia" << endl;
        return;
    }

    Node *aux = head;
    int count = 0; 
    for(;aux->next != nullptr; aux = aux->next){
         if(aux->next->value == x){
            count++;
        }
    }

    for(int i = 0; i < count; i++)
        remove(x);
}

/* Remove a k-ésima célula da lista encadeada e retorna o seu valor. Note que deve-se 
ter 1 ≤ k ≤ size(); caso countrário, retorna-se o menor inteiro possı́vel (INT_MIN). */
int List::removeNodeAt( int k ){
   
    if(head->next == nullptr){
        cout << "lista vazia" << endl;
    }

    Node *aux = head;
    for(int count = 1; aux->next != nullptr; aux = aux->next, count++){
        if(k == count){
            Node *remover = aux->next;
            aux->next = remover->next;
            int n = remover->value;
            delete remover;
            return n;
        }
    
    }
    return INT_MIN;
}
 
/* Insere um novo nó com valor x após o k-ésimo nó da lista. Deve-se 
ter 0 ≤ k ≤ size() para que a inserção seja realizada; caso countrário, não sera realizada. */
void List::insertAfter( int x, int k ){
   
    if(head->next == nullptr){
        cout << "lista vazia" << endl;
        return;
    }

    Node *aux = head;
    for(int count = 0; aux->next != nullptr; aux = aux->next, count++ ){
          if(count == k){
            Node *newNode;
            newNode = new Node();
            newNode = aux->next;
            aux->next = newNode;
            newNode->value = x;
            return;
        }
    }

    if(k == size()){
        add(x);
        return;
    }
}

/* Retorna um ponteiro para uma cópia desta lista. */
List * List::copy(){
   
    List *Listnew = new List();
    for(Node *aux = this->head; aux->next != nullptr; aux = aux->next){
        Listnew->add(aux->next->value);

    }
    return Listnew;
}

/* Copia os elementos do array v para a lista. O array tem n elementos. 
Todos os elementos anteriores da lista são apagados. */
void List::copyArray( int v[], int n ){
   
    clear();
    for(int i = 0; i < n; i++){
        add(v[i]);
    }
}

/* Determina se a lista lst, passada por parâmetro, é igual à lista em questão. 
Duas listas são iguais se elas tem o mesmo tamanho e o valor do k-ésimo elemento da primeira lista é 
igual ao k-ésimo valor da segunda lista. */
bool List::equal( List *lst ){
    
    if(size() == lst->size()){
        Node *aux = head;
        for(Node *aux2 = lst->head; aux->next != nullptr; aux = aux->next, aux2 = aux2->next){
            if(aux->next->value != aux2->next->value)
                return false;
        }
        return true;
    }
    return false;
}

/* Concatena a lista atual com a lista lst passada como parâmetro para a função. 
Após essa operação, lst será uma lista vazia, ou seja, o único nó de lst sera o nó cabeça. */
void List::concatenate( List *lst ){
   
    for(Node *aux = lst->head; aux->next != nullptr; aux = aux->next){
        add(aux->next->value);
    }
    lst->clear();
}

/* Inverte a ordem dos nós (o primeiro nó passa a ser o último, o segundo passa a ser o penúltimo, etc.) 
Essa operação faz isso sem criar novos nós, apenas altera os ponteiros. */
void List::reverse(){
    
    int vet[size()];
    int i = size()-1;

    for(Node *aux = head; aux->next != nullptr; i--){
        vet[i] = aux->next->value;
        aux = aux->next;
    }
    copyArray(vet, size());
}
