//Buble Sort - Marcos Bee


#include "stdio.h"
#include "stdafx.h"
#include "stdlib.h"


#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS


int tmpscanf;//variável utilizada no comando scanf
int vetor[5];        //vetor
int n;                //controle de execucao
int i = 0;            //controle de iteracao(for)
int aux;            //guarda valor para troca
int numerodevalores = 5;//

void ordenaBubleSort();

int main() {
    


    FILE *arquivoleitura;
    FILE *arquivoescrita;
    arquivoleitura = fopen("leitura.txt", "r");
    arquivoescrita = fopen("escrita.txt", "w");

    if (arquivoleitura == NULL){
        printf("\nErro ao abrir arquivo de leitura");
    }else{
        printf("\nArquivo de leitura aberto");
    }
    if (arquivoescrita == NULL) {
        printf("\nErro ao abrir arquivo de escrita");
    }else{
        printf("\nArquivo de escrita aberto");
    }
    
    //lendo do arquivo
    while (!feof(arquivoleitura))
    {
        fscanf(arquivoleitura, "%d", &vetor[i]);
        i++;
    }
    //imprimindo na tela
    printf("\nValores do vetor: ");
    for (i = 0; i < numerodevalores; i++) {
        printf("%d ", vetor[i]);
    }
    //ORDENANDO BUBLE SORT
    ordenaBubleSort();

    //imprimindo na tela
    printf("\nValores do vetor: ");
    for (i = 0; i < numerodevalores; i++) {
        printf("%d ", vetor[i]);
    }

    //escrevendo no arquivo
    for (i = 0;i<numerodevalores;i++) {
        fprintf(arquivoescrita, "%d ", vetor[i]);
    }
    fclose(arquivoleitura);
    fclose(arquivoescrita);
    system("pause");
    
}

void ordenaBubleSort() {
    //Ordena em ordem crescente
    //controle de execucoes do algorótmo Buble Sort
    for (n=0; n < numerodevalores;n++) {    //se nao for trocado nenhum na execucao interna ele continua zero e para de executar porque já está ordenado
        printf(">");
        for (i = 0;i<numerodevalores-1;i++) {
            printf(":");
            if (vetor[i]>vetor[i+1]){
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                printf(",");
            }
        }
    }
}

