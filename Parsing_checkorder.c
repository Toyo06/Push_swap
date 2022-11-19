/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_checkorder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:33:19 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/26 14:06:25 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkorder(t_node **heada)
{
	t_node	*tmp;

	tmp = (*heada);
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return ;
		tmp = tmp->next;
	}
	exit (0);
}
