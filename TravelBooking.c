#include "TravelBooking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
  int dia;
  int mes;
  int ano;
};

struct voo {
  int codigo;
  char origem[100];
  char destino[100];
};

struct no_voo {
  Voo *voo;
  struct no_voo *proximo;
};

struct lista_voo {
  struct no_voo *primeiro;
};

struct passageiro {
  int id;
  char nome[100];
  char endereco[100];
};

struct no_passageiro {
  Passageiro *passageiro;
  struct no_passageiro *proximo;
};

struct lista_passageiro {
  struct no_passageiro *primeiro;
};

struct reserva {
  int codigo;
  Data *data_viagem;
  Passageiro *passageiro;
  Voo *voo;
  Assento assento;
};

struct agenda {
  Data* data;
  Reserva *reserva;
  Agenda *esq;
  Agenda *dir;
  Agenda *pai;
};

struct trecho {
  Reserva *reserva;
  struct trecho *proximo;
};

struct viagem {
  struct trecho *primeiro_trecho;
};



struct tabela_viagem {
  int tamanho;
  //Viagem *tabela_hash;
  Viagem* t[];
};

int data_tamanho(){return sizeof(Data);}
int assento_tamanho(){return sizeof(Assento);}

Data* data_nova(int dia, int mes, int ano){
  if(dia > 0 && dia <= 30 && mes > 0 && mes <= 12 && ano > 0 && ano <= 9999){
    Data *data = (Data*) malloc(sizeof(Data));
    data -> dia = dia;
    data -> mes = mes;
    data -> ano = ano; 
    return data;
  }
  else{
    return NULL;
  }
}
void printa_data(Data* data){
  int dia,mes,ano;
  dia = data->dia;
  mes = data->mes;
  ano = data->ano;
  
  printf("Data da viagem: d%d/%d/%d\n",dia,mes,ano);
}
// Retorna apenas um inteiro para ser a chave da data;
int data_inteiro(Data* data){

  int aux = data->dia + ((data->mes)*30) + ((data->ano)*365);

  return aux;
}

// ************** Passageiro.c ***********
int verifica_params_passageiro(int id, char *nome, char *endereco) {
  if (id < 1 || nome == NULL || endereco == NULL) {
    return -1;
  }

  if (strlen(nome) > 100 || strlen(endereco) > 100) {
    return -1;
  }

  return 1;
}

Passageiro *passageiro_novo(int id, char *nome, char *endereco) {
  if (verifica_params_passageiro(id, nome, endereco) == -1) {
    return NULL;
  }
  if (strcmp(nome, endereco) == 0){
    return NULL;
  }
  Passageiro *novo_Passageiro = (Passageiro*)malloc(sizeof(Passageiro));
  novo_Passageiro->id = id;
  strcpy(novo_Passageiro->nome, nome);
  strcpy(novo_Passageiro->endereco, endereco);

  return novo_Passageiro;
}

int passageiro_verifica(Passageiro *Passageiro) {
  int id_aux;
  char nome_aux[100];
  char endereco_aux[150];
  
  passageiro_acessa(Passageiro, &(id_aux), nome_aux, endereco_aux);
  if (id_aux < 0 || strlen(nome_aux)>100 || strlen(endereco_aux)>150 ) {
    return -1;
  }
  else {
    return 1;
  }
}

void passageiro_libera(Passageiro **Passageiro) {
  if(Passageiro != NULL){
    free(*Passageiro);
    *Passageiro = NULL;   
  } 
}
  
  
void passageiro_acessa(Passageiro *Passageiro, int *id, char *nome, char *endereco) {
  if(Passageiro == NULL){
    *id = -1;
    strcpy(nome, "NULL");
    strcpy(endereco, "NULL");  
  }
  else {
    *id = Passageiro->id;
    strcpy(nome, Passageiro->nome);
    strcpy(endereco, Passageiro->endereco);
  }
}

