#include <stdio.h>
#include <stdlib.h>
#include "coreGame.h"
#include <ncurses.h>
#include "interfaceHandler.h"

menuHandler menuState;
mineSweeper gameField;
gameDisplayHandler gameHandler;

int main ()
{
    menuState.currentState = 0;
    menuState.menuPosition = 0;

    gameHandler.currentRowPosition = 0;
    gameHandler.currentColPosition = 0;
    gameHandler.currentSelectedCellState = 0;
    gameHandler.howManyTries = 0;

    gameField = createMineSweeper(7, 6);
    gameField.howManyBombs = 2;
    gameField = populateMineSweeper(gameField);

    initscr();
    keypad(stdscr, TRUE);
    noecho();

    int menuAux = 0;
    int cellSelected[3] = {0, 0, 0};
    while (true)
    {
        switch (menuState.currentState)
        {
        case 0:
            /* Main Menu */
            displayMenu(menuState, 0, 0, 0);
            menuAux = getMenuInputKeys(menuState);
            if (!(menuAux == 10))
                menuState.menuPosition = menuAux;
            else
            {
                if (menuState.menuPosition == 0)
                    menuState.currentState = 1;
                else
                    exit(0);   
            }
            break;
        case 1:
            /* Game Screen*/
            displayGameField(gameField, gameHandler.currentRowPosition, gameHandler.currentColPosition);
            gameHandler = getGameInputKeys(gameHandler, gameField.rows, gameField.cols);
            if(gameHandler.currentSelectedCellState == 1)
            {
                if(isBomb(gameHandler.currentRowPosition, gameHandler.currentColPosition, gameField))
                    menuState.currentState = 2;
                else
                {
                    gameField.cellUnits[gameHandler.currentRowPosition][gameHandler.currentColPosition].isClicked = true;
                    gameHandler.currentSelectedCellState = 0;
                }
            }
            break;
        case 2:
            /* Win Screen*/
            displayWinScreen(gameHandler);
            menuState.menuPosition = 0;
            menuState.currentState = 0;
            gameField = populateMineSweeper(gameField);
            break;
        }
    }
    
    return 0;
}