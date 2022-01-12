#include "push_swap.h"

int str_space(const char *s, int c)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)s;
	while (result[i] != '\0' && result[i] != (char) c)
		i++;
	if (result[i] == (char)c)
		return (1);
	return (0);
}

int part_yourself(int *arr_yourself, int begin_yourself, int end_yourself)
{
    int pivot_you;
    int b;
    int e;

    pivot_you = arr_yourself[begin_yourself];
    b = begin_yourself + 1;
    e = end_yourself;
    if (b < e)
    {
        while(arr_yourself[b] < pivot_you && b <= end_yourself)
            b++;
        while(arr_yourself[e] > pivot_you)
            e--;
        if (b < e)
            swap_yourself(arr_yourself[b], arr_yourself[e]);  
    }
    arr_yourself[begin_yourself] = arr_yourself[e];
    arr_yourself[e] = pivot_you;
    return(e);
}

void struct_init(t_stack *stack)
{
    stack->top_a = 0;
    stack->ele_tot = 0;
    stack->top_b = 0;
}

int is_numeric(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return(0);
    }
    return(1);
}

// void 
void check_stack(char *str, t_stack *st)
{
    int ele;
    st->ele_tot++;
    ft_putnbr_fd(st->ele_tot, 1);
    // st->stack_a = (int *)malloc(sizeof(int) * (st->ele_tot + 1));
    // if ()
    if (is_numeric(str))
    {
        ele = ft_atoi(str);
        // fill_stack(str, st);
    }
    else
        err(2);
}

// void count ()

int mangh_stack(char **str, int argc, t_stack *st)
{
    int i;
    int k;
    char **split;

    i = 1;
    k = 0;
    while (i < argc)
    {
        if (str_space(str[i], ' '))
        {
            split = ft_split(str[i], ' ');
            while (split[k])
                check_stack(split[k++], st);
            free_split(split, k);
        }
        else 
            check_stack(str[i], st);
        i++;
    }
    return (1);
}
int main(int argc, char **argv)
{
    t_stack stack;
    int e;

    struct_init(&stack);
    if (argc > 1)
        e = mang_stack(argv, argc, &stack);
    else 
        err(1);
    return 0;
}