void passageiro_atribui(Passageiro *passageiro, int id, char *nome, char *endereco) {
  if (passageiro != NULL && verifica_params_passageiro(id, nome, endereco) == 1) {
    passageiro->id = id;
    strcpy(passageiro->nome, nome);
    strcpy(passageiro->endereco, endereco);
  }  
}

int passageiro_igual(Passageiro *Passageiro1, Passageiro *Passageiro2){
  if (Passageiro1 == NULL || Passageiro2 == NULL) {
    return -1;
  }

  if (Passageiro1->id != Passageiro2->id) {
    return 0;
  }

  if (strcmp(Passageiro1->nome, Passageiro2->nome) != 0) {
    return 0;
  }

  if (strcmp(Passageiro1->endereco, Passageiro2->endereco) != 0) {
    return 0;
  }

  return 1;
}

int passageiro_tamanho(){
  return sizeof(Passageiro);
}

// ******************* FilaPassageiro.c ****************

typedef struct no_passageiro No_Passageiro;

No_Passageiro* no_passageiro_cria(Passageiro* passageiro){
    No_Passageiro* novo =(No_Passageiro*) malloc(sizeof(No_Passageiro));
    novo->passageiro = passageiro;
    novo->proximo = NULL;
}

ListaPassageiro* fila_passageiro_cria(){
  ListaPassageiro* nova_lista = (ListaPassageiro *)malloc(sizeof(ListaPassageiro));
   nova_lista->primeiro = NULL;
  return nova_lista;
  
}

int fila_passageiro_libera(ListaPassageiro **lista){
  if(lista != NULL){
    if((*lista)->primeiro != NULL){
      No_Passageiro* aux = (*lista)->primeiro;
      do{
        passageiro_libera(&aux->passageiro);
        aux = aux->proximo;
      } while(aux != NULL);
    }
    free(*lista);
    *lista = NULL;
    return 1;
  }
  return 0;
}

Passageiro* fila_passageiro_busca(ListaPassageiro* lista, int id){
  if (lista!=NULL && lista->primeiro!=NULL){
    
    
 No_Passageiro* x = lista->primeiro;
  
  int id_aux;
  char nome[100];
  char end[150];
  do{
passageiro_acessa(x->passageiro,&id_aux,nome,end);
  if(id == id_aux){
      return x->passageiro;
    }
    x =  x->proximo;
    } while(x!=NULL ) ;
    }
  return NULL;
}

int fila_passageiro_insere(ListaPassageiro* lista, Passageiro* passa){
  if(lista == NULL || passa == NULL){
    return -1;
  }
  
  if(lista->primeiro != NULL){
    int id;
    char nome[50];
    char end[100];
    passageiro_acessa(passa, &id, nome, end);
    Passageiro *aux = fila_passageiro_busca(lista, id);
    if(aux != NULL){
      return 0;
    }
    No_Passageiro* ultimo = lista->primeiro;
    while(ultimo->proximo != NULL){
      ultimo = ultimo->proximo;
    }
    No_Passageiro* novo = no_passageiro_cria(passa);
    ultimo->proximo = novo;
    return 1;
    
  }
  else if (lista->primeiro == NULL){
    No_Passageiro* novo = no_passageiro_cria(passa);
    lista->primeiro = novo;
    return 1;
  }
  
}
//
Passageiro* fila_passageiro_retira(ListaPassageiro* lista){
  if(lista == NULL ||lista->primeiro == NULL){
    return NULL;
  }
  Passageiro* viajante = lista->primeiro->passageiro;
  lista->primeiro = lista->primeiro->proximo;
  return viajante;
}
// Retorna -1 se a lista for nulo, retorna 1 se a lista for vazia, e retorna
// 0 caso contrário
int fila_passageiro_vazia(ListaPassageiro* lista){
  if (lista==NULL){
    return -1;
  }
  if (lista->primeiro==NULL){
    return 1;
  }
  return 0;
}

