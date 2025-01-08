/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:47:03 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/08 14:14:04 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	verif_state_tab(int *list_sorted, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (list_sorted[i] > list_sorted[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_double(int *list_sorted, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (list_sorted[i] == list_sorted[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	bubble_sort(int *list_sorted, int size)
{
	int	i;
	int	temp;

	while (!verif_state_tab(list_sorted, size))
	{
		i = 0;
		while (i < size - 1)
		{
			if (list_sorted[i] > list_sorted[i + 1])
			{
				temp = list_sorted[i];
				list_sorted[i] = list_sorted[i + 1];
				list_sorted[i + 1] = temp;
			}
			i++;
		}
	}
	if (check_double(list_sorted, size) == 0)
		return (0);
	return (1);
}

void	change_a_value(t_list *temp_a, int *list_sorted)
{
	int		min_index;
	char	*new_content;

	while (temp_a != NULL)
	{
		min_index = 0;
		while (ft_atoi(temp_a->content) != list_sorted[min_index])
		{
			min_index++;
		}
		new_content = ft_itoa(min_index + 1);
		free(temp_a->content);
		temp_a->content = new_content;
		temp_a = temp_a->next;
	}
}

int	convert_a(t_list **a)
{
	int				min_index;
	int				*list_sorted;
	t_list			*temp_a;
	const int		size = ft_lstsize(*a);

	min_index = 0;
	temp_a = *a;
	list_sorted = malloc(sizeof(int) * size);
	if (!list_sorted)
		return (0);
	while (temp_a != NULL)
	{
		list_sorted[min_index] = ft_atoi(temp_a->content);
		temp_a = temp_a->next;
		min_index++;
	}
	temp_a = *a;
	if (bubble_sort(list_sorted, size) == 0)
	{
		free(list_sorted);
		return (0);
	}
	change_a_value(temp_a, list_sorted);
	free(list_sorted);
	return (1);
}
