/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrar <abrar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:19:23 by aaljaber          #+#    #+#             */
/*   Updated: 2022/01/16 13:09:19 by abrar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include   <stdio.h>
# include   <unistd.h>
# include	<stdlib.h>
# include   "./libft/libft.h"
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"
# define HUND_CHUNK 4
# define FIHUND_CHUNK 8

typedef struct s_struct
{
    int *array_yourself;
    int pivot_yourself;
    int total_yourself;
}   t_struct_yourself;

typedef struct s_range
{
    int range_size;
    int end_i;
    int begin_i;
    int stack_id;
}   t_range;

typedef struct s_stack
{
    int *stack_a;
    int *stack_b;
    int *mark_chunk;
    int top_a;
    int top_b;
    int ele_tot;
    int median;
    int mark_bottom;
    int top_small_a;
    t_range r;
    int range_size;
    int limit;
    t_struct_yourself doo;
}   t_stack;

void    err(int op);
void	free_split(char **str, int tot);
void    push_b(t_stack *st);
void    push_a(t_stack *st);
void    swap_a(t_stack *st);
void    swap_b(t_stack *st);
void    swap_ab(t_stack *st);
void    rot_a(t_stack *st);
void    rot_b(t_stack *st);
void    rot_ab(t_stack *st);
void    revrot_a(t_stack *st);
void    revrot_b(t_stack *st);
void    revrot_ab(t_stack *st);
int     str_space(const char *s, int c);
int     is_dup(t_stack *st);
int     check(int num, int *arr, int i);
int     is_numeric(char *str);
void    struct_init(t_stack *stack);
void    fill_stack(char **str, t_stack *st, int i);
void    fill_stack2(char **str, t_stack *st, int i);
void    mang_stack(char **str, int argc, t_stack *st);
void    control_algo(t_stack *st);
void    three_algo(t_stack *st);
void    two_algo(t_stack *st);
void    fix_yourself(t_stack *st);
void    find_median(t_stack *st);
void    fivfor_algo(t_stack *st);
void    free_yourself(t_stack *st);
int     is_sort(t_stack *st);
void	free_stack(t_stack *st);
void    big_algo(t_stack *st);
void    sizeof_range(t_stack *st);
void    small_algo(t_stack *st);
void    printArray(int arr[], int size); //dele
void    part_a(t_stack *st);
void    part_b(t_stack *st);
void    three_algoo(t_stack *st);
void    check_to_swap(t_stack *st);
#endif