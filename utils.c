/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:02:43 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/12/22 14:51:11 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ra_bis(t_list **a)
{
	t_list	*first_node;
	t_list	*last_node;

	first_node = *a;
	last_node = *a;
	if (!a || !(*a) || (*a)->next == NULL)
		return ;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	(*a) = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
	ft_printf("ra\n");
}

int	cost_to_smaller(t_list **a, t_list **b, int index)
{
	int		cost_ra;
	int		cost_rra;
	t_list	*temp_a;
	t_list	*temp_b;

	cost_ra = 0;
	cost_rra = 0;
	temp_a = *a;
	temp_b = *b;
	if (ft_atoi(temp_a->content) == index)
		return (1);
	if (ft_atoi(temp_a->next->content) == index)
		return (1);
	if (ft_atoi(temp_a->next->next->content) == index)
		return (1);
	return (0);
}

void	fill_with_smaller(t_list **a, t_list **b, int size)
{
	int	index;

	index = 1;
	while (index <= size)
	{
		if (cost_to_smaller(a, b, index) == 1)
		{
			while (ft_atoi((*a)->content) != index)
			{
				ra_bis(a);
			}
		}
		else
		{
			while (ft_atoi((*a)->content) != index)
			{
				rra(a);
			}
		}
		pb(a, b);
		index++;
	}
}
