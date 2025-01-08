/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:47:10 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/07 11:30:45 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rrb(t_list **b)
{
	t_list	*first_node;
	t_list	*before_last_node;
	t_list	*last_node;

	before_last_node = *b;
	last_node = *b;
	first_node = *b;
	if (!b || !(*b) || (*b)->next == NULL)
		return ;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
		if (last_node->next != NULL)
			before_last_node = last_node;
	}
	(*b) = last_node;
	last_node->next = first_node;
	before_last_node->next = NULL;
	ft_printf("rrb\n");
}

void	rra(t_list **a)
{
	t_list	*first_node;
	t_list	*before_last_node;
	t_list	*last_node;

	before_last_node = *a;
	last_node = *a;
	first_node = *a;
	if (!a || !(*a) || (*a)->next == NULL)
		return ;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
		if (last_node->next != NULL)
			before_last_node = last_node;
	}
	(*a) = last_node;
	last_node->next = first_node;
	before_last_node->next = NULL;
	ft_printf("rra\n");
}
