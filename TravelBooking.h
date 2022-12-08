enum cod_assento {
    A0, B0, C0,
    A1, B1, C1, 
    A2, B2, C2,
    A3, B3, C3,
    A4, B4, C4,
    A5, B5, C5,
    A6, B6, C6,
    A7, B7, C7,
    A8, B8, C8, 
    A9, B9, C9
 };

typedef enum cod_assento Assento;
typedef struct data Data;
typedef struct voo Voo;
typedef struct lista_voo ListaVoo;
typedef struct passageiro Passageiro;
typedef struct lista_passageiro ListaPassageiro;
typedef struct reserva Reserva;
typedef struct agenda Agenda;
typedef struct viagem Viagem;
typedef struct tabela_viagem TabelaViagem;
typedef struct trecho Trecho;

/*Retorna o tamanhos em bytes das structs Assento e Data*/
int data_tamanho();
int assento_tamanho();

//Cria uma nova Data com os parametros passados
Data* data_nova(int dia, int mes, int ano);

// Exibe a data usando printf
void printa_data(Data* data);

int data_inteiro(Data* data); // Retorna um inteiro referente ao número de dias da data

// ********** Passageiro.h ******************

// verifica se algum dos valores na struct passageiro é nulo. Se sim, retorna -1. Se não, retorna 1
int passageiro_verifica(Passageiro *passageiro);

/* Aloca e retorna um passageiro com os dados passados por parâmetro. Porém, para os
 * casos em que (i) pelo menos um dos parâmetros sejam nulos <-1, NULL, NULL>; e
 * (ii) o tamanho das strings origem e destino sejam maiores que os da especificação
 * (50 e 30, respectivamente), a função deve retornar NULL. Ok*/
Passageiro *passageiro_novo(int codigo, char *nome, char *endereco);

/* Libera a memória de um passageiro previamente criado e atribui NULL ao passageiro. Ok*/
void passageiro_libera(Passageiro **passageiro);

/* Copia os valores de um passageiro para as referências informadas. Em caso de passageiro
 * NULL, atribuir valor padrão <-1, "NULL", "NULL"> aos parâmetros. Ok */
void passageiro_acessa(Passageiro *passageiro, int *codigo, char *origem, char *destino);

/* Atribui novos valores aos campos de um passageiro. Porém, para os casos em que (i)
 * algum dos parâmetros sejam nulos <NULL, -1, NULL, NULL>; ou (ii) o tamanho
 * das strings origem e destino sejam maiores que os da especificação (50 e 30,
 * respectivamente), a função não deve fazer a atribuição. Ok */
void passageiro_atribui(Passageiro *passageiro, int codigo, char *origem, char *destino);

/* Avalia se dois passageiros são iguas. A função deve retornar 1 se os passageiros
 * possuem os mesmos dados, 0 caso os dados dos passageiros possuam alguma diferença
 * e -1 caso pelo menos um dos passageiros seja NULL Ok.
 */
int passageiro_igual(Passageiro *passageiro1, Passageiro *passageiro2);

/* Retorna o tamanho em bytes do TAD aluno. Ok */
int passageiro_tamanho();

// *********************** FilaPassageiro.h ********************

struct no_passageiro* no_passageiro_cria(Passageiro* passageiro);

/* Aloca espaço em memória e retorna uma ListaPassageiro ok */
ListaPassageiro *fila_passageiro_cria();

/* Libera a memória de uma ListaPassageiro previamente criada e atribui NULL ao ponteiro
 * ListaPassageiro. Retorna 1 caso seja possível fazer a liberação e 0 caso a ListaPassageiro
 * informada seja NULL. ok */
int fila_passageiro_libera(ListaPassageiro **ListaPassageiro);

/* Insere um Passageiro na ListaPassageiro. Retorna 1 se foi possível adicionar, 0 caso já
 * exista um Passageiro com a mesma id (nesse caso, o Passageiro não pode ser
 * adicionado) e -1 caso a ListaPassageiro ou Passageiro sejam NULL ok
 */
