#include "push_swap.h"

void	free_split(char **str, int tot)
{
	int	i;

	i = 0;
	while (i < tot)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack *st)
{
	free (st->stack_a);
	free (st->stack_b);
}

void	err(int op)
{
    // if (op == 1)
    //     ft_putstr_fd("Error\n", 1);
    if (op == 2)
        ft_putstr_fd("Error\n", 1);
	if (op == 3)
		ft_putstr_fd("Error\n", 1);
	if (op == 4)
		ft_putstr_fd("Error\n", 1);
    exit(1);
}