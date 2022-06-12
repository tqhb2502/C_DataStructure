#include <stdio.h>
#include <stdlib.h>
// modified here too.
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

typedef struct stack_t
{
    node *top;
} stack;

node *create_new_node()
{
    node *cur = (node *)malloc(sizeof(node));
    cur->next = NULL;
    return cur;
}

//khoi tao stack
stack *stack_init()
{
    stack *cur = (stack *)malloc(sizeof(stack));
    cur->top = NULL;
    return cur;
}

//kiem tra danh sach co rong khong
int is_empty(stack *stk)
{
    return (stk->top == NULL);
}

//day phan tu vao stack
void stack_push(stack *stk)
{
    node *cur = create_new_node();
    cur->next = stk->top;
    stk->top = cur;
    return;
}

//lay phan tu tu stack
data_type stack_pop(stack *stk)
{
    node *tmp_node = stk->top;
    stk->top = stk->top->next;
    data_type cur_data = tmp_node->data;
    free(tmp_node);
    return cur_data;
}

//xoa stack
void make_null_stack(stack *stk)
{
    while (!is_empty(stk))
        stack_pop(stk);
    return;
}

//in cac phan tu trong stack
void print_stack(stack *stk)
{
    node *tmp_node = stk->top;
    while (tmp_node != NULL)
    {
        printf("%d ", tmp_node);
        tmp_node = tmp_node->next;
    }
    return;
}

int main()
{
    stack *stk = stack_init();
    printf("%d\n", is_empty(stk));
    stack_push(stk);
    print_stack(stk);
    printf("\n");
    stack_push(stk);
    print_stack(stk);
    printf("\n");
    printf("%d\n", is_empty(stk));
    make_null_stack(stk);
    /*stack_pop(stk);
    print_stack(stk);
    printf("\n");
    stack_pop(stk);
    print_stack(stk);
    printf("\n");*/
    printf("%d\n", is_empty(stk));
    return 0;
}