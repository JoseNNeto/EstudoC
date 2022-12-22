#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista
struct node {
  int data;
  struct node *next;
  struct node *prev;
};

// Estrutura da lista
struct list {
  struct node *head;
};

// Aloca memória para um novo nó e retorna um ponteiro para ele
struct node *create_node(int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

// Inicializa uma lista vazia
void init_list(struct list *list) {
  list->head = NULL;
}

// Adiciona um novo nó com o dado especificado no início da lista
void add_first(struct list *list, int data) {
  // Cria o novo nó
  struct node *new_node = create_node(data);

  if (list->head == NULL) {
    // Se a lista estiver vazia, o novo nó será o único elemento da lista
    // e sua própria anterior e próxima referência
    new_node->next = new_node;
    new_node->prev = new_node;
    list->head = new_node;
 
