#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4
#define MAX_CIDADES 32 


typedef struct {
    char codigo[4]; 
    long populacao; 
    float area;    
    float pib;      
    int pontos_turismo; 
} Cidade;

void cadastrarCidade(Cidade *cidade, char estado, int cidade_num) {
    sprintf(cidade->codigo, "%c%02d", estado, cidade_num);
    
    printf("Cadastro da cidade %s:\n", cidade->codigo);
    
    printf("Digite a populacao: ");
    scanf("%ld", &cidade->populacao);
    
    printf("Digite a area (em km²): ");
    scanf("%f", &cidade->area);
    
    printf("Digite o PIB (em milhões): ");
    scanf("%f", &cidade->pib);
    
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &cidade->pontos_turismo);
    
    printf("\nCidade %s cadastrada com sucesso!\n\n", cidade->codigo);
}

void exibirCidade(const Cidade *cidade) {
    printf("Dados da cidade %s:\n", cidade->codigo);
    printf("Populacao: %ld\n", cidade->populacao);
    printf("Area: %.2f km²\n", cidade->area);
    printf("PIB: %.2f milhões\n", cidade->pib);
    printf("Pontos turisticos: %d\n", cidade->pontos_turismo);
    printf("\n");
}

int main() {
    Cidade cidades[MAX_CIDADES];
    int i, j;
    char estado;
    
    for (i = 0; i < NUM_ESTADOS; i++) {
        estado = 'A' + i; 
        
        for (j = 0; j < NUM_CIDADES; j++) {
            cadastrarCidade(&cidades[i * NUM_CIDADES + j], estado, j + 1);
        }
    }
    
    for (i = 0; i < MAX_CIDADES; i++) {
        exibirCidade(&cidades[i]);
    }

    return 0;
}