int fila_passageiro_insere(ListaPassageiro *ListaPassageiro, Passageiro *Passageiro);

/* Remove um Passageiro na ListaPassageiro. Retorna o Passageiro ou NULL caso a ListaPassageiro esteja vazia ou
 * seja NULL ok */
Passageiro *fila_passageiro_retira(ListaPassageiro *ListaPassageiro);

/* Recupera o primeiro Passageiro da ListaPassageiro. Retorna o Passageiro ou NULL caso a ListaPassageiro esteja
 * vazia ou seja NULL */
Passageiro *fila_passageiro_primeiro(ListaPassageiro *ListaPassageiro);

/* Busca Passageiro pelo número de id. Retorna o Passageiro se este estiver na
 * lista e NULL caso contrário, isto é, (i) ListaPassageiro vazia; (ii) não exista Passageiro
 * com a id fornecida; ou (iii) a ListaPassageiro seja NULL ok */
Passageiro *fila_passageiro_busca(ListaPassageiro *ListaPassageiro, int id);

/* Verifica se a ListaPassageiro está vazia. Retorna 1 se a ListaPassageiro estiver vazia, 0 caso não
 * esteja vazia e -1 se a ListaPassageiro for NULL ok
 */
int fila_passageiro_vazia(ListaPassageiro *ListaPassageiro);


/* Computa a quantidade de Passageiros na fila. Retorna a quantidade de Passageiros
 * ou -1, caso a fila for NULL. ok 
 */
int fila_passageiro_quantidade(ListaPassageiro *fila);

//***************** Voo.h **************************
// verifica se algum dos valores na struct voo é nulo. Se sim, retorna -1. Se não, retorna 1
int voo_verifica(Voo *voo);

/* Aloca e retorna um Voo com os dados passados por parâmetro. Porém, para os
 * casos em que (i) pelo menos um dos parâmetros sejam nulos <-1, NULL, NULL>; e
 * (ii) o tamanho das strings origem e destino sejam maiores que os da especificação
 * (50 e 30, respectivamente), a função deve retornar NULL. Ok*/
Voo *voo_novo(int codigo, char *origem, char *destino);

/* Libera a memória de um Voo previamente criado e atribui NULL ao Voo. Ok*/
void voo_libera(Voo **Voo);

/* Copia os valores de um Voo para as referências informadas. Em caso de Voo
 * NULL, atribuir valor padrão <-1, "NULL", "NULL"> aos parâmetros. Ok */
void voo_acessa(Voo *Voo, int *codigo, char *origem, char *destino);

/* Atribui novos valores aos campos de um Voo. Porém, para os casos em que (i)
 * algum dos parâmetros sejam nulos <NULL, -1, NULL, NULL>; ou (ii) o tamanho
 * das strings origem e destino sejam maiores que os da especificação (50 e 30,
 * respectivamente), a função não deve fazer a atribuição. Ok */
void voo_atribui(Voo *Voo, int codigo, char *origem, char *destino);

/* Avalia se dois Voos são iguas. A função deve retornar 1 se os Voos
 * possuem os mesmos dados, 0 caso os dados dos Voos possuam alguma diferença
 * e -1 caso pelo menos um dos Voos seja NULL Ok.
 */
int voo_igual(Voo *Voo1, Voo *Voo2);

/* Retorna o tamanho em bytes do TAD aluno. Ok */
int voo_tamanho();

// ******************** FilaVoo.h **********************

struct no_voo* no_voo_cria(Voo* voo);

/* Aloca espaço em memória e retorna uma ListaVoo ok */
ListaVoo *fila_voo_cria();

/* Libera a memória de uma ListaVoo previamente criada e atribui NULL ao ponteiro
 * ListaVoo. Retorna 1 caso seja possível fazer a liberação e 0 caso a ListaVoo
 * informada seja NULL. ok */
int fila_voo_libera(ListaVoo **ListaVoo);

/* Insere um Voo na ListaVoo. Retorna 1 se foi possível adicionar, 0 caso já
 * exista um Voo com a mesma codigo (nesse caso, o Voo não pode ser
 * adicionado) e -1 caso a ListaVoo ou Voo sejam NULL ok
 */
