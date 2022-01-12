#include "push_swap.h"

void    find_median(t_stack *st)
{
    int m;
    //check
    // if (st->doo.total_yourself % 2)
    //     {
        m = 0;
            if (st->ele_tot < 500)
            {
                m = st->doo.total_yourself / HUND_CHUNK; //around 16 for 500 will give 10991 //around 8 for 952
                st->range_size = m + 1;
            }
            else if (st->ele_tot > 100)
            {
                m = st->doo.total_yourself / FIHUND_CHUNK; //around 16 for 500 will give 10991 //around 8 for 952
                st->range_size = m + 1;
            }
            else if (st->ele_tot == 5)
            {
                m = st->doo.total_yourself / 2;
                st->range_size = m + 1;
            }
    //     }
    // else
    //     {
    //         m = st->doo.total_yourself / 3;
    //         st->range_size = m;
    //     }
    st->median = st->doo.array_yourself[m];
}

// void    sizeof_range(t_stack *st)
// {
//     // if (st->doo.total_yourself % 2)
//     // st->range_size = st->doo.total_yourself - (st->doo.total_yourself / 2) + 1;
//     // else 
//     st->range_size = st->doo.total_yourself - (st->doo.total_yourself / 2);
// }
