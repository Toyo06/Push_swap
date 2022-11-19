/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algo_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:17:45 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/22 10:25:23 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	searchafter(t_node **heada, t_base *base)
{
	t_node	*tmp;

	tmp = (*heada);
	base->calcul.justafter = base->calcul.truehightnb;
	if (base->calcul.actualtest == base->calcul.truehightnb)
	{
		base->calcul.justafter = base->calcul.truelownb;
		return ;
	}
	while (tmp)
	{
		if (tmp->data > base->calcul.actualtest
			&& tmp->data < base->calcul.justafter)
			base->calcul.justafter = tmp->data;
		tmp = tmp->next;
	}
}

void	bigandlownb(t_node **heada, t_base *base)
{
	t_node	*tmp;

	tmp = (*heada);
	base->calcul.truelownb = tmp->data;
	base->calcul.truehightnb = tmp->data;
	while (tmp)
	{
		if (tmp->data > base->calcul.truehightnb)
			base->calcul.truehightnb = tmp->data;
		if (tmp->data < base->calcul.truelownb)
			base->calcul.truelownb = tmp->data;
		tmp = tmp->next;
	}
}

int	searchfrombotom(t_node **heada, t_base *base)
{
	t_node	*tmp;
	int		i;

	tmp = (*heada);
	i = 0;
	while (tmp)
	{
		if (tmp->data == base->calcul.justafter)
		{
			base->calcul.testnode = tmp->data;
			return (i);
		}
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	nextnodetopush(t_node **heada, t_node **headb, t_base *base)
{
	t_node	*tmpb;
	int		i;

	tmpb = (*headb);
	i = 0;
	base->calcul.optimove = base->opti.totalarg * 2;
	while (tmpb)
	{
		base->calcul.actualtest = tmpb->data;
		searchafter(heada, base);
		base->calcul.totalmove = searchfrombotom(heada, base) + i;
		if (base->calcul.totalmove < base->calcul.optimove)
		{
			base->calcul.optimove = base->calcul.totalmove;
			base->calcul.nextnode = base->calcul.testnode;
			base->calcul.nextnodeb = base->calcul.actualtest;
		}
		tmpb = tmpb->next;
		i++;
	}
}
