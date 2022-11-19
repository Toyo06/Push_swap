/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algo_by3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:48:36 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/21 14:24:14 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo3(t_node **head, t_base *base)
{
	if ((*head)->data < (*head)->next->data
		&& (*head)->next->data < (*head)->next->next->data)
		return ;
	if ((*head)->data < (*head)->next->data
		&& (*head)->next->data > (*head)->next->next->data
		&& (*head)->data < (*head)->next->next->data)
	{
		sa(head, base, 0);
		ra(head, base, 0);
	}
	else if ((*head)->data > (*head)->next->data
		&& (*head)->data < (*head)->next->next->data
		&& (*head)->next->data < (*head)->next->next->data)
		sa(head, base, 0);
	else if ((*head)->data < (*head)->next->data
		&& (*head)->data > (*head)->next->next->data
		&& (*head)->next->data > (*head)->next->next->data)
		rra(head, base, 0);
	else if ((*head)->next->next->data > (*head)->next->data)
		ra(head, base, 0);
	else
	{
		sa(head, base, 0);
		rra(head, base, 0);
	}
}
