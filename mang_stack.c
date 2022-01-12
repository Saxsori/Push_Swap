#include "push_swap.h"

void fill_stack(char **str, t_stack *st, int i)
{
    int ele;

    st->stack_b = (int *)malloc(sizeof(int) * (st->ele_tot + 1));
    st->top_a = st->ele_tot - 1;
    st->top_b = -1;
    while (i < st->ele_tot) 
    {
        ele = ft_atoi(str[i]);
        st->stack_a[st->top_a] = ele;
        // ft_putnbr_fd(st->stack_a[i], 1);
        st->top_a--;
        i++;
    }
    st->top_a = st->ele_tot - 1;
}

void fill_stack2(char **str, t_stack *st, int i)
{
    int ele;

    st->stack_b = (int *)malloc(sizeof(int) * (st->ele_tot));
    st->top_a = st->ele_tot - 1;
    st->top_b = -1;
    while (i < st->ele_tot + 1) 
    {
        ele = ft_atoi(str[i]);
        st->stack_a[st->top_a] = ele;
        st->top_a--;
        i++;
    }
    st->top_a = st->ele_tot - 1;
}

void single_arg(char **str, t_stack *st)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (is_numeric(str[i]) == 0)
            err(2);
        i++;
    }
    st->stack_a = (int *)malloc(sizeof(int) * (st->ele_tot + 1));
    st->doo.total_yourself = st->ele_tot + 1;
    if (!st->stack_a)
    {
        free(st->stack_a);
        exit(1);
    }
    fill_stack(str, st, 0);
    if (is_dup(st))
    {
        free(st->stack_a);
        free(st->stack_b);
        err(3);
    }

}

void multi_arg(char **str, int argc, t_stack *st)
{
    int i;

    i = 1;
    st->ele_tot = argc - 1;
    while (i < argc)
    {
        if (is_numeric(str[i]) == 0)
            err(2);
        i++;
    }
    st->stack_a = (int *)malloc(sizeof(int) * (st->ele_tot));
    st->doo.total_yourself = st->ele_tot;
    if (!st->stack_a)
    {
        free(st->stack_a);
        exit(1);
    }
    fill_stack2(str, st, 1);
    if (is_dup(st))
    {
        free(st->stack_a);
        free(st->stack_b);
        err(3);
    }

}

void mang_stack(char **str, int argc, t_stack *st)
{
    int i;
    int k;
    char **split;

    i = 1;
    k = -1;
    if (argc == 2)
    {
        if (str_space(str[1], ' '))
        {
            split = ft_split(str[1], ' ');
            while (split[++k])
                st->ele_tot++;
            single_arg(split, st);
            free_split(split, st->ele_tot);
        }
    }
    if (argc > 2)
        multi_arg(str, argc, st);
}