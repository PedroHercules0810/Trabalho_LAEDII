#define SIZE 32
typedef struct lista *agendaDeContatos[SIZE];

struct contato *criaContato(char *nome, char *tel, char *email);

void iniciarAgenda(agendaDeContatos Hash);

int inserir(agendaDeContatos Hash, struct contato *c);

struct contato *buscarContato(agendaDeContatos Hash, struct contato *c);

int removerContato(agendaDeContatos Hash, struct contato *c);

void exportarContatos(agendaDeContatos Hash);

void listarContatos(agendaDeContatos Hash);
