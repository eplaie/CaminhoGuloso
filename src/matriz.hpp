#ifndef MATRIZ_HPP
#define MATRIZ_HPP
#define N 8
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
typedef struct Valor Valor;
typedef struct Matriz Matriz;
using namespace std;

struct Valor {
    int val;
};

struct Matriz {
    Valor Mat[N][N];
};

void imprime_matriz(Valor x[N][N]);
int obter_valor_direita(Valor x[N][N], int i, int j);
int obter_valor_esquerda(Valor x[N][N], int i, int j);
int obter_valor_baixo(Valor x[N][N], int i, int j);
int obter_valor_diagonal_direita(Valor x[N][N], int i, int j);
int obter_valor_diagonal_esquerda(Valor x[N][N], int i, int j);
bool checar_valores_iguais(int valor_direita, int valor_esquerda, int valor_baixo, int valor_diagonal_direita, int valor_diagonal_esquerda);
bool decisao_maior(vector <int> vector_decisao, int pos);
void processa_matriz(Valor x[N][N], int ordem_matriz);
void preenche_matriz(vector <int> conteudo, int ordem_matriz);

#endif