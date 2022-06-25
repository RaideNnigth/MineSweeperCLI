#include <stdio.h>
#include <stdlib.h>
#include "coreGame.h"
#include <stdbool.h>
#include <time.h>

bool isBomb(int row, int col, mineSweeper gameField)
{
    if(gameField.cellUnits[row][col].bombValue == -1)
        return true;
    else
        return false;
}

int getNumberOfBombsNearBy(mineSweeper cellMap, int row, int col)
{
    int rowMax = cellMap.rows;
    int colMax = cellMap.cols;
    int total_neighbours = 0;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if(!(row + i < 0 || col + j < 0 || row + i > rowMax || col + j > colMax))
                if(isBomb(row + i, col + j, cellMap))
                    total_neighbours++; 
    return total_neighbours;
}
mineSweeper populateMineSweeper(mineSweeper gameField)
{
    int randomRowPos;
    int randomColPos;
    srand(time(0));

    for (int i = 0; i < gameField.rows; i++)
        for (int j = 0; j < gameField.cols; j++)
            gameField.cellUnits[i][j].bombValue = 0;
    for (int i = 0; i < gameField.howManyBombs; i++)
    {
        randomRowPos = rand() % (gameField.rows);
        randomColPos = rand() % (gameField.cols);
        while(gameField.cellUnits[randomRowPos][randomColPos].bombValue == -1)
        {
            randomRowPos = rand() % (gameField.rows);
            randomColPos = rand() % (gameField.cols);
        }
        gameField.cellUnits[randomRowPos][randomColPos].bombValue = -1;
        gameField.cellUnits[randomRowPos][randomColPos].isClicked = false;
    }
    for (int i = 0; i < gameField.rows; i++)
        for (int j = 0; j < gameField.cols; j++)
            if(!isBomb(i, j, gameField))
            {
                gameField.cellUnits[i][j].bombValue = getNumberOfBombsNearBy(gameField, i, j);
                gameField.cellUnits[i][j].isClicked = false;
            }
    return gameField;
}
mineSweeper createMineSweeper(int numberOfRows, int NumberOFCols)
{
    mineSweeper gameField;
    gameField.cols = NumberOFCols;
    gameField.rows = numberOfRows;
    //gameField.cellUnits = calloc((numberOfRows * NumberOFCols), sizeof(cellElement));
    //gameField.cellUnits = malloc(numberOfRows * sizeof(gameField.cellUnits));
    //for (int c = 0; c < numberOfRows; c++)
        //gameField.cellUnits[c] = malloc(NumberOFCols * sizeof(gameField.cellUnits[c]));
    return gameField;
}