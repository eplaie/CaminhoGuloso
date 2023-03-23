#include "matriz.hpp"

void imprime_matriz(Valor x[N][N]) {
    for (int i = 0; i < N; i++) {
        cout << "\t\t\t";

        for (int j = 0; j < N; j++) {
            cout << x[i][j].val << "\t";
        }

        cout << endl;
    }

    cout << endl << endl;
}

int obter_valor_direita(Valor x[N][N], int i, int j){
    int valor_direita = 0;

    if (j <= (N - 2)) {
        valor_direita = x[i][j + 1].val;
    }

    return valor_direita;
}

int obter_valor_esquerda(Valor x[N][N], int i, int j){
    int valor_esquerda = 0;

    if (j > 0 && i != (N - 1)) {
        valor_esquerda = x[i][j - 1].val;
    }

    return valor_esquerda;
}

int obter_valor_baixo(Valor x[N][N], int i, int j){
    int valor_baixo = 0;

    if (i <= (N - 2)) {
        valor_baixo = x[i + 1][j].val;
    }

    return valor_baixo;
}

int obter_valor_diagonal_direita(Valor x[N][N], int i, int j){
    int valor_diagonal_direita = 0;

    if (i <= (N - 2) && j <= (N - 2)) {
        valor_diagonal_direita = x[i + 1][j + 1].val;
    }

    return valor_diagonal_direita;
}

int obter_valor_diagonal_esquerda(Valor x[N][N], int i, int j){
    int valor_diagonal_esquerda = 0;

    if (i <= (N - 2) && j > 0) {
        valor_diagonal_esquerda = x[i + 1][j - 1].val;
    }

    return valor_diagonal_esquerda;
}

bool checar_valores_iguais(int valor_direita, int valor_esquerda, int valor_baixo, int valor_diagonal_direita, int valor_diagonal_esquerda) {
    vector <int> valores_vec;
    valores_vec.push_back(valor_direita);
    valores_vec.push_back(valor_esquerda);
    valores_vec.push_back(valor_baixo);
    valores_vec.push_back(valor_diagonal_direita);
    valores_vec.push_back(valor_diagonal_esquerda);
    int maior = valores_vec[0];
    int cont = 0;

    for (int i = 1; i < 5; i++) {
        if (valores_vec[i] > maior) {
            maior = valores_vec[i];
        }
    }

    for (int i = 0; i < 5; i++) {
        if (valores_vec[i] == maior) {
            cont++;
        }
    }

    if (cont > 1) {
        return true;
    } else {
        return false;
    }
}

bool decisao_maior(vector <int> decisao, int pos) {
    for (int i = 0; i < 5; i++) {
        if (decisao[i] > decisao[pos]) {
            return false;
        }
    }

    return true;
}

