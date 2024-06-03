
void	handle_coins(char **map, t_solong *img)
{
	if (img->coins > 0 && map[img->x_player][img->y_player] == 'C')
	{
		map[img->x_player][img->y_player] = '0';
		img->coins--;
	}
	get_player_position(map, img, 'E');
	if (img->coins == 0)
	{
		mlx_put_image_to_window(img->mlx, img->win, img->o_door, (PXL
				* img->img_w), (PXL * img->img_h));
	}
}

void	put_str(t_solong *s, int x, int y, char *str)
{
	mlx_put_image_to_window(s->mlx, s->win, s->player, (PXL * y), (PXL * x));
	mlx_put_image_to_window(s->mlx, s->win, s->wall, (PXL * 1), (PXL * 0));
	mlx_string_put(s->mlx, s->win, 10, 25, 200, "MOVES");
	mlx_string_put(s->mlx, s->win, 70, 25, 200, str);
}

void	ft_free(t_solong *track)
{
	char	**map;
	int		i;

	map = track->map;
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	free(track);
	ft_printf("Error\nالخريطة تخالف المعايير الوطنية\n");
	exit(1);
}

void	free_strct(t_solong *tacker)
{
	char	**map;
	int		i;

	map = tacker->map;
	if (!map)
		return ;
	i = 0;
	while (map[i])
		free(map[i]);
	free(map);
	free(tacker);
	exit(1);
}

int	select_move(int keycode, t_solong *img)
{
	char	**map;
	int		x;
	int		y;

	if (keycode == ESC || keycode == Q)
		ft_exit(img);
	map = img->map;
	x = img->x_player;
	y = img->y_player;
	if ((keycode == UP && map[x - 1][y] && map[x - 1][y] != '1'))
		ft_move(x - 1, y, img);
	else if ((keycode == DOWN && map[x + 1][y] != '1'))
		ft_move(x + 1, y, img);
	else if ((keycode == RIGHT && map[x][y + 1] && map[x][y + 1] != '1'))
		ft_move(x, y + 1, img);
	else if ((keycode == LEFT && map[x][y - 1] && map[x][y - 1] != '1'))
		ft_move(x, y - 1, img);
	return (1);
}