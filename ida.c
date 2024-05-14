#include <stdio.h>

#include "ida.h"


// Função para ajustar o tamanho dos vetores adicionando zeros no início do vetor menor
void ajustarTamanhoDosVetores(Ida *v1, Ida *v2) {
    if (v1->tamanho < v2->tamanho) {
        int diferenca = v2->tamanho - v1->tamanho;
        for (int i = v1->tamanho - 1; i >= 0; i--) {
            v1->vetor[i + diferenca] = v1->vetor[i];
        }
        for (int i = 0; i < diferenca; i++) {
            v1->vetor[i] = 0;
        }
        v1->tamanho = v2->tamanho;
    } else if (v2->tamanho < v1->tamanho) {
        int diferenca = v1->tamanho - v2->tamanho;
        for (int i = v2->tamanho - 1; i >= 0; i--) {
            v2->vetor[i + diferenca] = v2->vetor[i];
        }
        for (int i = 0; i < diferenca; i++) {
            v2->vetor[i] = 0;
        }
        v2->tamanho = v1->tamanho;
    }
}


// Função para somar vetores de algarismos com carry
void somarVetoresComCarry(Ida v1, Ida v2, Ida *resultado) {
    int tamanho = v1.tamanho;
    int carry = 0; // Inicializa o "vai um" como 0

    for (int i = tamanho - 1; i >= 0; i--) {
        int soma = v1.vetor[i] + v2.vetor[i] + carry;
        resultado->vetor[i] = soma % 10; // Armazena o valor menos significativo da soma
        carry = soma / 10; // Atualiza o carry para a próxima iteração
    }

    // Se ainda houver carry após a iteração, você pode armazená-lo no início do vetor resultado
    if (carry > 0) {
        for (int i = tamanho - 1; i >= 0; i--) {
            resultado->vetor[i + 1] = resultado->vetor[i];
        }
        resultado->vetor[0] = carry;
        resultado->tamanho = tamanho + 1;
    } else {
        resultado->tamanho = tamanho;
    }
}
