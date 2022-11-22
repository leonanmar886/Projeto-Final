#include "TravelBooking.h"




//   Aloca e retorn um passageiro com os dados passados por parâmetro
Passageiro* passageiro_novo(int id, char* nome, char* endereço);

void passageiro_libera(Passageiro** passageiro);

void passageiro_acessa(Passageiro* passa, int* id, char* nome, char* endereco);

void passageiro_atribui(Passageiro* passa, int id, char* nome, char* end);

int passageiro_igual(Passageiro* passa1, Passageiro* passa2);