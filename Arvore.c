//Árvore  - Marcos Bee
//APAGA NO COM DOIS FILHOS -> promove o nó mais a direita da esquerda
//--------------------------> promove o nó mais a esquerda da direita

#include "stdio.h"
#include "stdafx.h"
#include "stdlib.h"

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

struct noArvore {
    struct noArvore *pontCima;
    int numero;                            //valor            
    struct noArvore *pontDireita;
    struct noArvore *pontEsquerda;
    int filho;                            //1 se ele for filho da esquerda do pai e 2 se for filho da direita do pai
};
noArvore *arvore;
noArvore *dedo;
int tmpscanf;//variável utilizada no comando scanf

//Protótipos das funções
void iniciaarvore(noArvore *arvore);
void mostraarvore(noArvore *arvore);
noArvore *criandoNo(int novoNo, noArvore *noDeCima);                //funcao com retorno, retorna o novo elemento para o antigo apontar para ele
void localizaLocalDeInsercao(int novoNo, noArvore *noAtual);
int verificanumerodefilhos(noArvore *no);
void excluisemfilho(noArvore *no);
void excluicomumfilho(noArvore *no);
void excluicomdoisfilhos(noArvore *no);
int procuramaisadireitadaesquerda(noArvore *no);

int main() {
    arvore = (noArvore *)malloc(sizeof(noArvore));
    iniciaarvore(arvore);
    dedo = arvore;
    while (true) {
        system("cls");
        printf("Percorrendo a arvore\n");
        mostraarvore(arvore);
        printf("\nNo atual: \n");
        printf("*- Numero: %d\n", dedo->numero);
        printf("*- Ponteiro:          %p\n", dedo);
        printf("*- Ponteiro esquerda: %p\n", dedo->pontEsquerda);
        printf("*- Ponteiro direita:  %p\n", dedo->pontDireita);
        printf("*- Ponteiro cima:     %p\n", dedo->pontCima);
        printf("*- Filho da (1-esq,2-dir): %d\n", dedo->filho);
        
        
        printf("\n\n\n\n");
        printf("|-------MENU------|\n");
        printf("| 1-Esquerda  <-- |\n");
        printf("| 2-Direita   --> |\n");
        printf("| 3-Cima       ^  |\n");
        printf("|-----------------|\n");
        printf("| 4-Adicionar NEW |\n");
        printf("|-----------------|\n");
        printf("| 5-Remover    X  |\n");
        printf("|-----------------|\n");
        printf("6-Sair\n");
        scanf("%d", &tmpscanf);
        if(tmpscanf == 1){
            //indo para a esquerda do atual
            if (dedo->pontEsquerda != NULL) { dedo = dedo->pontEsquerda; }    //antes de ir para a direita, consulta se não é null
            else { printf("Erro! - A arvore esta vazia a esquerda do no atual\n"); system("pause"); }//mensagem de erro
        }else if(tmpscanf == 2){
            //indo para a direita do atual
            if (dedo->pontDireita != NULL) { dedo = dedo->pontDireita; }        //antes de ir para a direita, consulta se não é null
            else { printf("Erro! - A arvore esta vazia a direita do no atual\n"); system("pause"); }//mensagem de erro
        }else if(tmpscanf == 3){
            dedo = dedo->pontCima;
        }else if(tmpscanf == 4){
            //Adicionando nó na árvore
            printf("Digite o novo numero:\n");
            scanf("%d", &tmpscanf);
            localizaLocalDeInsercao(tmpscanf,arvore);
        }else if (tmpscanf == 5) {
            //Removendo nó na árvore - Verificar quantos filhos a árvore tem
            int filhos = verificanumerodefilhos(dedo);
            switch (filhos) {
                case 0:
                    excluisemfilho(dedo);                                //chama a função que exclui sem filho mandando o no apontado (dedo)
                    dedo = arvore;                                        //dedo aponta para a raiz da arvore apos a exclusao
                    break;

                case 1:
                    excluicomumfilho(dedo);
                    dedo = arvore;
                    break;
                default:
                    excluicomdoisfilhos(dedo);
                    dedo = arvore;
            }

        }else if(tmpscanf==6){
            break;
        }
        else {
            printf("Erro! - opcao invalida\n"); system("pause");
        }
    }
        return 0;
}
void iniciaarvore(noArvore *arvore){
    //inicia a arvore com o primeiro nó apontando o esq e dir para nulo
    printf("Digite o numero que sera guardado no no raiz!\n");
    scanf("%d", &tmpscanf);
    arvore->numero = tmpscanf;
    arvore->pontCima = NULL;
    arvore->pontEsquerda = NULL;
    arvore->pontDireita = NULL;
    arvore->filho = 0;
}
void mostraarvore(noArvore *noArvoreDedo){
    printf("|%d",noArvoreDedo->numero);//imprime o nó atual
    //percorre esquerda
    if(noArvoreDedo->pontEsquerda!=NULL){
        //chama o filho
        mostraarvore(noArvoreDedo->pontEsquerda);
    }
    //percorre direita
    if (noArvoreDedo->pontDireita != NULL) {
        //chama o filho
        mostraarvore(noArvoreDedo->pontDireita);
    }
}

