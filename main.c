
#include "push_swap.h"

void struct_init(t_stack *stack)
{
    stack->top_a = 0;
    stack->ele_tot = 0;
    stack->top_b = 0;
}

void    control_algo(t_stack *st)
{
    if (!is_sort(st))
    {
        if (st->ele_tot == 2)
            two_algo(st);
        if (st->ele_tot == 3)
            three_algo(st);
        if (st->ele_tot == 5 || st->ele_tot == 4)
            fivfor_algo(st);
        if (st->ele_tot > 5)
            big_algo(st);
        // free_yourself(st);
    }
    else
    {
        free_stack(st);
        exit(0);
    }
}

int main(int argc, char **argv)
{
    t_stack stack;
    int i;
    
    i = 0;
    struct_init(&stack);
    if (argc > 1)
    {
        mang_stack(argv, argc, &stack);
        //         printArray(stack.stack_b, stack.ele_tot);
        // ft_putchar_fd('\n', 1);
        // ft_putnbr_fd(stack.stack_b[stack.top_b], 1);
        // ft_putchar_fd('\n', 1);
        // printArray(stack.stack_a, stack.ele_tot);
        // ft_putchar_fd('\n', 1);
        // ft_putnbr_fd(stack.stack_a[stack.top_a], 1);
        control_algo(&stack);

        // printArray(stack.stack_b, stack.ele_tot);
        // ft_putchar_fd('\n', 1);
        // ft_putnbr_fd(stack.stack_b[stack.top_b], 1);
        // ft_putchar_fd('\n', 1);
        // printArray(stack.stack_a, stack.ele_tot);
        // ft_putchar_fd('\n', 1);
        // ft_putnbr_fd(stack.stack_a[stack.top_a], 1);
    }
    // else
    //     err(1);
    return 0;
}
        // i = 0;
        // while (i < stack.ele_tot)
        //     ft_putnbr_fd(stack.stack_b[i++], 1);
        //             ft_putchar_fd('\n', 1);
        // ft_putnbr_fd(stack.stack_b[stack.top_b], 1);
        //             ft_putchar_fd('\n', 1);
        // i = 0;
        // while (i < stack.ele_tot)
        //     ft_putnbr_fd(stack.stack_a[i++], 1);
        //             ft_putchar_fd('\n', 1);
        // ft_putnbr_fd(stack.stack_a[stack.top_a], 1);
        //             ft_putchar_fd('\n', 1);

        // revrot_a(&stack);
        // i = 0;
        // while (i < stack.ele_tot)
        //     ft_putnbr_fd(stack.stack_b[i++], 1);
        //             ft_putchar_fd('\n', 1);
        // ft_putnbr_fd(stack.stack_b[stack.top_b], 1);
        //             ft_putchar_fd('\n', 1);
        // i = 0;
        // while (i < stack.ele_tot)
        //     ft_putnbr_fd(stack.stack_a[i++], 1);
        //             ft_putchar_fd('\n', 1);
        //     ft_putnbr_fd(stack.stack_a[stack.top_a], 1);
        //             ft_putchar_fd('\n', 1);
        // ft_putchar_fd('\n', 1);
        // revrot_a(&stack);
        //     ft_putchar_fd('\n', 1);
        // ft_putchar_fd('\n', 1);
        // while (i < stack.ele_tot)
        // {
        //     push_ab(&stack);
        //     i++;
        // }
        // i = 0;
        // while (i < stack.ele_tot)
        //     ft_putnbr_fd(stack.stack_b[i++], 1);
        //     ft_putchar_fd('\n', 1);
        // i = 0;
        // while (i < stack.ele_tot)
        //     ft_putnbr_fd(stack.stack_a[i++], 1);
        //     ft_putchar_fd('\n', 1);
        // // ft_putnbr_fd(stack.top_a, 1);
        // // ft_putnbr_fd(stack.top_b, 1);
        // i = 0;
        // while (i < stack.ele_tot)
        // {
        //     push_ba(&stack);
        //     i++;
        // }
        // i = 0;
        // while (i < stack.ele_tot)
        //     ft_putnbr_fd(stack.stack_b[i++], 1);
        //     ft_putchar_fd('\n', 1);
        // i = 0;
        // while (i < stack.ele_tot)
        //     ft_putnbr_fd(stack.stack_a[i++], 1);
        //     ft_putchar_fd('\n', 1);