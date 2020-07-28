#include <iostream>
#include <iomanip>

using namespace std;

// Example

// Ex: 
// Operador "&" fornece o endereço de memória de uma variável;

// int a = 1;
// int *p;
// p = &a;


// Ex2:
// int b = 2 + *p --> b recebe valor 3 (2 + 1)
// *p = 5; --> isto modifica a variável 'a'

// int a = 1;
// int *p;
// p = &a;

// Esquema ilustrativo da memória:

//  Endereço  Valor  Variável
//           -------
//       100 |     |               
//           -------
//       200 |  1  | a  
//           -------
//       300 |     |
//           -------    
//       400 |     |   
//           -------
//       500 |     |    
//           -------
//       600 | 200 | p  
//           -------
//       700 |     |    
//           -------
//             ...


// int main(){
//     int a = 1;
//     int *p = &a;

//     cout << "Endereço de memória a:" << p << endl;
//     cout << "Valor armazenado no local apontado:" << *p << endl;

//     *p = 5;
//     cout << "Valor armazenado no local apontado:" << *p << endl;
//     cout << "Valor de a:" << a;
// }

// aqui não modifica
// void f(int x){
//     x = 2;
// }

// int main(){
//     int y = 1;
//     f(y);

//     cout << y; // Iprime o valor 1.
//     return 0;
// }

// void f(int *x){
//     *x = 2;
// }

// int main(){
//     int y = 1;
//     f(&y);

//     cout << y; //Iprime o valor 2
//     return 0;
// }

// Podemos ter ponteiros para estruturas. Portanto, podemos modificar campos de estruturas passadas como parâmetro.

// struct tupla{
//     int x;
//     float y;
// };

// void f(tupla *p){
//     (*p).y = 3;
// }

// int main(){
//     tupla t = {1, 2.0};

//     f(&t);

//     cout << std::fixed;
//     cout << t.x << std::setprecision(1) << t.y;
// }

// Para melhorar a legibilidade, a linguagem C++ permite escrever (*t).x como t->x.