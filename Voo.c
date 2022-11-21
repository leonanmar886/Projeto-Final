#include "Voo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct voo {
  int codigo;
  char origem[100];
  char destino[100];
};

// voo verifica
// voo novo 
// voo libera
// voo acessa (leitura)
// voo edita

int verifica_params(int codigo, char *origem, char *destino) {
  if (codigo < 0 || origem == NULL || destino == NULL) {
    return -1;
  }

  if (strlen(origem) > 100 || strlen(destino) > 100) {
    return -1;
  }

  return 1;
}

Voo *voo_novo(int codigo, char *origem, char *destino) {
  if (verifica_params(codigo, origem, destino) == -1) {
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
    return 1;   
  } 
  return 0;
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
  if (voo != NULL && verifica_params(codigo, origem, destino) == 1) {
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

