#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
    int x;
    int y;
    struct ponto *prox;
    struct ponto *ant;
}Ponto;

typedef struct lista{
    Ponto *inicio;
    Ponto *fim;
    int qtd;
}Lista;

void criaLista(Lista *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}
void inserir(Lista *l, int x, int y){
    Ponto *novo = (Ponto*) malloc(sizeof(Ponto));

    if(novo){
        novo->x = x;
        novo->y = y;
        l->inicio = novo;
        if(l->fim == NULL){
            l->fim = novo;
            novo->prox = novo;
            novo->ant = novo;
        l->fim->prox = l->inicio;
        l->qtd++;
        }
    }
}
Ponto *remover(Lista *l, int x, int y){
    Ponto *aux, *remover = NULL;

    if(l->inicio == l->fim && l->inicio->x == x && l->inicio->y == y){
        remover = l->inicio;
        l->inicio = NULL;
        l->fim = NULL;
        l->qtd--;
    }
    else if(l->inicio->x == x && l->inicio->y == y){
        remover = l->inicio;
        l->inicio = remover->prox;
        l->fim->prox = l->inicio;
        l->qtd--;
    }
    else{
        aux = l->inicio;
        while(aux->prox != l->inicio && aux->prox->x != x || aux->prox->y != y){
            aux = aux->prox;
        if(aux->prox->x == x && aux->prox->y == y){
            if(l->fim == aux->prox){
                remover = aux->prox;
                aux->prox = remover->prox;
                l->fim = aux;
            } 
            else{
                remover = aux->prox;
                aux->prox = remover->prox;
            }
            l->qtd = l->qtd--;
            } 
        }
    }
}
void imprimir(Lista *l){
    Ponto *aux = l->inicio;
    if(aux){
        do{
            printf("x: %d y: %d", aux->x, aux->y);
            aux = aux->prox;
        }while(aux != l->inicio);
        printf("\nInicio: %d e %d\n", l->inicio->x, l->inicio->y);
    }
}
void reinicializa(Lista *l){
    Ponto *aux = l->inicio;
    Ponto *remover = NULL;
    if(aux){
        do{
            remover = aux;
            aux = aux->prox;
            free(remover);
        }while(aux != l->inicio);
    }
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int main(){
    Lista *l = (Lista*) malloc(sizeof(Lista));
    criaLista(l);
    inserir(l, 10, 20);
    inserir(l, 30, 40);
    inserir(l, 50, 60);
    imprimir(l);

    remover(l, 10, 20);
    imprimir(l);

    reinicializa(l);
    imprimir(l);
    free(l);
    return 0;
}