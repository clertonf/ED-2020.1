#include <iostream>

using namespace std;

int conta_char_rec(char* s, char c, int n = 0){
    // n = 0;
    // \0 = fim da linha de um vetor de caracter, para representar uma string

    if(s[n]=='\0'){
        return 0;
    }

    else 
        if(s[n]==c){
        return 1 + conta_char_rec(s, c, n+1);

    }

    else{
        return 0 + conta_char_rec(s, c, n+1);
    }
}

int main(){

    char s[102], c;

    cin.get(s,102);
    cin.ignore();
    cin >> c;

    // int n = strlen(s); vai pegar o numéro de caracteres de s;

    int qtd = conta_char_rec(s,c);
    cout << c << "\n";

    //Chamar a função aqui e imprimir na tela;
    return 0;
}