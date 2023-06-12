/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:28:33 by viktortr          #+#    #+#             */
/*   Updated: 2023/06/12 16:45:54 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	print_stack(t_twostacks *t_twostacks)
{
	t_node	*current;

	current = t_twostacks->top1;
	printf("Stack contents:\n");
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
	current = t_twostacks->top2;
	printf("Stack contents:\n");
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}*/

void	algorithms(int argc, char *argv[])
{
	int			nums;
	t_twostacks	stacks;
	int			*numarray;
	t_twostacks	index_stacks;

	nums = argc - 1;
	duplicates(argc, argv);
	numarray = malloc(nums * sizeof(int));
	stacks = create_two_stacks(&index_stacks);
	push_numbers_to_stack(&stacks, argc, argv);
	create_num_array(argc, argv, numarray);
	ft_qsort(numarray, argc - 1, sizeof(int));
	index_stacks = create_two_stacks(&index_stacks);
	fill_index_stack(&stacks, &index_stacks, argc, numarray);
	if (argc - 1 <= 3 && argc - 1 > 1)
		sortfor3(&index_stacks);
	if (argc - 1 == 5)
		sortfor5(&index_stacks);
	if (argc - 1 == 4)
		sortfor4(&index_stacks);
	if (argc - 1 > 5)
		sort_100(&index_stacks);
	ft_lstclear(&index_stacks);
	free(numarray);
}

int	main(int argc, char *argv[])
{
	algorithms(argc, argv);
	return (0);
}