Passageiro* fila_passageiro_primeiro(ListaPassageiro* lista){
  if(lista == NULL || lista->primeiro->passageiro ==NULL){
    return NULL;
  }
  return lista->primeiro->passageiro;
}

// ***************** Voo.c ***************

int verifica_params_voo(int codigo, char *origem, char *destino) {
  if (codigo < 0 || origem == NULL || destino == NULL) {
    return -1;
  }

  if (strlen(origem) > 100 || strlen(destino) > 100) {
    return -1;
  }
  return 1;
}

Voo *voo_novo(int codigo, char *origem, char *destino) {
  if (verifica_params_voo(codigo, origem, destino) == -1) {
    return NULL;
  }
  if (strcmp(origem, destino) == 0){
    return NULL;
  }
  Voo *novo_voo = (Voo*)malloc(sizeof(Voo));
  novo_voo->codigo = codigo;
  strcpy(novo_voo->origem, origem);
  strcpy(novo_voo->destino, destino);
  return novo_voo;
}

int voo_verifica(Voo *voo) {
  int codigo_aux;
  char origem_aux[100];
  char destino_aux[150];
  
  voo_acessa(voo, &(codigo_aux), origem_aux, destino_aux);
  if (codigo_aux < 0 || strlen(origem_aux)>100 || strlen(destino_aux)>150 ) {
    return -1;
  }
  else {
    return 1;
  }
}

void voo_libera(Voo **voo) {
  if(voo != NULL){
    free(*voo);
    *voo = NULL;   
  } 
}
  
  
void voo_acessa(Voo *voo, int *codigo, char *origem, char *destino) {
  if(voo == NULL){
    *codigo = -1;
    strcpy(origem, "NULL");
    strcpy(destino, "NULL");  
  }
  else {
    *codigo = voo->codigo;
    strcpy(origem, voo->origem);
    strcpy(destino, voo->destino);
  }
}

void voo_atribui(Voo *voo, int codigo, char *origem, char *destino) {
  if (voo != NULL && verifica_params_voo(codigo, origem, destino) == 1) {
    voo->codigo = codigo;
    strcpy(voo->origem, origem);
    strcpy(voo->destino, destino);
  }  
}

int voo_igual(Voo *Voo1, Voo *Voo2){
  if (Voo1 == NULL || Voo2 == NULL) {
    return -1;
  }

  if (Voo1->codigo != Voo2->codigo) {
    return 0;
  }

  if (strcmp(Voo1->origem, Voo2->origem) != 0) {
    return 0;
  }

  if (strcmp(Voo1->destino, Voo2->destino) != 0) {
    return 0;
  }

  return 1;
}

int voo_tamanho(){
  return sizeof(Voo);
}

// ********************* FilaVoo.c

typedef struct no_voo No_Voo;

No_Voo* no_voo_cria(Voo* voo){
  No_Voo* novo = (No_Voo *)malloc(sizeof(No_Voo));
  novo->voo = voo;
  novo->proximo = NULL;
  return novo;
}

ListaVoo* fila_voo_cria() {
  ListaVoo *nova_lista = (ListaVoo *) malloc(sizeof(ListaVoo));
  nova_lista->primeiro = NULL;
  return nova_lista;
}

int fila_voo_libera(ListaVoo **lista) {
  if (lista != NULL) {
    free(*lista);
    *lista = NULL;
    return 1;
  }
  return 0;
}


Voo* fila_voo_busca(ListaVoo *lista, int codigo) {
  if(lista == NULL || lista->primeiro == NULL) {
    return NULL;
  }
  No_Voo *x = lista->primeiro;
  int codigo_aux;
  char origem[100];
  char destino[100];

  while(x != NULL){
    voo_acessa(x->voo, &codigo_aux, origem, destino);
    if(codigo_aux == codigo){
      return x->voo;
    }
    x =  x->proximo;
    }
  
  return NULL;
}

