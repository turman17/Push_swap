/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:28:09 by viktortr          #+#    #+#             */
/*   Updated: 2023/06/09 14:29:28 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bf(t_twostacks *indexStacks, int b_val)
{
	t_node	*tmp;
	int		bf;

	bf = INT_MAX;
	tmp = indexStacks->top1;
	while (tmp)
	{
		if (tmp->data > b_val && bf > tmp->data)
			bf = tmp->data;
		tmp = tmp->next;
	}
	return (bf);
}

int	get_lowest_cost(t_twostacks *indexStacks)
{
	t_node	*tmp_b;
	int		bf;
	int		lowestcost;
	int		cost;
	int		best_nbr;

	lowestcost = INT_MAX;
	tmp_b = indexStacks->top2;
	while (tmp_b)
	{
		bf = get_bf(indexStacks, tmp_b->data);
		cost = get_cost(indexStacks, bf, tmp_b->data);
		if (cost < lowestcost)
		{
			best_nbr = tmp_b->data;
			lowestcost = cost;
		}
		tmp_b = tmp_b->next;
	}
	return (best_nbr);
}

void	sort_100(t_twostacks *indexStacks)
{
	int	b_val;
	int	bf;

	mean_value(indexStacks);
	while (ft_lstsize(indexStacks, 1) > 5 && !is_sorted(indexStacks))
	{
		if (indexStacks->top1->data <= mean_value(indexStacks))
			pb(indexStacks);
		else
			ra(indexStacks);
	}
	sortfor5(indexStacks);
	while (indexStacks->top2 != NULL)
	{
		b_val = get_lowest_cost(indexStacks);
		bf = get_bf(indexStacks, b_val);
		put_on_top_b(indexStacks, indexStacks->top2, ft_lstsize(indexStacks, 0),
			b_val);
		put_on_top_a(indexStacks, indexStacks->top1, ft_lstsize(indexStacks, 1),
			bf);
		pa(indexStacks);
	}
	while (!is_sorted(indexStacks))
		ra(indexStacks);
}
