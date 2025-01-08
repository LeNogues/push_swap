/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:47:05 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/12/12 11:57:22 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*node_to_push;

	if (!b || !(*b))
		return ;
	node_to_push = *b;
	*b = (*b)->next;
	if (!*a)
		node_to_push->next = NULL;
	ft_lstadd_front(a, node_to_push);
	ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*node_to_push;

	if (!a || !(*a))
		return ;
	node_to_push = *a;
	*a = (*a)->next;
	if (!*b)
		node_to_push->next = NULL;
	ft_lstadd_front(b, node_to_push);
	ft_printf("pb\n");
}
