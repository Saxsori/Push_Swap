# include "push_swap.h"

// void    chunk_size(t_stack *st)
// {
//     static int  i;
    
//     /*  st->limit is the number of chunks
//         -2 b/c the number of chunks is ex/16 so 1 in A and the index for 
//         the top of B is the chunk n.15 so in the index is 14
//         first condition is for the last index to check if we got the last chunk
//     */
//     if (i + 1 == st->limit - 1)
//     {
//         st->r.begin_i = st->mark_chunk[0];
//         st->r.end_i = 0;
//         st->r.range_size = st->mark_chunk[0] + 1;
//     }
//     else 
//     {
//         st->r.begin_i = st->mark_chunk[(st->limit - 2) - i];
//         st->r.end_i = st->mark_chunk[(st->limit - 2) - (i + 1)];
//         st->r.range_size = st->mark_chunk[(st->limit - 2) - i] - st->mark_chunk[(st->limit - 2) - (i + 1)];
//     }

//     i++;
// }

static int  scan_top_a(t_stack *st)
{
    int i;

    i = st->top_a;
    while (i >= 0 && st->stack_a[i] < st->stack_b[st->top_b])
        i--;
    return (st->top_a - (i + 1));
}

void    check_stack_a(t_stack *st)
{
    int small_num;
    int i;

    i = 0;
    small_num = scan_top_a(st);
    while (i <= small_num)
    {
        rot_a(st);
        i++;
    }
    push_a(st);
    i = 0;
    while (i <= small_num)
    {
        revrot_a(st);
        i++;
    }
}

void    check_push_to_a(t_stack *st)
{
    if (st->stack_a[st->top_a] > st->stack_b[st->top_b])
        push_a(st);
    else
        check_stack_a(st);
}

void    part_b(t_stack *st)
{
    int i;
    int uu;

    i = 0;
    uu = st->top_a;
    // ft_putchar_fd('t', 1);
    // ft_putnbr_fd(st->top_small_a, 1);
    // ft_putchar_fd('\n', 1);
    while (i < st->ele_tot - uu + 1 && st->top_b > -1)
    {
        // printf("lallalala\n");
        // chunk_size(st);
        // ft_putnbr_fd(st->r.range_size, 1);
        // if (st->r.range_size < 6)
        //     {
                check_push_to_a(st);
        //         printf("nnnn\n");
        //     }
        // else if (st->r.range_size > 6)
        //  printf("jjjjj\n");
        // while (i < st->limit - 2)
        // {
        //             chunk_size(st);
        //             st->r.range_size = st->r.range_size + st->r.range_size;
        // ft_putchar_fd('\n', 1);
        // i++;
        // }
        // ft_putnbr_fd(st->r.range_size, 1);
        i++;
        
    }
    
}
    // int i;

    // i = 0;
    // while (i < st->limit)
    // {
    //     chunk_size(st);
    //     fix_yourself_range(st, 2);
    //     if (st->r.range_size < 6)
    //     {
    //         if (st->r.range_size < 4)
                
    //         if (st->r.range_size < 6)
    //     }
    //     i++;
    // }
//     chunk_size(st);
//     ft_putnbr_fd(st->r.range_size, 1);
//             ft_putchar_fd('\n', 1);
//     chunk_size(st);
//     ft_putnbr_fd(st->r.range_size, 1);
//             ft_putchar_fd('\n', 1);
//     chunk_size(st);
//     ft_putnbr_fd(st->r.range_size, 1);
//             ft_putchar_fd('\n', 1);
//     ft_putnbr_fd(st->ele_tot, 1);
//             ft_putchar_fd('\n', 1);
    // ft_putnbr_fd(st->r.range_size, 1);
    // i = 0;
    // while (i < 15)
    // {
        // ft_putnbr_fd(st->mark_chunk[st->limit - 2], 1);
        // ft_putchar_fd('\n', 1);
    //     i++;
    // }