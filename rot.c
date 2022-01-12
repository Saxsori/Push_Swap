#include "push_swap.h"

void    rot_a(t_stack *st)
{
    int temp;
    int i;

    temp = st->stack_a[st->top_a];
    i = 0;
    while (i < st->top_a)
    {
        st->stack_a[st->top_a - i] = st->stack_a[st->top_a - (i + 1)];
        i++;
    }
    st->stack_a[0] = temp;
    ft_putstr_fd("ra\n", 1);
}

void    rot_b(t_stack *st)
{
    int temp;
    int i;

    temp = st->stack_b[st->top_b];
    i = 0;
    while (i < st->top_b)
    {
        st->stack_b[st->top_b - i] = st->stack_b[st->top_b - (i + 1)];
        i++;
    }
    st->stack_b[0] = temp;
    ft_putstr_fd("ra\n", 1);
}

void    rot_ab(t_stack *st)
{
    rot_a(st);
    rot_b(st);
    ft_putstr_fd("rr\n", 1);
}