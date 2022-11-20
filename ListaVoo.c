#include "TadNoVoo.h"
#include "TadVoo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no_voo {
  Voo *voo;
  struct no_voo *proximo;
};

struct lista_voo { 
  struct no_voo *primeiro;
};

Lista* cria_lista() {
  Lista *nova_lista = (Lista *) malloc(sizeof(Lista));
  nova_lista->primeiro = NULL;
  return nova_lista;
}

int libera_lista(Lista **lista) {
  if (lista != NULL) {
    free(*lista);
    *lista = NULL;
    return 1;
  }
  return -1;
}


Lista* buscar_lista(Lista *lista, int codigo) {
  if(lista == NULL || lista->primeiro == NULL) {
    return NULL;
  }
  No_Voo *x = lista->primeiro;
  int codigo_aux;
  char origem[100];
  char destino[150];
  voo_acessa(x->voo, &codigo_aux, origem, destino);

  while(x != NULL){
    if(codigo_aux == codigo){
      return x->voo;
    }
    x =  x->proximo;
    }
  
  return NULL;
}

int inserir_lista(Lista *lista, Voo *voo){
  if(lista == NULL || voo == NULL){
    return -1
  }
  if(lista->primeiro != NULL){
    int codigo;
    char origem[100];
    char destino[150];
    voo_acessa(voo, &codigo, origem, destino);
    Voo *aux = buscar_lista(lista, codigo);
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


Voo* lista_remove(Lista* lista){
  if(lista == NULL || lista->primeiro == NULL){
    return NULL;
  }
  Voo* voo = lista->primeiro->voo;
  lista->primeiro = lista->primeiro->proximo;
  return voo;
}
