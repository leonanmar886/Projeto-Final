#include "TravelBooking.h"

/* Aloca espaço em memória e retorna uma ListaVoo */
ListaVoo *fila_voo_cria();

/* Libera a memória de uma ListaVoo previamente criada e atribui NULL ao ponteiro
 * ListaVoo. Retorna 1 caso seja possível fazer a liberação e 0 caso a ListaVoo
 * informada seja NULL. */
int fila_voo_libera(ListaVoo **ListaVoo);

/* Insere um Voo na ListaVoo. Retorna 1 se foi possível adicionar, 0 caso já
 * exista um Voo com a mesma codigo (nesse caso, o Voo não pode ser
 * adicionado) e -1 caso a ListaVoo ou Voo sejam NULL
 */
int fila_voo_insere(ListaVoo *ListaVoo, Voo *voo);

/* Remove um Voo na ListaVoo. Retorna o Voo ou NULL caso a ListaVoo esteja vazia ou
 * seja NULL */
Voo *fila_voo_retira(ListaVoo *ListaVoo);

/* Recupera o primeiro Voo da ListaVoo. Retorna o Voo ou NULL caso a ListaVoo esteja
 * vazia ou seja NULL */
Voo *fila_voo_primeiro(ListaVoo *ListaVoo);

/* Busca Voo pelo número de codigo. Retorna o Voo se este estiver na
 * lista e NULL caso contrário, isto é, (i) ListaVoo vazia; (ii) não exista Voo
 * com a codigo fornecida; ou (iii) a ListaVoo seja NULL */
Voo *fila_voo_busca(ListaVoo *ListaVoo, int codigo);

/* Verifica se a ListaVoo está vazia. Retorna 1 se a ListaVoo estiver vazia, 0 caso não
 * esteja vazia e -1 se a ListaVoo for NULL
 */
int fila_voo_vazia(ListaVoo *ListaVoo);

/* Computa a quantidade de Voos Voos na ListaVoo. Retorna a quantidade de Voos
 * ou -1, caso a ListaVoo for NULL.
 */

/* Computa a quantidade de voos na fila. Retorna a quantidade de voos
 * ou -1, caso a fila for NULL.
 */
int fila_voo_quantidade(ListaVoo *fila);