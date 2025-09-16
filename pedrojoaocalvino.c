#include <stdio.h>          
#include <string.h>

/* Integrantes (04G)
    André Doerner Duarte - 10427938
    Matheus Leonardo Cardoso Kroeff - 10426434
    Naoto Ushizaki - 10437445
*/


int buscaChave(char mapa[10][10], int n, int m, int linha, int coluna, int visitado[10][10]) {
    // Verificar limites da matriz
    if (linha < 0 || linha >= n || coluna < 0 || coluna >= m) return 0;

    // Verificar se já visitou essa posição
    if (visitado[linha][coluna]) return 0;
    visitado[linha][coluna] = 1;

    // Verificar se encontrou a chave
    if (mapa[linha][coluna] == '*') return 1;

    // Se for corredor horizontal, pode mover esquerda/direita
    if (mapa[linha][coluna] == 'H') {
        if (buscaChave(mapa, n, m, linha, coluna - 1, visitado)) return 1;
        if (buscaChave(mapa, n, m, linha, coluna + 1, visitado)) return 1;
    }

    // Se for corredor vertical, pode mover cima/baixo
    if (mapa[linha][coluna] == 'V') {
        if (buscaChave(mapa, n, m, linha - 1, coluna, visitado)) return 1;
        if (buscaChave(mapa, n, m, linha + 1, coluna, visitado)) return 1;
    }

    return 0;
}

int main(){
    int n; // número de linhas (andares)
    scanf("%d", &n);

    char mapa[10][10];
    int m = 0; // número de colunas

    // leitura da matriz 
    for (int i = 0; i < n; i++) {
        char linha_char[20];
        int j = 0;

        while (1) {
            scanf("%s", linha_char);
            m = strlen(linha_char);
            if(m > 10) m =10;
            for(int a = 0; a < m; a++){
                if (linha_char[a] == 'H' || linha_char[a] == 'V' || linha_char[a] == '*') {
                mapa[i][j++] = linha_char[a];
                } else {
                printf("\nERROR");
                break; 
                }
            }
            if (j >= 10 || j >= m) break;
        }
        if (j > m) m = j; 
    }
        

    int linhaInicial, colunaInicial;
    scanf("%d %d", &linhaInicial, &colunaInicial);

    int visitado[10][10] = {0}; // matriz auxiliar 

    if (buscaChave(mapa, n, m, linhaInicial, colunaInicial, visitado)) {
        printf("Chave encontrada no Edifício João Calvino!\n");
    } else {
        printf("Não conseguimos encontrar a chave no Edifício João Calvino.\n");
    }

    return 0;
}