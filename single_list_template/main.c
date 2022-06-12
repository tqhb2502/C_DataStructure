#include <stdio.h>
#include <stdlib.h>
// hello, Huy modified something here.
// modified one more time.
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

//tao nut moi
node *create_new_node()
{
    node *cur = (node *)malloc(sizeof(node));
    cur->next = NULL;
    return cur;
}

//chen nut moi vao sau nut p
void insert_to_p(node *first, int p)
{
    node *tmp_node = first;
    int count = 0;
    while (count < p)
    {
        tmp_node = tmp_node->next;
        count++;
    }
    node *cur = create_new_node();
    cur->next = tmp_node->next;
    tmp_node->next = cur;
    return;
}

//chen nut moi vao dau
void insert_to_head(node *first)
{
    node *cur = create_new_node();
    cur->next = first->next;
    first->next = cur;
    return;
}

//chen nut moi vao cuoi
void insert_to_last(node *first)
{
    node *tmp_node = first;
    while (tmp_node->next != NULL)
        tmp_node = tmp_node->next;
    node *cur = create_new_node();
    tmp_node->next = cur;
    return;
}

//xoa nut o vi tri p
data_type delete_node_p(node *first, int p)
{
    node *prev_node = first;
    node *tmp_node = first;
    int count = 0;
    while (count < p)
    {
        prev_node = tmp_node;
        tmp_node = tmp_node->next;
        count++;
    }
    prev_node->next = tmp_node->next;
    data_type cur_data = tmp_node->data;
    free(tmp_node);
    return cur_data;
}

//xoa nut o dau danh sach
void delete_head_node(node *first)
{
    node *tmp_node = first->next;
    first->next = tmp_node->next;
    free(tmp_node);
    return;
}

//xoa nut o cuoi danh sach
void delete_last_node(node *first)
{
    node *prev_node = first;
    node *tmp_node = first;
    while (tmp_node->next != NULL)
    {
        prev_node = tmp_node;
        tmp_node = tmp_node->next;
    }
    free(tmp_node);
    prev_node->next = NULL;
    return;
}

//kiem tra danh sach rong
int is_empty(node *first)
{
    return (first->next == NULL);
}

//xoa danh sach
void make_null_list(node *first)
{
    while (!is_empty(first))
        delete_head_node(first);
    return;
}

//in danh sach
void print_list(node *first)
{
    node *tmp_node = first->next;
    while (tmp_node != NULL)
    {
        printf("%d ", tmp_node);
        tmp_node = tmp_node->next;
    }
    return;
}

int main()
{
    node *first = create_new_node();
    //printf("%d", first);
    insert_to_head(first);
    insert_to_head(first);
    insert_to_head(first);
    print_list(first);
    printf("\n");
    insert_to_last(first);
    insert_to_last(first);
    print_list(first);
    printf("\n");
    insert_to_p(first, 1);
    print_list(first);
    printf("\n");
    insert_to_p(first, 2);
    insert_to_p(first, 4);
    print_list(first);
    printf("\n");
    delete_node_p(first, 3);
    print_list(first);
    printf("\n");
    delete_node_p(first, 1);
    print_list(first);
    printf("\n");
    delete_head_node(first);
    print_list(first);
    printf("\n");
    delete_head_node(first);
    print_list(first);
    printf("\n");
    delete_last_node(first);
    print_list(first);
    printf("\n");
    delete_last_node(first);
    print_list(first);
    printf("\n");
    printf("%d\n", is_empty(first));
    make_null_list(first);
    printf("%d\n", is_empty(first));
    return 0;
}
