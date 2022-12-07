#include "TravelBooking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct viagem Viagem;
typedef struct tabela_viagem TabelaViagem;
typedef struct trecho Trecho;
struct data {
  int dia;
  int mes;
  int ano;
};

struct voo {
  int codigo;
  char origem[100];
  char destino[100];
};

struct no_voo {
  Voo *voo;
  struct no_voo *proximo;
};

struct lista_voo {
  struct no_voo *primeiro;
};

struct passageiro {
  int id;
  char nome[100];
  char endereco[100];
};

struct no_passageiro {
  Passageiro *passageiro;
  struct no_passageiro *proximo;
};

struct lista_passageiro {
  struct no_passageiro *primeiro;
};

struct reserva {
  int codigo;
  Data *data_viagem;
  Passageiro *passageiro;
  Voo *voo;
  Assento assento;
};

struct agenda {
  Data* data;
  Reserva *reserva;
  Agenda *esq;
  Agenda *dir;
  Agenda *pai;
};

struct trecho {
  Reserva *reserva;
  struct trecho *proximo;
};

struct viagem {
  struct trecho *primeiro_trecho;
};

struct tabela_viagem {
  int tamanho;
  Viagem *tabela_hash;
};
// Retorna 1 se as reserva não são do mesmo passageiro, ou se as datas das reservas não estão numa ordem 
// cronológica plausível, ou se as datas de inicial e fim da viagem são coincidentes, caso contrário retorna 0
int verifica_casos(Viagem* roteiro){
 if(roteiro == NULL ) return -1;
  
  Trecho* aux1 = roteiro->primeiro_trecho;
  Trecho* aux2 = aux1;
  while(aux1 != NULL){
    if(aux1->proximo != NULL){
     if(aux1->reserva->passageiro->id != aux1->proximo->reserva->passageiro->id ||
       data_inteiro(aux1->reserva->data_viagem)  > data_inteiro(aux1->proximo->reserva->data_viagem))
       {
      return 1;
    }            
      }
    if(aux1->proximo == NULL){
        if (data_inteiro(aux1->reserva->data_viagem) == data_inteiro(aux2->reserva->data_viagem))
          return 1;
      }
    aux1 = aux1->proximo;
  }
return 0;
}

Viagem* lista_viagem_cria(){
  
  Viagem* novo_roteiro = (Viagem*) malloc(sizeof(Viagem));
  novo_roteiro->primeiro_trecho = NULL;
  return novo_roteiro;
}



int lista_viagem_libera(Viagem** lista_roteiro){
  if(lista_roteiro != NULL){
    if((*lista_roteiro)->primeiro_trecho != NULL){
      Trecho* aux = (*lista_roteiro)->primeiro_trecho;
      do{
        reserva_libera(&aux->reserva);
        aux = aux->proximo;
      } while(aux != NULL);
    }
    free(*lista_roteiro);
    *lista_roteiro = NULL;
    return 1;
  }
  return 0;
}

Reserva* lista_viagem_busca(Viagem* lista, int codigo){
  if(lista != NULL && lista->primeiro_trecho!=NULL){

    Trecho* x = lista->primeiro_trecho;
    int codigo_aux;
    Data* data;
    Passageiro* passageiro;
    Voo* voo;
    Assento assento;
    do{
     reserva_acessa(x->reserva, &codigo_aux, &data, &passageiro, &voo, &assento);
     if(codigo == codigo_aux){
       return x->reserva;
     }
      x = x->proximo;
      }while(x!=NULL);
    }
  return NULL;
}

int lista_viagem_insere(Viagem* lista, Reserva* reserva){
  if(lista == NULL || reserva == NULL || verifica_casos(lista) == 1){
    return -1;
  }
  if(lista->primeiro_trecho!= NULL){
    int codigo;
    Data* data;
    Passageiro* passageiro;
    Voo* voo;
    Assento assento;
    reserva_acessa(reserva, &codigo, &data, &passageiro, &voo, &assento);
    Reserva* aux = lista_reserva_busca(lista, codigo);

    if(aux != NULL){
      return 0;
    }
  }
    if(lista->primeiro_trecho == NULL){
      Trecho* novo = (Trecho*) malloc(sizeof(Trecho));
      novo->reserva = reserva;
      novo->proximo = NULL;
      lista->primeiro_trecho = novo;
    }
    else{
      Trecho* ultimo = lista->primeiro_trecho;
      while(ultimo->proximo != NULL){
        ultimo = ultimo->proximo;
      }
      Trecho* novo = (Trecho*)malloc(sizeof(Trecho));
      novo->reserva = reserva;
      novo->proximo = NULL;
      ultimo->proximo = novo;
    }
  return 1;
}

int lista_viagem_vazia(Viagem* lista){
  if(lista == NULL){
    return -1;
  }
  if(lista->primeiro_trecho == NULL){
    return 1;
  }
  return 0;
}

Reserva* lista_viagem_primeiro(Viagem* lista){
  if(lista == NULL || lista->primeiro_trecho->reserva == NULL){
    return NULL;
  }
  return lista->primeiro_trecho->reserva;
}

Reserva* lista_viagem_retira(Viagem* lista){
  if(lista == NULL || lista->primeiro_trecho == NULL){
    return NULL;
  }
  Reserva* primeira_reserva = lista->primeiro_trecho->reserva;
  lista->primeiro_trecho = lista->primeiro_trecho->proximo;
  
  return primeira_reserva;
}