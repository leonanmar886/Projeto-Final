#include "TravelBooking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

float teste_fila_voo_vazia() {
    Viagem *viagem = lista_viagem_cria();
    if (viagem != NULL && lista_viagem_vazia(viagem) == 1) {
        printf("[Passou] - viagem_vazia() \n");
        return 1;
    } else {
        printf("[Falhou] - fila_voo_vazia() \n");
        return 0;
    }
}

float teste_viagem_insere() {
    Viagem *viagem = lista_viagem_cria();

    Data *data1 = data_nova(16, 4, 2023);
    Data *data2 = data_nova(12, 12, 2021);
    Assento assento1 = A0;
    Assento assento2 = B7;
    Passageiro *passageiro1 = passageiro_novo(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
    Passageiro *passageiro2 = passageiro_novo(3, "Mauricio Marques", "Rua Carlos Vasconcelos, 150");
    Voo *voo1 = voo_novo(52, "Nova Iorque", "Londres");
    Voo *voo2 = voo_novo(12, "Montevideu", "Buenos Aires");

    Reserva *reserva1 = reserva_nova(1, data1, passageiro1, voo1, assento1);
    Reserva *reserva2 = reserva_nova(1, data2, passageiro2, voo2, assento2);

    if (lista_viagem_insere(viagem, reserva1) == 1 && lista_viagem_insere(viagem, reserva2) == 0 && lista_viagem_insere(viagem, NULL) == -1) {
        printf("[Passou] - fila_voo_insere\n");
        return 1;
    } else {
        printf("[Falhou] - fila_voo_insere()\n");
    }
    return 0;
}

float teste_viagem_primeiro() {
    Viagem *viagem = fila_voo_cria();
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
        if (trecho_igual(primeiro_trecho, viagem->primeiro_trecho) == 1) {
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

float testa_viagem_busca() {
    ListaVoo *viagem = fila_voo_cria();
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

        Reserva *aux = lista_viagem_busca(viagem, 2);
        if (aux != NULL) {
            if (reserva_igual(aux, reserva2) == 1 && lista_viagem_busca(NULL, -1) == NULL) {
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

float teste_viagem_retira() {
    ListaVoo *viagem = fila_voo_cria();
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