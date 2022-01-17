#include "push_swap.h"

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        {
            ft_putnbr_fd(arr[i], 1);
            ft_putchar_fd(' ', 1);
        }
}

void    free_yourself(t_stack *st)
{
    free (st->doo.array_yourself);
    st->doo.pivot_yourself = 0;
    st->doo.total_yourself = 0;
    st->median = 0;
}

static void    swap_yourself(int *b, int *e)
{
    int temp;

    temp = *b;
    *b = *e;
    *e = temp;
}

static int  part_yourself(int *arr_yourself, int begin_yourself, int end_yourself) 
{ 
    int pivot_yourself;
    int i;
    int j;
    pivot_yourself = arr_yourself[end_yourself];
    i = begin_yourself - 1;
    j = begin_yourself;

    while (j <= end_yourself - 1) 
    { 
        if (arr_yourself[j] < pivot_yourself) 
        { 
            i++; 
            swap_yourself(&arr_yourself[i], &arr_yourself[j]); 
        } 
        j++;
    } 
    swap_yourself(&arr_yourself[i + 1], &arr_yourself[end_yourself]); 
    return (i + 1); 
}

static void    sort_yourself(int *arr_yourself, int begin_yourself, int end_yourself)
{
    int repart_yourself;

    if (begin_yourself < end_yourself)
    {
        repart_yourself = part_yourself(arr_yourself, begin_yourself, end_yourself);
        sort_yourself(arr_yourself, begin_yourself, repart_yourself - 1);
        sort_yourself(arr_yourself, repart_yourself + 1, end_yourself);
    }
}

// int    count_yourself(t_stack *st)
// {
//     int tot;
//     int i;

//     i = st->top_a;
//     while()
// }


void    fix_yourself(t_stack *st)
{
    int i;
    st->doo.total_yourself = st->top_a + 1;
    st->doo.array_yourself = (int *)malloc((st->doo.total_yourself + 1) * sizeof(int));
    i = -1;
    while(++i < st->doo.total_yourself)
        st->doo.array_yourself[i] = st->stack_a[i];
    sort_yourself(st->doo.array_yourself, 0, st->doo.total_yourself - 1);
}





    // printArray(st->doo.array_yourself, st->doo.total_yourself); 
    // printArray(st->doo.array_yourself, st->doo.total_yourself); 