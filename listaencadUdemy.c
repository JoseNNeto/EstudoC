#include <stdio.h>
#include <stdlib.h>

struct ponto
{
    float x;
    float y;
    struct ponto *prox;
};

typedef struct ponto Ponto;

void adiciona(Ponto *p, float x, float y)
{
    Ponto *novo = (Ponto *) malloc(sizeof(Ponto));
    novo->x = x;
    novo->y = y;
    novo->prox = NULL;
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = novo;
}

int main(void)
{
    Ponto *p =(Ponto*) malloc(sizeof(Ponto));
    p->x = 10;
    p->y = 20;

    Ponto *q =(Ponto*) malloc(sizeof(Ponto));
    q->x = 30;
    q->y = 40;

    Ponto *r =(Ponto*) malloc(sizeof(Ponto));
    r->x = 50;
    r->y = 60;

    p->prox = q;
    q->prox = r;
    r->prox = NULL;

}