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
    if(reserva == NULL || proximo_trecho == NULL){
        return NULL;
    }

    Trecho* trecho = (Trecho*) malloc(sizeof(Trecho));
    trecho->reserva = reserva;
    trecho->proximo = proximo_trecho;

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
    Reserva* reserva_aux = trecho->reserva;
    Trecho* trecho_aux = trecho->proximo;

    *(reserva) = *(reserva_aux);
    *(proximo_trecho) = *(trecho_aux);
};