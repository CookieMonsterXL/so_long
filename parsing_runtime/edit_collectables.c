/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_collectables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:18:42 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/13 13:25:43 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/so_long.h"

int	check_collectable(t_sl *sl)
{
	sl->collected++;
	if (sl->collected == sl->collectable_total)
		sl->exit_unlock = 1;
	return (0);
}

int	remove_collectable_mlx(t_vars *vars)
{
	int	remove;

	remove = vars->sl->collectable_total - vars->sl->collected;
	vars->sl->key_img->instances[remove].z = -1;
	return (0);
}
