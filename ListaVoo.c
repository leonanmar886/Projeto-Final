#include "ListaVoo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no_voo {
  Voo *voo;
  struct no_voo *proximo;
};

typedef struct no_voo No_Voo;


struct lista_voo { 
  struct no_voo *primeiro;
};

ListaVoo* fila_voo_cria() {
  ListaVoo *nova_lista = (ListaVoo *) malloc(sizeof(ListaVoo));
  nova_lista->primeiro = NULL;
  return nova_lista;
}

int fila_voo_libera(ListaVoo **lista) {
  if (lista != NULL) {
    free(*lista);
    *lista = NULL;
    return 1;
  }
  return 0;
}


Voo* fila_voo_busca(ListaVoo *lista, int codigo) {
  if(lista == NULL || lista->primeiro == NULL) {
    return NULL;
  }
  No_Voo *x = lista->primeiro;
  int codigo_aux;
  char origem[100];
  char destino[100];

  while(x != NULL){
    voo_acessa(x->voo, &codigo_aux, origem, destino);
    if(codigo_aux == codigo){
      return x->voo;
    }
    x =  x->proximo;
    }
  
  return NULL;
}

int fila_voo_insere(ListaVoo *lista, Voo *voo){
  if(lista == NULL || voo == NULL){
    return -1;
  }

  if(lista->primeiro != NULL){
    int codigo;
    char origem[100];
    char destino[100];
    voo_acessa(voo, &codigo, origem, destino);
    Voo *aux = fila_voo_busca(lista, codigo);
    if(aux != NULL){
      return 0;
    }
    
  }
  if (lista->primeiro == NULL){
    No_Voo* novo = (No_Voo *)malloc(sizeof(No_Voo));
    novo->voo = voo;
    novo->proximo = NULL;
    lista->primeiro = novo;
  }
  else {
    No_Voo* ultimo = lista->primeiro;
    while (ultimo->proximo != NULL){
      ultimo = ultimo->proximo;
    }
  No_Voo* novo = (No_Voo *)malloc(sizeof(No_Voo));
  novo->voo = voo;
  novo->proximo = NULL;
  ultimo->proximo = novo;
    
  }
  return 1;
  
}


Voo* fila_voo_retira(ListaVoo* lista){
  if(lista == NULL || lista->primeiro == NULL){
    return NULL;
  }
  Voo* voo = lista->primeiro->voo;
  lista->primeiro = lista->primeiro->proximo;
  return voo;
}

Voo *fila_voo_primeiro(ListaVoo *fila) {
  if (fila_voo_vazia(fila) || fila == NULL){
    return NULL;
  }
  Voo* ptr_1st_voo = fila->primeiro->voo; //testars
  return ptr_1st_voo;
}

int fila_voo_vazia(ListaVoo *fila){
  if (fila == NULL){
    return -1;
  }
  if ((fila -> primeiro) == NULL){
    return 1;  
  }
  else{
    return 0;
  }
  }

int fila_voo_quantidade(ListaVoo *fila) {
    if (fila == NULL){
      return -1;
    }
    else{
      int tamanho = 0;
      No_Voo* aux = fila->primeiro;
      while (aux != NULL){
        aux = aux -> proximo;
        tamanho ++;
      }
      return tamanho;
    }
}
