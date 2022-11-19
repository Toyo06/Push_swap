/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mouve_sa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:46:38 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/19 04:32:53 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **head, t_base *base, int nb)
{
	int	tmp;

	tmp = (*head)->data;
	(*head)->data = (*head)->next->data;
	(*head)->next->data = tmp;
	if (nb == 0)
	{
		if (base->opti.totalcommand == 0)
		{
			base->opti.sa = 1;
			base->opti.totalcommand = 1;
		}
		else
		{
			base->opti.totalcommand = 3;
			base->opti.sa += 2;
		}
		if (base->opti.totalcommand == 3)
			writeopti(base);
	}
}

void	sb(t_node **head, t_base *base, int nb)
{
	int	tmp;

	tmp = (*head)->data;
	(*head)->data = (*head)->next->data;
	(*head)->next->data = tmp;
	if (nb == 0)
	{
		if (base->opti.totalcommand == 0)
		{
			base->opti.sb = 1;
			base->opti.totalcommand = 1;
		}
		else
		{
			base->opti.sb += 2;
			base->opti.totalcommand = 3;
		}
		if (base->opti.totalcommand == 3)
			writeopti(base);
	}
}
