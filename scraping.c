/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scraping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:47:25 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/07 11:18:53 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

char	*create_single_line(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*temp;
	char	*new_str;

	i = 2;
	str = ft_strdup(argv[1]);
	while (i < argc)
	{
		temp = ft_strjoin(str, " ");
		new_str = ft_strjoin(temp, argv[i]);
		free(temp);
		free(str);
		str = new_str;
		i++;
	}
	i = 0;
	while (str[i] && str[i] == 32)
	{
		i++;
	}
	if (!str[i])
		return (0);
	return (str);
}

int	verif_argv(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
		{
			if (str[i] != '-')
			{
				free(str);
				return (0);
			}
			else if (str[i + 1] < '0' || str[i + 0] > '9')
			{
				free(str);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	create_node(t_list **a, char *argv)
{
	int		i;
	char	**list_splited;
	t_list	*new_node;
	char	*str;

	i = 0;
	new_node = *a;
	list_splited = ft_split(argv, ' ');
	while (list_splited[i] != 0)
	{
		str = ft_itoa(ft_atoi(list_splited[i]));
		if (ft_strncmp(str, list_splited[i], ft_strlen(list_splited[i])) != 0)
		{
			while (list_splited[i])
				free(list_splited[i++]);
			return (free(str), free(list_splited), 0);
		}
		free(str);
		new_node = ft_lstnew(list_splited[i]);
		if (!new_node)
			return (free(new_node), 0);
		ft_lstadd_back(a, new_node);
		i++;
	}
	return (free(list_splited), 1);
}
