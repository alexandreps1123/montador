#ifndef __QUEUE__
#define __QUEUE__

typedef struct Line
{
    char line[256];
    struct Line *next;
} Line;

typedef struct Text
{
    Line *head;
    Line *tail;
} Text;

void createText(Text *q);

int isEmpty(Text *q);

void enqueue(Text *q, Line *elem);

void dequeue(Text *q);

void clear(Text *q);

Line *printHead(Text *q);

int length(Text *q);

#endif /* __QUEUE__ */