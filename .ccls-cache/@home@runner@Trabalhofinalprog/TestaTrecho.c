#include "TravelBooking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct trecho {
  Reserva *reserva;
  struct trecho *proximo;
};

struct reserva {
  int codigo;
  Data *data_viagem;
  Passageiro *passageiro;
  Voo *voo;
  Assento assento;
};

int testa_novo_trecho(){
    Assento assento = "A1";
    Voo* voo = voo_novo(550, "Camberra", "Sydney");
    Passageiro *passageiro = passageiro_novo(1, "Abraão", "Rua Taquari, 3850");
    Data* data = criar_data(27, 11, 2022);
    Reserva* reserva = reserva_nova(55, data, passageiro, voo, assento);
    Trecho* trecho = novo_trecho(reserva, NULL);
    Trecho* trecho2 = novo_trecho(NULL, NULL);

    if(trecho == NULL || trecho2 != NULL){
        printf("[Falhou] - novo_trecho()\n");
        return 0;
    }

    printf("[Passou] - novo_trecho()\n");
    return 1;

};

int testa_trecho_libera(){
    Assento assento = "A1";
    Voo* voo = voo_novo(550, "Camberra", "Sydney");
    Passageiro *passageiro = passageiro_novo(1, "Abraão", "Rua Taquari, 3850");
    Data* data = criar_data(27, 11, 2022);
    Reserva* reserva = reserva_nova(55, data, passageiro, voo, assento);
    Trecho* trecho = novo_trecho(reserva, NULL);

    trecho_libera(&trecho);

    if (trecho != NULL){
        printf("[Falhou] - trecho_libera()\n");
        return 0;
    }

    printf("[Passou] - trecho_libera()\n");
    return 1;
};

int testa_trecho_igual(){
    Assento assento = "A1";
    Voo* voo = voo_novo(550, "Camberra", "Sydney");
    Passageiro *passageiro = passageiro_novo(1, "Abraão", "Rua Taquari, 3850");
    Data* data = criar_data(27, 11, 2022);
    Reserva* reserva = reserva_nova(55, data, passageiro, voo, assento);
    Trecho* trecho = novo_trecho(reserva, NULL);
    Trecho* trecho2 = novo_trecho(reserva, NULL);

    if(trecho_igual(trecho, trecho2) != 1){
        printf("[Falhou] - trecho_igual()\n");
        return 0;
    }

        printf("[Passou] - trecho_atribui()\n");
        return 1;
};

int testa_trecho_acessa(){
    Assento assento = "A1";
    Voo* voo = voo_novo(550, "Camberra", "Sydney");
    Passageiro *passageiro = passageiro_novo(1, "Abraão", "Rua Taquari, 3850");
    Data* data = criar_data(27, 11, 2022);
    Reserva* reserva = reserva_nova(55, data, passageiro, voo, assento);
    Trecho* trecho = novo_trecho(reserva, NULL);

    Trecho* trecho1 = (Trecho*) malloc(sizeof(Trecho));

    trecho_acessa(trecho, trecho1->reserva, trecho1->proximo);

    if(trecho_igual(trecho, trecho1) != 1){
        printf("[Falhou] - trecho_acessa()\n");
        return 0;
    }

    printf("[Passou] - trecho_acessa()\n");
    return 1;
    
};

int testa_trecho_atribui(){
    Assento assento = "A1";
    Voo* voo = voo_novo(550, "Camberra", "Sydney");
    Passageiro *passageiro = passageiro_novo(1, "Abraão", "Rua Taquari, 3850");
    Data* data = criar_data(27, 11, 2022);
    Reserva* reserva = reserva_nova(55, data, passageiro, voo, assento);
    Trecho* trecho = novo_trecho(reserva, NULL);

    Assento assento2 = "A2";
    Voo* voo2 = voo_novo(540, "Sobral", "Juazeiro do Norte");
    Passageiro *passageiro2 = passageiro_novo(2, "João", "Rua Ipanema, 487");
    Data* data2 = criar_data(28, 12, 2022);
    Reserva* reserva2 = reserva_nova(56, data2, passageiro2, voo2, assento2);
    Trecho* trecho2 = novo_trecho(reserva2, NULL);

    trecho_atribui(trecho, reserva2, NULL);

    if(trecho_igual(trecho, trecho2) != 1){
        printf("[Falhou] - trecho_atribui()\n");
        return 0;
    }

    printf("[Passou] - trecho_atribui()\n");
    return 1;
};