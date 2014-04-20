typedef struct Celula {
    int conteudo;
    struct Celula *prox;
} Celula;

void imprime(Celula *ini);
