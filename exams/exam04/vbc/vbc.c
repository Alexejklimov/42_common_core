#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(n));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
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

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of file\n");
}

int accept(char **s, char c)
{
    (void)c;
    if (**s)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
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
    return 0;
}

//////////////////// added part /////////////////////

int skob(char *s)
{
    int i = 0;
    int acc = 0;

    while (s[i])
    {
        if (s[i] == '(')
            acc++;
        if (s[i] == ')')
        {
            acc--;
            if (acc < 0)
                return -1;
        }
        i++;
    }
    return acc;
}
node    *pmult(char **s);
node    *grp(char **s);

node    *padd(char **s)
{
    node    *left;
    node    *right;
    node    tmp;

    left = pmult(s);
    if (!left)
        return NULL;
    while (**s == '+')
    {
        (*s)++;
        right = pmult(s);
        if (!right)
        {
            destroy_tree(left);
            return NULL;
        }
        tmp.type = ADD;
        tmp.l = left;
        tmp.r = right;
        left = new_node(tmp);
    }
    return (left);
}

node    *pmult(char **s)
{
    node    *left;
    node    *right;
    node    tmp;

    left = grp(s);
    if (!left)
        return NULL;
    while (**s == '*')
    {
        (*s)++;
        right = pmult(s);
        if (!right)
        {
            destroy_tree(left);
            return NULL;
        }
        tmp.type = MULTI;
        tmp.l = left;
        tmp.r = right;
        left = new_node(tmp);
    }
    return (left);
}

node    *grp(char **s)
{
    node    *res;
    node    tmp;

    res = NULL;
    if (**s == '(')
    {
        (*s)++;
        res = padd(s);
        if (!res || **s != ')')
        {
            destroy_tree(res);
            unexpected(**s);
            return NULL;
        }
        (*s)++;
        return res;
    }
    if (isdigit(**s))
    {
        tmp.val = **s - '0';
        tmp.type = VAL;
        res = new_node(tmp);
        (*s)++;
        return res;
    }
    unexpected(**s);
    return NULL;
}

/////////// end of added part /////////////////////

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);

    if (skob(argv[1]) == -1)
    {
        printf("unexpected token '('\n");
        return 1;
    }
    node *tree = padd(&argv[1]);
    if (!tree)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
}
