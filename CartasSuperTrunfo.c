#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_CIDADES 20

// Criação da estrutura que armazenará as cidades

typedef struct
{
    char Codigo[4];
    int Populacao;
    float Area;
    float PIB;
    int NumPonTuristicos;
    float DensPopulacional;
    float PIBPerCapita;
    float SuperPoder;
} Cidade;

// Criação da função de amostragem de cartas

void ExibirCarta(Cidade cidade)
{
    printf("\nNome: %s", cidade.Codigo);
    printf("\nPopulação: %d pessoas", cidade.Populacao);
    printf("\nÁrea: %.2f Km²", cidade.Area);
    printf("\nPIB: R$ %.2f", cidade.PIB);
    printf("\nPontos turísticos: %d", cidade.NumPonTuristicos);
    printf("\nDensidade populacional: %.2f pessoas por Km²", cidade.DensPopulacional);
    printf("\nPIB per capita: R$ %.2f por pessoa", cidade.PIBPerCapita);
    printf("\nSuper poder:  %.2f pontos\n\n", cidade.SuperPoder);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Cidade cidades[MAX_CIDADES];
    Cidade guerreira1;
    Cidade guerreira2;

    int NumCidades;
    char CodBatalha1[4], CodBatalha2[4], JogNovam[2] = "Y", CriaCarta[2] = "Y";
    int Guer1_PTS, Guer2_PTS;

    printf("\n**** Seja bem vindo ao Super Trunfo! ****");

    printf("\nQuantas cidades deseja cadastrar? (Max.: %d) \n", MAX_CIDADES);
    scanf(" %d", &NumCidades);

    if (NumCidades < 1 || NumCidades > MAX_CIDADES)
    {
        printf("\nO número digitado excede o limite!");
        return 1;
    }

    while (strcmp(CriaCarta, "Y") == 0)
    {

        // Coleta dos dados das cidades.

        for (int i = 0; i < NumCidades; i++)
        {
            printf("\nCrie a carta a seguir:\n\n");

            printf("\nCódigo:(Ex.: A01, A02) ");
            scanf(" %3s", cidades[i].Codigo);

            printf("\nPopulação: ");
            scanf(" %d", &cidades[i].Populacao);

            printf("\nÁrea: (Em Km²)");
            scanf(" %f", &cidades[i].Area);

            printf("\nPIB: (Em R$)");
            scanf(" %f", &cidades[i].PIB);

            printf("\nNúmero de pontos turísticos: ");
            scanf(" %d", &cidades[i].NumPonTuristicos);

            cidades[i].DensPopulacional = (float)cidades[i].Populacao / cidades[i].Area;
            cidades[i].PIBPerCapita = (float)cidades[i].PIB / cidades[i].Populacao;
            cidades[i].SuperPoder = (float)cidades[i].Populacao + cidades[i].Area + cidades[i].PIB + cidades[i].NumPonTuristicos + cidades[i].DensPopulacional + cidades[i].PIBPerCapita;

            printf("\nCidade cadastrada! Dados exibidos a seguir:");

            ExibirCarta(cidades[i]);
        }

        while (strcmp(JogNovam, "Y") == 0 && NumCidades > 2) // Serve para finalizar o código quando a pessoa não quiser mais jogar
        {
            Guer1_PTS = 0;
            Guer2_PTS = 0;

            // Amostragem das cartas criadas

            printf("\n**** Ok! Vamos agora pôr as cidades em batalha! ****\n");
            printf("\nA seguir, estão as cartas criadas:\n");

            for (int i = 0; i < NumCidades; i++)
            {
                ExibirCarta(cidades[i]);
            }

            // Seleção das cartas que irão batalhar

            printf("\nDigite, a seguir, os códigos das cartas que deseja que batalhem:\n");
            scanf(" %3s %3s", CodBatalha1, CodBatalha2);

            for (int i = 0; i < NumCidades; i++)
            {
                if (strcmp(CodBatalha1, cidades[i].Codigo) == 0)
                {
                    guerreira1 = cidades[i];
                }
                else if (strcmp(CodBatalha2, cidades[i].Codigo) == 0)
                {
                    guerreira2 = cidades[i];
                }
            }

            // Amostragem das cartas que irão batalhar

            printf("\nLogo abaixo estão nossas cartas guerreiras:\n");

            printf("\n**** Primeira desafiante: ****\n");

            ExibirCarta(guerreira1);

            printf("\n**** Segunda desafiante: ****\n");

            ExibirCarta(guerreira2);

            // Amostragem dos resultados de batalha individuais

            printf("\nResultado da batalha:\n");

            // Verificação da populaçao vencedora

            if (guerreira1.Populacao > guerreira2.Populacao)
            {
                Guer1_PTS++;
                printf("\nMaior população:\n\n Cidade: %s com %d pessoas\n", guerreira1.Codigo, guerreira1.Populacao);
            }
            else if (guerreira2.Populacao > guerreira1.Populacao)
            {
                Guer2_PTS++;
                printf("\nMaior população:\n\n Cidade: %s com %d pessoas\n", guerreira2.Codigo, guerreira2.Populacao);
            }
            else
            {
                printf("\nHouve um empate na competição de maior população: Nenhuma cidade pontuou\n\n");
            }

            // Verificação da área vencedora

            if (guerreira1.Area > guerreira2.Area)
            {
                Guer1_PTS++;
                printf("\nMaior área:\n\n Cidade: %s com %.3f Km²\n", guerreira1.Codigo, guerreira1.Area);
            }
            else if (guerreira2.Area > guerreira1.Area)
            {
                Guer2_PTS++;
                printf("\nMaior área:\n\n Cidade: %s com %.3f Km²\n", guerreira2.Codigo, guerreira2.Area);
            }
            else
            {
                printf("\nHouve um empate na competição de maior área: Nenhuma cidade pontuou\n\n");
            }

            // Verificação do PIB vencedor

            if (guerreira1.PIB > guerreira2.PIB)
            {
                Guer1_PTS++;
                printf("\nMaior PIB:\n\n Cidade: %s com R$ %.2f \n", guerreira1.Codigo, guerreira1.PIB);
            }
            else if (guerreira2.PIB > guerreira1.PIB)
            {
                Guer2_PTS++;
                printf("\nMaior PIB:\n\n Cidade: %s com R$ %.2f \n", guerreira2.Codigo, guerreira2.PIB);
            }
            else
            {
                printf("\nHouve um empate na competição de maior PIB: Nenhuma cidade pontuou\n\n");
            }

            // Verificação do número de pontos turísticos vencedor

            if (guerreira1.NumPonTuristicos > guerreira2.NumPonTuristicos)
            {
                Guer1_PTS++;
                printf("\nMais pontos turísticos:\n\n Cidade: %s com %d pontos turísticos\n", guerreira1.Codigo, guerreira1.NumPonTuristicos);
            }
            else if (guerreira2.NumPonTuristicos > guerreira1.NumPonTuristicos)
            {
                Guer2_PTS++;
                printf("\nMais pontos turísticos:\n\n Cidade: %s com %d pontos turísticos\n", guerreira2.Codigo, guerreira2.NumPonTuristicos);
            }
            else
            {
                printf("\nHouve um empate na competição de maior número de pontos turísticos: Nenhuma cidade pontuou\n\n");
            }

            // Verificação da densidade populacional vencedora

            if (guerreira1.DensPopulacional < guerreira2.DensPopulacional)
            {
                Guer1_PTS++;
                printf("\nMenor densidade populacional:\n\n Cidade: %s com %.2f pessoas por Km²\n", guerreira1.Codigo, guerreira1.DensPopulacional);
            }
            else if (guerreira2.DensPopulacional < guerreira1.DensPopulacional)
            {
                Guer2_PTS++;
                printf("\nMenor densidade populacional:\n\n Cidade: %s com %.2f pessoas por Km²\n", guerreira2.Codigo, guerreira2.DensPopulacional);
            }
            else
            {
                printf("\nHouve um empate na competição de menor densidade populacional: Nenhuma cidade pontuou\n\n");
            }

            // Verificação do PIB per capita vencedor

            if (guerreira1.PIBPerCapita > guerreira2.PIBPerCapita)
            {
                Guer1_PTS++;
                printf("\nMaior PIB per capita:\n\n Cidade: %s com $RS %.2f por pessoa\n", guerreira1.Codigo, guerreira1.PIBPerCapita);
            }
            else if (guerreira2.PIBPerCapita > guerreira1.PIBPerCapita)
            {
                Guer2_PTS++;
                printf("\nMaior PIB per capita:\n\n Cidade: %s com %.2f por pessoa\n", guerreira2.Codigo, guerreira2.PIBPerCapita);
            }
            else
            {
                printf("\nHouve um empate na competição de maior PIB per capita: Nenhuma cidade pontuou\n\n");
            }

            // Verificação do super poder vencedor

            if (guerreira1.SuperPoder > guerreira2.SuperPoder)
            {
                Guer1_PTS++;
                printf("\nMaior Super Poder:\n\n Cidade: %s com %.2f pontos\n", guerreira1.Codigo, guerreira1.SuperPoder);
            }
            else if (guerreira2.SuperPoder > guerreira1.SuperPoder)
            {
                Guer2_PTS++;
                printf("\nMaior Super Poder:\n\n Cidade: %s com %.2f pontos\n", guerreira2.Codigo, guerreira2.SuperPoder);
            }
            else
            {
                printf("\nHouve um empate na competição de maior Super Poder: Nenhuma cidade pontuou\n\n");
            }

            // Amostragem da carta vencedora

            if (Guer1_PTS > Guer2_PTS)
            {
                printf("\nA Cidade vencedora da competição é a %s, com %d pontos!\n", guerreira1.Codigo, Guer1_PTS);
                printf("\nTodos os dados da cidade:\n");

                ExibirCarta(guerreira1);
            }
            else if (Guer2_PTS > Guer1_PTS)
            {
                printf("\nA Cidade vencedora da competição é a %s, com %d pontos!\n", guerreira2.Codigo, Guer2_PTS);

                ExibirCarta(guerreira2);
            }
            else
            {
                printf("\nHouve um empate na competição: A pontuação de ambas as cidades foi igual a %d\n\n", Guer1_PTS);
            }

            printf("\nGostaria de realizar outra batalha dentre as cartas criadas? ('Y' para sim ou 'N' para criar novas cartas ou finalizar o jogo)\n\n");
            scanf(" %2s", JogNovam);
        }

        if (NumCidades < 2)
        {
            printf("\nPara conseguir batalhar com as cartas, deve-se ter pelo menos duas.\n\n");
        }

        printf("\nGostaria de criar novas cartas? ('Y' para sim ou 'N' para finalizar o jogo)\n\n");
        scanf(" %2s", CriaCarta);
    }

    printf("\nJogo Finalizado!\n\n");

    return 0;
}