int fila_voo_insere(ListaVoo *lista, Voo *voo){
  if(lista == NULL || voo == NULL){
    return -1;
  }

  if(lista->primeiro != NULL){
    int codigo;
    char origem[100];
    char destino[100];
    voo_acessa(voo, &codigo, origem, destino);
    Voo *aux = fila_voo_busca(lista, codigo);
    if(aux != NULL){
      return 0;
    }
    No_Voo* ultimo = lista->primeiro;
    while (ultimo->proximo != NULL){
      ultimo = ultimo->proximo;
    }
    No_Voo* novo = no_voo_cria(voo);
    ultimo->proximo = novo;
    return 1;    
  }
  else if (lista->primeiro == NULL){
    No_Voo* novo = no_voo_cria(voo);
    lista->primeiro = novo;
    return 1;
  }
}


Voo* fila_voo_retira(ListaVoo* lista){
  if(lista == NULL || lista->primeiro == NULL){
    return NULL;
  }
  Voo* voo = lista->primeiro->voo;
  lista->primeiro = lista->primeiro->proximo;
  return voo;
}

Voo *fila_voo_primeiro(ListaVoo *fila) {
  if (fila_voo_vazia(fila) || fila == NULL){
    return NULL;
  }
  Voo* ptr_1st_voo = fila->primeiro->voo; //testars
  return ptr_1st_voo;
}

int fila_voo_vazia(ListaVoo *fila){
  if (fila == NULL){
    return -1;
  }
  if ((fila -> primeiro) == NULL){
    return 1;  
  }
  else{
    return 0;
  }
  }

int fila_voo_quantidade(ListaVoo *fila) {
    if (fila == NULL){
      return -1;
    }
    else{
      int tamanho = 0;
      No_Voo* aux = fila->primeiro;
      while (aux != NULL){
        aux = aux -> proximo;
        tamanho ++;
      }
      return tamanho;
    }
}

// ******************* Reserva.c ********************

#define TRUE 1
#define FALSE 0  


Reserva *reserva_nova(int codigo, Data *data, Passageiro *passageiro, Voo *voo, Assento assento){
  if (codigo > 0 && data != NULL && passageiro != NULL && voo != NULL){
  Reserva* reserva  = (Reserva*)malloc(sizeof(Reserva));
  reserva->data_viagem  = data;
  reserva->assento = assento;
  reserva->codigo = codigo;
  reserva->passageiro = passageiro;
  reserva->voo = voo; 
    

  return reserva;
  }
  else{
    return NULL;
  }
}

// Função para atribuir NULO à reserva. retorna 1 se conseguir liberar, e 0 caso contrário
int reserva_libera(Reserva** reserva){
  if(reserva==NULL){return 0;}
  
  
    free(*reserva);
    *reserva = NULL;
    
  
  
  return 1;
}
int verifica_reserva(Reserva *reserva,int codigo,Data *data,Passageiro *passageiro,Voo *voo, Assento assento){ // corrigir a função
  if(codigo<1 || data == NULL || passageiro == NULL || voo == NULL || assento< 0 )
  {
    return -1;
  }
  return 1;
}

void reserva_acessa(Reserva *reserva, int *codigo, Data **data, Passageiro **passageiro, Voo **voo, Assento *assento){
  if (reserva == NULL && verifica_reserva(reserva, reserva->codigo, reserva->data_viagem, reserva->passageiro, reserva->voo, reserva->assento)){ // corrigir
    *codigo = -1;
    *data = NULL;
    *passageiro = NULL;
    *voo = NULL;
    *assento = -1;
    
}
  else{
    *codigo = reserva->codigo;
    *data = reserva->data_viagem;
    *passageiro = reserva->passageiro;
    *voo = reserva->voo;
    *assento = reserva->assento;
      
  }
}

