#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "coreGame.h"
#include "interfaceHandler.h"
#include "highScoreHandler.h"

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
    
    createHighScoreTxtFile();

    node *head = createNode();
    createLinkedList(head);

    initscr();
    keypad(stdscr, TRUE);
    noecho();

    int menuAux = 0;
    int cellSelected[3] = {0, 0, 0};
    int minor1 = organizeLinkedList(head);
    int minor2 = organizeLinkedList(head);
    int minor3 = organizeLinkedList(head);
    while (true)
    {
        switch (menuState.currentState)
        {
        case 0:
            /* Main Menu */
            displayMenu(menuState,
                        minor1, minor2, minor3);
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
            appendHighScore(gameHandler.howManyTries);
            gameHandler.howManyTries = 0;
            node *temp;
            node *temp2 = head;
            while (true)
            {
                temp = temp2;
                if(temp == NULL)
                    break;
                temp2 = temp2->next;
                free(temp);
            }
            head = createNode();
            createLinkedList(head);
            gameField = populateMineSweeper(gameField);
            minor1 = organizeLinkedList(head);
            minor2 = organizeLinkedList(head);
            minor3 = organizeLinkedList(head);
            break;
        }
    }
    
    return 0;
}