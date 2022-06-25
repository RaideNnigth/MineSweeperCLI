/*
    Estrutura de dados da lista encadeada
    onde data são os highscores e o next é
    um ponteiro que aponta para o proximo node
*/
typedef struct linkedListNode {
    int data;
    struct linkedListNode *next;
}node;
/*
    Método que cria um node vazio apontando para
    o final, usado para retornar o head;
*/
node* createNode();
/*
    Método que adiciona um node a lista como se fosse
    uma pilha, recebe o Head da lista e um valor
    para adicionar como data no node
*/
void addNode(node *head, char value);
/*
    Método que cria um arquivo de texto
    chamado HighScore.txt caso não exista e o
    preenche com 3 valores de 100;
*/
void createHighScoreTxtFile();
/*
    Método que popula os dados da lista encadeada
    com os valores salvos no TXT, recebe como parametro
    o ínicio de uma lista encadeada.
*/
void createLinkedList(node *head);
/*
    Método que insere no final do txt em uma nova
    linha o valor inteiro enviado como parametro
*/
void appendHighScore(int value);
/*
    Método deleta um elemento especifico
    da lista encadeada, recebendo o node de inicio
    e o node a ser deletado
*/
void deleteElement(node *head, node *element);
/*
    Método que retorna o menor valor inteiro
    em uma lista encadeada, recebendo como parametro
    o primeiro ponteiro da mesma
*/
int organizeLinkedList(node *head);