int fila_voo_insere(ListaVoo *ListaVoo, Voo *voo);

/* Remove um Voo na ListaVoo. Retorna o Voo ou NULL caso a ListaVoo esteja vazia ou
 * seja NULL ok */
Voo *fila_voo_retira(ListaVoo *ListaVoo);

/* Recupera o primeiro Voo da ListaVoo. Retorna o Voo ou NULL caso a ListaVoo esteja
 * vazia ou seja NULL */
Voo *fila_voo_primeiro(ListaVoo *ListaVoo);

/* Busca Voo pelo número de codigo. Retorna o Voo se este estiver na
 * lista e NULL caso contrário, isto é, (i) ListaVoo vazia; (ii) não exista Voo
 * com a codigo fornecida; ou (iii) a ListaVoo seja NULL ok */
Voo *fila_voo_busca(ListaVoo *ListaVoo, int codigo);

/* Verifica se a ListaVoo está vazia. Retorna 1 se a ListaVoo estiver vazia, 0 caso não
 * esteja vazia e -1 se a ListaVoo for NULL ok
 */
int fila_voo_vazia(ListaVoo *ListaVoo);


/* Computa a quantidade de voos na fila. Retorna a quantidade de voos
 * ou -1, caso a fila for NULL. ok 
 */
int fila_voo_quantidade(ListaVoo *fila);



//****************** Reserva.h *********************

// verifica se algum dos valores na struct Reserva é nulo. Se sim, retorna -1. Se não, retorna 1
int reserva_verifica(Reserva *reserva);

/* Aloca e retorna um Reserva com os dados passados por parâmetro. Porém, para os
 * casos em que (i) pelo menos um dos parâmetros sejam nulos <-1, NULL, NULL>; e
 * (ii) a data seja inferior ao dia 01/12/2023, a função deve retornar NULL. */
Reserva *reserva_nova(int codigo, Data *data_viagem, Passageiro *passageiro, Voo *voo, Assento assento);

/* Libera a memória de uma Reserva previamente criada e atribui NULL a Reserva. */
int reserva_libera(Reserva **reserva);

/* Copia os valores de uma Reserva para as referências informadas. Em caso de Reserva
 * NULL, atribuir valor padrão <-1, "NULL", "NULL"> aos parâmetros. */
void reserva_acessa(Reserva *reserva, int *codigo, Data **origem, Passageiro **passageiro, Voo **voo, Assento *assento);

/* Atribui novos valores aos campos de uma Reserva. Porém, para os casos em que (i)
 * algum dos parâmetros sejam nulos <NULL, -1, NULL, NULL>; ou (ii) a data seja inferior a 01/12/2022, a função não deve fazer a atribuição. */
void reserva_atribui(Reserva *reserva, int codigo, Data *data_viagem, Passageiro *passageiro, Voo *voo, Assento assento);

/* Avalia se duas Reservas são iguais. A função deve retornar 1 se as Reservas
 * possuem os mesmos dados, 0 caso os dados dos Reservas possuam alguma diferença
 * e -1 caso pelo menos um dos Reservas seja NULL Ok.
 */
int reserva_igual(Reserva *Reserva1, Reserva *Reserva2);

/* Retorna o tamanho em bytes do TAD reserva.  */
int reserva_tamanho();



//******************************* ArvoreAgenda.h *********************
/* TAD: Agenda (Reserva *reserva, Agenda *esq, Agenda *dir) */


// ************** ArvoreReserva.h *******************
/* TAD: Agenda (Reserva *reserva, Agenda *esq, Agenda *dir) */

/* Aloca e retorna um No com os dados passados por parâmetro. Retorna no nó
 * criado ou NULL caso não seja posivel criar o nó. */
Agenda* criar_no_agenda(Data* chave, Reserva* conteudo);

// Função para atribuir NULO ao nó reserva. retorna 1 se conseguir liberar, e 0 caso contrário
int libera_no_agenda(Agenda* no);

