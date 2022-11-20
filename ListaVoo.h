typedef struct no_voo No_Voo;
typedef struct lista_voo Lista;

// cria uma lista encadeada de voos
Lista *cria_lista();

// libera uma lista existente e retorna 1 se foi possível e -1 se não foi possível
int libera_lista(Lista **lista);

// busca um voo pelo seu código na lista de voos, retorna NULL se a lista for vazia
// ou se o voo não existir
Lista* buscar_lista(Lista *lista, int codigo);

//insere na lista um voo, retorna -1 se se a lista ou o voo forem nulos
//retorna 0 se esse voo já estiver na lista
//retorna 1 se for possível inserir esse voo na lista
int inserir_lista(Lista *lista, Voo *voo);

//remove um voo da lista, retorna o voo removido ou NULL se a lista for nula ou vazia
Voo* lista_remove(Lista* lista);