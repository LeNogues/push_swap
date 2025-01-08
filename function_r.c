/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:47:07 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/07 11:30:40 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rb(t_list **b)
{
	t_list	*first_node;
	t_list	*last_node;

	first_node = *b;
	last_node = *b;
	if (!b || !(*b) || (*b)->next == NULL)
		return ;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	(*b) = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
	ft_printf("rb\n");
}

void	ra(t_list **a)
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
