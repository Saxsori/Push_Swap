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

void    three_algoo(t_stack *st)
{
    if(st->stack_a[st->top_a] < st->stack_a[st->top_a - 1])
    small_topcheck(st);
    else if(st->stack_a[st->top_a] > st->stack_a[st->top_a - 1])
    big_topcheck(st);
}

static void    find_push(t_stack *st)
{
    int i;
    int count_pa;

    count_pa = 0;
    i = st->top_a + 1;
    while (--i > 2 && count_pa != 2)
    {
        if (st->stack_a[i] > st->median || st->stack_a[i] < st->median)
        {
            if (i == st->top_a)
                push_b(st);
            else
            {
                rot_a(st);
                push_b(st);
            }
            count_pa++;
        }
    }

    while(--i > -1 && count_pa != 2)
    {
        if (st->stack_a[i] > st->median || st->stack_a[i] < st->median)
        {
            if (i == 0)
            {
                swap_a(st);
                push_b(st);
            }
            else
            {
                rot_a(st);
                push_b(st);
            }
            count_pa++;
        }  
    }
}

static void    first_push(t_stack *st)
{
    if (st->stack_b[st->top_b] > st->stack_a[st->top_a] && st->stack_b[st->top_b] < st->stack_a[st->top_a - 1])
    {
        push_a(st);
        swap_a(st);
    } 
    if (st->stack_b[st->top_b] > st->stack_a[st->top_a - 1] && st->stack_b[st->top_b] < st->stack_a[0])
    {
        revrot_a(st);
        push_a(st);
        rot_a(st);
        rot_a(st);
    }
    if (st->stack_b[st->top_b] > st->stack_a[0])
    {
        push_a(st);
        rot_a(st);
    }

}

static void    second_push(t_stack *st)
{
    if (st->stack_b[st->top_b] < st->stack_a[st->top_a])
            push_a(st);
    if (st->stack_b[st->top_b] > st->stack_a[st->top_a] && st->stack_b[st->top_b] < st->stack_a[st->top_a - 1])
        {
            push_a(st);
            swap_a(st);
        }
    // if (st->stack_b[st->top_b] > st->stack_a[st->top_a - 1] && st->stack_b[st->top_b] < st->stack_a[st->top_a - 2])
    // {
    //     revrot_a(st);
    //     revrot_a(st);
    //     push_a(st);
    //     rot_a(st);
    //     rot_a(st);
    //     rot_a(st);
    // }
    if (st->stack_b[st->top_b] > st->stack_a[st->top_a - 2] && st->stack_b[st->top_b] < st->stack_a[st->top_a - 3])
    {
        revrot_a(st);
        push_a(st);
        rot_a(st);
        rot_a(st);
    }
    // if (st->stack_b[st->top_b] > st->stack_a[st->top_b - 1])
    //     {
    //         push_a(st);
    //         // rot_a(st);
    //     }
}

void    small_algo(t_stack *st)
{
    fix_yourself(st);
    find_median(st);
    // ft_putnbr_fd(st->median, 1);
    if (st->top_a + 1 == 5)
    {
        find_push(st);
        // push_b(st);
        // push_b(st);
        three_algoo(st);
        if(st->stack_b[st->top_b] < st->stack_b[st->top_b - 1])
            swap_b(st);
        first_push(st);
        second_push(st);
    }
    if (st->top_a + 1 == 4)
    {
        push_b(st);
        three_algoo(st);
        first_push(st);
    }
    free_yourself(st);
}