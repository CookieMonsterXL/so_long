/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:34:14 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/03 17:06:37 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/so_long.h"


int	main(int argc, char **argv)
{
	t_sl	solong;

	initvar(&solong);
	if (argc == 1)
		showerror(&solong, "Missing map (./so_long maps/intra.ber)");
	if (argc > 2)
		showerror(&solong, "Too many arguments");
	parsing(&solong, argv[1]);
	display(&solong);
	return (0);
}
