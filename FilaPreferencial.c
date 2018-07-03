//Lista encadeada preferencial

#include "stdio.h"
#include "stdafx.h"
#include "stdlib.h"

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

struct elemento {
    int num;
    struct elemento *prox;
};
int opcao;
int tmp;


void inicia(elemento *lista);
void mostra(elemento *lista);
void insere(elemento *lista, int numero);
void andafila(elemento *listanormal, elemento *listapreferencial);



int main(void)
{
    elemento *listanormal = (elemento *)malloc(sizeof(elemento));
    elemento *listapreferencial = (elemento *)malloc(sizeof(elemento));
    inicia(listanormal);
    inicia(listapreferencial);
    while (true) {
        printf("      MENU    Digite a opcao\n");
        printf("-------------------------------------\n");
        printf("1-Mostrar as filas\n");
        printf("2-Inserir numero na fila normal\n");
        printf("3-Inserir numero na fila preferencial\n");
        printf("4-Andar a fila(remover elemento)\n");
        printf("5-sair\n");
        scanf("%d", &opcao);
        system("cls");

        if (opcao == 1) {
            if (listapreferencial->prox == NULL) {
                printf("Fila preferencial vazia!\n");
            }
            else {
                printf("Mostrando fila preeferencial!\n");
                mostra(listapreferencial);
            }
            if (listanormal->prox == NULL) {
                printf("Fila vazia!\n");
            }
            else {
                printf("Mostrando fila!\n");
                mostra(listanormal);
            }


        }
        else if (opcao == 2) {
            printf("Inserindo na fila normal\nDigite o numero a ser inserido:\n");
            scanf("%d", &tmp);
            insere(listanormal, tmp);
            printf("Inserindo com sucesso!\n");
        }
        else if (opcao == 3) {
            printf("Inserindo na fila preferencial\nDigite o numero a ser inserido:\n");
            scanf("%d", &tmp);
            insere(listapreferencial, tmp);
            printf("Inserindo com sucesso!\n");
        }
        else if (opcao == 4) {
            andafila(listanormal, listapreferencial);
        }
        else if (opcao == 5) {
            return 0;
        }


    }
}

void inicia(elemento *lista)
{
    lista->prox = NULL;

}

void mostra(elemento *lista) {
    elemento *dedo;
    dedo = lista->prox;
    while (dedo != NULL) {
        printf("| %d", dedo->num);
        dedo = dedo->prox;
    }
    printf("\n");
}

void insere(elemento *lista, int numero) {
    elemento *novo = (elemento *)malloc(sizeof(elemento));
    novo->num = numero;
    novo->prox = NULL;

    if (lista->prox == NULL)//se não tem nenhum elemento na lista ele adiciona um a cabeca
        lista->prox = novo;
    else {
        elemento *dedo = lista->prox;

        while (dedo->prox != NULL) {
            dedo = dedo->prox;
        }

        dedo->prox = novo;
    }
}

void andafila(elemento *listanormal, elemento *listapreferencial) {
    printf("Andando fila!..\n");

    if (listapreferencial->prox != NULL) {
        printf("Andando fila preferencial!\n");
        elemento *dedo = listapreferencial->prox;
        printf("Elemento removido da fila: %d\n", dedo->num);
        elemento *darfreepreferencial = dedo;
        dedo = dedo->prox;
        listapreferencial->prox = dedo;
        free(darfreepreferencial);
    }
    else {
        printf("Fila preferencial vazia!\n");
        if (listanormal->prox == NULL) {
            printf("Fila normal vazia, não tem ninguem para atender!\n");
        }
        else {
            elemento *dedo = listanormal->prox;
            printf("Elemento removido da fila: %d\n", dedo->num);
            elemento *darfreenormal = dedo;
            dedo = dedo->prox;
            listanormal->prox = dedo;
            free(darfreenormal);
        }
    }

}