int reserva_igual(Reserva *Reserva1, Reserva *Reserva2){
  if (Reserva1 == NULL || Reserva2 == NULL){
    return -1;
  }
  if (Reserva1 -> codigo == Reserva2 -> codigo && data_inteiro(Reserva1->data_viagem) == data_inteiro(Reserva2->data_viagem) && passageiro_igual(Reserva1 -> passageiro, Reserva2->passageiro) == 1 && voo_igual(Reserva1 -> voo, Reserva2 ->voo) == 1 && Reserva1 -> assento == Reserva2 ->assento){
    return 1;
  }
    return 0;

}

int reserva_tamanho() {
  return sizeof(Reserva);
}

void reserva_atribui(Reserva *reserva, int codigo, Data *data_viagem, Passageiro *passageiro, Voo *voo, Assento assento) {
  if (reserva!=NULL && verifica_reserva(reserva, codigo, data_viagem, passageiro, voo, assento)==1) {
    if ((data_viagem->ano)>=2023 && (data_viagem->mes)>=1 && (data_viagem->dia)>=1) {
      reserva->codigo = codigo;
      reserva->data_viagem = data_viagem;
      reserva->passageiro = passageiro;
      reserva->voo = voo;
      reserva->assento = assento;
    }
  }
}

// reserva->data_viagem será a chave,a struct reserva será o conteudo
/* Aloca e retorna um No com os dados passados por parâmetro. Retorna no nó
 * criado ou NULL caso não seja posivel criar o nó. */
Agenda* criar_no_agenda(Data* chave, Reserva* conteudo) {
  Agenda* no_agenda;
  
  if(chave!= NULL && conteudo!= NULL){
   no_agenda =(Agenda*)malloc(sizeof(Agenda));
    }
  else{
    return NULL;
  }
  no_agenda->data = chave;
  no_agenda->reserva = conteudo;
  no_agenda->esq = NULL;
  no_agenda->dir = NULL;
  

  return no_agenda;
  
}


// Função para atribuir NULO ao nó reserva. retorna 1 se conseguir liberar, e 0 caso contrário
int libera_no_agenda(Agenda* no){
  if( no==NULL) return 0;
  
  if(no!=NULL){
    libera_no_agenda(no->esq);
    libera_no_agenda(no->dir);
    free(no);
  }
  
  return 1;
}

/* Retorna a chave do nó ou 0 caso o nó seja NULL.  */
int chave_agenda(Agenda* no){
  if(no==NULL) {
    return 0;
  }
  return data_inteiro(no->data);
}

/* Retorna o conteúdo do no ou NULL caso o nó seja NULL. */
Reserva* conteudo_agenda(Agenda* no){
  if(no==NULL) return NULL;
  return no->reserva;
  
}

/* Adiciona um nó à esquerda ou à direita do nó raiz. Retorna a raiz da árvore
 * resultante ou NULL caso (i) a raiz e o nó sejam NULL e (ii) caso o nó possua
 * mesma chave que outro nó previamente inserido na árvore. */

Agenda* insere_no_agenda (Agenda* raiz, Agenda* no){
  if(raiz == NULL || no == NULL) return NULL;

  Agenda* x = raiz;
  Agenda* y = NULL;



  int chave_x = data_inteiro(x->reserva->data_viagem);
  int chave_no = data_inteiro(no->reserva->data_viagem);
  while(x != NULL){
    y = x;
    if(chave_no < chave_x){
      x = x->esq;
    } else if (chave_no > chave_x){
      x = x->dir;      
    } 
     // Caso seja a mesma reserva (sem datas ou codigos diferentes) ou apenas o codigo da reserva seja igual 
    else if(reserva_igual(no->reserva,x->reserva) == 1 || no->reserva->codigo == x->reserva->codigo){
      return NULL;
    }
    else{// caso os nós possuam a mesma chave 
      x = x->esq;
    }
  }

  int chave_y = data_inteiro(y->reserva->data_viagem);
  no->pai = y;
  if(y == NULL){
    raiz = no;
  } else if(chave_no < chave_y){
    y->esq = no;
  } else{
    y->dir = no;
  }
  return raiz;
  
}

