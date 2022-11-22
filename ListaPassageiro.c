#include "ListaPassageiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct no_passageiro {
  Passageiro *passageiro;
  struct no_passageiro *proximo;
};

struct lista_passageiro {
  struct no_passageiro *primeiro;
};

ListaPassageiro* fila_passageiro_cria(){
  ListaPassageiro* nova_lista = (ListaPassageiro *)malloc(sizeof(ListaPassageiro));
   nova_lista->primeiro = NULL;
  return nova_lista;
  
}

int fila_passageiro_libera(ListaPassageiro **lista){
  if(lista != NULL){
    if((*lista)->primeiro != NULL){
      No* aux = (*lista)->primeiro;
      do{
        passageiro_libera(&aux->passageiro);
        aux = aux->proximo;
      } while(aux != NULL);
    }
    free(*lista);
    *lista = NULL;
    return 1;
  }
  return 0;
}

Passageiro* fila_passageiro_busca(ListaPassageiro* lista, int id){
  if (lista!=NULL && lista->primeiro!=NULL){
    
    
 No* x = lista->primeiro;
  
  int id_aux;
  char nome[100];
  char end[150];
  do{
passageiro_acessa(x->passageiro,&id_aux,nome,end);
  if(id == id_aux){
      return x->passageiro;
    }
    x =  x->proximo;
    } while(x!=NULL ) ;
    }
  return NULL;
}

int fila_passageiro_insere(ListaPassageiro* lista, Passageiro* passa){
  if(lista == NULL || passa == NULL){
    return -1;
  }
  if(lista->primeiro!= NULL){
    int id;
    char nome[50];
    char end[100];
    passageiro_acessa(passa, &id, nome, end);
    Passageiro *aux =fila_passageiro_busca(lista, id);
    if(aux != NULL){
      return 0;
    }
    
  }
  if (lista->primeiro == NULL){
    No* novo =(No *) malloc(sizeof(No));
    novo->passageiro = passa;
    novo->proximo = NULL;
    lista->primeiro = novo;
  }
  else {
    No* ultimo = lista->primeiro;
    while( ultimo->proximo != NULL){
      ultimo = ultimo->proximo;
    }
  No* novo = (No *)malloc(sizeof(No));
  novo->passageiro = passa;
  novo->proximo = NULL;
  ultimo->proximo = novo;  
    
  }
  return 1;
  
}
//
Passageiro* fila_passageiro_retira(ListaPassageiro* lista){
  if(lista == NULL ||lista->primeiro == NULL){
    return NULL;
  }
  Passageiro* viajante = lista->primeiro->passageiro;
  lista->primeiro = lista->primeiro->proximo;
  return viajante;
}
// Retorna -1 se a lista for nulo, retorna 1 se a lista for vazia, e retorna
// 0 caso contrário
int fila_passageiro_vazia(ListaPassageiro* lista){
  if (lista==NULL){
    return -1;
  }
  if (lista->primeiro==NULL){
    return 1;
  }
  return 0;
}

Passageiro* fila_passageiro_primeiro(ListaPassageiro* lista){
  if(lista == NULL || lista->primeiro->passageiro ==NULL){
    return NULL;
  }
  return lista->primeiro->passageiro;
}
