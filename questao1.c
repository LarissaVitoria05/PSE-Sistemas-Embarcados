#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    int freq;
} Elemento;

// Função para comparar a frequência (decrescente) e o valor (caso de empate)
int comparar(const void *a, const void *b) {
    Elemento *elemA = (Elemento *)a;
    Elemento *elemB = (Elemento *)b;

    if (elemB->freq != elemA->freq) {
        return elemB->freq - elemA->freq; // Ordem decrescente de frequência
    }
    return elemB->valor - elemA->valor;   // Desempate por valor
}

int main() {
    int total_elementos = 20;

    // Alocação dinâmica para armazenar os 20 valores lidos
    int *temperaturas = (int *) malloc(total_elementos * sizeof(int));
    if (temperaturas == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Entrando a seguinte sequencia de temperaturas (%d valores):\n", total_elementos);
    for (int i = 0; i < total_elementos; i++) {
        scanf("%d", &temperaturas[i]);
    }

    // Estrutura para agrupar e contar frequências de elementos únicos
    Elemento frequencias[20];
    int qtd_unicos = 0;

    for (int i = 0; i < total_elementos; i++) {
        int encontrado = 0;
        for (int j = 0; j < qtd_unicos; j++) {
            if (frequencias[j].valor == temperaturas[i]) {
                frequencias[j].freq++;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            frequencias[qtd_unicos].valor = temperaturas[i];
            frequencias[qtd_unicos].freq = 1;
            qtd_unicos++;
        }
    }

    // Libera o vetor dinamicamente alocado conforme solicitado
    free(temperaturas);

    // Ordena as frequências em ordem decrescente
    qsort(frequencias, qtd_unicos, sizeof(Elemento), comparar);

    // Exibição do relatório final
    printf("\nRELATORIO DE FREQUENCIA\n");
    printf("=======================\n");
    for (int i = 0; i < qtd_unicos; i++) {
        if (frequencias[i].freq > 1) {
            printf("%d - %d VEZES\n", frequencias[i].valor, frequencias[i].freq);
        } else {
            printf("%d - %d VEZ\n", frequencias[i].valor, frequencias[i].freq);
        }
    }

    return 0;
}