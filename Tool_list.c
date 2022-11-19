/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:37:37 by sroggens          #+#    #+#             */
/*   Updated: 2022/11/13 15:40:48 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addnode(t_node **head, int nb)
{
	(*head) = malloc(sizeof(t_node));
	(*head)->data = nb;
	(*head)->next = NULL;
}

void	addnextnode(t_node **head, t_node *new_node)
{
	t_node	*tmp;

	tmp = (*head);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	tmp->next->next = NULL;
}

void	printthelist(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp)
	{
		ft_printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

void	malloclistb(t_node **headb)
{
	(*headb) = malloc(sizeof(t_node));
}

int	countlist(t_node **head)
{
	int		i;
	t_node	*tmp;

	tmp = (*head);
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
