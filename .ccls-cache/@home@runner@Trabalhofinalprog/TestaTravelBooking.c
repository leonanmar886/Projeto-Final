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



int teste_lista_passageiro_cria() {
  ListaPassageiro *lista = lista_passageiro_cria();
  if (lista != NULL) {
    printf("[Passou] - lista_passageiro_cria()\n");
    return 1;
  } else {
    printf("[Falhou] - lista_passageiro_cria()\n");
    return 0;
  }
}

int teste_lista_passageiro_libera() {
  float pontuacao = 0;
  ListaPassageiro *lista = lista_passageiro_cria();
  lista_passageiro_libera(&lista);
  if (lista != NULL || lista_passageiro_libera(NULL) != 0) {
    printf(
        "[Falhou] - lista_passageiro_libera()\n");
    return 0;
  } else {
    printf(
        "[Passou] - lista_passageiro_libera()\n");
    return 1;
  }
}



int teste_lista_passageiro_insere() {
  ListaPassageiro *lista = lista_passageiro_cria();
  if (lista != NULL) {
    Passageiro *abraao = passageiro_novo(1, "Abraão", "Rua Ipanema, 221");
    Passageiro *jorge = passageiro_novo(1, "Jorge", "Rua Ipanema, 224");
    if (lista_passageiro_insere(lista, abraao) == 1 && lista_passageiro_insere(lista, jorge) == 0 && lista_passageiro_insere(lista, NULL) == -1) {
      Passageiro *jaco = passageiro_novo(2, "Jaco", "Rua Ipanema, 222");
      if (lista_passageiro_insere(lista, jaco) == 1) {
        Passageiro *jose = passageiro_novo(3, "Jose", "Rua Ipanema, 223");
        if (lista_passageiro_insere(lista, jose) == 1) {
          printf("[Passou] - lista_passageiro_insere()\n");
          return 1;
        } else {
          printf("[Falhou] - lista_passageiro_insere()\n");
        }
      } else {
        printf("[Falhou] - lista_passageiro_insere()\n");
      }
    } else {
      printf("[Falhou] - lista_passageiro_insere()\n");
    }
  } else {
    printf(
        "[Falhou] - lista_passageiro_insere()\n");
  }
  return 0;
}

int teste_lista_passageiro_retira() {
  ListaPassageiro *lista = lista_passageiro_cria();
  if (lista != NULL) {
    Passageiro *abraao = passageiro_novo(1, "Abraão", "Rua Ipanema, 222");
    lista_passageiro_insere(lista, abraao);
    Passageiro *jaco = passageiro_novo(2, "Jaco", "Rua Ipanema, 223");
    lista_passageiro_insere(lista, jaco);
    Passageiro *jose = passageiro_novo(3, "Jose", "Rua Ipanema, 224");
    lista_passageiro_insere(lista, jose);
    Passageiro *passageiro = lista_passageiro_retira(lista, 1);

    if (passageiro_igual(passageiro, abraao) == 1) {
      passageiro = lista_passageiro_retira(lista, 2);
      if (passageiro_igual(passageiro, jaco) == 1) {
        passageiro = lista_passageiro_retira(lista, 3);
        if (passageiro_igual(passageiro, jose) == 1 && lista_passageiro_retira(lista, 1) == NULL && lista_passageiro_retira(NULL, 1) == NULL) {
          printf("[Passou] - lista_passageiro_retira()\n");
          return 1;
        } else {
          printf("[Falhou] - lista_passageiro_retira()\n");
        }
      } else {
        printf("[Falhou] - lista_passageiro_retira()\n");
      }
    } else {
      printf(
          "[Falhou] - lista_passageiro_retira()\n");
    }
  } else {
    printf(
        "[Falhou] - lista_passageiro_retira()\n");
  }
  return 0;
}
// Trecho repetido

int teste_lista_passageiro_busca() {
  int id;
  char nome[50];
  char endereco[100];
  ListaPassageiro *lista = lista_passageiro_cria();
  if (lista != NULL) {
    Passageiro *abraao = passageiro_novo(1, "Abraão", "Rua Ipanema, 221");
    lista_passageiro_insere(lista, abraao);
    Passageiro *jaco = passageiro_novo(2, "Jaco", "Rua Ipanema, 222");
    lista_passageiro_insere(lista, jaco);
    Passageiro *jose = passageiro_novo(3, "Jose", "Rua Ipanema, 223");
    lista_passageiro_insere(lista, jose);
    Passageiro *aux = lista_passageiro_busca(lista, 2);
    Passageiro *aux1 = lista_passageiro_busca(lista, 5);
    Passageiro *aux2 = lista_passageiro_busca(NULL, 1);
    if (aux != NULL && aux1 == NULL && aux2 == NULL) {
      passageiro_acessa(aux, &id, nome, endereco);
      if (id == 2 && strcmp(nome, "Jaco") == 0 &&
          strcmp(endereco, "Rua Ipanema, 222") == 0) {
        printf("[Passou] - lista_passageiro_busca()\n");
        return 1;
      } else {
        printf("[Falhou] - lista_passageiro_busca()\n");
      }
    } else {
      printf("[Falhou] - lista_passageiro_busca()\n");
    }
  } else {
    printf("[Falhou] - lista_passageiro_busca()\n");
  }
  return 0;
}

float teste_lista_passageiro_vazia() {
  ListaPassageiro *lista = lista_passageiro_cria();
  if (lista != NULL && lista_passageiro_vazia(lista) == 1) {
    printf("[Passou] - lista_passageiro_vazia() \n");
    return 1;
} 
  Passageiro* passageiro_aux = passageiro_novo(1,"José", "Rua Humerto Monte 22");
  lista_passageiro_insere(lista, passageiro_aux);

  if (lista_passageiro_vazia(lista) != 0){
    printf("[Falhou] - lista_passageiro_vazia() \n");
    return 0;
  }

  
  else {
    printf("[Falhou] - lista_passageiro_vazia() \n");
    return 0;
  }
}

