#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>
#include "coreGame.h"
#include "interfaceHandler.h"

int getMenuInputKeys(menuHandler menuHandler)
{
    int keyPressed = getch();
    int menuPosition = menuHandler.menuPosition;
    switch (keyPressed)
    {
    case KEY_UP:
        if (!(menuPosition == 0))
            menuPosition--;
        break;
    case KEY_DOWN:
        if (!(menuPosition == 1))
            menuPosition++;
        break;
    case KEY_BACKSPACE:
        menuPosition = 10;
        break;
    default:
        break;
    }
    return menuPosition;
}

void displayMenu(menuHandler menuHandler, int h1, int h2, int h3)
{
    clear();
    switch (menuHandler.menuPosition)
    {
    case 0:
        printw("-------------------------------------------\n");
        printw("-> Start new game!\n");
        printw("Exit\n");
        printw("-------------------------------------------\n");
        printw("Seu top 3 HighScore são:\n");
        printw("1- %d\n", h1);
        printw("2- %d\n", h2);
        printw("3- %d\n", h3);
        printw("-------------------------------------------\n");
        break;
    case 1:
        printw("-------------------------------------------\n");
        printw("Start new game!\n");
        printw("-> Exit\n");
        printw("-------------------------------------------\n");
        printw("Seu top 3 HighScore são:\n");
        printw("1- %d\n", h1);
        printw("2- %d\n", h2);
        printw("3- %d\n", h3);
        printw("-------------------------------------------\n");
        break;
    }
    refresh();
}

gameDisplayHandler getGameInputKeys(gameDisplayHandler handler, int maxRow, int maxCol)
{
    int keyPressed = getch();
    switch (keyPressed)
    {
        case KEY_RIGHT:
            handler.currentColPosition++;
            break;
        case KEY_LEFT:
            handler.currentColPosition--;
            break;
        case KEY_UP:
            handler.currentRowPosition--;
            break;
        case KEY_DOWN:
            handler.currentRowPosition++;
            break;
        case KEY_BACKSPACE:
            handler.currentSelectedCellState = 1;
            handler.howManyTries++;
            break;
    }
    return handler;
}
void displayGameField(mineSweeper gameField, int currentRowSelected, int currentColSelected)
{
    clear();
    for (int i = 0; i < gameField.rows; i++)
    {
        for (int j = 0; j < gameField.cols; j++)
        {
            if (currentRowSelected == i && currentColSelected == j)
            {
                attron(A_BOLD);
                if (gameField.cellUnits[i][j].isClicked)
                    printw("| %d |", gameField.cellUnits[i][j].bombValue);
                else
                    printw("| O |");
                 attroff(A_BOLD);
            }
            else
            {
                if (gameField.cellUnits[i][j].isClicked)
                    printw("| %d |", gameField.cellUnits[i][j].bombValue);
                else
                    printw("| O |");
            }        
        }
        printw("\n");
    }
    refresh();
}

void displayWinScreen(gameDisplayHandler handler)
{
    clear();
    printw("-----------------------------------------------------\n");
    printw("Parabéns!!! Você achou uma bomba!!!\n");
    printw("Em Apenas %d movimentos!!!!\n", handler.howManyTries);
    printw("-----------------------------------------------------\n");
    printw("Aperte qualquer botão para voltar ao menu principal\n");
    printw("-----------------------------------------------------\n");
    refresh();
    getch();
}
