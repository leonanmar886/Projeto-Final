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

struct voo {
  int codigo;
  char origem[100];
  char destino[100];
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
  Viagem **tabela_hash;
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

TabelaViagem* cria_hash(int tamanho){
  
  TabelaViagem* novo_hash = (TabelaViagem*)malloc(sizeof(TabelaViagem));
  Viagem* vetor = (Viagem*) malloc(sizeof(Viagem*) * tamanho);
  novo_hash -> tabela_hash = vetor;
  novo_hash->tamanho = tamanho; 
  return novo_hash;
}


void inicializar_tabela(Viagem* roteiros, TabelaViagem* tabela){
  int size  = ((tabela -> tamanho)*2)+1;
  while(eh_primo(size) == 0){
    size++;
  }

  tabela->tamanho = size;
 
  for(int i=0; i < tabela->tamanho; i++){
    tabela -> tabela_hash[i] = NULL;
  } 
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

int funcaoHash(int codigoHash, TabelaViagem* tabela){  
  return codigoHash % tabela->tamanho;
}

int inserir_tabela(Viagem* viagem, TabelaViagem* tabela){
  int id = funcaoHash(codigo_hash(viagem),tabela);
  
  if(tabela -> tabela_hash[id] == NULL){// insere apenas quando nulo para não haver colisão
   tabela -> tabela_hash[id] = &(viagem);
   return 1;
    }  
  return 0;
}

Viagem* busca_tabela(Viagem* viagem, TabelaViagem* tabela){
  int id = funcaoHash(codigo_hash(viagem),tabela);
  if(tabela->tabela_hash[id]!= NULL){
    if(tabela->tabela_hash[id] == viagem ){
      return viagem;
    }
  }
  return NULL;
}

// retira um roteiro de viagem da Tabela e atribui NULL, retorna NULL caso já for NULL
//, e o roteiro caso contrário

Viagem* retira_hash(TabelaViagem* tabela, Viagem* viagem ){
  int id = funcaoHash(codigo_hash(viagem),tabela);
   Viagem* aux;
  if(tabela -> tabela_hash[id] == NULL){
    return NULL;
  } 
  else{
    
    aux = tabela -> tabela_hash[id];
    tabela -> tabela_hash[id] = NULL;
  }
  return aux;
}

//
int libera_hash(TabelaViagem** tabela){
  if(tabela == NULL) return 0;
  
  free(*tabela);
  *tabela = NULL;
  return 1;
}

void imprimir_viagem(Viagem* roteiros[],TabelaViagem* tabela, Viagem* viagem){
  int id = funcaoHash(codigo_hash(viagem),tabela);
   
  Trecho* aux = roteiros[id]->primeiro_trecho ;
  int ordem = 1;
  printf("\tINTINERÁRIO DA VIAGEM:\n");
  while(aux!=NULL){
    
   printf("**************************************\n");
   printf("\t Reserva %d",ordem)/ 
   printf("Codigo da reserva: %d\n", aux->reserva->codigo);
   printa_data(aux->reserva->data_viagem);
   printf("Codigo do Voo: %d\n",aux->reserva->voo->codigo);
   printf("Nome do passageiro: %s\n", aux->reserva->passageiro->nome);
   printf("Id do passageiro: %d\n", aux->reserva->passageiro->id); 
   printf("Endereço do passageiro: %s\n", aux->reserva->passageiro->endereco);
   ordem++;  
   aux = aux->proximo;
  }
}

