#include "Passageiro.h"

typedef struct  no_passageiro No;

ListaPassageiro* fila_passageiro_cria();
//
int fila_passageiro_libera(ListaPassageiro **lista);

Passageiro* fila_passageiro_busca(ListaPassageiro* lista, int id);

int fila_passageiro_insere(ListaPassageiro* lista, Passageiro* passa);

Passageiro* fila_passageiro_retira(ListaPassageiro* lista);

int fila_passageiro_vazia(ListaPassageiro* lista);

Passageiro* fila_passageiro_primeiro(ListaPassageiro* lista);