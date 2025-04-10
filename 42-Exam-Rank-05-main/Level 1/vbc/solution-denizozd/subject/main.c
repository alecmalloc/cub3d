#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

#include <stdlib.h>
#include <stddef.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node * new_node(node n)
{
    node *ret = calloc(1, sizeof(node));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void unexpected_char(char c)
{
    if (c)
        printf("Unexpexted token '%c'\n", c);
    else
        printf("Unexpexted end of input \n");
}

int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s,c))
        return (1);
    unexpected_char(**s);
    return (0);
}

node *parse_expr(char *s)
{
    // Your code is here
    if(*s)
    {
        destroy_tree(ret);
        return (NULL);
    }
    return (ret);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
}

int main (int argc, char** argv)
{
    if (argc!= 2)
        return 1;
    node *tree = parse_expr(argv[1]);
    if (!tree)
        return 1;
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return (0);
}