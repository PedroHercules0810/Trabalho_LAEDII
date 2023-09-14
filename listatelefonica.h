#include"listatelefonica.cpp"
struct contato *criaContato(char *nome, char *tel, char *email);
int concatenacao(char c[]);
int funHashDiv(int key);
int funcHashMult(int key);
typedef struct lista *agendaDeContatos[size];
void iniciarAgenda(agendaDeContatos Hash);
int inserir(agendaDeContatos Hash, struct contato *c);