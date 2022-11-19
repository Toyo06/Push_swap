/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:42:39 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/22 09:58:49 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optipa(t_base *base)
{
	if (base->opti.totalcommand == 0)
	{
		base->opti.totalcommand = 1;
		base->opti.pa = 1;
	}
	else
	{
		base->opti.totalcommand = 3;
		base->opti.pa += 2;
	}
	if (base->opti.totalcommand == 3)
		writeopti(base);
}

void	optipb(t_base *base)
{
	if (base->opti.totalcommand == 0)
	{
		base->opti.totalcommand = 1;
		base->opti.pb = 1;
	}
	else
	{
		base->opti.totalcommand = 3;
		base->opti.pb += 2;
	}
	if (base->opti.totalcommand == 3)
		writeopti(base);
}

void	pb(t_node **headb, t_node **heada, t_base *base)
{
	t_node	*tmp;

	tmp = (*heada);
	(*heada) = (*heada)->next;
	tmp->next = (*headb);
	(*headb) = tmp;
	optipb(base);
}

void	pa(t_node **heada, t_node **headb, t_base *base)
{
	t_node	*tmp;

	tmp = (*headb);
	(*headb) = (*headb)->next;
	tmp->next = (*heada);
	(*heada) = tmp;
	optipa(base);
}
