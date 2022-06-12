#include <stdio.h>
#include <stdlib.h>

typedef struct data_type_t
{
    int field_1;
    char field_2;
    float field_3;
} data_type;

typedef struct node_t
{
    data_type data;
    struct node_t *next;
} node;

typedef struct queue_t
{
    node *front;
    node *rear;
} queue;

node *create_new_node()
{
    node *cur = (node *)malloc(sizeof(node));
    cur->next = NULL;
    return cur;
}

//khoi tao queue
queue *queue_init()
{
    queue *cur = (queue *)malloc(sizeof(queue));
    cur->front = NULL;
    cur->rear = NULL;
    return cur;
}

//kiem tra queue rong
int is_empty(queue *q)
{
    return ((q->front == NULL) && (q->rear == NULL));
}

//kich thuoc queue
int size(queue *q)
{
    node *tmp_node = q->front;
    int count = 0;
    while (tmp_node != NULL)
    {
        count++;
        tmp_node = tmp_node->next;
    }
    return count;
}

//them phan tu vao queue
void en_queue(queue *q)
{
    node *cur = create_new_node();
    if (!is_empty(q))
    {
        q->rear->next = cur;
        q->rear = cur;
    }
    else
    {
        q->front = cur;
        q->rear = cur;
    }
    return;
}

//lay 1 phan tu trong queue, CHUA FREE BO NHO
node *de_queue(queue *q)
{
    node *tmp_node = q->front;
    if (tmp_node != NULL)
    {
        q->front = q->front->next;
        if (q->front == NULL)
            q->rear = NULL;
        tmp_node->next = NULL;
    }
    return tmp_node;
}

//in cac phan tu trong queue
void print_queue(queue *q)
{
    node *tmp_node = q->front;
    while (tmp_node != NULL)
    {
        printf("%d ", tmp_node);
        tmp_node = tmp_node->next;
    }
    printf("\n");
    return;
}

int main()
{
    queue *q = queue_init();
    printf("%d\n", is_empty(q));
    printf("%d\n", size(q));
    en_queue(q);
    printf("%d\n", size(q));
    print_queue(q);
    en_queue(q);
    printf("%d\n", size(q));
    print_queue(q);
    de_queue(q);
    printf("%d\n", size(q));
    print_queue(q);
    de_queue(q);
    printf("%d\n", size(q));
    print_queue(q);
    printf("%d", is_empty(q));
    return 0;
}