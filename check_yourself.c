#include "push_swap.h"

int    is_sort(t_stack *st)
{
    int i;
    int j;

    i = -1;
    j = st->top_a;
    fix_yourself(st);
    while(++i < st->ele_tot)
    {
        if (st->stack_a[j--] != st->doo.array_yourself[i])
            return(0);
    }
    return(1);
}