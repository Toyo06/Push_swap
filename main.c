/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:37:25 by sroggens          #+#    #+#             */
/*   Updated: 2022/11/15 07:32:44 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*lista;
	t_node	*listb;
	t_base	base;

	if (argc == 1)
		exiteror();
	if (argc == 2 && ft_strlen(argv[1]) == 0)
		exit(0);
	parsing2(&base, argv, argc);
	prepalist(&lista, &base);
	checkorder(&lista);
	bigandlownb(&lista, &base);
	if (base.opti.totalarg == 3)
		algo3(&lista, &base);
	else if (base.opti.totalarg > 3)
		algoother1(&lista, &listb, &base);
	writeopti(&base);
	finalplacement(&lista, &base);
	writeopti(&base);
}
