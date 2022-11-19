/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:36:03 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/22 10:25:59 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepalist(t_node **lista, t_base *base)
{
	int		j;
	t_node	*new_node;

	j = 0;
	addnode(lista, base->parsing.tabint[j]);
	j++;
	while (j < base->parsing.totaltab)
	{
		addnode(&new_node, base->parsing.tabint[j]);
		addnextnode(lista, new_node);
		j++;
	}
}
