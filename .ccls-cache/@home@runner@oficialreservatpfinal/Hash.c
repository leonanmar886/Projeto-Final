#include "TravelBooking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define TAMANHO_MAXIMO 10
typedef struct viagem Viagem;
typedef struct tabela_viagem TabelaViagem;
typedef struct trecho Trecho;
struct data {
  int dia;
  int mes;
  int ano;
};

struct passageiro {
  int id;
  char nome[100];
  char endereco[100];
};


struct reserva {
  int codigo;
  Data *data_viagem;
  Passageiro *passageiro;
  Voo *voo;
  Assento assento;
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
  Viagem* t[];
};

int eh_primo(int valor){
  int i = 2;
  int x;
  while(i <= valor-1){
    x = valor%i;
   if(x==0){
     return 0;
   }
    i++;
  }
  return 1;
}
TabelaViagem* cria_hash(int size){
  
  TabelaViagem* novo_hash = (TabelaViagem*)malloc(sizeof(TabelaViagem));

  novo_hash->tabela_hash = NULL;
  novo_hash->tamanho = size; 
  return novo_hash;
}

void inicializar_tabela( Viagem* roteiros[], TabelaViagem* hash){
 
  for(int i=0;i < hash->tamanho; i++){
    roteiros[i] = NULL;
  }
  hash->t[0] = roteiros[0]; 
}

int codigo_hash(Viagem* lista){

  int soma = 0; 
  Trecho* aux = lista->primeiro_trecho;
  
  while(aux->proximo!=NULL){
    soma+=aux->reserva->codigo;
    aux = aux->proximo;
  }
  soma += aux->reserva->passageiro->id;
  
  return soma;
}

int funcaoHash(int codigo_hash, TabelaViagem* tabela){
  int tamanho = (tabela->tamanho*2)+1;
  while(eh_primo(tamanho) == 0){
    tamanho++;
  }
  return codigo_hash%tamanho;
}

void inserir_tabela( Viagem* tab[],Viagem* viagem, TabelaViagem* tabela){
  int id = funcaoHash(codigo_hash(viagem),tabela);
  
  if(tab[id] == NULL){// insere apenas quando nulo para não haver colisão
   tab[id] = viagem;
   tabela->t[id] = tab[id];
  // tabela->tamanho++; 
    }  
}
Viagem* busca(Viagem* t[], Viagem* viagem, TabelaViagem* tabela){
  int id = funcaoHash(codigo_hash(viagem),tabela);
  if(t[id]!= NULL){
    if(t[id] == viagem ){
      return viagem;
    }
  }
  return NULL;
}