void localizaLocalDeInsercao(int novoNo, noArvore *noAtual) {        //funcao que localiza o local de insercao do novo no
    if(novoNo==(noAtual->numero)){                                    //verifica se o nó já não existe na arvore
        printf("Erro! - Este elemento ja esta na arvore\n"); system("pause"); return;
    }else if(novoNo>(noAtual->numero)){                                //escolhe para qual dos lados da arvore vai - direita
        if (noAtual->pontDireita==NULL){                            //verifica se nó da direita esta vago
            noAtual->pontDireita = criandoNo(novoNo, noAtual);        //adiciona no nó vago a direita
            noAtual->pontDireita->filho = 2;                        //filho da direita
        }else{                                                        //chama a funcao recursivamente pelo ponteiro da direita
            localizaLocalDeInsercao(novoNo,noAtual->pontDireita);    //chama recursivamente o filho da direita
        }
    }else{                                                            //esquerda
        if (noAtual->pontEsquerda==NULL){                            //verifica se nó da esquerda esta vago
            noAtual->pontEsquerda = criandoNo(novoNo,noAtual);        //adiciona no no vago a esquerda
            noAtual->pontEsquerda->filho = 1;                        //filho da esquerda
        }
        else{
            localizaLocalDeInsercao(novoNo,noAtual->pontEsquerda);    //chama recursivo o nó da esquerda, tem alguem, navegar no de baixo
        }
    }
}
noArvore *criandoNo(int novoNo, noArvore *noDeCima){                //recebe o no de cima para referenciar, novo nó para adicionar
    noArvore *novonodaarvore = (noArvore *)malloc(sizeof(noArvore));//cria o novo no da arvore que será inserido
    novonodaarvore->numero = novoNo;                                //adiciona no novo no o valor recebido pela funcao de criar o novo nó
    novonodaarvore->pontCima = noDeCima;                            //amarração, novo nó criado tem de apontar para o ponteiro de cima
    novonodaarvore->pontDireita = NULL;                                //o novo nó criado não terá nenhum filho
    novonodaarvore->pontEsquerda = NULL;                            //o novo nó criado não terá nenhum filho
    return novonodaarvore;                                            //ligacao do no antigo com o novo, retorna o novo ponteiro
}

int verificanumerodefilhos(noArvore *no){                            //funcao que recebe um nó e retorna o numero de filhos dela
    int numerodefilhos=0;
    if (no->pontEsquerda != NULL) { numerodefilhos++; }                //se tiver filho a esquerda vai ser diferente de null, ai acrescenta um
    if (no->pontDireita != NULL) { numerodefilhos++; }                //se tiver filho a direita vai ser diferente de null, ai acrescenta um
    return numerodefilhos;
}

void excluisemfilho(noArvore *no){                                    //exclui o no sem nenhum filho
    if(no->filho==1){//esq                                          //verifica se e filho da esquerda ou direita
        no->pontCima->pontEsquerda = NULL;
    }else{//dir
        no->pontCima->pontDireita = NULL;
    }
    free(no);
}
void excluicomumfilho(noArvore *no){
    if (no->filho == 1) {//é filho da esq                                //verifica se e filho da esquerda ou direita
        if (no->pontEsquerda!=NULL){//tem filho a esq                //verifica se tem filho a esquerda ou a direita
            no->pontCima->pontEsquerda = no->pontEsquerda;
            no->pontEsquerda->pontCima = no->pontCima;
        }else{//tem filho a dir
            no->pontCima->pontEsquerda = no->pontDireita;
            no->pontDireita->pontCima = no->pontCima;
            no->pontDireita->filho = 1;//o ponteiro de baixo antes era filho da direita agora virou filho da esquerda
        }
    }
    else {//é filho da direita
        if (no->pontEsquerda != NULL) {//tem filho a esq             //verifica se tem filho a esquerda ou a direita
            no->pontCima->pontDireita = no->pontEsquerda;
            no->pontEsquerda->pontCima = no->pontCima;
            no->pontEsquerda->filho = 2;//o ponteiro de baixo antes era filho da esquerda agora virou filho da direita
        }
        else {//tem filho a dir
            no->pontCima->pontDireita = no->pontDireita;
            no->pontDireita->pontCima = no->pontCima;
        }
    }
    free(no);
}
void excluicomdoisfilhos(noArvore *no) {
    //Promove o nó mais a esquerda da direita
    int promovido = procuramaisadireitadaesquerda(no);    //nó que é excluido e promovido à posição do excluido
    no->numero = promovido;                                //renomeia o nó que foi 'excluido' com o nó que realmente foi excluido
}

int procuramaisadireitadaesquerda(noArvore *no){
    printf("\nProcurando nó a ser promovido...\n  ");
    noArvore *procura = no;                //equivalente ao dedo
    int tmp,tmpfilhos;                    //guarda o nó a ser promovido para retornar no finao da função | variavel para guardar o numero de filhos do no a ser excluido depois de promovido
    procura = procura->pontEsquerda;    //...da esquerda
    
    //------------------CHAMADA REPETITIVA------------------------//
    
    while (true)                                //rotina que busca o nó mais a direita
    {
        if (procura->pontDireita == NULL) {        //verifica se não tem filho à direita
            //não tem filho à direita, logo ele é o nó mais a direita
            tmp = procura->numero;                //está salvo o número para ser retornado
            //excluir este nó
            tmpfilhos = verificanumerodefilhos(procura);    //verifica quantos filhos o nó a ser promovido que será excluido tem
            //ele vai ter um ou nenhum filho
            if (tmpfilhos == 1) {                //tem um filho
                excluicomumfilho(procura);
            }
            else if (tmpfilhos == 0) {            //não tem nenhum filho
                excluisemfilho(procura);
            }
            else {                                //nunca vai ter dois filhos
                printf("\nOcorreu algum ERRO durante a procura do numero de filhos da exclusão!\n");
            }
            return tmp;                        //retornar o valor dele para a funcao
        }
        else {
            //tem filho a direita
            procura = procura->pontDireita;
            
        }
    }
}

