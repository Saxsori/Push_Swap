# include "push_swap.h"

static int  scan_top_a(t_stack *st)
{
    int i;

    i = st->top_a;
    while (i >= 0 && st->stack_a[i] < st->stack_b[st->top_b])
        i--;
    return (st->top_a - (i + 1));
}

static int scan_bottom_a(t_stack *st)
{
    int i;

    i = 0;
    while (st->stack_a[i] != st->mark_bottom && st->stack_a[i] > st->stack_b[st->top_b])
        i++;
    return(i - 1);
}
static int scan_bottomf_a(t_stack *st)
{
    int i;

    i = 0;
    while (st->stack_a[i] != st->mark_bottom)
        i++;
    return(i - 1);
}

void    check_stack_a(t_stack *st)
{
    int small_num;
    int rra_num;
    int i;

    if (st->stack_a[0] == st->mark_bottom)
    {
        if (st->stack_a[st->top_a] > st->stack_b[st->top_b])
            push_a(st);
        else if (st->stack_a[st->top_a] < st->stack_b[st->top_b])
        {
            i = 0;
            small_num = scan_top_a(st);
            check_to_swap(st);
            while (i <= small_num)
            {
                rot_a(st);
                i++;
            }
            push_a(st);
        }
    }
    else if (st->stack_a[0] != st->mark_bottom)
    {
        if (st->stack_a[st->top_a] < st->stack_b[st->top_b])
        {
            i = 0;
            small_num = scan_top_a(st);
            while (i <= small_num)
            {
                rot_a(st);
                i++;
            }
        }
        else if (st->stack_a[st->top_a] > st->stack_b[st->top_b])
        {
            if (st->stack_b[st->top_b] > st->stack_a[0])
                push_a(st);
            check_to_swap(st);
            if (st->stack_b[st->top_b] < st->stack_a[0])
            {
                rra_num = scan_bottom_a(st);
                i = 0;
                while (i <= rra_num)
                {
                    revrot_a(st);
                    i++;
                }
                push_a(st);
            }
        }
    }
}

void    check_to_swap(t_stack *st)
{
    if (st->stack_b[st->top_b] < st->stack_b[st->top_b - 1] && st->top_b > 0)
        swap_b(st);
}
void    check_push_to_a(t_stack *st)
{
    // if (st->stack_a[st->top_a] > st->stack_b[st->top_b] && st->stack_a[0] == st->mark_bottom)
    //     push_a(st);
    // else
    // if (st->top_b > 0)
    //     check_to_swap(st);
    check_stack_a(st);
}

void    part_b(t_stack *st)
{
    int i;
    int uu;

    i = 0;
    uu = st->top_a;
    st->mark_bottom = st->stack_a[0];
    while (st->top_b > -1)
        check_push_to_a(st);
    uu = scan_bottomf_a(st);
    i = 0;
    while (i <= uu)
    {
        revrot_a(st);
        i++;
    }
}