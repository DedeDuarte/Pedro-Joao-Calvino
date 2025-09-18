#include <stdio.h>          
#include <string.h>

#define MAX_SIZE 10

/*
Integrantes (04G) {
    Matheus Leonardo Cardoso Kroeff {
        RA: MAX_SIZE426434;
    }

    André Doerner Duarte {
        RA: MAX_SIZE427938;
    }

    Naoto Ushizaki {
        RA: MAX_SIZE437445;
    }
}
*/

/**
 * @brief Procura recursivamente por uma chave em um prédio representado por matriz.
 *
 * A função recebe uma matriz de caracteres representando os andares de um prédio,
 * onde cada posição contém:
 * - 'H': movimentação horizontal (esquerda/direita)
 * - 'V': movimentação vertical (cima/baixo)
 * - '*': posição da chave
 * 
 * @param map      Matriz (em strings) de 'H', 'V' e '*' do prédio
 * @param n        Numero de andares do prédio
 * @param m        Numero de colunas do prédio
 * @param linha    Linha da posição inicial 
 * @param coluna   Coluna da posição inicial
 * @param visitado Matriz auxiliar
 * 
 * @retval 1: Chave encontrada
 * @retval 2: Chave não encontrada
 * 
 * @note Função MAX_SIZE0% recursiva
 */
int buscaChave(char mapa[MAX_SIZE][MAX_SIZE], int n, int m, int linha, int coluna, int visitado[MAX_SIZE][MAX_SIZE]) {
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

/**
 * @brief Função principal
 * 
 * @retval 0: Codigo executado com sucesso
 * 
 * @note Tamanho máximo da matiz: [MAX_SIZE x MAX_SIZE]
 * @warning Entradas diferentes de 'H', 'V' e '*' na matriz resultam em erro!
 */
int main(){
    int n; // número de linhas (andares)
    scanf("%d", &n);

    char mapa[MAX_SIZE][MAX_SIZE];
    int m = 0; // número de colunas

    // leitura da matriz 
    for (int i = 0; i < n; i++) {
        char linha_char[20];
        int j = 0;

        while (1) {
            scanf("%s", linha_char);
            m = strlen(linha_char);
            if(m > MAX_SIZE) m = MAX_SIZE;
            for(int a = 0; a < m; a++){
                if (linha_char[a] == 'H' || linha_char[a] == 'V' || linha_char[a] == '*') {
                mapa[i][j++] = linha_char[a];
                } else {
                printf("\nERROR");
                break; 
                }
            }
            if (j >= MAX_SIZE || j >= m) break;
        }
        if (j > m) m = j; 
    }
        

    int linhaInicial, colunaInicial;
    scanf("%d %d", &linhaInicial, &colunaInicial);

    int visitado[MAX_SIZE][MAX_SIZE] = {0}; // matriz auxiliar 

    if (buscaChave(mapa, n, m, linhaInicial, colunaInicial, visitado)) {
        printf("Chave encontrada no Edifício João Calvino!\n");
    } else {
        printf("Não conseguimos encontrar a chave no Edifício João Calvino.\n");
    }

    return 0;
}