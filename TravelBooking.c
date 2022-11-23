#include "TravelBooking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  Reserva *reserva;
  Agenda *esq;
  Agenda *dir;
};

struct trecho {
  Reserva *reserva;
  struct trecho *proximo;
};

struct viagem {
  struct trecho *trechos;
};

struct tabela_viagem {
  int tamanho;
  Viagem *tabela_hash;
};

// ************** Passageiro.c ***********
int verifica_params_passageiro(int id, char *nome, char *endereco) {
  if (id < 0 || nome == NULL || endereco == NULL) {
    return -1;
  }

  if (strlen(nome) > 100 || strlen(endereco) > 100) {
    return -1;
  }

  return 1;
}

Passageiro *passageiro_novo(int id, char *nome, char *endereco) {
  if (verifica_params_passageiro(id, nome, endereco) == -1) {
    return NULL;
  }
  if (strcmp(nome, endereco) == 0){
    return NULL;
  }
  Passageiro *novo_Passageiro = (Passageiro*)malloc(sizeof(Passageiro));
  novo_Passageiro->id = id;
  strcpy(novo_Passageiro->nome, nome);
  strcpy(novo_Passageiro->endereco, endereco);

  return novo_Passageiro;
}

int passageiro_verifica(Passageiro *Passageiro) {
  int id_aux;
  char nome_aux[100];
  char endereco_aux[150];
  
  passageiro_acessa(Passageiro, &(id_aux), nome_aux, endereco_aux);
  if (id_aux < 0 || nome_aux == NULL || endereco_aux == NULL) {
    return -1;
  }
  else {
    return 1;
  }
}

int passageiro_libera(Passageiro **Passageiro) {
  if(Passageiro != NULL){
    free(*Passageiro);
    *Passageiro = NULL;   
  } 
}
  
  
void passageiro_acessa(Passageiro *Passageiro, int *id, char *nome, char *endereco) {
  if(Passageiro == NULL){
    *id = -1;
    strcpy(nome, "NULL");
    strcpy(endereco, "NULL");  
  }
  else {
    *id = Passageiro->id;
    strcpy(nome, Passageiro->nome);
    strcpy(endereco, Passageiro->endereco);
  }
}

void passageiro_atribui(Passageiro *passageiro, int id, char *nome, char *endereco) {
  if (passageiro != NULL && verifica_params_passageiro(id, nome, endereco) == 1) {
    passageiro->id = id;
    strcpy(passageiro->nome, nome);
    strcpy(passageiro->endereco, endereco);
  }  
}

int passageiro_igual(Passageiro *Passageiro1, Passageiro *Passageiro2){
  if (Passageiro1 == NULL || Passageiro2 == NULL) {
    return -1;
  }

  if (Passageiro1->id != Passageiro2->id) {
    return 0;
  }

  if (strcmp(Passageiro1->nome, Passageiro2->nome) != 0) {
    return 0;
  }

  if (strcmp(Passageiro1->endereco, Passageiro2->endereco) != 0) {
    return 0;
  }

  return 1;
}

int passageiro_tamanho(){
  return sizeof(Passageiro);
}

// ******************* FilaPassageiro.c ****************

typedef struct no_passageiro No_Passageiro;

ListaPassageiro* fila_passageiro_cria(){
  ListaPassageiro* nova_lista = (ListaPassageiro *)malloc(sizeof(ListaPassageiro));
   nova_lista->primeiro = NULL;
  return nova_lista;
  
}

int fila_passageiro_libera(ListaPassageiro **lista){
  if(lista != NULL){
    if((*lista)->primeiro != NULL){
      No_Passageiro* aux = (*lista)->primeiro;
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
    
    
 No_Passageiro* x = lista->primeiro;
  
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
    No_Passageiro* novo =(No_Passageiro*) malloc(sizeof(No_Passageiro));
    novo->passageiro = passa;
    novo->proximo = NULL;
    lista->primeiro = novo;
  }
  else {
    No_Passageiro* ultimo = lista->primeiro;
    while( ultimo->proximo != NULL){
      ultimo = ultimo->proximo;
    }
  No_Passageiro* novo = (No_Passageiro *)malloc(sizeof(No_Passageiro));
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

// ***************** Voo.c ***************

int verifica_params_voo(int codigo, char *origem, char *destino) {
  if (codigo < 0 || origem == NULL || destino == NULL) {
    return -1;
  }

  if (strlen(origem) > 100 || strlen(destino) > 100) {
    return -1;
  }
  return 1;
}

Voo *voo_novo(int codigo, char *origem, char *destino) {
  if (verifica_params_voo(codigo, origem, destino) == -1) {
    return NULL;
  }
  if (strcmp(origem, destino) == 0){
    return NULL;
  }
  Voo *novo_voo = (Voo*)malloc(sizeof(Voo));
  novo_voo->codigo = codigo;
  strcpy(novo_voo->origem, origem);
  strcpy(novo_voo->destino, destino);
  return novo_voo;
}

int voo_verifica(Voo *voo) {
  int codigo_aux;
  char origem_aux[100];
  char destino_aux[150];
  
  voo_acessa(voo, &(codigo_aux), origem_aux, destino_aux);
  if (codigo_aux < 0 || origem_aux == NULL || destino_aux == NULL) {
    return -1;
  }
  else {
    return 1;
  }
}

int voo_libera(Voo **voo) {
  if(voo != NULL){
    free(*voo);
    *voo = NULL;   
  } 
}
  
  
void voo_acessa(Voo *voo, int *codigo, char *origem, char *destino) {
  if(voo == NULL){
    *codigo = -1;
    strcpy(origem, "NULL");
    strcpy(destino, "NULL");  
  }
  else {
    *codigo = voo->codigo;
    strcpy(origem, voo->origem);
    strcpy(destino, voo->destino);
  }
}

void voo_atribui(Voo *voo, int codigo, char *origem, char *destino) {
  if (voo != NULL && verifica_params_voo(codigo, origem, destino) == 1) {
    voo->codigo = codigo;
    strcpy(voo->origem, origem);
    strcpy(voo->destino, destino);
  }  
}

int voo_igual(Voo *Voo1, Voo *Voo2){
  if (Voo1 == NULL || Voo2 == NULL) {
    return -1;
  }

  if (Voo1->codigo != Voo2->codigo) {
    return 0;
  }

  if (strcmp(Voo1->origem, Voo2->origem) != 0) {
    return 0;
  }

  if (strcmp(Voo1->destino, Voo2->destino) != 0) {
    return 0;
  }

  return 1;
}

int voo_tamanho(){
  return sizeof(Voo);
}

// ********************* FilaVoo.c

typedef struct no_voo No_Voo;

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
