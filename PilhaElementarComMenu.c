//Pilha elementar  com menu

#include "stdio.h"
#include "stdafx.h"
#include "stdlib.h"

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

int main()
{
    int menu = 0;

    int pilha[5];
    int ponto = 0;
    int tmp = 0;

    //    printf("\nTestando o c++\n\n");


    while (1) {
        printf("=====================================\n");
        printf("      MENU\nDigite a opcao\n");
        printf("-------------------------------------\n");
        printf("1-Mostrar pilha\n");
        printf("2-Inserir numero na pilha\n");
        printf("3-Obter numero da pilha(remover)\n");
        printf("4-sair\n");
        scanf("%d", &menu);
        system("cls");

        if (menu == 1) {
            printf("\nMostrando a pilha...\n");
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
        else if (menu == 2) {
            printf("\nInserindo na pilha...\n");
            printf("Digite o valor:\n");
            scanf("%d", &tmp);
            pilha[ponto] = tmp;
            ponto++;
        }
        else if (menu == 3) {
            printf("\nRemovendo da pilha(o ultimo)...\n");
            printf("||%d||\n", pilha[ponto - 1]);
            ponto--;
        }
        else if (menu == 4) {
            return 0;
        }

    }



    return 0;
}
