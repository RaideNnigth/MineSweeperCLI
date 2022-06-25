#include <stdbool.h>

#ifndef coreGame
#define coreGame
/*
    Estrutura de dados que representa a celula e suas propriedades, onde o
    bombValue é a quantidade de bombas em volta da celula, caso seja 3
    quer dizer que outras 3 celulas em volta são bombas, caso o valor
    seja -1 significa que a própria celula é uma bomba
*/
typedef struct cell
{
    int bombValue;
    bool isClicked;
}cellElement;

/*
    Estrutura que representa a matrix de celulas do jogo, definindo o número
    de colunas e linhas, a quantidade de bombas na matrix e também a propria
    matrix de celulas
*/
typedef struct mineSweeper
{
    int rows;
    int cols;
    int howManyBombs;
    cellElement cellUnits[7][6];
}mineSweeper;
/*
    A função isBomb() verifica se um ponto na matrix é uma bomba, caso seja
    ele retorna verdadeiro, caso não ele retorna falso. Leva como argumento
    a linha e coluna da celula bem como o struct da matrix "mineSweeper"   
*/
bool isBomb(int row, int col, mineSweeper gameField);
/*
    A função getNumberOfBombsNearBy(), tem como objetivo contar o número de
    bombas em volta de uma celula, retornando um número inteiro com o valor
    podendo variar de 1 à 8
*/
int getNumberOfBombsNearBy(mineSweeper cellMap, int row, int col);
/*
    A função populateMineSweeper(), popula a matrix do gameField e depois
    posiciona aleatoriamente as bombas pela mesma, a função também tem como
    objetivo inserir o valor de bombas perto de uma célula em cada uma
    que não é bomba.
*/
mineSweeper populateMineSweeper(mineSweeper gameField);
/*
    Cria um "objeto" do tipo MineSweeper e retorna a alocação dele
*/
mineSweeper createMineSweeper(int numberOfRows, int NumberOFCols);

#endif