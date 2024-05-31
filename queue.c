#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createText(Text *q)
{
    q->head = NULL;
    q->tail = NULL;
}

int isEmpty(Text *q)
{
    if (q->head == NULL) return 1;

    return 0;
}

void enqueue(Text *q, Line *line)
{
    Line *p;

    p = malloc(sizeof(Line));
    if (p == NULL)
    {
        printf("Nao foi possivel alocar memoria");
        return;
    }

    strcpy(p->line, line->line);
    p->next = NULL;

    if (isEmpty(q)) q->head = p;
    else q->tail->next = p;

    q->tail = p;
}

void dequeue(Text *q)
{
    Line *p;

    if (isEmpty(q))
    {
        printf("A Fila esta vazia.\n");
        return;
    }

    p = q->head;

    q->head = p->next;

    if (q->head == NULL) q->tail = NULL;

    free(p);

    return;
}

void clear(Text *q)
{
    Line *next_line, *excluir;

    if (isEmpty(q))
    {
        printf("A Fila esta vazia.\n");
        return;
    }

    next_line = q->head;
    while (next_line != NULL)
    {
        excluir = next_line;
        next_line = next_line->next;
        free(excluir);
    }

    createText(q);

    return;
}

Line *printHead(Text *q)
{
    Line *p;

    if (isEmpty(q))
    {
        printf("A Fila esta vazia.");
        p = NULL;
        return p;
    }

    p = q->head;

    return p;
}

int length(Text *q)
{
    Line *p;
    int count = 0;

    if (!isEmpty(q))
    {
        p = q->head;
        while (p != NULL)
        {
            p = p->next;
            count++;
        }
    }

    return count;
}

