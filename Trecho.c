#include "TravelBooking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct trecho {
  Reserva *reserva;
  struct trecho *proximo;
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

