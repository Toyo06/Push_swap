/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mouve_rra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:50:03 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/22 10:01:37 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optirra(t_base *base)
{
	if (base->opti.totalcommand == 0)
	{
		base->opti.totalcommand = 1;
		base->opti.rra = 1;
	}
	else
	{
		base->opti.totalcommand = 3;
		base->opti.rra += 2;
	}
	if (base->opti.totalcommand == 3)
		writeopti(base);
}

void	optirrb(t_base *base)
{
	if (base->opti.totalcommand == 0)
	{
		base->opti.totalcommand = 1;
		base->opti.rrb = 1;
	}
	else
	{
		base->opti.totalcommand = 3;
		base->opti.rrb += 2;
	}
	if (base->opti.totalcommand == 3)
		writeopti(base);
}

void	rra(t_node **list, t_base *base, int nb)
{
	t_node	*tail;
	t_node	*head;

	tail = (*list);
	head = (*list);
	while (tail->next)
		tail = tail->next;
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = (*list);
	(*list) = tail;
	optirra(base);
	nb += nb;
}

void	rrb(t_node **list, t_base *base, int nb)
{
	t_node	*tail;
	t_node	*head;

	tail = (*list);
	head = (*list);
	while (tail->next)
		tail = tail->next;
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = (*list);
	(*list) = tail;
	optirrb(base);
	nb += nb;
}
