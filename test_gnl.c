/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:09:25 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/02 11:25:06 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*str;
	char	*lines;
	int		ret;

	ret = 1;
	fd = open("main.c", O_RDONLY);
	while (ret == 1)
	{
		ret = get_next_line(fd, &lines);
		printf("%s\n", lines);
	}

}
