#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TravelBooking.h"

int teste_passageiro_novo(){
  printf("************************************************ TESTE PASSAGEIROS ************************************************ \n");
  char nome1[100] = "Carlinhos";
  char endereco1[100] = "Rua Taquari, 3850";
  char nome2[100] = "898493aaaaa84";
  char endereco2[100] = "75834578";

  Passageiro* passageiro1 = passageiro_novo(1, nome1, endereco1); // passageiro com dados válidos.
  Passageiro* passageiro2 = passageiro_novo(-1, nome2, endereco2); // passageiro com dados inválidos.
  Passageiro* passageiro3 = passageiro_novo(1, NULL, NULL); // passageiro com dados nulos,

  if(passageiro1 == NULL || passageiro2 != NULL || passageiro3 != NULL){
    printf("[Falhou] - passageiro_cria()\n");
    return 0;
  }

  printf("[Passou] - passageiro_cria()\n");
  return 1;
}

float teste_passageiro_acessa() {
  int id;
  char nome[50];
  char endereco[100];
  Passageiro *passageiro = passageiro_novo(1, "Abraão", "Rua Taquari, 3850");
  if (passageiro != NULL) {
    passageiro_acessa(passageiro, &id, nome, endereco);
    if (id == 1 && strcmp(nome, "Abraão") == 0 &&
        strcmp(endereco, "Rua Taquari, 3850") == 0) {
      printf(
          "[Passou] - passageiro_acessa()\n");
      return 1;
    } else {
      printf(
          "[Falhou] - passageiro_acessa()\n");
      return 0;
    }
  } else {
    printf("[Passou] - passageiro_acessa()\n");
    return 0;
  }
}

int teste_passageiro_libera(){

  Passageiro* passageiro = passageiro_novo(1, "Abraão", "Computação");
  Passageiro* passageiro2 = NULL;

  passageiro_libera(&passageiro);
  passageiro_libera(&passageiro2);

  if (passageiro != NULL || passageiro2 != NULL) {
    printf("[Falhou] - passageiro_libera()\n");
    return 0;
  } 
  
  printf("[Passou] - passageiro_libera()\n");
  return 1;
}

int teste_passageiro_igual(){
  Passageiro* passageiro_1 = passageiro_novo(4, "Cleber", "Vitoria");
  Passageiro* passageiro_2 = passageiro_novo(4, "Cleber", "Vitoria");
  if (passageiro_igual(passageiro_1, passageiro_2) == 1){
    printf("[Passou] - passageiro_igual()\n");
    return 1;
  }
  printf("[Falhou] - passageiro_igual()");
  return 0;
}

float teste_passageiro_atribui_dados_validos() {
  int id;
  char nome[50];
  char endereco[100];
  
  Passageiro *passageiro_1 = passageiro_novo(1, "Lucas", "Coritiba");
  if (passageiro_1 != NULL) {
    passageiro_atribui(passageiro_1, 2, "Felipe", "Recife");
    passageiro_acessa(passageiro_1, &id, nome, endereco);
    if (id == 2 && strcmp(nome, "Felipe") == 0 &&
        strcmp(endereco, "Recife") == 0) {
      printf(
          "[Passou] - passageiro_atribui()\n");
      return 1;
    } else {
      printf(
          "[Falhou] - passageiro_atribui()\n");
          return 0;
        } 
  } else {
    printf(
        "[Falhou] - passageiro_atribui()\n");
        return 0;
  }
}

