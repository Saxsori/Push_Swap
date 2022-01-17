#include "push_swap.h"

static void    small_topcheck(t_stack *st)
{
    // if(st->stack_a[st->top_a - 1] < st->stack_a[0])
    // {
    //     if(st->stack_a[st->top_a] < st->stack_a[0])
    //     ft_putstr_fd(BMAG "Already sorted", 1);
    // }
    if(st->stack_a[st->top_a - 1] > st->stack_a[0])
    {
        if(st->stack_a[st->top_a] < st->stack_a[0])
        {
            revrot_a(st);
            swap_a(st);
        }
        if(st->stack_a[st->top_a] > st->stack_a[0])
            revrot_a(st);
    }
}

static void    big_topcheck(t_stack *st)
{
    if(st->stack_a[st->top_a - 1] < st->stack_a[0])
    {
        if(st->stack_a[st->top_a] < st->stack_a[0])
        swap_a(st);
        else if(st->stack_a[st->top_a] > st->stack_a[0])
        rot_a(st);
    }
    else if(st->stack_a[st->top_a - 1] > st->stack_a[0])
    {
        swap_a(st);
        revrot_a(st);
    }
}

void    three_algo(t_stack *st)
{
    if(st->stack_a[st->top_a] < st->stack_a[st->top_a - 1])
    small_topcheck(st);
    else if(st->stack_a[st->top_a] > st->stack_a[st->top_a - 1])
    big_topcheck(st);
}

void    two_algo(t_stack *st)
{
    // if(st->stack_a[st->top_a] < st->stack_a[0])
    //     ft_putstr_fd(BMAG "Already sorted", 1);
    if(st->stack_a[st->top_a] > st->stack_a[0])
        swap_a(st);
}