/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algo_other1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:27:10 by sroggens          #+#    #+#             */
/*   Updated: 2022/11/11 21:03:36 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algoother1(t_node **heada, t_node **headb, t_base *base)
{
	while (countlist(heada) > 3)
	{
		if ((*heada)->data == base->calcul.truehightnb)
			ra(heada, base, 0);
		pb(headb, heada, base);
	}
	algo3(heada, base);
	while (countlist(headb) > 0)
	{
		divlist(heada, headb, base);
		nextnodetopushbis(heada, headb, base);
		if (base->calcul.truerra == 0 && base->calcul.truerrb == 0)
			algootherpart1(heada, headb, base);
		else if (base->calcul.truerra == 1 && base->calcul.truerrb == 1)
			algootherpart2(heada, headb, base);
		else
			algootherpart3(heada, headb, base);
		pa(heada, headb, base);
	}
}

void	algootherpart1(t_node **heada, t_node **headb, t_base *base)
{
	while ((*headb)->data != base->calcul.nextnodeb
		|| (*heada)->data != base->calcul.nextnode)
	{
		if ((*heada)->data != base->calcul.nextnode)
			ra(heada, base, 0);
		if ((*headb)->data != base->calcul.nextnodeb)
			rb(headb, base, 0);
	}
}

void	algootherpart2(t_node **heada, t_node **headb, t_base *base)
{
	while ((*heada)->data != base->calcul.nextnode
		|| (*headb)->data != base->calcul.nextnodeb)
	{
		if ((*heada)->data != base->calcul.nextnode)
			rra(heada, base, 0);
		if ((*headb)->data != base->calcul.nextnodeb)
			rrb(headb, base, 0);
	}
}

void	algootherpart3(t_node **heada, t_node **headb, t_base *base)
{
	if (base->calcul.truerrb == 0)
	{
		while ((*heada)->data != base->calcul.nextnode
			|| (*headb)->data != base->calcul.nextnodeb)
		{
			if ((*heada)->data != base->calcul.nextnode)
				rra(heada, base, 0);
			if ((*headb)->data != base->calcul.nextnodeb)
				rb(headb, base, 0);
		}
	}
	if (base->calcul.truerra == 0)
	{
		while ((*heada)->data != base->calcul.nextnode
			|| (*headb)->data != base->calcul.nextnodeb)
		{
			if ((*heada)->data != base->calcul.nextnode)
				ra(heada, base, 0);
			if ((*headb)->data != base->calcul.nextnodeb)
				rrb(headb, base, 0);
		}
	}
}
