#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int key;
    struct node_t *left;
    struct node_t *right;
} node;

typedef struct queue_node_t
{
    node *tree_node;
    struct queue_node_t *next;
} queue_node;

typedef struct queue_t
{
    queue_node *front;
    queue_node *rear;
} queue;

node *create_new_node()
{
    node *cur = (node *)malloc(sizeof(node));
    cur->left = NULL;
    cur->right = NULL;
    return cur;
}

queue_node *create_new_queue_node()
{
    queue_node *cur = (queue_node *)malloc(sizeof(queue_node));
    cur->tree_node = NULL;
    cur->next = NULL;
    return cur;
}

queue *create_new_queue()
{
    queue *cur = (queue *)malloc(sizeof(queue));
    cur->front = NULL;
    cur->rear = NULL;
    return cur;
}

void en_queue(queue *q, node *tnode)
{
    queue_node *cur = create_new_queue_node();
    cur->tree_node = tnode;
    if (q->front == NULL)
    {
        q->front = cur;
        q->rear = cur;
        return;
    }
    q->rear->next = cur;
    q->rear = cur;
    return;
}

node *de_queue(queue *q)
{
    queue_node *tmp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    node *tnode = tmp->tree_node;
    free(tmp);
    return tnode;
}

int queue_is_empty(queue *q)
{
    return (q->front == NULL);
}

node *insert(node *cur, int ins_key)
{
    if (cur == NULL)
    {
        node *tmp = create_new_node();
        tmp->key = ins_key;
        return tmp;
    }
    if (ins_key < cur->key)
        cur->left = insert(cur->left, ins_key);
    else
        cur->right = insert(cur->right, ins_key);
    return cur;
}

node *search(node *cur, int srch_key)
{
    if (cur == NULL) return NULL;
    if (srch_key == cur->key) return cur;
    if (srch_key < cur->key)
        return search(cur->left, srch_key);
    else
        return search(cur->right, srch_key);
}

node *find_min(node *root)
{
    node *tmp = root;
    while (tmp->left != NULL)
        tmp = tmp->left;
    return tmp;
}

node *find_max(node *root)
{
    node *tmp = root;
    while (tmp->right != NULL)
        tmp = tmp->right;
    return tmp;
}

node *delete(node *cur, int del_key)
{
    if (cur == NULL) return NULL;
    if (del_key < cur->key)
        cur->left = delete(cur->left, del_key);
    else
    {
        if (del_key > cur->key)
            cur->right = delete(cur->right, del_key);
        else
        {
            if (cur->left != NULL && cur->right != NULL)
            {
                node *tmp;
                tmp = find_min(cur->right);
                cur->key = tmp->key;
                cur->right = delete(cur->right, cur->key);
            }
            else
            {
                node *child;
                if (cur->left == NULL) child = cur->right;
                else child = cur->left;
                free(cur);
                return child;   
            }
        }
    }
    return cur;
}

void print_with_bfs(node *root)
{
    queue *q = create_new_queue();
    en_queue(q, root);
    while (!queue_is_empty(q))
    {
        node *tmp = de_queue(q);
        printf("%d ", tmp->key);
        if (tmp->left != NULL)
            en_queue(q, tmp->left);
        if (tmp->right != NULL)
            en_queue(q, tmp->right);
    }
    printf("\n");
    return;
}

void sort_with_bst(node *cur)
{
    if (cur == NULL) return;
    sort_with_bst(cur->left);
    printf("%d ", cur->key);
    sort_with_bst(cur->right);
    return;
}

int main()
{
    node *root = NULL;
    int a[10] = {25, 2, 2001, 64, 20, 29, 12, 2020, 8, 3};
    int i;
    for (i = 0; i < 10; i++)
        root = insert(root, a[i]);
    node *tmp_node;
    tmp_node = find_min(root);
    printf("%d\n", tmp_node->key);
    tmp_node = find_max(root);
    printf("%d\n", tmp_node->key);
    for (i = 0; i < 10; i++)
    {
        tmp_node = search(root, i);
        if (tmp_node == NULL)
            printf("Khong tin thay!\n");
        else
            printf("%d\n", tmp_node->key);
    }
    print_with_bfs(root);
    //printf("%d %d %d", root->key, root->left->key, root->right->key);
    /*root = delete(root, 20);
    print_with_bfs(root);
    root = delete(root, 64);
    print_with_bfs(root);
    root = delete(root, 2020);
    print_with_bfs(root);
    root = delete(root, 25);
    print_with_bfs(root);*/
    sort_with_bst(root);
    return 0;
}