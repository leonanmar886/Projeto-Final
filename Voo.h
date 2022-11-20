#include "TravelBooking.h"

// verifica se algum dos valores na struct voo é nulo. Se sim, retorna -1. Se não, retorna 1
int voo_verifica(Voo *voo);

/* Aloca e retorna um Voo com os dados passados por parâmetro. Porém, para os
 * casos em que (i) pelo menos um dos parâmetros sejam nulos <-1, NULL, NULL>; e
 * (ii) o tamanho das strings origem e destino sejam maiores que os da especificação
 * (50 e 30, respectivamente), a função deve retornar NULL. */
Voo *voo_novo(int codigo, char *origem, char *destino);

/* Libera a memória de um Voo previamente criado e atribui NULL ao Voo. */
void voo_libera(Voo **Voo);

/* Copia os valores de um Voo para as referências informadas. Em caso de Voo
 * NULL, atribuir valor padrão <-1, "NULL", "NULL"> aos parâmetros. */
void voo_acessa(Voo *Voo, int *codigo, char *origem, char *destino);

/* Atribui novos valores aos campos de um Voo. Porém, para os casos em que (i)
 * algum dos parâmetros sejam nulos <NULL, -1, NULL, NULL>; ou (ii) o tamanho
 * das strings origem e destino sejam maiores que os da especificação (50 e 30,
 * respectivamente), a função não deve fazer a atribuição. */
void voo_atribui(Voo *Voo, int codigo, char *origem, char *destino);

/* Avalia se dois Voos são iguas. A função deve retornar 1 se os Voos
 * possuem os mesmos dados, 0 caso os dados dos Voos possuam alguma diferença
 * e -1 caso pelo menos um dos Voos seja NULL.
 */
int voo_igual(Voo *Voo1, Voo *Voo2);