/* Retorna a altura da árvore ou -1 caso a raiz seja NULL. */
int abb_altura(Agenda* raiz){
 if(raiz == NULL){
   return -1;
 }
  else{
    int aux1, aux2;
    aux1 = abb_altura(raiz->esq);
    aux2 = abb_altura(raiz->dir);
    if(aux1 >= aux2){
      return aux1+1;
    }
    else{
      return aux2 +1;
    }
  }
}

Agenda* Minimo( Agenda* no){
  if( no == NULL) return NULL;
  
  while( no->esq != NULL){
    no = no->esq;
  }
 return no;
}
Agenda* Sucessor(Agenda* no){
  if(no == NULL) return NULL;
  
  if(no->dir != NULL){
    return Minimo(no->dir);
  }
  Agenda* y = no->pai;
  while( y != NULL && no == y->dir){ //para subir na árvore
    no = y;
    y = no->pai;
  }
  return y;
}

// Substitui a árvore enraizada em u pela árvore enraizada em v
void Transplantar (Agenda* u, Agenda* v, Agenda* raiz){
  if(u->pai == NULL){
    raiz = v;
  }
  else if( u == u->pai->esq){
    u->pai->esq = v;
  }
  else{
    u->pai->dir = v;
  }
  if( v!= NULL){
    v->pai = u->pai;
  }
}

Agenda *busca_agenda_codigo(Agenda *raiz, int codigo){
  int aux;
  if(raiz!= NULL){
   aux = raiz->reserva->codigo;   
     }
if(raiz ==NULL || codigo == aux){
     return raiz;
   }
  
   if(raiz!= NULL){  
   return busca_agenda_codigo(raiz->esq, codigo);   
    return busca_agenda_codigo(raiz->dir, codigo); 
     }

}


/* Remove o nó com a chave fornecida. Retorna a raiz da arvore atualizada ou
 * NULL em caso a raiz fornecida seja NULL. 
*/
Agenda* remove_no_agenda(Agenda* raiz, int codigo){
  if(raiz == NULL) return NULL;

  Agenda* no = busca_agenda_codigo(raiz,  codigo);
  if(no->esq == NULL){
    Transplantar(no, no->dir, raiz);
  }
  else if(no->dir == NULL){
    Transplantar(no, no->esq, raiz);
  }
  else{
      Agenda* y = Sucessor(no);
      Transplantar(y, y->dir, raiz);
      y->esq = no->esq;
      no->pai->esq = y;
      y->dir = no->dir;
    if(no->dir != NULL){
      no->pai->dir = y;
    }
    Transplantar(no, y, raiz);
  }
return raiz;
}

/* Retorna o número de nós da árvore ou -1 caso a raiz seja NULL. */
int abb_numero(Agenda* raiz){
  if(raiz == NULL ) return -1;
  int aux = 1;

  if(raiz != NULL){
    if(abb_numero(raiz->esq) != -1){
      aux = aux+ abb_numero(raiz->esq);
    }
     if(abb_numero(raiz->dir) != -1){
      aux = aux+ abb_numero(raiz->dir);
    }
  }
  return aux;
}

Agenda *abb_busca_agenda_passageiro_voo(Agenda *raiz, int id_passageiro, int codigo_voo){
  int aux1, aux2;
   if (raiz!= NULL){
   aux1 = raiz->reserva->passageiro->id;
   aux2 = raiz->reserva->voo->codigo;
  }
    if(raiz == NULL || aux1 == id_passageiro && aux2 == codigo_voo){
      return raiz;
    }
    if(raiz != NULL){
  return abb_busca_agenda_passageiro_voo(raiz->esq, id_passageiro, codigo_voo );
  
    return abb_busca_agenda_passageiro_voo(raiz->dir, id_passageiro, codigo_voo );
      }

}
  
