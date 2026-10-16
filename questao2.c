
#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas, colunas;

    printf("Numero de linhas: ");
    scanf("%d", &linhas);
    printf("Numero de colunas: ");
    scanf("%d", &colunas);

    // Alocação dinâmica da matriz original
    int **matriz = (int **) malloc(linhas * sizeof(int *));
    // Alocação dinâmica da matriz invertida (imagem negativa)
    int **matriz_invertida = (int **) malloc(linhas * sizeof(int *));

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        matriz_invertida[i] = (int *) malloc(colunas * sizeof(int));
    }

    printf("Valores digitados para a matriz (por linha):\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
            // Cálculo do tom complementar (imagem negativa)
            matriz_invertida[i][j] = 255 - matriz[i][j];
        }
    }

    // Exibição da Matriz Original
    printf("\nMatriz da imagem original (digitada):\n\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Exibição da Matriz Invertida
    printf("\nMatriz da imagem invertida (gerada pelo programa):\n\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%3d ", matriz_invertida[i][j]);
        }
        printf("\n");
    }

    // Liberação da memória alocada
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
        free(matriz_invertida[i]);
    }
    free(matriz);
    free(matriz_invertida);

    return 0;
}