float teste_passageiro_atribui_dados_invalidos() {
  int id;
  char nome[55] = "N";
  char endereco[150] = "C";

  for (int i = 0; i < 53; i++) {
    strcat(nome, "N");
  }

  for (int i = 0; i < 140; i++) {
    strcat(endereco, "C");
  }

  Passageiro *passageiro = passageiro_novo(1, "Belem", "Fortaleza");
  if (passageiro != NULL) {
    passageiro_atribui(passageiro, 2, nome, endereco);
    passageiro_acessa(passageiro, &id, nome, endereco);
    if (id == 1 || strcmp(nome, "Belem") == 0 ||
        strcmp(endereco, "Fortaleza") == 0) {
          passageiro_atribui(NULL, -1, NULL, NULL);
          passageiro_acessa(passageiro, &id, nome, endereco);
    if (id == 1 || strcmp(nome, "Belem") == 0 ||
        strcmp(endereco, "Fortaleza") == 0) {
      printf("[Passou] - passageiro_atribui() \n");
      return 1;
    } else {
      printf("[Falhou] - passageiro_atribui() \n");
    }
  } else {
    printf(
        "[Falhou] - passageiro_atribui()\n");
  }
  return 0;
}
}



int teste_fila_passageiro_cria() {
  ListaPassageiro *fila = fila_passageiro_cria();
  if (fila != NULL) {
    printf("[Passou] - fila_passageiro_cria()\n");
    return 1;
  } else {
    printf("[Falhou] - fila_passageiro_cria()\n");
    return 0;
  }
}

int teste_fila_passageiro_libera() {
  float pontuacao = 0;
  ListaPassageiro *fila = fila_passageiro_cria();
  fila_passageiro_libera(&fila);
  if (fila != NULL || fila_passageiro_libera(NULL) != 0) {
    printf(
        "[Falhou] - fila_passageiro_libera()\n");
    return 0;
  } else {
    printf(
        "[Passou] - fila_passageiro_libera()\n");
    return 1;
  }
}



int teste_fila_passageiro_insere() {
  ListaPassageiro *fila = fila_passageiro_cria();
  if (fila != NULL) {
    Passageiro *abraao = passageiro_novo(1, "Abraão", "Rua Ipanema, 221");
    Passageiro *jorge = passageiro_novo(1, "Jorge", "Rua Ipanema, 224");
    if (fila_passageiro_insere(fila, abraao) == 1 && fila_passageiro_insere(fila, jorge) == 0 && fila_passageiro_insere(fila, NULL) == -1) {
      Passageiro *jaco = passageiro_novo(2, "Jaco", "Rua Ipanema, 222");
      if (fila_passageiro_insere(fila, jaco) == 1) {
        Passageiro *jose = passageiro_novo(3, "Jose", "Rua Ipanema, 223");
        if (fila_passageiro_insere(fila, jose) == 1) {
          printf("[Passou] - fila_passageiro_insere()\n");
          return 1;
        } else {
          printf("[Falhou] - fila_passageiro_insere()\n");
        }
      } else {
        printf("[Falhou] - fila_passageiro_insere()\n");
      }
    } else {
      printf("[Falhou] - fila_passageiro_insere()\n");
    }
  } else {
    printf(
        "[Falhou] - fila_passageiro_insere()\n");
  }
  return 0;
}

int teste_fila_passageiro_retira() {
  ListaPassageiro *fila = fila_passageiro_cria();
  if (fila != NULL) {
    Passageiro *abraao = passageiro_novo(1, "Abraão", "Rua Ipanema, 222");
    fila_passageiro_insere(fila, abraao);
    Passageiro *jaco = passageiro_novo(2, "Jaco", "Rua Ipanema, 223");
    fila_passageiro_insere(fila, jaco);
    Passageiro *jose = passageiro_novo(3, "Jose", "Rua Ipanema, 224");
    fila_passageiro_insere(fila, jose);
    Passageiro *passageiro = fila_passageiro_retira(fila);

    if (passageiro_igual(passageiro, abraao) == 1) {
      passageiro = fila_passageiro_retira(fila);
      if (passageiro_igual(passageiro, jaco) == 1) {
        passageiro = fila_passageiro_retira(fila);
        if (passageiro_igual(passageiro, jose) == 1 && fila_passageiro_retira(NULL) == NULL) {
          printf("[Passou] - fila_passageiro_retira()\n");
          return 1;
        } else {
          printf("[Falhou] - fila_passageiro_retira()\n");
        }
      } else {
        printf("[Falhou] - fila_passageiro_retira()\n");
      }
    } else {
      printf(
          "[Falhou] - fila_passageiro_retira()\n");
    }
  } else {
    printf(
        "[Falhou] - fila_passageiro_retira()\n");
  }
  return 0;
}
// Trecho repetido