/* Adiciona um nó à esquerda ou à direita do nó raiz. Retorna a raiz da árvore
 * resultante ou NULL caso (i) a raiz e o nó sejam NULL e (ii) caso o nó possua
 * mesma chave que outro nó previamente inserido na árvore. */
Agenda* insere_no_agenda (Agenda* raiz, Agenda* no);

/* Retorna o conteúdo do no ou NULL caso o nó seja NULL. */
Reserva* conteudo_agenda(Agenda* no);

/* Procura o nó pela chave. Retorna o nó caso a busca obtenha sucesso ou NULL em
 * caso contrário. */
Agenda *busca_agenda_codigo(Agenda *agenda_raiz, int codigo);

/* Procura o nó pela chave. Retorna o nó caso a busca obtenha sucesso ou NULL em
 * caso contrário. */
Agenda *abb_busca_agenda_passageiro_voo(Agenda *agenda_raiz, int id_passageiro, int codigo_voo);

/* Procura o nó pela chave. Retorna o nó caso a busca obtenha sucesso ou NULL em
 * caso contrário. */
Agenda *abb_busca_agenda_data_passageiro(Agenda *agenda_raiz, int id_passageiro, Data* data_viagem);

/* Remove o nó com a chave fornecida. Retorna a raiz da arvore atualizada ou
 * NULL em caso a raiz fornecida seja NULL. 
*/
Agenda* remove_no_agenda(Agenda* raiz, int codigo);

/* Retorna a altura da árvore ou -1 caso a raiz seja NULL. */
int abb_altura(Agenda *agenda);

/* Retorna o número de nós da árvore ou -1 caso araiz seja NULL. */
int abb_numero(Agenda *agenda);

/* Retorna a chave do nó ou NULL caso o nó seja NULL.  */
int chave_agenda(Agenda* no);

//Retorna o conteudo da reserva ou NULL caso a reserva seja NULL. *
Reserva* conteudo_agenda(Agenda *agenda);

Agenda *Sucessor(Agenda *agenda);

Agenda *Minimo (Agenda *agenda);

Viagem* lista_viagem_cria();

Reserva* lista_viagem_busca(Viagem* viagem, int codigo);

int lista_viagem_insere(Viagem* viagem, Reserva* reserva);

int lista_viagem_vazia(Viagem* viagem);

Trecho* lista_viagem_primeiro(Viagem* viagem);

Trecho* lista_viagem_retira(Viagem* viagem);

int lista_viagem_libera(Viagem** viagem);

/* Aloca e retorna um novo trecho que contém uma reserva e um ponteiro para o próximo trecho.
  (i) Se os campos passados como parametro forem NULL, a função retorna NULL;
*/
Trecho* novo_trecho(Reserva* reserva, Trecho* proximo_trecho);

// Libera o espaço de memória atribuído a um trecho e atribui NULL ao Trecho.
int trecho_libera(Trecho** trecho);

//Atribui aos campos os valores de reserva e proximo trecho armazenados no trecho.
int trecho_acessa(Trecho* trecho, Reserva* reserva, Trecho* proximo_trecho);

/* Atribui ao trecho passado como parâmetro os novos valores de reserva e proximo trecho.
   (i) Se os campos passados como parâmetro forem inválidos, as alterações não serão feitas.
   (ii) Se o trecho passado como parâmetro for NULL, as alterações não serão feitas.
*/
int trecho_atribui(Trecho* trecho, Reserva* nova_reserva, Trecho* novo_proximo_trecho);

/* Verifica se os trechos passados como parâmetros são iguais. Os trechos serão considerados iguais
   se e somente se as reservas e os proximos trechos forem iguais.
   (i) Se os trechos forem iguais, a função retorna 1.
   (ii) Se os trechos forem diferentes, a função retorna 0.
   (iii) Se um dos trechos for inválido ou NULL, a função retorna -1.
*/
int trecho_igual(Trecho* trecho1, Trecho* trecho2);

Trecho* trecho_cria(Reserva* reserva);

int trecho_valido(Trecho* trecho_origem, Trecho* trecho_destino);