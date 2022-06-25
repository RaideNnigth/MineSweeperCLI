#ifndef interfaceHandler
#define interfaceHandler
/*
    Estrutura que representa as propriedades do Menu 
    principal e armazena a qual elemento deve ser
    visualizado
*/
typedef struct menuHandler
{
    int currentState;
    int menuPosition;
}menuHandler;
/*
    Estrutura representativa das propriedades da view
    do mineField, salva também o número de tentativas
*/
typedef struct gameDisplayHandler
{
    int currentRowPosition;
    int currentColPosition;
    int currentSelectedCellState;
    int howManyTries;
}gameDisplayHandler;
/*
    Método para gerenciar e receber os inputs do Main Menu
    recebe como parametro um struct do menuHandler, retorna
    valor int que é usado para posicionar o "->" no elemento
    desejado e também para selecionar o elemento
*/
int getMenuInputKeys(menuHandler menuHandler);
/*
    Método para mostrar na tela com ncurses o Main Menu e suas própriedades,
    recebe como párametro um struct de menuHandler e 3 inteiros para o highscore
*/
void displayMenu(menuHandler menuHandler, int h1, int h2, int h3);
/*
    Método usado para gerenciar os inputs do user durante a visualização
    do gamefield, recebe como párametro um gameDisplayHandler e os limites do field
*/
gameDisplayHandler getGameInputKeys(gameDisplayHandler handler, int maxRow, int maxCol);
/*
    Método usado para mostrar o gameField na tela com Ncurses, recebendo um
    struct do tipo mineSweeper e as posições selecionadas na matrix de células,
    printa na tela a matrix
*/
void displayGameField(mineSweeper gameField, int currentRowSelected, int currentColSelected);
/*
    Método que mostra na tela a win screen e a pontuação da rodada.
*/
void displayWinScreen(gameDisplayHandler handler);
#endif