int teste_fila_passageiro_busca() {
  int id;
  char nome[50];
  char endereco[100];
  ListaPassageiro *fila = fila_passageiro_cria();
  if (fila != NULL) {
    Passageiro *abraao = passageiro_novo(1, "Abraão", "Rua Ipanema, 221");
    fila_passageiro_insere(fila, abraao);
    Passageiro *jaco = passageiro_novo(2, "Jaco", "Rua Ipanema, 222");
    fila_passageiro_insere(fila, jaco);
    Passageiro *jose = passageiro_novo(3, "Jose", "Rua Ipanema, 223");
    fila_passageiro_insere(fila, jose);
    Passageiro *aux = fila_passageiro_busca(fila, 2);
    Passageiro *aux1 = fila_passageiro_busca(fila, 5);
    Passageiro *aux2 = fila_passageiro_busca(NULL, 1);
    if (aux != NULL && aux1 == NULL && aux2 == NULL) {
      passageiro_acessa(aux, &id, nome, endereco);
      if (id == 2 && strcmp(nome, "Jaco") == 0 &&
          strcmp(endereco, "Rua Ipanema, 222") == 0) {
        printf("[Passou] - fila_passageiro_busca()\n");
        return 1;
      } else {
        printf("[Falhou] - fila_passageiro_busca()\n");
      }
    } else {
      printf("[Falhou] - fila_passageiro_busca()\n");
    }
  } else {
    printf("[Falhou] - fila_passageiro_busca()\n");
  }
  return 0;
}

float teste_fila_passageiro_vazia() {
  ListaPassageiro *fila = fila_passageiro_cria();
  if (fila != NULL && fila_passageiro_vazia(fila) == 1) {
    printf("[Passou] - fila_passageiro_vazia() \n");
    return 1;
} 
  Passageiro* passageiro_aux = passageiro_novo(1,"José", "Rua Humerto Monte 22");
  fila_passageiro_insere(fila, passageiro_aux);

  if (fila_passageiro_vazia(fila) != 0){
    printf("[Falhou] - fila_passageiro_vazia() \n");
    return 0;
  }

  
  else {
    printf("[Falhou] - fila_passageiro_vazia() \n");
    return 0;
  }
}

float teste_fila_passageiro_primeiro() {
  ListaPassageiro *fila = fila_passageiro_cria();
  if (fila != NULL) {
    Passageiro *passageiro_1 = passageiro_novo(1, "Recife", "Fortaleza");
    fila_passageiro_insere(fila, passageiro_1);
    Passageiro *passageiro_2 = passageiro_novo(2, "Palmas", "Paris");
    fila_passageiro_insere(fila, passageiro_2);
    Passageiro *passageiro_3 = passageiro_novo(3, "Miami", "Manaus");
    fila_passageiro_insere(fila, passageiro_3);
    Passageiro *passageiro_primeiro = fila_passageiro_primeiro(fila);

    if (passageiro_igual(passageiro_primeiro, passageiro_1) == 1) {
      printf("[Passou] - fila_passageiro_primeiro()\n");
      return 1;

    } else {
      printf("[Falhou] - fila_passageiro_primeiro()\n");
    }
  } else {
    printf(
        "[Falhou] - fila_passageiro_primeiro()\n");
  }
  return 0;
}


//*******************************************
//*******************************************
//---------------------------Testes relacionados a Voo-----------------------------------------------------------------------------
//*******************************************
//*******************************************

