#include <stdio.h>
#include <stdlib.h>
#include "highScoreHandler.h"

void addNode(node *head, char value){
    node *temp, *element;
    temp = (node *)malloc(sizeof(node));
    temp->data = value;
    
    temp->next = head->next;
    head->next = temp;
}
void createHighScoreTxtFile()
{
    FILE *fp = fopen("highscore.txt", "r");
    if (fp == NULL)
    {
        char value[5] = "100\n";
        fp = fopen("highscore.txt" ,"a");
        for (int i = 0; i < 3; i++)
            fputs(value, fp);
    }
    fclose(fp);
}
void createLinkedList(node *head)
{
    FILE *fp = fopen("highscore.txt", "r");
    char *linha = NULL;
    size_t len = 0;
    int numValue = 0;
    while (getline(&linha, &len ,fp) != -1)
        addNode(head, atoi(linha));
    fclose(fp);
}
void appendHighScore(int value)
{
    FILE *fp = fopen("highscore.txt", "a");
    char snum[5];
    snprintf(snum, sizeof(snum), "\n%d", value);
    fputs(snum, fp);
    fclose(fp);
}
void deleteElement(node *head, node *element)
{
    node *i, *j;
    for (i = head, j = head->next; j != element; i = j, j = j->next)
        continue;
    i->next = j->next;
    free(j);
}
int organizeLinkedList(node *head)
{
    node *smallestNumber;
    smallestNumber = head->next;
    node *temp = head->next;
    int tempSmallestNumber = 100;
    while (temp != NULL)
    {
        smallestNumber->data > temp->data ? smallestNumber = temp : smallestNumber;
        temp = temp->next;
    }
    tempSmallestNumber = smallestNumber->data;
    deleteElement(head, smallestNumber);
    return tempSmallestNumber;
}
