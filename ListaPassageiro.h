typedef struct passageiro Passageiro;
typedef struct lista_passageiro Lista;
typedef struct  no_passageiro No;

Lista* fila_cria();
//
int fila_libera(Lista **lista);

Passageiro* fila_busca(Lista* lista, int id);

int fila_insere(Lista* lista, Passageiro* passa);

Passageiro* fila_remove(Lista* lista);