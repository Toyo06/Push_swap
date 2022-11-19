/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupopti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:01:42 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/21 16:13:27 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setvalueopti(t_base *base)
{
	base->opti.ra = 0;
	base->opti.rb = 0;
	base->opti.sa = 0;
	base->opti.sb = 0;
	base->opti.rra = 0;
	base->opti.rrb = 0;
	base->opti.pa = 0;
	base->opti.pb = 0;
	base->opti.totalcommand = 0;
}

void	printnoopti(t_base *base)
{
	printfirst(base);
	seekopti(base);
}

void	printoptibis(t_base *base)
{
	if (base->opti.rra + base->opti.rrb == 3 && (base->opti.rra
			!= 3 && base->opti.rrb != 3))
	{
		ft_printf("rrr\n");
		base->opti.rra = 0;
		base->opti.rrb = 0;
		base->opti.totalcommand = 0;
	}
}

void	printopti(t_base *base)
{
	if (base->opti.ra + base->opti.rb == 3 && (base->opti.ra
			!= 3 && base->opti.rb != 3))
	{
		ft_printf("rr\n");
		base->opti.ra = 0;
		base->opti.rb = 0;
		base->opti.totalcommand = 0;
	}
	if (base->opti.sa + base->opti.sb == 3 && (base->opti.sa
			!= 3 && base->opti.sb != 3))
	{
		ft_printf("ss\n");
		base->opti.sa = 0;
		base->opti.sb = 0;
		base->opti.totalcommand = 0;
	}
	printoptibis(base);
}

void	writeopti(t_base *base)
{
	printopti(base);
	printnoopti(base);
}