void processa_matriz(Valor x[N][N], int ordem_matriz) {
    int i_inicial, j_inicial;

    do {
        cout << "\t\t- Informe a coordenada i inicial: ";
        cin >> i_inicial;

        if (i_inicial > 7 || i_inicial < 0) {
            cout << "\tERRO: são aceitos apenas valores a partir de 0 e até 7!\n";
        }
    } while (i_inicial > 7 || i_inicial < 0);

    do {
        cout << "\t\t- Informe a coordenada j inicial: ";
        cin >> j_inicial;

        if (j_inicial > 7 || j_inicial < 0) {
            cout << "\tERRO: são aceitos apenas valores a partir de 0 e até 6!\n";
        }
    } while (j_inicial > 7 || j_inicial < 0);

    cout << endl;

    cout << "\t\t- Descrição do caminho percorrido na matriz " <<  ordem_matriz << ": " << endl << endl;

    int i = i_inicial, j = j_inicial, total = x[i][j].val, valor_direita, valor_esquerda, valor_baixo, valor_diagonal_direita, valor_diagonal_esquerda;
    bool decisao;
    vector <int> vector_decisao;
    x[i][j].val = -1;

    while (i != (N - 1) || j != (N - 1)) {
        valor_direita = obter_valor_direita(x, i, j);
        valor_esquerda = obter_valor_esquerda(x, i, j);
        valor_baixo = obter_valor_baixo(x, i, j);
        valor_diagonal_direita = obter_valor_diagonal_direita(x, i, j);
        valor_diagonal_esquerda = obter_valor_diagonal_esquerda(x, i , j);

        vector_decisao.push_back(valor_direita); // 0
        vector_decisao.push_back(valor_esquerda); // 1
        vector_decisao.push_back(valor_baixo); // 2
        vector_decisao.push_back(valor_diagonal_direita); // 3 
        vector_decisao.push_back(valor_diagonal_esquerda); //4

        // checar maiores valores iguais
        decisao = checar_valores_iguais(valor_direita, valor_esquerda, valor_baixo, valor_diagonal_direita, valor_diagonal_esquerda);

        if (decisao == true) {
            
            if (i <= (N - 2)) { // primeira opcao -> baixo
                cout << "\t\t\t  *Foi para baixo" << endl;
                total += x[i + 1][j].val;
                x[i + 1][j].val = -1;
                i++;
            } else if (j <= (N - 2)) { // segunda opcao -> direita
                cout << "\t\t\t  *Foi para direita" << endl;
                total += x[i][j + 1].val;
                x[i][j + 1].val = -1;
                j++;
            } else if (i <= (N - 2) && j <= (N - 2)) { // terceira opcao -> diagonal direita
                cout << "\t\t\t  *Foi para diagonal direita" << endl;
                total += x[i + 1][j + 1].val;
                x[i + 1][j + 1].val = -1;
                i++; j++;
            } else if (i <= (N - 2) && j > 0) { // quarta opcao -> diagonal esquerda
                cout << "\t\t\t  *Foi para diagonal esquerda" << endl;
                total += x[i + 1][j - 1].val;
                x[i + 1][j - 1].val = -1;
                i++; j--;
            } else if (j > 0) { // quinta opcao -> esquerda
                cout << "\t\t\t  *Foi para esquerda" << endl;
                total += x[i][j - 1].val;
                x[i][j - 1].val = -1;
                j--;
            }
        } else {
            if (decisao_maior(vector_decisao, 0)) { // direita
                cout << "\t\t\t  *Foi para direita" << endl;
                total += x[i][j + 1].val;
                x[i][j + 1].val = -1;
                j++;

            } else if (decisao_maior(vector_decisao, 1)) { // esquerda
                cout << "\t\t\t  *Foi para esquerda" << endl;
                total += x[i][j - 1].val;
                x[i][j - 1].val = -1;
                j--;

            } else if (decisao_maior(vector_decisao, 2)) { // baixo
                cout << "\t\t\t  *Foi para baixo" << endl;
                total += x[i + 1][j].val;
                x[i + 1][j].val = -1;
                i++;

            } else if (decisao_maior(vector_decisao, 3)) { // diagonal direita
                cout << "\t\t\t  *Foi para diagonal direita" << endl;
                total += x[i + 1][j + 1].val;
                x[i + 1][j + 1].val = -1;
                i++; j++;

            } else if (decisao_maior(vector_decisao, 4)) { // diagonal esquerda
                cout << "\t\t\t  *Foi para diagonal esquerda" << endl;
                total += x[i + 1][j - 1].val;
                x[i + 1][j - 1].val = -1;
                i++; j--;
            }
        }

        vector_decisao.clear();
    }

    cout << endl << endl << "\t\t- Visualização do caminho percorrido na matriz " << ordem_matriz << ":" << endl << endl;
    imprime_matriz(x);
    cout << "\t\t- A soma dos valores percorridos na matriz " << ordem_matriz << " é: " << total << endl << endl;
    cout << "========================================================================================" << endl << endl;
}

void preenche_matriz(vector <int> conteudo, int ordem_matriz) {
    Valor mat[N][N];
    int k = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j].val = conteudo[k];
            k++;
        }
    }

    cout << "\t\t      Essa é a matriz inicial " << ordem_matriz << ": " << endl << endl;
    imprime_matriz(mat);
    processa_matriz(mat, ordem_matriz);
}