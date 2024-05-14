#ifndef IDA
#define IDA



// Definição do TAD para o vetor
typedef struct ida {
    int tamanho;
    int vetor[300]; // Tamanho máximo do vetor
} Ida;


// Função para ajustar o tamanho dos vetores adicionando zeros no início do vetor menor
void ajustarTamanhoDosVetores(Ida *v1, Ida *v2);

// Função para somar vetores de algarismos com carry
void somarVetoresComCarry(Ida v1, Ida v2, Ida *resultado);










#endif
