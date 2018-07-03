
//Lista Duplamente Encadeada - Marcos Bee - Lista encadeada //preferencial

#include "stdio.h"
#include "stdafx.h"
#include "stdlib.h"

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

struct elemento {
    int numero;
    struct elemento *anterior;
    struct elemento *proximo;
};
int tmpins;
int opcao;
int tmp;
int controleinicial;
elemento *controle;
elemento *lista;
elemento *temporario;

void inicia(elemento *lista);
void mostra();



int main(void)
{
    lista = (elemento *)malloc(sizeof(elemento));
    inicia(lista);
    controle = lista;
    while (true) {
        //Ver a lista    
        if (lista->proximo == NULL) {
            printf("####--LISTA DUPLAMENTE ENCADEADA--####\n");
            printf("Lista esta vazia!\n");
            printf("Digite o primeiro numero da lista!\n");
            scanf("%d", &controleinicial);
            lista->numero = controleinicial;
            lista->proximo = lista;
            lista->anterior = lista;
            mostra();
        }
        else {
            printf("Mostrando lisla !\n");
            mostra();
        }
        //----------------------------------------------------
        printf("      MENU    Digite a opcao LDE\n");
        printf("-------------------------------------\n");
        printf("1-Iterar\n");
        printf("2-sair\n");
        scanf("%d", &opcao);
        system("cls");
        //////////////////////////////////////////////////////
        if (opcao == 1) {//Iterar na lista

            while (true) {
                system("cls");
                printf("Iterando na lista\n");
                mostra();
                printf("No atual: \n");
                printf("*- Numero: %d\n", controle->numero);
                printf("*- Ponteiro: %d\n", controle);
                printf("*- Ponteiro anterior: %d\n", controle->anterior);
                printf("*- Ponteiro proximo: %d\n", controle->proximo);
                printf("---SUBMENU----\n");
                printf("1-Proximo   -->\n");
                printf("2-Anterior  <--\n");
                printf("3-Inserir um numero antes do %d\n", controle->numero);
                printf("4-Remover este numero\n");
                printf("5-voltar ao menu inicial\n");
                scanf("%d", &opcao);
                if (opcao == 1) {
                    controle = controle->proximo;
                }
                else if (opcao == 2) {
                    controle = controle->anterior;
                }
                else if (opcao == 3) {//Inserindo antes
                    elemento *novo = (elemento *)malloc(sizeof(elemento));
                    printf("Digite o valor a ser inserido:\n");
                    scanf("%d", &tmpins);
                    novo->numero = tmpins;
                    novo->proximo = controle;
                    novo->anterior = controle->anterior;//ver no caderno
                    temporario = controle->anterior;
                    controle->anterior = novo;
                    temporario->proximo = novo;//pulo do gato
                }
                else if (opcao == 4) {//Removendo
                    if (controle == lista) {
                        printf("######Voce esta tentado remover o no raiz da lista\n");
                        printf("######Ele so pode ser alterado\n######Digite o novo valor para o no raiz:\n");
                        scanf("%d", &tmpins);
                        lista->numero = tmpins;
                        printf("Raiz alterada\n");
                    }
                    else {
                        temporario = controle;
                        controle = controle->anterior;
                        controle->proximo = temporario->proximo;
                        controle = temporario->proximo;
                        controle->anterior = temporario->anterior;
                        free(temporario);
                        printf("Ligacoes refeitas\n");
                    }
                }
                else {
                    system("cls");
                    break;
                }
            }


            printf("Inserido com sucesso!\n");
        }
        else {
            return 0;
        }
    }
}

void inicia(elemento *lista)
{
    //Inicia a lista, colocando o ponteiro anterior e o proximo apontando nulo
    lista->anterior = NULL;
    lista->proximo = NULL;
}

void mostra() {
    elemento *dedo;
    dedo = lista;
    printf("----------------LISTA--------------------\n");
    while (true) {
        printf("| %d", dedo->numero);
        if ((dedo->proximo) == lista) {//o elemento mostrado tem como proximo o no raiz da lista
            printf("\nTodos os elementos foram mostrados\n");
            break;
        }
        dedo = dedo->proximo;
    }
    printf("\n-----------------------------------------\n");
}






