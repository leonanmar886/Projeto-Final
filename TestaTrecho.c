#include "TravelBooking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int testa_trecho_libera();

int testa_trecho_acessa();

int testa_trecho_atribui();

int testa_trecho_igual();