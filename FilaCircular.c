//Fila Circular 

#include "stdio.h"
#include "stdafx.h"
#include "stdlib.h"

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

int main()
{
    int menu = 0;

    int fila[5];
    int comecodafila = 0;
    int proximaentrada = 0;
    int quantidade = 0;
    int controle = 0;
    int tmp = 0;

    //    printf("\nTestando o c++\n\n");


    while (1) {
        printf("=====================================\n");
        printf("      MENU      Digite a opcao\n");
        printf("-------------------------------------\n");
        printf("1-Mostrar Fila\n");
        printf("2-Inserir numero na fila\n");
        printf("3-Obter numero da fila(remover)\n");
        printf("4-sair\n");
        scanf("%d", &menu);
        system("cls");

        if (menu == 1) {
            printf("\nMostrando a fila...\n");
            if (quantidade == 0)
            {
                printf("Fila vazia\n");
            }
            else {
                controle = 0;
                for (int i = comecodafila;controle<quantidade; i++)
                {    
                    if (i == 5) { i = 0; }//conecta o filal da fila com o começo
                    printf("|%d", fila[i]);
                    controle++;

                }
                printf("\n");
            }
        }else if (menu == 2) {
            printf("\nInserindo na fila...\n");
            if (quantidade==5) {
                printf("\nA fila esta cheia, remova alguem da fila para poder inserir\n");
                
            }
            else {
                quantidade++;
                printf("Digite o valor:\n");
                scanf("%d", &tmp);
                fila[proximaentrada] = tmp;
                proximaentrada++;
                if (proximaentrada == 5) { proximaentrada = 0; }
            }
        }
        else if (menu == 3) {
            printf("\nRemovendo da fila(primeiro da fila)...\n");
            printf("||%d||\n", fila[comecodafila]);
            comecodafila++;
            quantidade--;
            if (comecodafila == 5) { comecodafila = 0; }
        }
        else{
            return 0;
        }
        

    }



    return 0;
}
