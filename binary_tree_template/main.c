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
    //data_type data;
    int data;
    struct node_t *left, *right;
} node;

int get_max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

node *create_new_node()
{
    node *cur = (node *)malloc(sizeof(node));
    cur->left = NULL;
    cur->right = NULL;
    return cur;
}

node *fill_tree(int *a, int index, int n)
{
    if (index > n)
        return NULL;
    node *cur = create_new_node();
    cur->data = a[index];
    cur->left = fill_tree(a, 2 * index, n);
    cur->right = fill_tree(a, 2 * index + 1, n);
    return cur;
}

int tree_depth(node *cur)
{
    if (cur == NULL)
        return 0;
    int left_tree_depth = tree_depth(cur->left);
    int right_tree_depth = tree_depth(cur->right);
    return get_max(left_tree_depth, right_tree_depth) + 1;
}

int count_node(node *cur)
{
    if (cur == NULL)
        return 0;
    int left_nodes = count_node(cur->left);
    int right_nodes = count_node(cur->right);
    return left_nodes + right_nodes + 1;
}

void print_preorder(node *cur)
{
    if (cur == NULL)
        return;
    printf("%d ", cur->data);
    print_preorder(cur->left);
    print_preorder(cur->right);
    return;
}

void print_inorder(node *cur)
{
    if (cur == NULL)
        return;
    print_inorder(cur->left);
    printf("%d ", cur->data);
    print_inorder(cur->right);
    return;
}

void print_postorder(node *cur)
{
    if (cur == NULL)
        return;
    print_postorder(cur->left);
    print_postorder(cur->right);
    printf("%d ", cur->data);
    return;
}

int main()
{
    FILE *fp;
    fp = fopen("input.inp", "r");
    int n, a[101], i;
    fscanf(fp, "%d", &n);
    for (i = 1; i <= n; i++)
        fscanf(fp, "%d", &a[i]);
    fclose(fp);
    node *root = fill_tree(a, 1, n);
    printf("%d\n", tree_depth(root));
    printf("%d\n", count_node(root));
    print_preorder(root);
    printf("\n");
    print_inorder(root);
    printf("\n");
    print_postorder(root);
    printf("\n");
    return 0;
}