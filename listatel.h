<<<<<<< HEAD
#define SIZE 32
typedef struct lista *agendaDeContatos[SIZE];

struct contato *criaContato(char *nome, char *tel, char *email);

void iniciarAgenda(agendaDeContatos Hash);

int inserir(agendaDeContatos Hash, struct contato *c);

struct contato *buscarContato(agendaDeContatos Hash, struct contato *c);

int removerContato(agendaDeContatos Hash, struct contato *c);

void exportarContatos(agendaDeContatos Hash);

void listarContatos(agendaDeContatos Hash);
=======
typedef struct contato Contato;
typedef struct lista Lista;
int dobra_binaria(char *chave);
Contato * insere_contato(Lista * l,Contato * c, char * nome, char * tel, char * email);
>>>>>>> bffd035c24af7b59a18ec54c7b9ef16b214d8048
