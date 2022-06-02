int	parsing(t_long *sl, char *map_file)
{
	map_exetention_check(map_file, sl);
	get_width_and_height(sl, map_file);
	malloc_map(sl);
	stockmap(sl, map_file);
	checkmap(sl);
	return (0);
}

int	get_width_and_height(t_sl sl, char *map_file);
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(map_file, O_RDONLY);
	ret = get_next_line(fd, &line);
	sl->map_width = ft_strlen(line);
	while (line[numberblank(line)] == '1' || line[numberblank(line)] == '0')
	{
		sl->x = ft_strlen(line);
		if (sl->x != sl->oldx)
			showerror(sl, "Map is not rectangular");
		sl->oldx = sl->x;
		if (ret != -1)
			free(line);
		ret = get_next_line(fd, &line);
		sl->y++;
	}
	if (sl->y == 0 || sl->x == 0)
		showerror(sl, "Map is not correct or not well formated");
	sl->yscreen = sl->y * 64;
	free(line);
	sl->xscreen = sl->x * 64;
	close(fd);
	return (0);
}