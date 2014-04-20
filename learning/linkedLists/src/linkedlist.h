typedef struct Celula {
    int conteudo;
    struct Celula *prox;
} Celula;

void imprime(Celula *ini);
Celula *busca(int x, Celula *ini);
Celula *busca_r(int x, Celula *ini);
Celula *create_cel(int conteudo);
Celula *insere(Celula *atual, Celula *cel);
int get_list_size(Celula *lista);
void remove_from_list(Celula *p);
