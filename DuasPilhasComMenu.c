// teste.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

int main()
{
    int menu = 0;

    int pilha[5];
    int pilhaamendoim[5];
    int pontoamendoim = 0;
    int ponto = 0;
    int tmp = 0;



    while (1) {
        printf("=====================================\n");
        printf("==   MENU      Digite a opcao      ==\n");
        printf("=====================================\n");
        printf("1-Mostrar pilha\n");
        printf("2-Inserir numero na pilha\n");
        printf("3-Obter numero da pilha(remover)\n");
        printf("4-sair\n");
        scanf("%d", &menu);
        printf("-------------------------------------\n");
        system("cls");

        if (menu == 1) {
            printf("Qual pilha deseja ver\n 1-Normal\n 2-Amendoim\n");
            scanf("%d", &menu);
            if (menu==1) {
                //vendo pilha normal
                printf("\nMostrando a pilha normal...\n");
                if (ponto == 0)
                {
                    printf("Pilha vazia\n");
                }
                else {
                    for (int i = 0; i<ponto; i++)
                    {
                        printf("|%d", pilha[i]);
                    }
                    printf("\n");
                }
            }
            else {
                //vendo pilha amendoim
                printf("\nMostrando a pilha de amendoim...\n");
                if (pontoamendoim == 0)
                {
                    printf("Pilha de amendoim vazia\n");
                }
                else {
                    for (int i = 0; i<pontoamendoim; i++)
                    {
                        printf("|%d", pilhaamendoim[i]);
                    }
                    printf("\n");
                }
            }

        }
        else if (menu == 2) {
            printf("Em qual pilha deseja inserir\n 1-Normal\n 2-Amendoim\n");
            scanf("%d", &menu);
            if (menu == 1) {
                //inserindo na pilha normal
                printf("\nInserindo na pilha normal...\n");
                printf("Digite o valor:\n");
                scanf("%d", &tmp);
                pilha[ponto] = tmp;
                ponto++;
            }
            else {
                //inserindo na pilha amendoim
                printf("\nInserindo na pilha amendoim...\n");
                printf("Digite o valor:\n");
                scanf("%d", &tmp);
                pilhaamendoim[pontoamendoim] = tmp;
                pontoamendoim++;
            }

        }
        else if (menu == 3) {
            
            /////////////////////////
            printf("De qual pilha deseja remover\n 1-Normal\n 2-Amendoim\n");
            scanf("%d", &menu);
            if (menu == 1) {
                //removendo da pilha normal
                printf("\nRemovendo da pilha normal(o ultimo)...\n");
                printf("||%d||\n", pilha[ponto - 1]);
                ponto--;
            }
            else {
                //removendo da pilha amendoim
                printf("\nRemovendo da pilha amendoim(o ultimo)...\n");
                printf("||%d||\n", pilhaamendoim[pontoamendoim - 1]);
                pontoamendoim--;
            }
        }
        else if (menu == 4) {
            return 0;
        }

    }



    return 0;
}
