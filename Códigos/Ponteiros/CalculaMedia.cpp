#include <iostream> //std::cout, std::fixed
#include <iomanip> // std::setprecision

struct aluno{
    float nota[3];
    float media;
};

// Recebe um aluno passado por referência, e preenche o campo "media" com a
// media das 3 notas do aluno.

void calculaMedia(aluno *a){
    float Auxmedia = 0;
    for(int i = 0; i < 3; i++){
        Auxmedia += a->nota[i];
    }

    a->media = Auxmedia/3;
}

// Recebe vetor de alunos ('turma') e número de alunos ('n'), e chama a função
// 'calcula_media' (da questão anterior) para cada aluno do vetor.
// Ou seja, preenche o campo 'media' de cada aluno com a média das 3 notas do aluno.
void calculaMediaTurma(aluno turma[], int n){
    for(int i = 0; i < n; i++){
        calculaMedia(&turma[i]);
    }
}


int main(){
    // aluno a;
    // int i;
    // for(i = 0; i < 3; i++){
    //     std::cin >> a.nota[i];
    // }

    int n;
    
    std::cin >> n;
    aluno turma[n];

    for(int j = 0; j < n; j++){
        for(int i = 0; i < 3; i++){
            std::cin >> turma[j].nota[i];
        }
    }


    //chamar a função "calcula_media_turma" passando o vetor de alunos "turma"

    calculaMediaTurma(turma, n);
  
    for(int j = 0; j < n; j++){
    std::cout << std::fixed;
    std::cout << std::setprecision(1) << turma[j].media << " ";

}
    return 0;
}