/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:44:38 by viktortr          #+#    #+#             */
/*   Updated: 2023/06/05 23:31:23 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_on_top_b(t_twostacks *indexStacks, t_node *head, int len, int val)
{
	int	count;

	count = 0;
	while (head->data != val)
	{
		count++;
		head = head->next;
	}
	if (count > (float)(len / 2))
	{
		count = len - count;
		while (count-- != 0)
			rrb(indexStacks);
	}
	else
	{
		while (count-- != 0)
			rb(indexStacks);
	}
}

void	put_on_top_a(t_twostacks *indexStacks, t_node *head, int len, int val)
{
	int	count;

	count = 0;
	while (head != NULL && head->data != val)
	{
		count++;
		head = head->next;
	}
	if (count > (float)(len / 2))
	{
		count = len - count;
		while (count-- != 0)
			rra(indexStacks);
	}
	else
	{
		while (count-- != 0)
			ra(indexStacks);
	}
}

int	mean_value(t_twostacks *indexStacks)
{
	t_node	*current;
	int		total;
	int		count;
	int		mean;

	total = 0;
	count = 0;
	current = indexStacks->top1;
	while (current != NULL)
	{
		total += current->data;
		count++;
		current = current->next;
	}
	mean = total / count;
	return (mean);
}

int	count_moves(t_node *head, int len, int value)
{
	int	count;

	count = 0;
	while (head != NULL && head->data != value)
	{
		count++;
		head = head->next;
	}
	if (count > (float)(len / 2))
		return (len - count);
	return (count);
}

int	get_cost(t_twostacks *indexStacks, int bf, int b_val)
{
	t_node		*tmp_a;
	t_node		*tmp_b;
	static int	moves;

	tmp_a = indexStacks->top1;
	tmp_b = indexStacks->top2;
	moves = count_moves(tmp_a, ft_lstsize(indexStacks, 1), bf);
	moves += count_moves(tmp_b, ft_lstsize(indexStacks, 0), b_val);
	return (moves);
}
