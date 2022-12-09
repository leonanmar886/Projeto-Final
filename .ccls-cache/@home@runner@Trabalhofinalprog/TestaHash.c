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
  Viagem *tabela_hash;
};

int teste_cria_hash(){
    printf("************************************************ TESTE HASH ************************************************");
    int tamanho = 10;
    TabelaViagem* novo_hash = cria_hash(tamanho);
    if (novo_hash != NULL && novo_hash -> tamanho == tamanho * 2 + 1 && novo_hash -> tabela_hash != NULL){
        printf("[Passou] - cria_hash()");
    }
    else{
    printf("[Falhou] - cria_hash()");
    }
    return 1;
}

int teste_inicializar_tabela(){
    int tamanho = 10;
    TabelaViagem* novo_hash = cria_hash(tamanho);
    if (novo_hash != NULL){
        inicializar_tabela(novo_hash);
        if ((&(novo_hash -> tabela_hash))[0] == NULL);{
            printf("[Passou] - inicializar_tabela()");
            return 1;
    }
    }
    printf("[Falhou] - inicializar_tabela()");
}

teste_inserir_tabela(){
    int tamanho = 10;
    TabelaViagem* novo_hash = cria_hash(tamanho);
    if (novo_hash != NULL){
        inicializar_tabela(novo_hash);
        
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
            if (lista_viagem_insere(viagem, reserva1) == 1 && lista_viagem_insere(viagem, reserva2) == 1 && lista_viagem_insere(viagem, reserva3 == 1)){
                if (inserir_tabela(novo_hash, viagem) == 1){
                    printf("[Passou] - inserir_tabela()");
                }
                else{
                    printf("[Falhou] - inserir_tabela()");
                }
            }
            else{
            printf("[Falhou] - inserir_tabela()");
            }
            }
            else{
                printf("[Falhou] - inserir_tabela()");
            }

}
printf("[Falhou] - inserir_tabela()");
}