#include <iostream>

using namespace std;

void converte_tempo(int segundos, int *hor, int *min, int *seg){
    *hor = segundos/(60*60);

    segundos = segundos%(60*60);

    *min = segundos/60;
    segundos = segundos%60;

    *seg = segundos;

}

int main(){
    int seg, h, m, s;
    std::cin >> seg;

    converte_tempo(seg, &h, &m, &s);
    std::cout << h << ":" << m << ":" << "s";

    return 0;
}