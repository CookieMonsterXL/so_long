/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 18:39:31 by tiemen        #+#    #+#                 */
/*   Updated: 2022/06/02 18:40:00 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	map_exetention_check(char *str, t_sl *sl)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e'
		&& str[i - 3] == 'b' && str[i - 4] == '.')
	{
		i = open(str, O_RDONLY);
		if (i == -1)
			showerror(sl, "File Name is not correct");
		else
			close(i);
		return (0);
	}
	showerror(sl, "Files without .ber extension is not accepted");
	return (0);
}