float teste_lista_passageiro_primeiro() {
  ListaPassageiro *lista = lista_passageiro_cria();
  if (lista != NULL) {
    Passageiro *passageiro_1 = passageiro_novo(1, "Recife", "Fortaleza");
    lista_passageiro_insere(lista, passageiro_1);
    Passageiro *passageiro_2 = passageiro_novo(2, "Palmas", "Paris");
    lista_passageiro_insere(lista, passageiro_2);
    Passageiro *passageiro_3 = passageiro_novo(3, "Miami", "Manaus");
    lista_passageiro_insere(lista, passageiro_3);
    Passageiro *passageiro_primeiro = lista_passageiro_primeiro(lista);

    if (passageiro_igual(passageiro_primeiro, passageiro_1) == 1) {
      printf("[Passou] - lista_passageiro_primeiro()\n");
      return 1;

    } else {
      printf("[Falhou] - lista_passageiro_primeiro()\n");
    }
  } else {
    printf(
        "[Falhou] - lista_passageiro_primeiro()\n");
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
int teste_lista_voo_cria() {
  ListaVoo *lista = lista_voo_cria();
  if (lista != NULL) {
    printf("[Passou] - lista_voo_cria()\n");
    return 1;
  } else {
    printf("[Falhou] - lista_voo_cria()\n");
    return 0;
  }
}
float teste_lista_voo_libera() {
  ListaVoo *lista = lista_voo_cria();
  lista_voo_libera(&lista);
  if (lista != NULL || lista_voo_libera(NULL) != 0) {
    printf(
        "[Falhou] - lista_voo_libera()\n");
    return 0;
  } else {
    printf(
        "[Passou] - lista_voo_libera()\n");
    return 1;
  }
}
float teste_lista_voo_vazia() {
  ListaVoo *lista = lista_voo_cria();
  if (lista != NULL && lista_voo_vazia(lista) == 1) {
    printf("[Passou] - lista_voo_vazia() \n");
    return 1;
} 
  Voo* voo_aux = voo_novo(1,"Maceio", "Campinas");
  lista_voo_insere(lista, voo_aux);
  if (lista_voo_vazia(lista) != 0){
    printf("[Falhou] - lista_voo_vazia() \n");
    return 0;
  }
  
  else {
    printf("[Falhou] - lista_voo_vazia() \n");
    return 0;
  }
}
float teste_lista_voo_insere() {
  ListaVoo *lista = lista_voo_cria();
  if (lista != NULL) {
    Voo *voo_manaus = voo_novo(1, "Manaus", "Fortaleza");
    Voo *voo_coritiba = voo_novo(1, "Coritiba", "Fortaleza");
    if (lista_voo_insere(lista, voo_manaus) == 1 && lista_voo_insere(lista, voo_coritiba) == 0 && lista_voo_insere(lista, NULL) == -1) {
      Voo *voo_palmas = voo_novo(2, "Palmas", "Fortaleza");
      Voo *voo_recife = voo_novo(2, "Recife", "Fortaleza");
      if (lista_voo_insere(lista, voo_palmas) == 1 && lista_voo_insere(lista, voo_recife) == 0) {
        Voo *voo_orlando = voo_novo(3, "Orlando", "Fortaleza");
        if (lista_voo_insere(lista, voo_orlando) == 1) {
          printf("[Passou] - lista_voo_insere\n");
          return 1;
        } else {
          printf("[Falhou] - lista_voo_insere()\n");
        }
      } else {
        printf("[Falhou] - lista_voo_insere()\n");
      }
    } else {
      printf("[Falhou] - lista_voo_insere()\n");
    }
  } else {
    printf(
        "[Falhou] - lista_voo_insere()\n");
  }
  return 0;
}
float teste_lista_voo_primeiro() {
  ListaVoo *lista = lista_voo_cria();
  if (lista != NULL) {
    Voo *voo_fortaleza = voo_novo(1, "Recife", "Fortaleza");
    lista_voo_insere(lista, voo_fortaleza);
    Voo* voo_paris = voo_novo(2, "Palmas", "Paris");
    lista_voo_insere(lista, voo_paris);
    Voo *voo_manaus = voo_novo(3, "Miami", "Manaus");
    lista_voo_insere(lista, voo_manaus);
    Voo *voo_primeiro = lista_voo_primeiro(lista);
    if (voo_igual(voo_primeiro, voo_fortaleza) == 1) {
      printf("[Passou] - lista_voo_primeiro()\n");
      return 1;
    } else {
      printf("[Falhou] - lista_voo_primeiro()\n");
    }
  } else {
    printf(
        "[Falhou] - lista_voo_primeiro()\n");
  }
  return 0;
}
float teste_lista_voo_busca() {
  int codigo;
  char origem[100];
  char destino[100];
  ListaVoo *lista = lista_voo_cria();
  if (lista != NULL) {
    Voo *voo_fortaleza = voo_novo(1, "Recife", "Fortaleza");
    lista_voo_insere(lista, voo_fortaleza);
    Voo* voo_paris = voo_novo(2, "Palmas", "Paris");
    lista_voo_insere(lista, voo_paris);
    Voo *voo_manaus = voo_novo(3, "Maceio", "Porto Alegre");
    lista_voo_insere(lista, voo_manaus);
    Voo *aux = lista_voo_busca(lista, 2);
    if (aux != NULL) {
      voo_acessa(aux, &codigo, origem, destino);
      if (codigo == 2 && strcmp(origem, "Palmas") == 0 &&
          strcmp(destino, "Paris") == 0) {
        printf("[Passou] - lista_voo_busca()\n");
               return 1;
      } else {
        printf("[Falhou] - lista_voo_busca()\n");
      }
    } else {
      printf("[Falhou] - lista_voo_busca()\n");
    }
  } else {
    printf("[Falhou] - lista_voo_busca()\n");
  }
  return 0;
}
float teste_lista_voo_retira() {
  ListaVoo *lista = lista_voo_cria();
  if (lista != NULL) {
    Voo *voo_fortaleza = voo_novo(1, "Recife", "Fortaleza");
    lista_voo_insere(lista, voo_fortaleza);
    Voo* voo_paris = voo_novo(2, "Palmas", "Paris");
    lista_voo_insere(lista, voo_paris);
    Voo *voo_manaus = voo_novo(3, "Maceio", "Porto Alegre");
    lista_voo_insere(lista, voo_manaus);
    Voo *aux = lista_voo_retira(lista, 1);
    if (voo_igual(aux, voo_fortaleza) == 1) {
      aux = lista_voo_retira(lista, 2);
      if (voo_igual(aux, voo_paris) == 1) {
        aux = lista_voo_retira(lista, 3);
        if (voo_igual(aux, voo_manaus) == 1) {
            aux = lista_voo_retira(lista, 1);
            Voo* aux2 = lista_voo_retira(NULL,1);
          if(aux == NULL && aux2 == NULL){
          printf("[Passou] - lista_voo_retira() \n");
          return 1;
          }
          else{
            printf("[Falhou] - lista_voo_retira()\n");
            return 0;
          }
        }
         else {
          printf("[Falhou] - lista_voo_retira()\n");
        }
      } else {
        printf("[Falhou] - lista_voo_retira()\n");
      }
    } else {
      printf(
          "[Falhou] - lista_voo_retira()\n");
    }
  } else {
    printf(
        "[Falhou] - lista_voo_retira()\n");
  }
  return 0;
}

// ********************* TESTES RESERVAS *************************
int teste_reserva_nova() {
  printf("************************************************ TESTE RESERVAS ************************************************ \n");

  Data *data1 = data_nova(16, 4, 2023);
  Data *data2 = data_nova(12, 12, 2021);
  Assento assento1 = A0;
  Assento assento2 = B7;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
  Voo *voo2 = voo_novo(12, "Montevideu", "Buenos Aires");

  Reserva *Reserva1 = reserva_nova(1, data1, passageiro1, voo1, assento1); // Reserva com dados válidos.
  Reserva *Reserva2 = reserva_nova(-1, data2, passageiro2, voo2, assento2); // Reserva com dados inválidos.
  Reserva *Reserva3 = reserva_nova(1, NULL, NULL, NULL, B1); // Reserva com dados nulos,

  if (Reserva1 == NULL || Reserva2 != NULL || Reserva3 != NULL) {
    printf("[Falhou] - reserva_cria()\n");
    return 0;
  }

  printf("[Passou] - reserva_cria()\n");
  return 1;
}

float teste_reserva_acessa() {
  int codigo_aux;
  Data *data_aux;
  Passageiro *passageiro_aux;
  Voo *voo_aux;
  Assento assento_aux;

  Data *data1 = data_nova(16, 4, 2023);
  Data *data2 = data_nova(12, 12, 2021);

  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
  
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
  Voo *voo2 = voo_novo(12, "Montevideu", "Buenos Aires");
  
  Assento assento1 = A0;
  Assento assento2 = B7;
  
  Reserva *Reserva1 = reserva_nova(1, data1, passageiro1, voo1, assento1); // Reserva com dados válidos.
  Reserva *Reserva2 = reserva_nova(-1, data2, passageiro2, voo2, assento2); // Reserva com dados inválidos.
  Reserva *Reserva3 = reserva_nova(1, NULL, NULL, NULL, B4); // Reserva com dados nulos,
  
  if (Reserva1 != NULL) {
    reserva_acessa(Reserva1, &codigo_aux, &data_aux, &passageiro_aux, &voo_aux, &assento_aux);
    if (codigo_aux == 1 && data_inteiro(data_aux) == data_inteiro(data1) && passageiro_igual(passageiro_aux, passageiro1) && voo_igual(voo_aux, voo1) == 1 && assento_aux == assento1){
      printf("[Passou] - reserva_acessa()\n");
      return 1;
    } else {
      printf("[Falhou] - Reserva_acessa()\n");
      return 0;
    }
  } else {
    printf("[Passou] - Reserva_acessa()\n");
    return 0;
  }
}

int teste_reserva_libera() {

  Data *data1 = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");

  Reserva *Reserva1 = reserva_nova(1, data1, passageiro1, voo1, assento1); // Reserva com dados válidos.
  reserva_libera(&Reserva1);

  if (Reserva1 != NULL) {
    printf("[Falhou] - reserva_libera()\n");
    return 0;
  }

  printf("[Passou] - reserva_libera()\n");
  return 1;
}

int teste_reserva_igual() {
  Data *data1 = data_nova(16, 4, 2023);
  Data *data2 = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Assento assento2 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Passageiro *passageiro2 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
  Voo *voo2 = voo_novo(52, "Nova Iorque", "Londres");
  Voo *voo3 = voo_novo(12, "Montevideu", "Buenos Aires");
  

  Reserva *Reserva1 = reserva_nova(1, data1, passageiro1, voo1, assento1); // Reserva com dados válidos.
  Reserva *Reserva2 = reserva_nova(1, data2, passageiro2, voo2, assento2); // Reserva com dados inválidos.
  Reserva *Reserva3 = reserva_nova(1, NULL, NULL, NULL, B4); // Reserva com dados nulos,
  Reserva *Reserva4 = reserva_nova(1, data2, passageiro2, voo3, assento2);

  if (reserva_igual(Reserva1, Reserva2) == 1) {
    if(reserva_igual(Reserva1, Reserva3) == -1){
      if (reserva_igual(Reserva4, Reserva1) == 0){
        printf("[Passou] - reserva_igual()\n");
        return 1;
        }
    }
  }
  printf("[Falhou] - reserva_igual()");
  return 0;
}

float teste_reserva_atribui_dados_validos() {
  Data *data1 = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");

  Data *data2 = data_nova(12, 5, 2024);
  Assento assento2 = B5;
  Passageiro *passageiro2 = passageiro_novo(2, "Elisandra Castro", "Rua Brooklyn, 1450");
  Voo *voo2 = voo_novo(123, "Fortaleza", "Guarulhos");

  int codigo_aux;
  Data *data_aux;
  Passageiro *passageiro_aux;
  Voo *voo_aux;
  Assento assento_aux;
  

  Reserva *Reserva1 = reserva_nova(1, data1, passageiro1, voo1, assento1);
  if (Reserva1 != NULL) {
    reserva_atribui(Reserva1, 4, data2, passageiro2, voo2, assento2);
    reserva_acessa(Reserva1, &codigo_aux, &data_aux, &passageiro_aux, &voo_aux, &assento_aux);
    if (codigo_aux == 4 && data_inteiro(data_aux) == data_inteiro(data2) && passageiro_igual(passageiro_aux, passageiro2) && voo_igual(voo_aux, voo2) == 1 && assento_aux == assento2) {
      printf("[Passou] - reserva_atribui()\n");
      return 1;
    } 
    else {
      printf("[Falhou] - reserva_atribui()\n");
      return 0;
    }
  } else {
    printf("[Falhou] - reserva_atribui()\n");
    return 0;
  }
}

float teste_reserva_atribui_dados_invalidos() {
  Data *data1 = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");

  Data *data2 = data_nova(12, 5, 2020);
  Assento assento2 = C2;
  Passageiro *passageiro2 = NULL;
  Voo *voo2 = voo_novo(123, "Fortaleza", "Guarulhos");

  int codigo_aux;
  Data *data_aux;
  Passageiro *passageiro_aux;
  Voo *voo_aux;
  Assento assento_aux;

  Reserva *Reserva1 = reserva_nova(1, data1, passageiro1, voo1, assento1);
  if (Reserva1 != NULL) {
    reserva_atribui(Reserva1, -22, data2, passageiro2, voo2, assento2);
    reserva_acessa(Reserva1, &codigo_aux, &data_aux, &passageiro_aux, &voo_aux, &assento_aux);
    if (codigo_aux == 1 && data_inteiro(data1) == data_inteiro(data_aux) && passageiro_igual(passageiro1, passageiro_aux) == 1 && voo_igual(voo1, voo_aux) && assento1 == assento_aux) {
        printf("[Passou] - reserva_atribui() \n");
        return 1;
      } else {
        printf("[Falhou] - reserva_atribui() \n");
      }
    } else {
      printf("[Falhou] - reserva_atribui()\n");
    }
    return 0;
  }
///////////////// TESTES AGENDA ///////////////////////////////////////////////////////

  void teste_conteudo_agenda() {
  Data* data = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
  Reserva* reserva1 = reserva_nova(1, data, passageiro1, voo1, assento1);

  Agenda* agenda = criar_no_agenda(data, reserva1);
  
  if (reserva_igual(reserva1, conteudo_agenda(agenda)) == 1 && conteudo_agenda(NULL) == NULL){
      printf("[Passou] - abb_acessa()\n");
  } else {
      printf("[Falhou] - abb_acessa()\n");
  }
}

void teste_insere_no_agenda() {
  Data* data = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
  Reserva* reserva1 = reserva_nova(1, data, passageiro1, voo1, assento1);

  Agenda* raiz = criar_no_agenda(data, reserva1);

  Data* data2 = data_nova(12,12,2021);
  Assento assento2 = B7;
  Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
  
  Voo *voo2 = voo_novo(12, "Montevideu", "Buenos Aires");
  Passageiro *passageiro3 = passageiro_novo(5, "Jonas Esticado", "Rua Nunes Valente, 1540");
  Reserva* reserva2 = reserva_nova(2, data2, passageiro2, voo2, assento2);
  Reserva* reserva3 = reserva_nova(45, data2, passageiro3, voo2, assento2);

  Agenda* no = criar_no_agenda(data2, reserva2);
  Agenda* no_2 = criar_no_agenda(data2, reserva3);
  raiz = insere_no_agenda(raiz, no);

  int codigo = data_inteiro(data2);
  int id2;
  char origem2[100], destino2[100];
  passageiro_acessa(passageiro2, &id2, origem2,  destino2);
   

  if(chave_agenda(abb_busca_agenda_data_passageiro(raiz, id2,data2)) == chave_agenda(no) 
    && insere_no_agenda(NULL, NULL) == NULL){
      if (insere_no_agenda(raiz, no_2) == NULL){
      printf("[Passou] - insere_no_agenda()\n");
      }
  } else {
      printf("[Falhou] - insere_no_agenda()\n");
  }
}

void teste_busca_agenda_codigo() {
  Data* data = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
  Reserva* reserva1 = reserva_nova(1, data, passageiro1, voo1, assento1);

  Agenda* raiz = criar_no_agenda(data, reserva1);

  Data* data2 = data_nova(12,12,2021);
  Assento assento2 = B7;
  Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
  Voo *voo2 = voo_novo(12, "Montevideu", "Buenos Aires");

  Reserva* reserva2 = reserva_nova(2, data2, passageiro2, voo2, assento2);

  Agenda* no = criar_no_agenda(data2, reserva2);

  raiz = insere_no_agenda(raiz, no);
  
  int codigo ;
  Data* aux1;
  Passageiro* aux2;
  Voo* aux3;
  Assento aux4;

  if(busca_agenda_codigo(raiz,2) == no && busca_agenda_codigo(NULL, -1) == NULL){
      printf("[Passou] - busca_agenda_codigo()\n");
  } else {
      printf("[Falhou] - busca_agenda_codigo()\n");
    
   
    
  }
}

void teste_libera_no_agenda() {
  Data* data = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
  Reserva* reserva1 = reserva_nova(1, data, passageiro1, voo1, assento1);

  Agenda* raiz = criar_no_agenda(data, reserva1);

  Data* data2 = data_nova(12,12,2021);
  Assento assento2 = B7;
  Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
  Voo *voo2 = voo_novo(12, "Montevideu", "Buenos Aires");

  Reserva* reserva2 = reserva_nova(2, data2, passageiro2, voo2, assento2);

  Agenda* no = criar_no_agenda(data2, reserva2);

  raiz = insere_no_agenda(raiz, no);

  int resultado = libera_no_agenda(no);

  if(resultado == 1 && libera_no_agenda(NULL) == 0 ){
      printf("[Passou] - libera_no_agenda()\n");
     
  } else {
      printf("[Falhou] - libera_no_agenda()\n");
  }
}

void teste_altura(){
  Data* data = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
  Reserva* reserva1 = reserva_nova(1, data, passageiro1, voo1, assento1);

  Agenda* raiz = criar_no_agenda(data, reserva1);

  Data* data2 = data_nova(12,12,2021);
  Assento assento2 = B7;
  Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
  Voo *voo2 = voo_novo(12, "Montevideu", "Buenos Aires");
  Reserva* reserva2 = reserva_nova(2, data2, passageiro2, voo2, assento2);

  Agenda* no = criar_no_agenda(data2, reserva2);

  Data* data3 = data_nova(26,12,2021);
  Assento assento3 = B7;
  Passageiro *passageiro3 = passageiro_novo(4, "Mauricio Carneiro", "Rua Carlos Lobo, 150");
  Voo *voo3 = voo_novo(3, "La Paz", "Buenos Aires");

  Reserva* reserva3 = reserva_nova(3, data3, passageiro3, voo3, assento3);

  Agenda* no2 = criar_no_agenda(data3, reserva3);

  raiz = insere_no_agenda(raiz, no);
  raiz = insere_no_agenda(raiz, no2);

  if(abb_altura(raiz)==2 && abb_altura(NULL)==-1){
    printf("[Passou] - abb_altura()\n");
  }else{
    printf("[Falhou] - abb_altura()\n");
  }
}


void teste_numero(){
  Data* data = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
  Reserva* reserva1 = reserva_nova(1, data, passageiro1, voo1, assento1);

  Agenda* raiz = criar_no_agenda(data, reserva1);

  Data* data2 = data_nova(12,12,2021);
  Assento assento2 = B7;
  Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
  Voo *voo2 = voo_novo(12, "Montevideu", "Buenos Aires");

  Reserva* reserva2 = reserva_nova(2, data2, passageiro2, voo2, assento2);

  Agenda* no = criar_no_agenda(data2, reserva2);

  Data* data3 = data_nova(26,12,2021);
  Assento assento3 = B7;
  Passageiro *passageiro3 = passageiro_novo(4, "Mauricio Carneiro", "Rua Carlos Lobo, 150");
  Voo *voo3 = voo_novo(3, "La Paz", "Buenos Aires");

  Reserva* reserva3 = reserva_nova(3, data3, passageiro3, voo3, assento3);

  Agenda* no2 = criar_no_agenda(data3, reserva3);

  raiz = insere_no_agenda(raiz, no);
  raiz = insere_no_agenda(raiz, no2);
  
  if(abb_numero(raiz)==3 && abb_numero(NULL)==-1){
    printf("[Passou] - abb_numero()\n");
  }else{
    printf("[Falhou] - abb_numero()\n");
  }
}

void teste_busca_agenda_passageiro_voo(){
  Data* data = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
  Reserva* reserva1 = reserva_nova(1, data, passageiro1, voo1, assento1);

  Agenda* raiz = criar_no_agenda(data, reserva1);

  Data* data2 = data_nova(12,12,2021);
  Assento assento2 = B7;
  Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
  Voo *voo2 = voo_novo(12, "Montevideu", "Buenos Aires");

  Reserva* reserva2 = reserva_nova(2, data2, passageiro2, voo2, assento2);

  Agenda* no = criar_no_agenda(data2, reserva2);

  Data* data3 = data_nova(26,12,2021);
  Assento assento3 = B7;
  Passageiro *passageiro3 = passageiro_novo(4, "Mauricio Carneiro", "Rua Carlos Lobo, 150");
  Voo *voo3 = voo_novo(3, "La Paz", "Buenos Aires");

  Reserva* reserva3 = reserva_nova(3, data3, passageiro3, voo3, assento3);

  Agenda* no2 = criar_no_agenda(data3, reserva3);

  raiz = insere_no_agenda(raiz, no);
  raiz = insere_no_agenda(raiz, no2);

  if(abb_busca_agenda_passageiro_voo(raiz, 3, 12) == no && abb_busca_agenda_passageiro_voo(NULL, 1, 52) == NULL){
    printf("[Passou] - busca_agenda_passageiro_voo()\n");
    
  }else{
    printf("[Falhou] - busca_agenda_passageiro_voo()\n");
  }
}

void teste_busca_agenda_data_passageiro(){
  Data* data = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
  Reserva* reserva1 = reserva_nova(1, data, passageiro1, voo1, assento1);

  Agenda* raiz = criar_no_agenda(data, reserva1);

  Data* data2 = data_nova(12,12,2021);
  Assento assento2 = B7;
  Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
  Voo *voo2 = voo_novo(12, "Montevideu", "Buenos Aires");

  Reserva* reserva2 = reserva_nova(2, data2, passageiro2, voo2, assento2);

  Agenda* no = criar_no_agenda(data2, reserva2);

  Data* data3 = data_nova(26,12,2021);
  Assento assento3 = B7;
  Passageiro *passageiro3 = passageiro_novo(4, "Mauricio Carneiro", "Rua Carlos Lobo, 150");
  Voo *voo3 = voo_novo(3, "La Paz", "Buenos Aires");

  Reserva* reserva3 = reserva_nova(3, data3, passageiro3, voo3, assento3);

  Agenda* no2 = criar_no_agenda(data3, reserva3);

  raiz = insere_no_agenda(raiz, no);
  raiz = insere_no_agenda(raiz, no2);

  if(abb_busca_agenda_data_passageiro(raiz, 4, data3) == no2 && abb_busca_agenda_data_passageiro(NULL, 1, data) == NULL ){
    printf("[Passou] - busca_agenda_data_passageiro()\n");
  }else{
    printf("[Falhou] - busca_agenda_data_passageiro()\n");
  }
}

void teste_remove_no_agenda(){
  Data* data = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
  Reserva* reserva1 = reserva_nova(1, data, passageiro1, voo1, assento1);

  Agenda* raiz = criar_no_agenda(data, reserva1);

  Data* data2 = data_nova(12,12,2021);
  Assento assento2 = B7;
  Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
  Voo *voo2 = voo_novo(12, "Montevideu", "Buenos Aires");

  Reserva* reserva2 = reserva_nova(2, data2, passageiro2, voo2, assento2);

  Agenda* no = criar_no_agenda(data2, reserva2);

  Data* data3 = data_nova(26,12,2021);
  Assento assento3 = B7;
  Passageiro *passageiro3 = passageiro_novo(4, "Mauricio Carneiro", "Rua Carlos Lobo, 150");
  Voo *voo3 = voo_novo(3, "La Paz", "Buenos Aires");

  Reserva* reserva3 = reserva_nova(3, data3, passageiro3, voo3, assento3);

  Agenda* no2 = criar_no_agenda(data3, reserva3);

  raiz = insere_no_agenda(raiz, no);
  raiz = insere_no_agenda(raiz, no2);

  raiz = remove_no_agenda(raiz, 2);

  if(busca_agenda_codigo(raiz, 2) == NULL && remove_no_agenda(NULL, 2) == NULL){
    printf("[Passou] - remove_no_agenda()\n");
  } else{
    printf("[Falhou] - remove_no_agenda()\n");
  }
}

void teste_chave_agenda(){
  printf("************************************************ TESTE AGENDA ************************************************ \n");

  Data* data = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
  Reserva* reserva1 = reserva_nova(1, data, passageiro1, voo1, assento1);

  Agenda* raiz = criar_no_agenda(data, reserva1);

  if(chave_agenda(raiz) == 738531 && chave_agenda(NULL) == 0){
    printf("[Passou] - chave_agenda()\n");
    
  } else{
    printf("[Falhou] - chave_agenda()\n");
  }
}

void teste_sucessor(){
  Data* data = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
  Reserva* reserva1 = reserva_nova(1, data, passageiro1, voo1, assento1);

  Agenda* raiz = criar_no_agenda(data, reserva1);

  Data* data2 = data_nova(12,12,2021);
  Assento assento2 = B7;
  Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
  Voo *voo2 = voo_novo(12, "Montevideu", "Buenos Aires");

  Reserva* reserva2 = reserva_nova(2, data2, passageiro2, voo2, assento2);

  Agenda* no = criar_no_agenda(data2, reserva2);

  Data* data3 = data_nova(26,12,2021);
  Assento assento3 = B7;
  Passageiro *passageiro3 = passageiro_novo(4, "Mauricio Carneiro", "Rua Carlos Lobo, 150");
  Voo *voo3 = voo_novo(3, "La Paz", "Buenos Aires");

  Reserva* reserva3 = reserva_nova(3, data3, passageiro3, voo3, assento3);

  Agenda* no2 = criar_no_agenda(data3, reserva3);

  raiz = insere_no_agenda(raiz, no);
  raiz = insere_no_agenda(raiz, no2);

  if(reserva_igual(conteudo_agenda(Sucessor(no)), reserva3) && Sucessor(NULL) == NULL){
    printf("[Passou] - sucessor()\n");
  } else{
    printf("[Falhou] - sucessor()\n");
  }
}

void teste_minimo(){
  Data* data = data_nova(16, 4, 2023);
  Assento assento1 = A0;
  Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
  Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
  Reserva* reserva1 = reserva_nova(1, data, passageiro1, voo1, assento1);

  Agenda* raiz = criar_no_agenda(data, reserva1);

  Data* data2 = data_nova(12,12,2021);
  Assento assento2 = B7;
  Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
  Voo *voo2 = voo_novo(12, "Montevideu", "Buenos Aires");

  Reserva* reserva2 = reserva_nova(2, data2, passageiro2, voo2, assento2);

  Agenda* no = criar_no_agenda(data2, reserva2);

  Data* data3 = data_nova(26,12,2021);
  Assento assento3 = B7;
  Passageiro *passageiro3 = passageiro_novo(4, "Mauricio Carneiro", "Rua Carlos Lobo, 150");
  Voo *voo3 = voo_novo(3, "La Paz", "Buenos Aires");

  Reserva* reserva3 = reserva_nova(3, data3, passageiro3, voo3, assento3);

  Agenda* no2 = criar_no_agenda(data3, reserva3);

  raiz = insere_no_agenda(raiz, no);
  raiz = insere_no_agenda(raiz, no2);

  if(reserva_igual(conteudo_agenda(Minimo(raiz)), reserva2) && Minimo(NULL) == NULL){
    printf("[Passou] - minimo()\n");
  } else{
    printf("[Falhou] - minimo()\n");
  }
}

///////////////// TESTES VIAGEM ///////////////////////////////////////////////////////

int teste_viagem_cria() {
    printf("************************************************ TESTE VIAGEM ************************************************ \n");
    Viagem *viagem = lista_viagem_cria();
    if (viagem != NULL) {
        printf("[Passou] - viagem_cria()\n");
        return 1;
    } else {
        printf("[Falhou] - viagem_cria()\n");
        return 0;
    }
}
float teste_viagem_libera() {
    Viagem *viagem = lista_viagem_cria();
    lista_viagem_libera(&viagem);
    if (viagem != NULL || lista_viagem_libera(NULL) != 0) {
        printf(
            "[Falhou] - viagem_libera()\n");
        return 0;
    } else {
        printf(
            "[Passou] - viagem_libera()\n");
        return 1;
    }
}

float teste_viagem_vazia() {
    Viagem *viagem = lista_viagem_cria();
    if (viagem != NULL && lista_viagem_vazia(viagem) == 1) {
        printf("[Passou] - viagem_vazia() \n");
        return 1;
    } else {
        printf("[Falhou] - lista_voo_vazia() \n");
        return 0;
    }
}

float teste_viagem_insere() {
    Viagem *viagem = lista_viagem_cria();
    if (viagem != NULL){
    Data *data1 = data_nova(16, 4, 2023);
    Data *data2 = data_nova(12, 12, 2021);
    Data *data3 = data_nova(12, 12, 2024);
    Assento assento1 = A0;
    Assento assento2 = B7;
    Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
    Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
    Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
    Voo *voo2 = voo_novo(12, "Montevideu", "Buenos Aires");
    Voo *voo3 = voo_novo(12, "Londres", "Buenos Aires");

    Reserva *reserva1 = reserva_nova(1, data1, passageiro1, voo1, assento1);
    Reserva *reserva2 = reserva_nova(1, data2, passageiro2, voo2, assento2);
    Reserva *reserva3 = reserva_nova(3, data3, passageiro1, voo3, assento2);

    if (lista_viagem_insere(viagem, reserva1) == 1 && lista_viagem_insere(viagem, reserva2) == 0 && lista_viagem_insere(viagem, NULL) == -1 && lista_viagem_insere(viagem, reserva3) == 1) {
        printf("[Passou] - viagem_insere()\n");
        return 1;
    } else {
        printf("[Falhou] - viagem_insere()\n");
    }
    }
    printf("[Falhou] - viagem_insere()\n");
    return 0;
}

float teste_viagem_primeiro() {
    Viagem *viagem = lista_viagem_cria();
    if (viagem != NULL) {
        Data *data1 = data_nova(16, 4, 2023);
        Data *data2 = data_nova(12, 12, 2021);
        Data *data3 = data_nova(07, 12, 2021);
        Assento assento1 = A0;
        Assento assento2 = B7;
        Assento assento3 = C7;
        Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
        Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
        Passageiro *passageiro3 = passageiro_novo(3, "Yara Vasconcelos", "Av. Beira Mar, 1998");
        Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
        Voo *voo2 = voo_novo(12, "Montevideu", "Buenos Aires");
        Voo *voo3 = voo_novo(92, "Dacar", "Gaborone");

        Reserva *reserva1 = reserva_nova(1, data1, passageiro1, voo1, assento1);
        Reserva *reserva2 = reserva_nova(2, data2, passageiro2, voo2, assento2);
        Reserva *reserva3 = reserva_nova(3, data3, passageiro3, voo3, assento3);

        lista_viagem_insere(viagem, reserva1);
        lista_viagem_insere(viagem, reserva2);
        lista_viagem_insere(viagem, reserva3);

        Trecho *primeiro_trecho = lista_viagem_primeiro(viagem);

        Trecho *trecho1 = trecho_cria(lista_viagem_busca(viagem, 1));
        if (trecho_igual(primeiro_trecho, trecho1) == 1) {
            printf("[Passou] - viagem_primeiro()\n");
            return 1;
        } else {
            printf("[Falhou] - viagem_primeiro()\n");
        }
    } else {
        printf(
            "[Falhou] - viagem_primeiro()\n");
    }
    return 0;
}

float teste_viagem_busca() {
    Viagem *viagem = lista_viagem_cria();
    if (viagem != NULL) {
        Data *data1 = data_nova(16, 4, 2023);
        Data *data2 = data_nova(12, 12, 2023);
        Data *data3 = data_nova(7, 12, 2024);
        Assento assento1 = A0;
        Assento assento2 = B7;
        Assento assento3 = C7;
        Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
        Passageiro *passageiro2 = passageiro_novo(2, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
        Passageiro *passageiro3 = passageiro_novo(3, "Yara Vasconcelos", "Av. Beira Mar, 1998");
        Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
        Voo *voo2 = voo_novo(12, "Londres", "Buenos Aires");
        Voo *voo3 = voo_novo(92, "Buenos Aires", "Gaborone");

        Reserva *reserva1 = reserva_nova(1, data1, passageiro1, voo1, assento1);
        Reserva *reserva2 = reserva_nova(2, data2, passageiro1, voo2, assento2);
        Reserva *reserva3 = reserva_nova(3, data3, passageiro1, voo3, assento3);

        lista_viagem_insere(viagem, reserva1);
        lista_viagem_insere(viagem, reserva2);
        lista_viagem_insere(viagem, reserva3);

        Reserva *aux = lista_viagem_busca(viagem, 2);
        if (aux != NULL) {
            if (reserva_igual(aux, reserva2) == 1 && lista_viagem_busca(NULL, -1) == NULL) {
                printf("[Passou] - viagem_busca()\n");
                return 1;
            } else {
                printf("[Falhou] - viagem_busca()\n");
            }
        } else {
            printf("[Falhou] - viagem_busca()\n");
        }
    } else {
        printf("[Falhou] - viagem_busca()\n");
    }
    return 0;
}

float teste_viagem_retira() {
    Viagem *viagem = lista_viagem_cria();
    if (viagem != NULL) {
        Data *data1 = data_nova(16, 4, 2023);
        Data *data2 = data_nova(12, 12, 2023);
        Data *data3 = data_nova(7, 12, 2024);
        Assento assento1 = A0;
        Assento assento2 = B7;
        Assento assento3 = C7;
        Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
        Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
        Passageiro *passageiro3 = passageiro_novo(3, "Yara Vasconcelos", "Av. Beira Mar, 1998");
        Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
        Voo *voo2 = voo_novo(12, "Londres", "Buenos Aires");
        Voo *voo3 = voo_novo(92, "Buenos Aires", "Gaborone");

        Reserva *reserva1 = reserva_nova(1, data1, passageiro1, voo1, assento1);
        Reserva *reserva2 = reserva_nova(2, data2, passageiro1, voo2, assento2);
        Reserva *reserva3 = reserva_nova(3, data3, passageiro1, voo3, assento3);

        lista_viagem_insere(viagem, reserva1);
        lista_viagem_insere(viagem, reserva2);
        lista_viagem_insere(viagem, reserva3);

        Trecho *aux = lista_viagem_retira(viagem);
        Trecho *trecho_retirado = trecho_cria(reserva1);
        if (trecho_igual(aux, trecho_retirado) == 1) {
            aux = lista_viagem_retira(viagem);
            trecho_retirado = trecho_cria(reserva2);
            if (trecho_igual(aux, trecho_retirado) == 1) {
                aux = lista_viagem_retira(viagem);
                trecho_retirado = trecho_cria(reserva3);
                if (trecho_igual(aux, trecho_retirado) == 1) {
                    aux = lista_viagem_retira(viagem);
                    if(aux == NULL){
                        printf("[Passou] - viagem_retira() \n");
                        return 1;
                    } else{
                        printf("[Falhou] - viagem_retira()\n");
                        return 0;
                    }
                } else {
                    printf("[Falhou] - viagem_retira()\n");
                }
            } else {
                printf("[Falhou] - viagem_retira()\n");
            }
        } else {
            printf("[Falhou] - viagem_retira()\n");
        }
    } else {
        printf("[Falhou] - viagem_retira()\n");
    }
    return 0;
}

int teste_cria_hash(){
    printf("************************************************ TESTE HASH ************************************************");
    int tamanho = 10;
    TabelaViagem* novo_hash = cria_hash(tamanho);
    if (novo_hash != NULL && tamanho_hash(novo_hash) != 0 && ponteiro_hash(novo_hash) != NULL){
        printf("\n[Passou] - cria_hash()");
    }
    else{
    printf("\n[Falhou] - cria_hash()");
    }
    return 1;
}

int teste_inicializar_hash(){
    int tamanho = 10;
    TabelaViagem* novo_hash = cria_hash(tamanho);
    if (novo_hash != NULL){
        inicializar_hash(novo_hash);
        if (ponteiro_hash(novo_hash) == NULL){
            printf("\n[Passou] - inicializar_hash()");
            return 1;
    }
    }
    printf("\n[Falhou] - inicializar_hash()");
}

int teste_inserir_hash(){
    int tamanho = 10;
    TabelaViagem* novo_hash = cria_hash(tamanho);
    if (novo_hash != NULL){
        inicializar_hash(novo_hash);
        
        Viagem *viagem = lista_viagem_cria();
        if (viagem != NULL) {
            Data *data1 = data_nova(16, 4, 2023);
            Data *data2 = data_nova(25, 4, 2023);
            Data *data3 = data_nova(8, 5, 2023);
            Assento assento1 = A0;
            Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
            Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
            Voo *voo2 = voo_novo(12, "Londres", "Buenos Aires");
            Voo *voo3 = voo_novo(12, "Buenos Aires", "São Paulo");

            Reserva *reserva1 = reserva_nova(1, data1, passageiro1, voo1, assento1);
            Reserva *reserva2 = reserva_nova(2, data2, passageiro1, voo2, assento1);
            Reserva *reserva3 = reserva_nova(3, data3, passageiro1, voo3, assento1);
            if (lista_viagem_insere(viagem, reserva1) == 1 && lista_viagem_insere(viagem, reserva2) == 1 && lista_viagem_insere(viagem, reserva3) == 1){
                if (inserir_hash(novo_hash, viagem) == 1){
                    printf("\n[Passou] - inserir_hash()");
                    return 1;
                }
                else{
                    printf("\n[Falhou] - inserir_hash()");
                }
            }
            else{
            printf("\n[Falhou] - inserir_hash()");
            }
            }
            else{
                printf("\n[Falhou] - inserir_hash()");
            }

}
printf("\n[Falhou] - inserir_hash()");
}

int teste_buscar_hash(){
    int tamanho = 10;
    TabelaViagem* novo_hash = cria_hash(tamanho);
    if (novo_hash != NULL){
        inicializar_hash(novo_hash);
        
        Viagem *viagem = lista_viagem_cria();
        if (viagem != NULL) {
            Data *data1 = data_nova(16, 4, 2023);
            Data *data2 = data_nova(25, 4, 2023);
            Data *data3 = data_nova(8, 5, 2023);
            Assento assento1 = A0;
            Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
            Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
            Voo *voo2 = voo_novo(12, "Londres", "Buenos Aires");
            Voo *voo3 = voo_novo(12, "Buenos Aires", "São Paulo");

            Reserva *reserva1 = reserva_nova(1, data1, passageiro1, voo1, assento1);
            Reserva *reserva2 = reserva_nova(2, data2, passageiro1, voo2, assento1);
            Reserva *reserva3 = reserva_nova(3, data3, passageiro1, voo3, assento1);
            if (lista_viagem_insere(viagem, reserva1) == 1 && lista_viagem_insere(viagem, reserva2) == 1 && lista_viagem_insere(viagem, reserva3) == 1){
              if (inserir_hash(novo_hash, viagem) == 1){
                int id = funcaoHash(novo_hash, codigo_hash(viagem));
                Viagem* aux = busca_hash(novo_hash, id);
                if (viagem_igual(viagem, aux) == 1){
                  printf("\n[Passou] - busca_hash()");
                  return 1;
                }
              }
            }
        }
    }
    printf("\n[Falhou] - busca_hash()");
    return 0;
}

int teste_retira_hash(){
    int tamanho = 10;
    TabelaViagem* novo_hash = cria_hash(tamanho);
    if (novo_hash != NULL){
        inicializar_hash(novo_hash);
        
        Viagem *viagem = lista_viagem_cria();
        if (viagem != NULL) {
            Data *data1 = data_nova(16, 4, 2023);
            Data *data2 = data_nova(25, 4, 2023);
            Data *data3 = data_nova(8, 5, 2023);
            Assento assento1 = A0;
            Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
            Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
            Voo *voo2 = voo_novo(12, "Londres", "Buenos Aires");
            Voo *voo3 = voo_novo(12, "Buenos Aires", "São Paulo");

            Reserva *reserva1 = reserva_nova(1, data1, passageiro1, voo1, assento1);
            Reserva *reserva2 = reserva_nova(2, data2, passageiro1, voo2, assento1);
            Reserva *reserva3 = reserva_nova(3, data3, passageiro1, voo3, assento1);
            if (lista_viagem_insere(viagem, reserva1) == 1 && lista_viagem_insere(viagem, reserva2) == 1 && lista_viagem_insere(viagem, reserva3) == 1){
              if (inserir_hash(novo_hash, viagem) == 1){
                int id = funcaoHash(novo_hash, codigo_hash(viagem));
                Viagem* aux_1 = retira_hash(novo_hash, id);
                Viagem* aux_2 = busca_hash(novo_hash, id);
                if (viagem_igual(viagem, aux_1) == 1 && aux_2 == NULL){
                  printf("\n[Passou] - retira_hash()");
                  return 1;
                }
              }
            }
        }
    }
    printf("\n[Falhou] - retira_hash()");
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
  teste_lista_passageiro_cria();
  teste_lista_passageiro_libera();
  teste_lista_passageiro_vazia();
  teste_lista_passageiro_insere();
  teste_lista_passageiro_primeiro();
  teste_lista_passageiro_busca();
  teste_lista_passageiro_retira();
  // Testes Voo

  teste_voo_novo();
  teste_voo_libera();
  teste_voo_acessa();
  teste_voo_atribui_dados_validos();
  teste_voo_atribui_dados_invalidos();
  teste_voo_igual();
  teste_lista_voo_cria();
  teste_lista_voo_libera();
  teste_lista_voo_vazia();
  teste_lista_voo_insere();
  teste_lista_voo_primeiro();
  teste_lista_voo_busca();
  teste_lista_voo_retira();

  //Testes Reserva
  teste_reserva_nova();
  teste_reserva_libera();
  teste_reserva_acessa();
  teste_reserva_acessa();
  teste_reserva_atribui_dados_validos();
  teste_reserva_atribui_dados_invalidos();
  teste_reserva_igual();

  //Testes Agenda
  teste_chave_agenda();
  teste_conteudo_agenda();
  teste_libera_no_agenda();
  teste_minimo();
  teste_numero();
  teste_busca_agenda_data_passageiro();
  teste_insere_no_agenda();
  teste_busca_agenda_codigo();
  teste_busca_agenda_passageiro_voo(); 
  teste_sucessor();
  teste_altura();
  teste_remove_no_agenda();
  
  //Testes Viagem
  teste_viagem_cria();
  teste_viagem_libera();
  teste_viagem_vazia();
  teste_viagem_insere();
  teste_viagem_primeiro();
  teste_viagem_busca();
  teste_viagem_retira();

  //Testes Hash
  teste_cria_hash();
  teste_inicializar_hash();

  teste_inserir_hash();
  teste_buscar_hash();
  
  return 0;
}