#include "TravelBooking.h"

//Aloca e retorna um novo trecho que contém uma reserva e um ponteiro para o próximo trecho.
Trecho* novo_trecho(Reserva* reserva, Trecho* proximo_trecho);

// Libera o espaço de memória atribuído a um trecho e atribui NULL ao Trecho.
void trecho_libera(Trecho** trecho);

//Atribui aos campos os valores de reserva e proximo trecho armazenados no trecho.
void trecho_acessa(Trecho* trecho, Reserva* reserva, Trecho* proximo_trecho);

/* Atribui ao trecho passado como parâmetro os novos valores de reserva e proximo trecho.
   (i) Se os campos passados como parâmetro forem inválidos, as alterações não serão feitas.
   (ii) Se o trecho passado como parâmetro for NULL, as alterações não serão feitas.
*/
void trecho_atribui(Trecho* trecho, Reserva* nova_reserva, Trecho* novo_proximo_trecho);

/* Verifica se os trechos passados como parâmetros são iguais. Os trechos serão considerados iguais
   se e somente se as reservas e os proximos trechos forem iguais.
   (i) Se os trechos forem iguais, a função retorna 1.
   (ii) Se os trechos forem diferentes, a função retorna 0.
   (iii) Se um dos trechos for inválido ou NULL, a função retorna -1.
*/
int trecho_igual(Trecho* trecho1, Trecho* trecho2);