/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algo_other2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:06:03 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/26 14:02:34 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divlist(t_node **heada, t_node **headb, t_base *base)
{
	base->calcul.divlista = (countlist(heada) / 2);
	base->calcul.divlistb = countlist(headb) / 2;
	if (base->calcul.divlista * 2 != countlist(heada))
		base->calcul.divlista = (countlist(heada) / 2) + 1;
	if (base->calcul.divlistb * 2 != countlist(headb))
		base->calcul.divlistb = (countlist(headb) / 2) + 1;
}

int	calculmovelista(t_node **heada, t_base *base)
{
	t_node	*tmp;
	int		i;

	tmp = (*heada);
	i = 0;
	base->calcul.falserra = 0;
	while (tmp->data != base->calcul.justafter)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > base->calcul.divlista)
	{
		i = i - (countlist(heada) - 1);
		if (i < 0)
			i *= -1;
		base->calcul.falserra = 1;
	}
	base->calcul.testnode = tmp->data;
	base->calcul.movea = i;
	return (i);
}

void	nextnodetopushbis(t_node **heada, t_node **headb, t_base *base)
{
	t_node	*tmpb;
	int		i;
	int		j;

	tmpb = (*headb);
	i = 0;
	base->calcul.optimove = base->opti.totalarg * 2;
	base->calcul.falserrb = 0;
	while (tmpb)
	{
		base->calcul.actualtest = tmpb->data;
		searchafter(heada, base);
		if (i > base->calcul.divlistb && countlist(headb) > 1)
			j = setjalgo(headb, base, j, i);
		else
			j = i;
		base->calcul.totalmove = calculmovelista(heada, base) + j;
		base->calcul.moveb = j;
		if (base->calcul.totalmove < base->calcul.optimove)
			setvalueforalgo(base, j);
		tmpb = tmpb->next;
		i++;
	}
	if (base->calcul.totalmove < base->calcul.optimove)
		setvalueforalgo(base, j);
}

void	setvalueforalgo(t_base *base, int j)
{
	base->calcul.optimove = base->calcul.totalmove;
	base->calcul.nextnode = base->calcul.testnode;
	base->calcul.countmoveb = j;
	base->calcul.countmovea = base->calcul.movea;
	base->calcul.nextnodeb = base->calcul.actualtest;
	base->calcul.truerrb = base->calcul.falserrb;
	base->calcul.truerra = base->calcul.falserra;
}

int	setjalgo(t_node **headb, t_base *base, int j, int i)
{
	j = i - (countlist(headb) - 1);
	base->calcul.falserrb = 1;
	if (j < 0)
		j *= -1;
	return (j);
}
