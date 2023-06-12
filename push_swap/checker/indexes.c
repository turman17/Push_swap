/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:30:18 by viktortr          #+#    #+#             */
/*   Updated: 2023/06/03 16:23:04 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare(const void *a, const void *b)
{
	int	num1;
	int	num2;
	int	result;

	num1 = *(const int *)a;
	num2 = *(const int *)b;
	result = (num1 > num2) - (num1 < num2);
	return (result);
}

void	push_numbers_to_stack(t_twostacks *stacks, int argc, char *argv[])
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		push1(stacks, num);
		i++;
	}
}

void	create_num_array(int argc, char *argv[], int nums[])
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		nums[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

void	fill_index_stack(t_twostacks *stacks, t_twostacks *indexStacks,
		int argc, int nums[])
{
	int	i;
	int	num;
	int	custom_index;

	while (!is_empty1(stacks))
	{
		num = pop1(stacks);
		custom_index = -1;
		i = 0;
		while (i < argc - 1)
		{
			if (nums[i] == num)
			{
				custom_index = i + 1;
				break ;
			}
			i++;
		}
		if (custom_index == -1)
			exit(1);
		push1(indexStacks, custom_index);
	}
}
