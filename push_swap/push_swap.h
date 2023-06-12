/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:33:33 by viktortr          #+#    #+#             */
/*   Updated: 2023/06/06 10:06:36 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_node
{
	int				data;
	struct t_node	*next;
}					t_node;

typedef struct t_twostacks
{
	t_node			*top1;
	t_node			*top2;
}					t_twostacks;

void				error(void);
int					ft_atoi(const char *str);
void				duplicates(int argc, char *argv[]);
int					adding_numbers(int argc, char *argv[]);
void				print_stack(t_twostacks *stacks);
void				push1(t_twostacks *stacks, int data);
void				push2(t_twostacks *stacks, int data);
int					pop1(t_twostacks *stacks);
int					pop2(t_twostacks *stacks);
int					is_empty1(t_twostacks *stacks);
int					is_empty2(t_twostacks *stacks);
t_node				*create_node(int data);
t_twostacks			create_two_stacks(t_twostacks *indexStacks);
void				push1(t_twostacks *indexStacks, int data);
void				push2(t_twostacks *indexStacks, int data);
int					pop1(t_twostacks *indexStacks);
int					pop2(t_twostacks *indexStacks);
int					is_empty1(t_twostacks *indexStacks);
int					is_empty2(t_twostacks *indexStacks);
void				sa(t_twostacks *indexStacks);
void				sb(t_twostacks *indexStacks);
void				ss(t_twostacks *indexStacks);
void				pb(t_twostacks *indexStacks);
void				pa(t_twostacks *indexStacks);
void				ra(t_twostacks *indexStacks);
void				rb(t_twostacks *indexStacks);
void				rr(t_twostacks *indexStacks);
void				rra(t_twostacks *indexStacks);
void				rrb(t_twostacks *indexStacks);
void				rrr(t_twostacks *indexStacks);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_swap(void *a, void *b, size_t size);
int					compare(const void *a, const void *b);
void				print_stack(t_twostacks *stacks);
void				push_numbers_to_stack(t_twostacks *stacks, int argc,
						char *argv[]);
void				create_num_array(int argc, char *argv[], int nums[]);
void				fill_index_stack(t_twostacks *stacks,
						t_twostacks *indexStacks,
						int argc,
						int nums[]);
int					main(int argc, char *argv[]);
int					compare(const void *a, const void *b);
void				sortfor3(t_twostacks *indexStacks);
void				sortfor5(t_twostacks *indexStacks);
int					is_sorted(t_twostacks *indexStacks);
void				test(t_twostacks *indexStacks);
void				stackargv(char *argv[]);
int					is_sorted2(t_twostacks *indexStacks);
void				sortfor4(t_twostacks *indexStacks);
void				sort_for_up_to_100(t_twostacks *indexStacks);
void				sort_100(t_twostacks *indexStacks);
int					ft_lstsize(t_twostacks *indexStacks, int flag);
void				ft_qsort(void *arr, int n, size_t size);
void				put_on_top_b(t_twostacks *indexStacks, t_node *head,
						int len, int val);
void				put_on_top_a(t_twostacks *indexStacks, t_node *head,
						int len, int val);
int					mean_value(t_twostacks *indexStacks);
int					count_moves(t_node *head, int len, int value);
int					get_cost(t_twostacks *indexStacks, int bf, int b_val);
void				ft_lstclear(t_twostacks *indexStacks);
int					compare(const void *a, const void *b);

#endif
