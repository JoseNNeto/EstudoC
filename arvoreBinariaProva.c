#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TIPO_IDENTIFICADOR;

struct registro_aluno{
    TIPO_IDENTIFICADOR id;
    char *nome;
    char *matricula;
    int idade;
    int periodo;
    int curso;
};

//char cursos[6] = {"informatica", "agroindustria", "agropecuaria", "engenharia", " enfermagem", "musica"};

typedef struct registro_aluno REG_ALUNO;

typedef struct node{
    REG_ALUNO aluno;
    struct node *esq;
    struct node *dir;
    struct node *pai;
} NODE;

typedef struct arvore{
    int id;
    int qtdElementos;
    NODE *raiz;
} ARVORE;

void criaArvore(ARVORE *arvore){
    arvore->id = 0;
    arvore->raiz = NULL;
    arvore->qtdElementos = 0;
}

void inicializarArvore(ARVORE *arvore){
    criaArvore(arvore);
}

void adicionarAluno(ARVORE *arvore, REG_ALUNO aluno){
    NODE *novo = (NODE*)malloc(sizeof(NODE));
    novo->aluno = aluno;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;
    if(arvore->raiz == NULL){
        arvore->raiz = novo;
    }else{
        NODE *atual = arvore->raiz;
        NODE *anterior = NULL;
        while(atual != NULL){
            anterior = atual;
            if(aluno.id < atual->aluno.id){
                atual = atual->esq;
            }else{
                atual = atual->dir;
            }
        }
        if(aluno.id < anterior->aluno.id){
            anterior->esq = novo;
        }else{
            anterior->dir = novo;
        }
        novo->pai = anterior;
    }
    arvore->qtdElementos++;
}

void imprimeArvore(NODE *raiz){
    if(raiz != NULL){
        imprimeArvore(raiz->esq);
        printf("ID: %d, Nome: %s, Matricula: %s, Idade: %d, Periodo: %d, Curso: %d\n", raiz->aluno.id, raiz->aluno.nome, raiz->aluno.matricula, raiz->aluno.idade, raiz->aluno.periodo, raiz->aluno.curso);
        imprimeArvore(raiz->dir);
    }
}

void removerAluno(ARVORE *arvore, TIPO_IDENTIFICADOR id){
    NODE *atual = arvore->raiz;
    NODE *anterior = NULL;
    while(atual != NULL && atual->aluno.id != id){
        anterior = atual;
        if(id < atual->aluno.id){
            atual = atual->esq;
        }else{
            atual = atual->dir;
        }
    }
    if(atual == NULL){
        printf("Aluno nao encontrado!");
    }else{
        if(atual->esq == NULL && atual->dir == NULL){
            if(anterior == NULL){
                arvore->raiz = NULL;
            }else{
                if(anterior->esq == atual){
                    anterior->esq = NULL;
                }else{
                    anterior->dir = NULL;
                }
            }
            free(atual);
        }else{
            if(atual->esq == NULL || atual->dir == NULL){
                NODE *filho;
                if(atual->esq == NULL){
                    filho = atual->dir;
                }else{
                    filho = atual->esq;
                }
                if(anterior == NULL){
                    arvore->raiz = filho;
                }else{
                    if(anterior->esq == atual){
                        anterior->esq = filho;
                    }else{
                        anterior->dir = filho;
                    }
                }
                free(atual);
            }else{
                NODE *sucessor = atual->dir;
                NODE *sucessorPai = atual;
                while(sucessor->esq != NULL){
                    sucessorPai = sucessor;
                    sucessor = sucessor->esq;
                }
                if(sucessorPai != atual){
                    sucessorPai->esq = sucessor->dir;
                    sucessor->dir = atual->dir;
                }
                sucessor->esq = atual->esq;
                if(anterior == NULL){
                    arvore->raiz = sucessor;
                }else{
                    if(anterior->esq == atual){
                        anterior->esq = sucessor;
                    }else{
                        anterior->dir = sucessor;
                    }
                }
                free(atual);
            }
        }
        arvore->qtdElementos--;
    }
}

