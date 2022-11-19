/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupoptibis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:16:16 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/21 14:07:28 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	seekopti(t_base *base)
{
	if (base->opti.ra >= 2)
		base->opti.ra = 1;
	else if (base->opti.rb >= 2)
		base->opti.rb = 1;
	else if (base->opti.sa >= 2)
		base->opti.sa = 1;
	else if (base->opti.sb >= 2)
		base->opti.sa = 1;
	else if (base->opti.rra >= 2)
		base->opti.rra = 1;
	else if (base->opti.rrb >= 2)
		base->opti.rrb = 1;
	else if (base->opti.pa >= 2)
		base->opti.pa = 1;
	else if (base->opti.pb >= 2)
		base->opti.pb = 1;
}

void	printfirstbis(t_base *base)
{
	if (base->opti.pa == 1)
	{
		ft_printf("pa\n");
		base->opti.pa = 0;
	}
	else if (base->opti.pb == 1)
	{
		ft_printf("pb\n");
		base->opti.pb = 0;
	}
	else if (base->opti.sa == 1)
	{
		ft_printf("sa\n");
		base->opti.sa = 0;
	}
	else if (base->opti.sb == 1)
	{
		ft_printf("sb\n");
		base->opti.sb = 0;
	}
}

void	printfirstbis2(t_base *base)
{
	if (base->opti.sa == 3)
	{
		ft_printf("sa\n");
		base->opti.sa = 2;
	}
	else if (base->opti.sb == 3)
	{
		ft_printf("sb\n");
		base->opti.sb = 2;
	}
	else if (base->opti.pa == 3)
	{
		ft_printf("pa\n");
		base->opti.pa = 2;
	}
	else if (base->opti.pb == 3)
	{
		ft_printf("pb\n");
		base->opti.pb = 2;
	}
}

void	printfirstbis1(t_base *base)
{
	if (base->opti.ra == 3)
	{
		ft_printf("ra\n");
		base->opti.ra = 2;
	}
	else if (base->opti.rb == 3)
	{
		ft_printf("rb\n");
		base->opti.rb = 2;
	}
	else if (base->opti.rra == 3)
	{
		ft_printf("rra\n");
		base->opti.rra = 2;
	}
	else if (base->opti.rrb == 3)
	{
		ft_printf("rrb\n");
		base->opti.rrb = 2;
	}
	printfirstbis2(base);
}

void	printfirst(t_base *base)
{
	if (base->opti.ra == 1)
	{
		ft_printf("ra\n");
		base->opti.ra = 0;
	}
	else if (base->opti.rb == 1)
	{
		ft_printf("rb\n");
		base->opti.rb = 0;
	}
	else if (base->opti.rra == 1)
	{
		ft_printf("rra\n");
		base->opti.rra = 0;
	}
	else if (base->opti.rrb == 1)
	{
		ft_printf("rrb\n");
		base->opti.rrb = 0;
	}
	printfirstbis(base);
	printfirstbis1(base);
}
