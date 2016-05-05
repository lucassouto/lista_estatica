//protótipos das funções
//os tipos de dados armazenados na lista
//os ponteiros
//tamanho do vetor utilizado
#define MAX 100

typedef struct aluno{
    int matricula;
    char nome[50];
    float n1,n2,n3;
}Aluno;

typedef struct lista Lista;

Lista* cria_Lista();
void libera_lista(Lista* li);
struct aluno cadastro(Lista* li);
int tam_Lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
int insere_final(Lista* li, struct aluno elemento);
int insere_inicio(Lista* li, struct aluno elemento);
int insere_ordenado(Lista* li, struct aluno elemento);
int remove_final(Lista* li);
int remove_inicio(Lista* li);
int remove_lista(Lista* li, int mat);
int consulta_lista_pos(Lista* li, int pos, struct aluno *elemento);
int consulta_lista_mat(Lista* li, int mat, struct aluno *elemento);
void escolha(Lista* li, int opcao);
void menu(Lista* li);
void exibirCadastro(struct aluno elemento);
struct aluno cadastro(Lista* li);
int arquivo_binario(Lista* li, struct aluno elemento);
