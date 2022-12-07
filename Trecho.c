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

int trecho_valido(Trecho* trecho_origem, Trecho* trecho_destino){
    Reserva* reserva_origem_aux;
    Reserva* reserva_origem_proximo_aux2;
    Reserva* reserva_destino_aux;
    Reserva* reserva_destino_proximo_aux2;

    trecho_acessa(trecho_origem, reserva_origem_aux, reserva_origem_proximo_aux2);
    trecho_acessa(trecho_origem, reserva_destino_aux, reserva_destino_proximo_aux2);

    int codigo_trecho_origem;
    Data *data_trecho_origem;
    Passageiro *passageiro_trecho_origem;
    Voo *voo_trecho_origem;
    Assento assento_trecho_origem;

    int codigo_trecho_destino;
    Data *data_trecho_destino;
    Passageiro *passageiro_trecho_destino;
    Voo *voo_trecho_destino;
    Assento assento_trecho_destino;

    reserva_acessa(reserva_origem_aux, &(codigo_trecho_origem), &(data_trecho_origem), &(passageiro_trecho_origem), &(voo_trecho_origem), &(assento_trecho_origem));
    reserva_acessa(reserva_destino_aux, &(codigo_trecho_destino), &(data_trecho_destino), &(passageiro_trecho_destino), &(voo_trecho_destino), &(assento_trecho_destino));

    if(data_inteiro(data_trecho_origem) < data_inteiro(data_trecho_destino)){
        if(passageiro_trecho_origem->id == passageiro_trecho_destino->id){
            if(strcmp(voo_trecho_origem->destino, voo_trecho_destino->origem) == 0){
                return 1;
            }
        }
    }
    return 0;
    
}

Trecho* trecho_cria(Reserva* reserva, Trecho* proximo_trecho){
    if (reserva == NULL){
        return NULL;
    }
    Trecho* trecho = (Trecho*) malloc(sizeof(Trecho));
    trecho -> reserva = reserva;
    if (proximo_trecho != NULL){
        if (trecho_valido(trecho, proximo_trecho) == 1){
            trecho -> proximo = proximo_trecho;
        }
    }
    else{
        trecho -> proximo = NULL;
    }
    return trecho;
}

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
    if(trecho == NULL || nova_reserva == NULL || novo_proximo_trecho == NULL){
        return NULL;
    };


    Reserva** reserva_aux = &(trecho->reserva);
    Trecho** trecho_aux = &(trecho->proximo);

    *reserva_aux = nova_reserva;
    if (trecho_valido(trecho, novo_proximo_trecho) == 1){
        *trecho_aux = novo_proximo_trecho;
    }
    else{
        *trecho_aux = NULL;
    }
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

