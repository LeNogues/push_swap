/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:47:22 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/08 14:17:29 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*str;
	int		result;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	str = ft_strdup(argv[1]);
	if (argc > 2)
	{
		free(str);
		str = create_single_line(argc, argv);
	}
	if (!verif_argv(str) || str[0] == 0 || str[0] == 32)
		return (write(2, "Error\n", 6), free(str), 0);
	result = create_node(&a, str);
	if (result == 0)
		return (write(2, "Error\n", 6), free_all(&a, str), 0);
	if (convert_a(&a) == 0)
		return (write(2, "Error\n", 6), free_all(&a, str), 0);
	choose_algo(&a, &b);
	free_all(&a, str);
	(void)result;
}
