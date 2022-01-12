#include "push_swap.h"

static int scan_top_a(t_stack *st)
{
    int i;

    i = st->top_a;
    while (i >= 0 && st->stack_a[i] >= st->median)
        i--;
    return (st->top_a - i);
}

static int scan_bottom_a(t_stack *st)
{
    int i;

    i = 0;
    while (i <= st->top_a && st->stack_a[i] >= st->median)
        i++;
    return(i);
}

int    initial_check_a(t_stack *st)
{
    int i;

    i = st->top_a;
    while(i-- > 0)
    {
        if (st->stack_a[i] <= st->median)
            return(1);
    }
    return(0);
}

void    check_push_to_b(t_stack *st)
{
    int top;
    int bottom;
    int i;

    i = 0;
    top = scan_top_a(st);
    bottom = scan_bottom_a(st);
    if (initial_check_a(st) && (bottom >= top || bottom == top - 1) && st->top_a > 4)
    {
        while (i <= top && st->stack_a[st->top_a] > st->median)
            {
                rot_a(st);
                i++;
            }
    }
    else if (initial_check_a(st) && bottom < top && st->top_a > 4)
    {
    i = 0;
        while (i <= bottom && st->stack_a[st->top_a] > st->median)
            {
                revrot_a(st);
                i++;
            }
    }
}

void    mark_chunks_b(t_stack *st)
{
    static int  i;

    st->mark_chunk[i] = st->top_b;
    i++;
}

void    find_tools(t_stack *st)
{
    find_median(st);
    // sizeof_range(st);
    // mark_chunks_b(st);
}

int limit_calc(t_stack *st)
{
    int limit;

    if (st->ele_tot < 500)
        limit = HUND_CHUNK * HUND_CHUNK;
    if (st->ele_tot > 100)
        limit = FIHUND_CHUNK * FIHUND_CHUNK;
    return (limit);
}


 void    algo(t_stack *st)
{
    int i;
    
    i = 0;
    find_tools(st);
    // ft_putnbr_fd(st->median, 1);
    while (initial_check_a(st) && i < st->range_size)
    {
        if (st->stack_a[st->top_a] <= st->median)
            push_b(st);
        else
        {
            if (initial_check_a(st))
            {
                check_push_to_b(st);
                if (st->stack_a[st->top_a] <= st->median)
                    push_b(st);
            }
        }
        i++;
    }
}

 void    apply_small_algo_a(t_stack *st)
{
        if (st->top_a + 1 == 5 || st->top_a + 1 == 4)
            small_algo(st);
        if (st->top_a + 1 == 3)
            three_algoo(st);
        // free_yourself(st);
}

void    part_a(t_stack *st)
{
    int j;
    
    j = 0;
    st->limit = limit_calc(st);
    // st->mark_chunk = (int *)malloc(st->limit - 1 * sizeof(int));
    while (j < st->limit && st->top_a > 4)
    {
        fix_yourself(st);
        algo(st);
        // mark_chunks_b(st);
    // ft_putnbr_fd(st->top_b, 1);
    // ft_putnbr_fd(st->stack_b[st->top_b], 1);
    // ft_putnbr_fd(st->mark_chunk[j], 1);
        free_yourself(st);
        j++;
    }
    apply_small_algo_a(st);
}

void    big_algo(t_stack *st)
{
    part_a(st);
    part_b(st);
}

            // free_yourself(st);

        // fix_yourself(st);
    //     j++;
    // }
    // check (st)
    // ft_putnbr_fd(st->range_size, 1);
    // ft_putnbr_fd(999, 1);
    // while (--limit < 0 && )

        // ft_putnbr_fd(st->limit, 1);
        // st->limit = 3;
    //     ft_putnbr_fd(st->top_b, 1);
    //     ft_putchar_fd('\n', 1);
    // printArray(st->mark_chunk, st->limit);
        // ft_putnbr_fd(st->stack_b[st->top_b], 1);
    // ft_putchar_fd('\n', 1);
    // ft_putnbr_fd(10000000, 1);

