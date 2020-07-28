#include <iostream>

using namespace std;

void hanoi(int n, char orig, char dest , char aux){
    
    if(n==1){
        cout << orig << dest << endl;
    }
    
    else{
    
            hanoi(n-1, orig, aux, dest);
            cout << orig << " -> " << dest << "\n";
            hanoi(n-1, aux, dest, orig);
    }
    
}

int main(){

    int n;
    cin >> n;
    
    hanoi(n, 'A' , 'C', 'B');
    return 0;
}