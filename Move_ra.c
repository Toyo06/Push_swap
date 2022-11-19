/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mouve_ra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:53:17 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/19 04:32:36 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optira(t_base *base)
{
	if (base->opti.totalcommand == 0)
	{
		base->opti.ra = 1;
		base->opti.totalcommand = 1;
	}
	else
	{
		base->opti.ra += 2;
		base->opti.totalcommand = 3;
	}
	if (base->opti.totalcommand == 3)
		writeopti(base);
}

void	optirb(t_base *base)
{
	if (base->opti.totalcommand == 0)
	{
		base->opti.rb = 1;
		base->opti.totalcommand = 1;
	}
	else
	{
		base->opti.rb += 2;
		base->opti.totalcommand = 3;
	}
	if (base->opti.totalcommand == 3)
		writeopti(base);
}

void	ra(t_node **head, t_base *base, int nb)
{
	t_node	*tmp;
	int		datatmp;

	tmp = (*head);
	datatmp = tmp->data;
	while (tmp->next)
	{
		tmp->data = tmp->next->data;
		tmp = tmp->next;
	}
	tmp->data = datatmp;
	if (nb == 0)
		optira(base);
}

void	rb(t_node **head, t_base *base, int nb)
{
	t_node	*tmp;
	int		datatmp;

	tmp = (*head);
	datatmp = tmp->data;
	while (tmp->next)
	{
		tmp->data = tmp->next->data;
		tmp = tmp->next;
	}
	tmp->data = datatmp;
	if (nb == 0)
		optirb(base);
}
