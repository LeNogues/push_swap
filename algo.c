/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:47:00 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/06 19:15:30 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	verif_state_list(t_list **a, t_list **b)
{
	t_list	*temp_a;

	temp_a = *a;
	if (b != NULL && *b != NULL)
		return (0);
	while (temp_a->next != NULL)
	{
		if (ft_atoi(temp_a->content) > ft_atoi(temp_a->next->content))
			return (0);
		temp_a = temp_a->next;
	}
	return (1);
}

int	verif_state_list_a(t_list **a)
{
	t_list	*temp_a;

	temp_a = *a;
	while (temp_a->next != NULL)
	{
		if (ft_atoi(temp_a->content) > ft_atoi(temp_a->next->content))
			return (0);
		temp_a = temp_a->next;
	}
	return (1);
}

void	ft_radix_sort(t_list **a, t_list **b)
{
	int	i;
	int	size;
	int	lap;

	size = ft_lstsize(*a);
	i = 0;
	while (!verif_state_list(a, b))
	{
		lap = 0;
		while (lap < size)
		{
			if (*a == NULL)
				break ;
			if (((ft_atoi((*a)->content) >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			lap++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

void	ft_small_sort(t_list **a, t_list **b)
{
	while (verif_state_list_a(a) != 1)
	{
		if (ft_lstsize(*a) > 3)
			fill_with_smaller(a, b, ft_lstsize(*a) - 3);
		if (ft_atoi((*a)->content) > ft_atoi((*a)->next->content))
			sa(a);
		if (ft_lstsize(*a) == 3)
		{
			if (ft_atoi((*a)->content) > ft_atoi((*a)->next->content)
				&& ft_atoi((*a)->content) > ft_atoi((*a)->next->next->content))
				ra(a);
			if (ft_atoi((*a)->content) > ft_atoi((*a)->next->content))
				sa(a);
			if (ft_atoi((*a)->next->content)
				> ft_atoi((*a)->next->next->content))
				rra(a);
		}
	}
	while (ft_lstsize(*b) != 0)
		pa(a, b);
}

void	choose_algo(t_list **a, t_list **b)
{
	const int	size = ft_lstsize((*a));

	if (size >= 6)
		ft_radix_sort(&(*a), &(*b));
	else if (size == 2)
	{
		if (!verif_state_list(&(*a), &(*b)))
			ra(&(*a));
	}
	else
	{
		ft_small_sort(&(*a), &(*b));
	}
}

/* Premier algo maison : 15 000 operation pour 100 nombres


	while(verif_state(&a, &b) == 0)
	{
		while(a != NULL)
		{
			pb(&a, &b);
		}
		while(b != NULL)
		{
			pa(&a, &b);
			if(a->next != NULL)
			{
				if(ft_atoi(a->content) > ft_atoi(a->next->content))
					ra(&a);
			}
		}
	}
*/