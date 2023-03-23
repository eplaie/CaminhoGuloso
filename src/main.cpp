#include "matriz.hpp"
using namespace std;

void read_matrices() {
    ifstream myfile;
    string line;
    vector <int> conteudo_matriz;

    int cont = 0;
    int ordem_matriz = 1;

    myfile.open("matrizes.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line, ';')) {
            conteudo_matriz.push_back(stoi(line));
            cont++;
            
            if (cont == (N*N)) {
                cont = 0;
                preenche_matriz(conteudo_matriz, ordem_matriz);
                conteudo_matriz.clear();
                ordem_matriz++;
            }
        }
    }
}

int main () {
    read_matrices();
}