#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa


int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    int Codigo;
    char Nome[50];
    int Populacao;
    float Area;
    float PIB;
    int NumPonTuristicos;
    int CriarCidade = 1;
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    printf ("Seja bem vindo ao Super Trunfo!");
    printf ("\nPara iniciar, defina os dados da Cidade:");
    
    printf ("\nNome: ");
    scanf (" %[^\n]", Nome);

    printf ("\nPopulação: ");
    scanf (" %d", &Populacao);

    printf ("\nÁrea: ");
    scanf (" %f", &Area);

    printf ("\nPIB: ");
    scanf (" %f", &PIB);

    printf ("\nNúmero de pontos turísticos: ");
    scanf (" %d", &NumPonTuristicos);
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    printf ("\nCidade cadastrada! Dados exibidos a seguir:");

    printf ("\nNome: %s", Nome);
    printf ("\nPopulação: %d pessoas", Populacao);
    printf ("\nNÁrea: %.2f Km²", Area);
    printf ("\nPIB: R$ %.2f", PIB);
    printf ("\nPontos turísticos: %d", NumPonTuristicos);

    return 0;
}
