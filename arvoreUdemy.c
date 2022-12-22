#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    struct no *esq;
    struct no *dir;
};

typedef struct no No;

No *criaNo(int valor){
    No *n = malloc(sizeof(No));
    n->valor = valor;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

void imprime(No *raiz){
    if (raiz != NULL){
        imprime(raiz->esq);
        printf("%d ", raiz->valor);
        imprime(raiz->dir);
    }
}

void adiciona(No *raiz, int valor){
    if (valor < raiz->valor){
        if (raiz->esq == NULL){
            raiz->esq = criaNo(valor);
        } else {
            adiciona(raiz->esq, valor);
        }
    } else {
        if (raiz->dir == NULL){
            raiz->dir = criaNo(valor);
        } else {
            adiciona(raiz->dir, valor);
        }
    }
}

void remover(No *no, int valor){
    No *filho = no;
    No *pai;

    do{
        pai = filho;
        if (valor < filho->valor){
            filho = filho->esq;
        }else if(valor > filho->valor){ 
            filho = filho->dir;
        }
    } while (filho != NULL && filho->valor != valor);
    if(filho!=NULL){
        if(filho->esq == NULL && filho->dir ==NULL){ //Nao ta com erro
            if(pai->esq == filho) pai->esq = NULL;
            if(pai->dir == filho) pai->dir = NULL;
        }
        if(filho->esq != NULL && filho->dir == NULL){ //ta com erro
            if(pai->esq == filho) 
            {
                pai->esq = filho->esq;
                filho->esq = NULL;
            }
            if(pai->dir == filho)
            {
                pai->dir = filho->esq;
                filho->esq = NULL;
            }
        }
        if(filho->dir != NULL && filho->esq == NULL){ //Nao ta com erro
            if(pai->esq == filho) pai->esq = filho->dir;
            if(pai->dir == filho) pai->dir = filho->dir;
            
        }
        if(filho->esq != NULL && filho->dir!=NULL){ //Nao ta com erro
            if(filho->esq->dir == NULL){
                filho->valor = filho->esq->valor;
            } else{
                No *p = filho->esq;
                No *aux = p;
                while(p->dir != NULL){
                    aux = p;
                    p = p->dir;
                }
                aux->dir = NULL;
                filho->valor = p->valor;
            } 
        }
    }
}
// Função que realiza a busca em profundidade em uma árvore binária
No* busca_profundidade(No *raiz, int valor) {
    // Se a raiz for nula, então a árvore está vazia
    if (raiz) {
        if( valor == raiz->valor){
            return raiz;
        } else if( valor < raiz->valor){
            return busca_profundidade(raiz->esq, valor);
        } else{
            return busca_profundidade(raiz->dir, valor);
        }
    } else {
        return NULL;
    }
}

int main(void){
    No *raiz = criaNo(10);
    No *n = NULL;
    adiciona(raiz, 5);
    adiciona(raiz, 15);
    imprime(raiz);
    printf("\n");
    adiciona(raiz, 3);
    adiciona(raiz, 7);
    imprime(raiz);
    printf("\n");
    adiciona(raiz, 12);
    adiciona(raiz, 18);
    imprime(raiz);
    printf("\n");
    adiciona(raiz, 16);
    adiciona(raiz, 1);
    imprime(raiz);
    printf("\n");
    adiciona(raiz, 4);
    imprime(raiz);
    printf("\n");

    
    /*imprime(raiz);

    n = busca_profundidade(raiz, 18);
    if(n){
        printf("Valor encontrado: %d\n", n->valor);
    } else{
        printf("Valor não encontrado");
    }
    
    imprime(raiz);
    
    */
    printf("REMOVENDO ALGUNS NOS\n");

    remover(raiz, 3);


    imprime(raiz);
   

}