void limparArvore(NODE *raiz){
    if(raiz != NULL){
        limparArvore(raiz->esq);
        limparArvore(raiz->dir);
        free(raiz);
    }
}

void destruirArvore(ARVORE *arvore){
    limparArvore(arvore->raiz);
    arvore->raiz = NULL;
    arvore->qtdElementos = 0;
}

 void buscaLargura(NODE *raiz){
    if(raiz != NULL){
        printf("ID: %d, Nome: %s, Matricula: %s, Idade: %d, Periodo: %d, Curso: %d\n", raiz->aluno.id, raiz->aluno.nome, raiz->aluno.matricula, raiz->aluno.idade, raiz->aluno.periodo, raiz->aluno.curso);
        buscaLargura(raiz->esq);
        buscaLargura(raiz->dir);
    }
}



int calcularProfundidade(NODE *raiz, int *profundidade){
    if(raiz != NULL){
        *profundidade = *profundidade + 1;
        calcularProfundidade(raiz->esq, profundidade);
        calcularProfundidade(raiz->dir, profundidade);
    }
    printf("Profundidade: %d\n", *profundidade);
    return *profundidade;
}
/*As funcoes sao:
    inicializarArvore(ARVORE *arvore)
    adicionarAluno(ARVORE *arvore, REG_ALUNO aluno)
    imprimeArvore(ARVORE *arvore)
    removerAluno(ARVORE *arvore, TIPO_IDENTIFICADOR id)
    limparArvore(NODE *raiz)
    destruirArvore(ARVORE *arvore)
    buscaLargura(ARVORE *arvore)
    calcularProfundidade(NODE *raiz, int *profundidade)
*/

int main(){
    int profundidade = 0;

    ARVORE arvore;
    inicializarArvore(&arvore);
    REG_ALUNO aluno1, aluno2, aluno3, aluno4, aluno5, aluno6;
    aluno1.id = 10;
    aluno1.nome = "Joao";
    aluno1.matricula = "123456";
    aluno1.idade = 20;
    aluno1.periodo = 1;
    aluno1.curso = 1;
    
    aluno2.id = 8;
    aluno2.nome = "Maria";
    aluno2.matricula = "654321";
    aluno2.idade = 19;
    aluno2.periodo = 1;
    aluno2.curso = 2;
    
    aluno3.id = 1;
    aluno3.nome = "Pedro";
    aluno3.matricula = "987654";
    aluno3.idade = 21;
    aluno3.periodo = 1;
    aluno3.curso = 3;
    
    aluno4.id = 15;
    aluno4.nome = "Jose";
    aluno4.matricula = "456789";
    aluno4.idade = 20;
    aluno4.periodo = 1;
    aluno4.curso = 4;
    
    aluno5.id = 12;
    aluno5.nome = "Ana";
    aluno5.matricula = "135792";
    aluno5.idade = 19;
    aluno5.periodo = 1;
    aluno5.curso = 5;
    
    aluno6.id = 7;
    aluno6.nome = "Paulo";
    aluno6.matricula = "246810";
    aluno6.idade = 21;
    aluno6.periodo = 1;
    aluno6.curso = 6;

    adicionarAluno(&arvore, aluno1);
    adicionarAluno(&arvore, aluno2);
    adicionarAluno(&arvore, aluno3);
    adicionarAluno(&arvore, aluno4);
    adicionarAluno(&arvore, aluno5);
    adicionarAluno(&arvore, aluno6);

    buscaLargura(arvore.raiz);

    profundidade = calcularProfundidade(arvore.raiz, &profundidade);
    printf("\nProfundidade: %d\n", profundidade);

    imprimeArvore(arvore.raiz);

    printf("Apos as remocoes:\n");
    removerAluno(&arvore, 8);
    removerAluno(&arvore, 12);
    
    imprimeArvore(arvore.raiz);
    
    destruirArvore(&arvore);

    imprimeArvore(arvore.raiz);
    return 0;
}