int teste_voo_novo(){
  printf("************************************************ TESTE VOOS ************************************************\n");
  int codigo_valido = 550;
  char origem_valido[100] = "Londres";
  char destino_valido[100] = "Sobral";
  int codigo_invalido = -2;
  char origem_invalido[200] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  char destino_invalido[200] =  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  Voo* Voo_Valido = voo_novo(codigo_valido, origem_valido, destino_valido);
  Voo* Voo_Igual = voo_novo(codigo_valido, origem_valido, origem_valido);
  Voo* Voo_Invalido = voo_novo(codigo_invalido, origem_valido, destino_invalido);
  Voo* Voo_Nulo = voo_novo(-1, origem_invalido, origem_invalido);
  if (Voo_Valido == NULL || Voo_Igual != NULL || Voo_Invalido != NULL || Voo_Nulo != NULL){
    printf("[Falhou] - voo_cria()\n");
    return 0;
  }
  else if(Voo_Valido != NULL && Voo_Igual == NULL || Voo_Invalido == NULL || Voo_Nulo == NULL){
    printf("[Passou] - voo_cria()\n");
    return 1;
  }
  else{
    printf("[Erro] - voo_cria()\n");
    return -1;
  }
}
int teste_voo_libera(){
  int codigo_valido = 550;
  char origem_valido[100] = "Londres";
  char destino_valido[100] = "Sobral";
  Voo* Voo_Valido = voo_novo(codigo_valido, origem_valido, destino_valido);
  Voo* Voo_Nulo = NULL;
  voo_libera(&(Voo_Valido));
  voo_libera(&(Voo_Nulo));
  if (Voo_Valido == NULL && Voo_Nulo == NULL){
    printf("[Passou] - voo_libera() \n");
    return 0;
  }
  else{
      printf("[Falhou] - voo_libera() \n");
      return 1;
  }
}
int teste_voo_acessa(){
  int codigo;
  char origem[100];
  char destino[100];
  Voo* Voo_Aux = voo_novo(1590, "Santiago", "Rio de Janeiro");
  if (Voo_Aux != NULL){
    voo_acessa(Voo_Aux, &(codigo), origem, destino);
    if (codigo == 1590 && strcmp(origem, "Santiago") == 0 && strcmp(destino, "Rio de Janeiro") == 0){
      printf("[Passou] - voo_acessa() \n");
      return 1;
    }
    else{
      printf("[Falhou] - voo_acessa() \n");
    }
  }
}
float teste_voo_atribui_dados_validos() {
  int codigo;
  char origem[100];
  char destino[100];
  
  Voo *voo = voo_novo(1, "Fortaleza", "Coritiba");
  if (voo != NULL) {
    voo_atribui(voo, 2, "Fortaleza", "Recife");
    voo_acessa(voo, &codigo, origem, destino);
    if (codigo == 2 && strcmp(origem, "Fortaleza") == 0 &&
        strcmp(destino, "Recife") == 0) {
      printf(
          "[Passou] - voo_atribui()\n");
      return 1;
    } else {
      printf(
          "[Falhou] - voo_atribui()\n");
          return 0;
        } 
  } else {
    printf(
        "[Falhou] - voo_atribui()\n");
        return 0;
  }
}
float teste_voo_atribui_dados_invalidos() {
  int codigo;
  char origem[1000] = "N";
  char destino[1000] = "C";
  for (int i = 0; i < 150; i++) {
    strcat(origem, "N");
  }
  for (int i = 0; i < 150; i++) {
    strcat(destino, "C");
  }
  Voo *voo = voo_novo(1, "Belem", "Fortaleza");
  if (voo != NULL) {
    voo_atribui(voo, 2, origem, destino);
    voo_acessa(voo, &codigo, origem, destino);
    if (codigo == 1 || strcmp(origem, "Belem") == 0 ||
        strcmp(destino, "Fortaleza") == 0) {
          voo_atribui(NULL, -1, "NULL", "NULL"); //correção
          voo_acessa(voo, &codigo, origem, destino);
    if (codigo == 1 || strcmp(origem, "Belem") == 0 ||
        strcmp(destino, "Fortaleza") == 0) {
      printf("[Passou] - voo_atribui() \n");
      return 1;
    } else {
      printf("[Falhou] - voo_atribui() \n");
    }
  } else {
    printf(
        "[Falhou] - voo_atribui()\n");
  }
  return 0;
}
}
int teste_voo_igual(){
  Voo* Voo_1 = voo_novo(4, "Paris", "Vitoria");
  Voo* Voo_2 = voo_novo(4, "Paris", "Vitoria");
  if (voo_igual(Voo_1, Voo_2) == 1){
    printf("[Passou] - voo_igual()\n");
    return 1;
  }
  printf("[Falhou] - voo_igual()");
  return 0;
}
int teste_fila_voo_cria() {
  ListaVoo *fila = fila_voo_cria();
  if (fila != NULL) {
    printf("[Passou] - fila_voo_cria()\n");
    return 1;
  } else {
    printf("[Falhou] - fila_voo_cria()\n");
    return 0;
  }
}
float teste_fila_voo_libera() {
  ListaVoo *fila = fila_voo_cria();
  fila_voo_libera(&fila);
  if (fila != NULL || fila_voo_libera(NULL) != 0) {
    printf(
        "[Falhou] - fila_voo_libera()\n");
    return 0;
  } else {
    printf(
        "[Passou] - fila_voo_libera()\n");
    return 1;
  }
}
float teste_fila_voo_vazia() {
  ListaVoo *fila = fila_voo_cria();
  if (fila != NULL && fila_voo_vazia(fila) == 1) {
    printf("[Passou] - fila_voo_vazia() \n");
    return 1;
} 
  Voo* voo_aux = voo_novo(1,"Maceio", "Campinas");
  fila_voo_insere(fila, voo_aux);
  if (fila_voo_vazia(fila) != 0){
    printf("[Falhou] - fila_voo_vazia() \n");
    return 0;
  }
  
  else {
    printf("[Falhou] - fila_voo_vazia() \n");
    return 0;
  }
}
float teste_fila_voo_insere() {
  ListaVoo *fila = fila_voo_cria();
  if (fila != NULL) {
    Voo *voo_manaus = voo_novo(1, "Manaus", "Fortaleza");
    Voo *voo_coritiba = voo_novo(1, "Coritiba", "Fortaleza");
    if (fila_voo_insere(fila, voo_manaus) == 1 && fila_voo_insere(fila, voo_coritiba) == 0 && fila_voo_insere(fila, NULL) == -1) {
      Voo *voo_palmas = voo_novo(2, "Palmas", "Fortaleza");
      Voo *voo_recife = voo_novo(2, "Recife", "Fortaleza");
      if (fila_voo_insere(fila, voo_palmas) == 1 && fila_voo_insere(fila, voo_recife) == 0) {
        Voo *voo_orlando = voo_novo(3, "Orlando", "Fortaleza");
        if (fila_voo_insere(fila, voo_orlando) == 1) {
          printf("[Passou] - fila_voo_insere\n");
          return 1;
        } else {
          printf("[Falhou] - fila_voo_insere()\n");
        }
      } else {
        printf("[Falhou] - fila_voo_insere()\n");
      }
    } else {
      printf("[Falhou] - fila_voo_insere()\n");
    }
  } else {
    printf(
        "[Falhou] - fila_voo_insere()\n");
  }
  return 0;
}
float teste_fila_voo_primeiro() {
  ListaVoo *fila = fila_voo_cria();
  if (fila != NULL) {
    Voo *voo_fortaleza = voo_novo(1, "Recife", "Fortaleza");
    fila_voo_insere(fila, voo_fortaleza);
    Voo* voo_paris = voo_novo(2, "Palmas", "Paris");
    fila_voo_insere(fila, voo_paris);
    Voo *voo_manaus = voo_novo(3, "Miami", "Manaus");
    fila_voo_insere(fila, voo_manaus);
    Voo *voo_primeiro = fila_voo_primeiro(fila);
    if (voo_igual(voo_primeiro, voo_fortaleza) == 1) {
      printf("[Passou] - fila_voo_primeiro()\n");
      return 1;
    } else {
      printf("[Falhou] - fila_voo_primeiro()\n");
    }
  } else {
    printf(
        "[Falhou] - fila_voo_primeiro()\n");
  }
  return 0;
}
float teste_fila_voo_busca() {
  int codigo;
  char origem[100];
  char destino[100];
  ListaVoo *fila = fila_voo_cria();
  if (fila != NULL) {
    Voo *voo_fortaleza = voo_novo(1, "Recife", "Fortaleza");
    fila_voo_insere(fila, voo_fortaleza);
    Voo* voo_paris = voo_novo(2, "Palmas", "Paris");
    fila_voo_insere(fila, voo_paris);
    Voo *voo_manaus = voo_novo(3, "Maceio", "Porto Alegre");
    fila_voo_insere(fila, voo_manaus);
    Voo *aux = fila_voo_busca(fila, 2);
    if (aux != NULL) {
      voo_acessa(aux, &codigo, origem, destino);
      if (codigo == 2 && strcmp(origem, "Palmas") == 0 &&
          strcmp(destino, "Paris") == 0) {
        printf("[Passou] - fila_voo_busca()\n");
               return 1;
      } else {
        printf("[Falhou] - fila_voo_busca()\n");
      }
    } else {
      printf("[Falhou] - fila_voo_busca()\n");
    }
  } else {
    printf("[Falhou] - fila_voo_busca()\n");
  }
  return 0;
}
float teste_fila_voo_retira() {
  ListaVoo *fila = fila_voo_cria();
  if (fila != NULL) {
    Voo *voo_fortaleza = voo_novo(1, "Recife", "Fortaleza");
    fila_voo_insere(fila, voo_fortaleza);
    Voo* voo_paris = voo_novo(2, "Palmas", "Paris");
    fila_voo_insere(fila, voo_paris);
    Voo *voo_manaus = voo_novo(3, "Maceio", "Porto Alegre");
    fila_voo_insere(fila, voo_manaus);
    Voo *aux = fila_voo_retira(fila);
    if (voo_igual(aux, voo_fortaleza) == 1) {
      aux = fila_voo_retira(fila);
      if (voo_igual(aux, voo_paris) == 1) {
        aux = fila_voo_retira(fila);
        if (voo_igual(aux, voo_manaus) == 1) {
          aux = fila_voo_retira(fila);
          if(aux == NULL){
          printf("[Passou] - fila_voo_retira() \n");
          return 1;}
          else{
            printf("[Falhou] - fila_voo_retira()\n");
            return 0;
          }
        }
         else {
          printf("[Falhou] - fila_voo_retira()\n");
        }
      } else {
        printf("[Falhou] - fila_voo_retira()\n");
      }
    } else {
      printf(
          "[Falhou] - fila_voo_retira()\n");
    }
  } else {
    printf(
        "[Falhou] - fila_voo_retira()\n");
  }
  return 0;
}

int main(void) {
  
  // Testes Passageiro
  
  teste_passageiro_novo();
  teste_passageiro_libera();
  teste_passageiro_acessa();
  teste_passageiro_atribui_dados_validos();
  teste_passageiro_atribui_dados_invalidos();
  teste_passageiro_igual();
  teste_fila_passageiro_cria();
  teste_fila_passageiro_libera();
  teste_fila_passageiro_vazia();
  teste_fila_passageiro_insere();
  teste_fila_passageiro_primeiro();
  teste_fila_passageiro_busca();
  teste_fila_passageiro_retira();
  // Testes Voo

  teste_voo_novo();
  teste_voo_libera();
  teste_voo_acessa();
  teste_voo_atribui_dados_validos();
  teste_voo_atribui_dados_invalidos();
  teste_voo_igual();
  teste_fila_voo_cria();
  teste_fila_voo_libera();
  teste_fila_voo_vazia();
  teste_fila_voo_insere();
  teste_fila_voo_primeiro();
  teste_fila_voo_busca();
  teste_fila_voo_retira();
  
  return 0;
}
