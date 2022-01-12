#include "push_swap.h"

void    push_b(t_stack *st)
{
    st->stack_b[++st->top_b] = st->stack_a[st->top_a];
    st->stack_a[st->top_a] = 0;
    st->top_a--;
    // st->top_b++;
    ft_putstr_fd("pb\n", 1);
}

void    push_a(t_stack *st)
{
    st->stack_a[++st->top_a] = st->stack_b[st->top_b];
    st->stack_b[st->top_b] = 0;
    st->top_b--;
    // st->top_a++;
    ft_putstr_fd("pa\n", 1);
}

void    swap_a(t_stack *st)
{
    int temp;

    temp = st->stack_a[st->top_a];
    st->stack_a[st->top_a] = st->stack_a[st->top_a - 1];
    st->stack_a[st->top_a - 1] = temp;
    ft_putstr_fd("sa\n", 1);
}

void    swap_b(t_stack *st)
{
    int temp;

    temp = st->stack_b[st->top_b];
    st->stack_b[st->top_b] = st->stack_b[st->top_b - 1];
    st->stack_b[st->top_b - 1] = temp;
    ft_putstr_fd("sb\n", 1);
}

void    swap_ab(t_stack *st)
{
    swap_a(st);
    swap_b(st);
    ft_putstr_fd("ss\n", 1);
}
