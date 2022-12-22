#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    int matricula;
    char nome[30];
    int idade;
    struct aluno *prox;
    struct aluno *ant;
} ALUNO;

typedef ALUNO *Lista_circ_dupl_enc;

void inicializa(Lista_circ_dupl_enc *inicio, Lista_circ_dupl_enc *fim){
    *list = (Lista_circ_dupl_enc) malloc(sizeof(ALUNO));
    
    (*list)->prox = *list;
    (*list)->ant = *list;
}

void insere(int matricula, char nome[], int idade, int pos, Lista_circ_dupl_enc *inicio, Lista_circ_dupl_enc *fim){
    ALUNO *novo = (ALUNO*) malloc(sizeof(ALUNO));
    novo->matricula = matricula;
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->prox = NULL;
    novo->ant = NULL;
    if(*inicio == NULL){
        *inicio = novo;
        *fim = novo;
    }else{
        if(pos == 0){
            novo->prox = *inicio;
            (*inicio)->ant = novo;
            *inicio = novo;
        }else if(pos == -1){
            (*fim)->prox = novo;
            novo->ant = *fim;
            *fim = novo;
        }else{
            ALUNO *aux = *inicio;
            int i = 0;
            while(i < pos){
                aux = aux->prox;
                i++;
            }
            novo->prox = aux;
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            aux->ant = novo;
        }
    }
    (*fim)->prox = *inicio;
    (*inicio)->ant = *fim;
}

void remove(int pos, Lista_circ_dupl_enc *inicio, Lista_circ_dupl_enc *fim){
    if(*inicio == NULL){
        printf("Lista vazia!");
    }else{
        if(pos == 0){
            ALUNO *aux = *inicio;
            *inicio = (*inicio)->prox;
            (*inicio)->ant = *fim;
            (*fim)->prox = *inicio;
            free(aux);
        }else if(pos == -1){
            ALUNO *aux = *fim;
            *fim = (*fim)->ant;
            (*fim)->prox = *inicio;
            (*inicio)->ant = *fim;
            free(aux);
        }else{
            ALUNO *aux = *inicio;
            int i = 0;
            while(i < pos){
                aux = aux->prox;
                i++;
            }
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            free(aux);
        }
    }
}
void imprime(Lista_circ_dupl_enc *inicio, Lista_circ_dupl_enc *fim){
    if(*inicio == NULL){
        printf("Lista vazia!");
    }else{
        ALUNO *aux = *inicio;
        while(aux != *fim){
            printf("Matricula: %d", aux->matricula);
            printf("Nome: %s", aux->nome);
            printf("Idade: %d", aux->idade);
            aux = aux->prox;
        }
    }
}

void reinicializa(Lista_circ_dupl_enc *inicio, Lista_circ_dupl_enc *fim){
    if(*inicio == NULL){
        printf("Lista vazia!");
    }else{
        ALUNO *aux = *inicio;
        while(aux != *fim){
            ALUNO *aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
        free(aux);
        *inicio = NULL;
        *fim = NULL;
    }
}

int main(){
    inicializa(&inicio, &fim);

    insere(1, "Joao", 20, 0, &inicio, &fim);
    insere(2, "Maria", 21, 1, &inicio, &fim);
    insere(3, "Jose", 22, 2, &inicio, &fim);
    insere(4, "Pedro", 23, 3, &inicio, &fim);

    imprime(&inicio, &fim);

    remove(0, &inicio, &fim);
    remove(1, &inicio, &fim);

    imprime(&inicio, &fim);

    reinicializa(&inicio, &fim);

    imprime(&inicio, &fim);
}