/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Final_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 02:56:28 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/21 14:26:08 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	countbybot(t_node **heada, t_base *base)
{
	t_node	*tmp;

	tmp = (*heada);
	base->finals.bybot = 0;
	while (tmp->data != base->calcul.truelownb)
	{
		tmp = tmp->next;
		base->finals.bybot++;
	}
}

void	finalplacement(t_node **heada, t_base *base)
{
	countbybot(heada, base);
	if (base->finals.bybot > countlist(heada) / 2)
		while ((*heada)->data != base->calcul.truelownb)
			rra(heada, base, 0);
	else
		while ((*heada)->data != base->calcul.truelownb)
			ra(heada, base, 0);
}