Agenda *abb_busca_agenda_data_passageiro(Agenda *raiz, int id_, Data* data){
 int aux2;
  int aux1 = data_inteiro(data);
  if(raiz!= NULL){
   aux2 = data_inteiro(raiz->reserva->data_viagem);
    }
  
  if(raiz == NULL ||(raiz->reserva->passageiro->id == id_ && aux2 == aux1)){
    return raiz;
  }
  if (aux1 < aux2){
    return abb_busca_agenda_data_passageiro(raiz->esq, id_, data);
  }
 return abb_busca_agenda_data_passageiro(raiz->dir, id_, data);
}


// *************************** Tabela Hash ******************************

int eh_primo(int valor){
  int i = 2;
  int x;
  while(i <= valor-1){
    x = valor%i;
   if(x==0){
     return 0;
   }
    i++;
  }
  return 1;
}
TabelaViagem* cria_hash(int size){
  
  TabelaViagem* novo_hash = (TabelaViagem*)malloc(sizeof(TabelaViagem));
  novo_hash->t[0] = NULL;
  //novo_hash->tabela_hash = NULL;
  novo_hash->tamanho = size; 
  return novo_hash;
}


void inicializar_tabela( Viagem* roteiros[], TabelaViagem* tabela){
  int size  = (tabela->tamanho*2)+1;
  while(eh_primo(size) == 0){
    size++;
  }
  tabela->tamanho = size;
 
  for(int i=0;i < tabela->tamanho; i++){
    roteiros[i] = NULL;
  }
  tabela->t[0] = roteiros[0]; 
}

int codigo_hash(Viagem* lista){

  int soma = 0; 
  Trecho* aux = lista->primeiro_trecho;
  
  while(aux->proximo!=NULL){
    soma+=aux->reserva->codigo;
    aux = aux->proximo;
  }
  soma += aux->reserva->passageiro->id;
  
  return soma;
}

int funcaoHash(int codigoHash, TabelaViagem* tabela){  
  return codigoHash % tabela->tamanho;
}

int inserir_tabela( Viagem* roteiros[],Viagem* viagem, TabelaViagem* tabela){
  int id = funcaoHash(codigo_hash(viagem),tabela);
  
  if(roteiros[id] == NULL){// insere apenas quando nulo para não haver colisão
   roteiros[id] = viagem;
   tabela->t[id] = roteiros[id];
   return 1;
    }  
  return 0;
}
Viagem* busca_tabela(Viagem* roteiros[], Viagem* viagem, TabelaViagem* tabela){
  int id = funcaoHash(codigo_hash(viagem),tabela);
  if(roteiros[id]!= NULL){
    if(roteiros[id] == viagem ){
      return viagem;
    }
  }
  return NULL;
}

// retira um roteiro de viagem da Tabela e atribui NULL, retorna NULL caso já for NULL
//, e o roteiro caso contrário

Viagem* retira_hash(Viagem* roteiros[],TabelaViagem* tabela, Viagem* viagem ){
  int id = funcaoHash(codigo_hash(viagem),tabela);
   Viagem* aux[tabela->tamanho];
  if(roteiros[id] == NULL){
    return NULL;
  } 
  else{
    
   aux[id] = roteiros[id];
    roteiros[id] = NULL;
  }
  return aux[id];
}

//
int libera_hash(TabelaViagem** tabela){
  if(tabela == NULL) return 0;
  
  free(*tabela);
  *tabela = NULL;
  return 1;
}

void imprimir_viagem(Viagem* roteiros[],TabelaViagem* tabela, Viagem* viagem){
  int id = funcaoHash(codigo_hash(viagem),tabela);
   
  Trecho* aux = roteiros[id]->primeiro_trecho ;
  
  printf("\tINTINERÁRIO DA VIAGEM:\n");
  while(aux!=NULL){
   printf("**************************************\n");
   printf("Codigo da reserva: %d\n", aux->reserva->codigo);
   printa_data(aux->reserva->data_viagem);
   printf("Codigo do Voo: %d\n",aux->reserva->voo->codigo);
   printf("Assento do Voo:%d\n",aux->reserva->assento);
    
    aux = aux->proximo;
  }
}
