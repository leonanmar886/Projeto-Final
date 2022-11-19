#include "Passageiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct passageiro {
  int id;
  char nome[100];
  char endereco[150];
};

int verifica(int id, char *nome, char *end) {
  if (id < 1 || nome == NULL || end == NULL) {
    return -1;
  }
if (strlen(nome)>100 || strlen(end)>150) {
    return -1;
  }
  return 1;
}

Passageiro* passageiro_novo(int id, char* nome, char* endereco){
  if (id<0 || nome==NULL || endereco == NULL) return NULL;
  
  Passageiro* novo_viajante = (Passageiro* )malloc(sizeof(Passageiro));
  novo_viajante->id = id;
  strcpy(novo_viajante->nome, nome );
  strcpy(novo_viajante->endereco, endereco);
  return novo_viajante;
}

void passageiro_libera(Passageiro **passageiro){
  if(passageiro!= NULL){
    free(*passageiro);
    *passageiro = NULL;      
  } 
}
void passageiro_acessa(Passageiro* passa, int* id, char* nome, char* endereco){
  if(passa == NULL){
    *id = -1;
    strcpy(nome,"NULL");
    strcpy(endereco, "NULL");
  }
  else{
    *id = passa->id;
    strcpy(nome, passa->nome);
    strcpy(endereco,passa->endereco);
  }
}

void passageiro_edita(Passageiro* passa, int id, char* nome, char* end){
  if(passa!=NULL && verifica(id,  nome,  end) == 1){
    passa->id = id;
    strcpy(passa->nome, nome);
    strcpy(passa->endereco, end);
  }
  