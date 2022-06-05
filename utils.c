/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:43:47 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/05 13:15:32 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/libft/libft.h"

// int	showerror(t_sl *sl, char *str)
// {
// 	write(1, "\033[31mError\n\033[0;37m", 12);
// 	ft_putstr(str);
// 	write(1, "\n", 1);
// 	freeandexit(sl);
// 	return (0);
// }

void	error_mgs(char *str)
{
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
	exit(1);
}
