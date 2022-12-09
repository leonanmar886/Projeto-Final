enum cod_assento {
    A0 = 1, B0, C0,
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

// Retorna apenas um inteiro para ser a chave da data;
int data_inteiro(Data* data);




// *********************** Passageiro.h ***********************




// Verifica se algum dos valores na struct passageiro é nulo. Se sim, retorna -1. Se não, retorna 1.
int passageiro_verifica(Passageiro *passageiro);

// Aloca e retorna um passageiro com os dados passados por parâmetro. Se algum dos parâmetros for nulo ou o tamanho das strings ultrapassar o tamanho limite, retorna NULL.
Passageiro *passageiro_novo(int codigo, char *nome, char *endereco);

// Libera a memória de um passageiro previamente criado e atribui NULL ao passageiro. Ok*/
void passageiro_libera(Passageiro **passageiro);

// Copia os valores de um passageiro para as referências informadas. Em caso de passageiro NULL, atribui valor padrão <-1, "NULL", "NULL"> aos parâmetros. Ok
void passageiro_acessa(Passageiro *passageiro, int *codigo, char *origem, char *destino);

// Atribui novos valores aos campos de um passageiro. Porém, para os casos em que algum dos parâmetros seja NULL ou as strings ultrapassem o tamanho limite, a função não faz a atribuição. Ok
void passageiro_atribui(Passageiro *passageiro, int codigo, char *origem, char *destino);

// Avalia se dois passageiros são iguas. A função retorna 1 se os passageiros possuem os mesmos dados, retorna 0 se os dados dos passageiros possuem alguma diferença e retorna -1 se pelo menos um dos passageiros seja NULL. Ok
int passageiro_igual(Passageiro *passageiro1, Passageiro *passageiro2);

// Retorna o tamanho em bytes do TAD aluno. Ok
int passageiro_tamanho();




// *********************** listaPassageiro.h ***********************




// Cria um nó do tipo No_Passageiro.
struct no_passageiro* no_passageiro_cria(Passageiro* passageiro);

// Aloca espaço em memória e retorna uma ListaPassageiro. ok
ListaPassageiro *lista_passageiro_cria();

// Libera a memória de uma ListaPassageiro criada anteriormente e atribui NULL ao ponteiro ListaPassageiro. Retorna 1 caso seja possível fazer a liberação e retorna 0 caso a ListaPassageiro informada seja NULL. ok
int lista_passageiro_libera(ListaPassageiro **ListaPassageiro);

// Insere um Passageiro na ListaPassageiro. Retorna 1 se foi possível adicionar, 0 caso já exista um Passageiro com o mesmo id (nesse caso, o Passageiro não será adicionado) e -1 caso a ListaPassageiro ou Passageiro sejam NULL. ok
int lista_passageiro_insere(ListaPassageiro *ListaPassageiro, Passageiro *Passageiro);

// Remove um Passageiro na ListaPassageiro. Retorna o Passageiro retirado ou NULL se a ListaPassageiro estiver vazia, ou seja, NULL. ok
Passageiro *lista_passageiro_retira(ListaPassageiro *ListaPassageiro, int id);

// Recupera o primeiro Passageiro da ListaPassageiro. Retorna o Passageiro ou NULL caso a ListaPassageiro esteja vazia ou seja NULL.
Passageiro *lista_passageiro_primeiro(ListaPassageiro *ListaPassageiro);

// Busca Passageiro pelo número de id. Retorna o Passageiro se este estiver na lista e NULL caso a lista seja vazia, não exista passageiro com o id fornecido ou a lista seja NULL.
Passageiro *lista_passageiro_busca(ListaPassageiro *ListaPassageiro, int id);

// Retorna 1 se a ListaPassageiro estiver vazia, 0 se não estiver e -1 se ela for NULL. ok
int lista_passageiro_vazia(ListaPassageiro *ListaPassageiro);




// *********************** Voo.h ***********************




// Verifica se algum dos valores na struct voo é incompatível. Se sim, retorna -1. Se não, retorna 1.
int voo_verifica(Voo *voo);

// Aloca e retorna um Voo com os dados passados por parâmetro. Se algum dos parâmetros for nulo ou o tamanho das strings ultrapassar o tamanho limite, retorna NULL. Ok
Voo *voo_novo(int codigo, char *origem, char *destino);

// Libera a memória de um Voo previamente criado e atribui NULL ao Voo. Ok
void voo_libera(Voo **Voo);

// Copia os valores de um Voo para as referências informadas. Em caso de Voo NULL, atribui valor padrão <-1, "NULL", "NULL"> aos parâmetros. Ok
void voo_acessa(Voo *Voo, int *codigo, char *origem, char *destino);

// Atribui novos valores aos campos de um Voo. Porém, para os casos em que algum dos parâmetros seja NULL ou as strings ultrapassem o tamanho limite, a função não deve fazer a atribuição. Ok
void voo_atribui(Voo *Voo, int codigo, char *origem, char *destino);

// Avalia se dois Voos são iguas. A função retorna 1 se os Voos possuem os mesmos dados, retorna 0 se os dados dos Voos possuem alguma diferença e retorna -1 se pelo menos um dos Voos seja NULL. Ok
int voo_igual(Voo *Voo1, Voo *Voo2);

// Retorna o tamanho em bytes do TAD Voo. Ok
int voo_tamanho();




// *********************** listaVoo.h ***********************




// Cria um nó do tipo. No_Voo
struct no_voo* no_voo_cria(Voo* voo);

// Aloca espaço em memória e retorna uma ListaVoo. ok
ListaVoo *lista_voo_cria();

// Libera a memória de uma ListaVoo previamente criada e atribui NULL ao ponteiro ListaVoo. Retorna 1 caso seja possível fazer a liberação e retorna 0 caso a ListaVoo informada seja NULL. ok
int lista_voo_libera(ListaVoo **ListaVoo);

// Insere um Voo na ListaVoo. Retorna 1 se foi possível adicionar, retorna 0 se já existe um Voo com o mesmo código (nesse caso, o Voo não pode ser adicionado) e retorna -1 caso a ListaVoo ou o Voo sejam NULL. ok
int lista_voo_insere(ListaVoo *ListaVoo, Voo *voo);

// Remove um Voo na ListaVoo. Retorna o Voo ou NULL caso a ListaVoo esteja vazia ou seja NULL ok
Voo *lista_voo_retira(ListaVoo *ListaVoo, int codigo);

// Recupera o primeiro Voo da ListaVoo. Retorna o Voo ou NULL caso a ListaVoo esteja vazia ou seja NULL
Voo *lista_voo_primeiro(ListaVoo *ListaVoo);

// Busca Voo pelo número de código. Retorna o Voo se este estiver na lista e NULL caso a lista seja vazia, não exista Voo com o código fornecido ou a lista seja NULL
Voo *lista_voo_busca(ListaVoo *ListaVoo, int codigo);

//Retorna 1 se a ListaVoo estiver vazia, 0 se não estiver e -1 se ela for NULL ok
int lista_voo_vazia(ListaVoo *ListaVoo);

// Computa a quantidade de voos na lista. Retorna a quantidade de voos ou -1, caso a lista seja NULL. ok 
int lista_voo_quantidade(ListaVoo *lista);




// *********************** Reserva.h ***********************




// Verifica se algum dos valores na struct Reserva é nulo. Se sim, retorna -1. Se não, retorna 1.
int reserva_verifica(Reserva *reserva, int codigo,Data *data,Passageiro *passageiro,Voo *voo, Assento assento);

// Aloca e retorna uma Reserva com os dados passados por parâmetro. Se algum dos parâmetros for nulo ou a data seja inferior ao dia 01/12/2023, retorna NULL Ok.
Reserva *reserva_nova(int codigo, Data *data_viagem, Passageiro *passageiro, Voo *voo, Assento assento);

// Libera a memória de uma Reserva previamente criada e atribui NULL a Reserva.
int reserva_libera(Reserva **reserva);

// Copia os valores de uma Reserva para as referências informadas. Em caso de Reserva NULL, atribui valor padrão <-1, "NULL", "NULL"> aos parâmetros.
void reserva_acessa(Reserva *reserva, int *codigo, Data **origem, Passageiro **passageiro, Voo **voo, Assento *assento);

// Atribui novos valores aos campos de uma Reserva. Porém, para os casos em que algum dos parâmetros seja NULL ou a data seja inferior a 01/12/2022, a função não deve fazer a atribuição.
void reserva_atribui(Reserva *reserva, int codigo, Data *data_viagem, Passageiro *passageiro, Voo *voo, Assento assento);

// Avalia se duas Reservas são iguais. A função deve retornar 1 se as Reservas possuem os mesmos dados, 0 caso os dados dos Reservas possuam alguma diferença e -1 caso pelo menos um dos Reservas seja NULL Ok.
int reserva_igual(Reserva *Reserva1, Reserva *Reserva2);

/* Retorna o tamanho em bytes do TAD reserva.  */
int reserva_tamanho();




//******************************* ArvoreAgenda.h *********************
/* TAD: Agenda (Reserva *reserva, Agenda *esq, Agenda *dir) */




// ************** ArvoreReserva.h *******************
/* TAD: Agenda (Reserva *reserva, Agenda *esq, Agenda *dir) */

// Aloca e retorna um No com os dados passados por parâmetro. Retorna o nó criado ou NULL caso não seja posivel criar o nó.
Agenda* criar_no_agenda(Data* chave, Reserva* conteudo);

// Função para atribuir NULL ao nó reserva. Retorna 1 se conseguir liberar e 0 caso contrário.
int libera_no_agenda(Agenda* no);

// Adiciona um nó à esquerda ou à direita do nó raiz. Retorna a raiz da árvore resultante ou NULL caso a raiz ou o nó sejam NULL ou o nó possua a mesma chave que outro nó previamente inserido na árvore.
Agenda* insere_no_agenda (Agenda* raiz, Agenda* no);

// Retorna o conteúdo do nó ou NULL caso o nó seja NULL.
Reserva* conteudo_agenda(Agenda* no);

// Procura a reserva na agenda através do código. Retorna o nó caso a busca obtenha sucesso ou NULL caso contrário.
Agenda *busca_agenda_codigo(Agenda *agenda_raiz, int codigo);

// Procura a reserva do passageiro pelo id deste e pelo código do voo passados por parâmetro. Retorna o nó caso a busca obtenha sucesso ou NULL caso contrário.
Agenda *abb_busca_agenda_passageiro_voo(Agenda *agenda_raiz, int id_passageiro, int codigo_voo);

// Procura o nó pela chave. Retorna o nó caso a busca obtenha sucesso ou NULL em caso contrário.
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

/* Retorna o sucessor do nó */
Agenda *Sucessor(Agenda *agenda);

/* Retorna nó mínimo da agenda */
Agenda *Minimo (Agenda *agenda);

/* Aloca espaço em memória e retorna uma ListaPassageiro */
Viagem* lista_viagem_cria();

/* Busca Voo pelo número de codigo. Retorna o Voo se este estiver na
 * lista e NULL caso contrário, isto é, (i) ListaVoo vazia; (ii) não exista Voo
 * com a codigo fornecida; ou (iii) a ListaVoo seja NULL ok */
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

int eh_primo(int valor);

TabelaViagem* cria_hash(int tamanho);

void inicializar_hash(TabelaViagem* tabela);

int codigo_hash(Viagem* viagem);

int funcaoHash(TabelaViagem* tabela, int codigoHash);

int inserir_hash(TabelaViagem* tabela, Viagem* viagem);

Viagem* busca_hash(TabelaViagem* tabela, int indice);

Viagem* retira_hash(TabelaViagem* tabela, int indice);

int libera_hash(TabelaViagem** tabela);

void imprimir_viagem(TabelaViagem* tabela, int indice);

int tamanho_hash(TabelaViagem* tabela);

Viagem* ponteiro_hash(TabelaViagem* tabela);

int viagem_igual(Viagem* viagem1, Viagem* viagem2);