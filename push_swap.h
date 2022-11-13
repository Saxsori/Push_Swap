/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:19:23 by aaljaber          #+#    #+#             */
/*   Updated: 2022/02/03 16:46:07 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	"./libft/libft.h"
# define HUND_CHUNK 3
# define FIHUND_CHUNK 4

typedef struct s_struct
{
	int	*array_yourself;
	int	pivot_yourself;
	int	total_yourself;
}	t_struct_yourself;
typedef struct s_stack
{
	int					*stack_a;
	int					*stack_b;
	int					*mark_chunk;
	int					top_a;
	int					top_b;
	int					ele_tot;
	int					median;
	int					mark_bottom;
	int					top_small_a;
	int					big_nums;
	int					num_push;
	int					top;
	int					bottom;
	int					small_num;
	int					rra_num;
	int					r;
	int					i;
	int					rra;
	int					ra;
	int					rb;
	int					rrb;
	int					g;
	int					range_size;
	int					limit;
	int					count_pa;
	t_struct_yourself	doo;
}	t_stack;
void	err(int op);
void	free_split(char **str, int tot);
void	push_b(t_stack *st);
void	push_a(t_stack *st);
void	swap_a(t_stack *st);
void	swap_b(t_stack *st);
void	swap_ab(t_stack *st);
void	rot_a(t_stack *st);
void	rot_b(t_stack *st);
void	rot_ab(t_stack *st);
void	revrot_a(t_stack *st);
void	revrot_b(t_stack *st);
void	revrot_ab(t_stack *st);
int		str_space(const char *s, int c);
int		is_dup(t_stack *st);
int		check(int num, int *arr, int i);
int		is_numeric(char *str);
void	struct_init(t_stack *stack);
void	fill_stack(char **str, t_stack *st, int i);
void	fill_stack2(char **str, t_stack *st, int i);
void	mang_stack(char **str, int argc, t_stack *st);
void	control_algo(t_stack *st);
void	three_algo(t_stack *st);
void	two_algo(t_stack *st);
void	fix_yourself(t_stack *st, int k);
void	find_median(t_stack *st);
void	fivfor_algo(t_stack *st);
void	free_yourself(t_stack *st);
int		is_sort(t_stack *st);
void	free_stack(t_stack *st);
void	big_algo(t_stack *st);
void	sizeof_range(t_stack *st);
void	small_algo(t_stack *st);
void	part_a(t_stack *st);
void	part_b(t_stack *st);
void	three_algoo(t_stack *st); //check
void	check_to_swap(t_stack *st);
void	check_push_to_a(t_stack *st);
void	check_stack_a(t_stack *st);
void	check_push_to_a2(t_stack *st);
int		initial_check_a(t_stack *st);
int		limit_calc(t_stack *st);
void	algo(t_stack *st);
void	find_tools(t_stack *st, int t);
void	apply_small_algo_a(t_stack *st);
int		scan_top_a(t_stack *st);
int		scan_bottom_a(t_stack *st);
void	single_arg(char **str, t_stack *st);
void	apply_ra(t_stack *st);
void	apply_rra(t_stack *st);
void	do_ra(t_stack *st);
void	do_rra(t_stack *st);
void	find_push(t_stack *st);
int		initial_check_b(t_stack *st);
void	choose_range(t_stack *st);
int		is_sooort(t_stack *st);
void	check_single_arg(char **str, t_stack *st);
void	find_range(t_stack *st);
void	count_yourself(t_stack *st, int k);
void	sort_yourself(int *arr_yourself, int begin_yourself, int end_yourself);
#endif
