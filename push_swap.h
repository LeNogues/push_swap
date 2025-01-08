/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:48:13 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/01/07 11:30:02 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	sa(t_list **a);
void	sb(t_list **b);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
int		verif_argv(char *str);
int		create_node(t_list **a, char *argv);
void	ft_radix_sort(t_list **a, t_list **b);
int		verif_state_tab(int *list_sorted, int size);
int		bubble_sort(int *list_sorted, int size);
int		convert_a(t_list **a);
char	*create_single_line(int argc, char **argv);
void	free_this_stack(t_list **stack);
void	free_all(t_list **stack, char *str);
void	choose_algo(t_list **a, t_list **b);
int		cost_to_smaller(t_list **a, t_list **b, int index);
void	fill_with_smaller(t_list **a, t_list **b, int size);

#endif