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

Trecho* novo_trecho(Reserva* reserva, Trecho* proximo_trecho){
    if(reserva == NULL){
        return NULL;
    }

    Trecho* trecho = (Trecho*) malloc(sizeof(Trecho));
    trecho->reserva = reserva;
    if(proximo_trecho != NULL){
        Trecho** trecho_endereco = &(trecho->proximo);
        *trecho_endereco = proximo_trecho;
    } else {
        trecho->proximo = NULL;
    }

    return trecho;
};

void trecho_libera(Trecho** trecho){
    if(trecho == NULL){
        return NULL;
    }

    free(*trecho);
    trecho = NULL;
};

void trecho_acessa(Trecho* trecho, Reserva* reserva, Trecho* proximo_trecho){
    if(trecho == NULL){
        return NULL;
    }

    Reserva** reserva_aux = &(reserva);
    Trecho** trecho_aux = &(proximo_trecho);

    *reserva_aux = trecho-> reserva;
    *trecho_aux = trecho->proximo;
};

void trecho_atribui(Trecho* trecho, Reserva* nova_reserva, Trecho* novo_proximo_trecho){
    if(nova_reserva == NULL || novo_proximo_trecho == NULL){
        return NULL;
    };

    Reserva** reserva_aux = &(trecho->reserva);
    Trecho** trecho_aux = &(trecho->proximo);

    *reserva_aux = nova_reserva;
    *trecho_aux = novo_proximo_trecho;
};

int trecho_igual(Trecho* trecho1, Trecho* trecho2){
    if(trecho1 == NULL || trecho2 == NULL){
        return -1;
    }
    
    Reserva* reserva1 = (Reserva*) malloc(sizeof(Reserva));
    Trecho* proximo_trecho1 = (Trecho*) malloc(sizeof(Trecho));
    Reserva* reserva2 = (Reserva*) malloc(sizeof(Reserva));
    Trecho* proximo_trecho2 = (Trecho*) malloc(sizeof(Trecho));
    trecho_acessa(trecho1, reserva1, proximo_trecho1);
    trecho_acessa(trecho2, reserva2, proximo_trecho2);

    int igualdade = reserva_igual(reserva1, reserva2);

    return igualdade;

}