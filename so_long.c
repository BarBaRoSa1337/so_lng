/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:10:25 by achakour          #+#    #+#             */
/*   Updated: 2024/06/03 18:36:16 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(int new_x, int new_y, t_solong *s)
{
	char	**map;
	char	*str;

	map = s->map;
	handle_coins(map, s);
	if (map[new_x][new_y] == 'E' || map[new_x][new_y] == 'V')
	{
		if (s->coins == 0 || map[new_x][new_y] == 'V')
		{
			ft_printf("Moves : %d\n", s->moves);
			ft_exit(s);
		}
	}
	else
	{
		ft_printf("Moves : %d\n", s->moves);
		str = ft_itoa(s->moves);
		mlx_put_image_to_window(s->mlx, s->win, s->back_ground, (PXL
				* s->y_player), (PXL * s->x_player));
		s->x_player = new_x;
		s->y_player = new_y;
		put_str(s, new_x, new_y, str);
		s->moves++;
		free(str);
	}
}

void	put_images(t_solong *s)
{
	char	**map;
	int		i;
	int		j;

	i = -1;
	map = s->map;
	while (++i < s->x)
	{
		j = -1;
		while (++j < s->y)
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(s->mlx, s->win, s->back_ground, (PXL
						* j), (PXL * i));
			else if (map[i][j] == '1')
				mlx_put_image_to_window(s->mlx, s->win, s->wall, (PXL * j), (PXL
						* i));
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(s->mlx, s->win, s->player, (PXL * j),
					(PXL * i));
			else
				put_images2(s, i, j);
		}
	}
}

void	ft_sleep(void)
{
	size_t	i;

	i = 0;
	while (i < 1000000000000000000)
		++i;
	while (i > 0)
		--i;
	i = 0;
	while (i < 1000000000000000000)
		++i;
	while (i > 0)
		--i;
	i = 0;
	while (i < 1000000000000000000)
		++i;
	while (i < 0)
		--i;
	i = 0;
	while (i < 1000000000000000000)
		++i;
	while (i < 0)
		--i;
	i = 0;
	while (i < 1000000000000000000)
		++i;
}

int	ft_patrol(t_solong *s)
{
	char	**map;
	int		i;
	int		j;

	i = -1;
	map = s->map;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'V')
			{
				mlx_put_image_to_window(s->mlx, s->win, s->enemy_hit, (PXL * j),
					(PXL * i));
				ft_sleep();
				ft_sleep();
				ft_sleep();
				ft_sleep();
				mlx_put_image_to_window(s->mlx, s->win, s->enem, (PXL * j), (PXL
						* i));
			}
		}
	}
	return (1);
}

int	main(int ac, char **ar)
{
	t_solong	*tracker;
	void		*mlx_win;
	void		*mlx;

	if (ac < 2)
		return (0);
	tracker = locate_struct(ar[1]);
	if (check_name(ar[1]) || !tracker)
	{
		ft_printf("Error\nاسم او معالم الخريطة غير صحيح\n");
		exit(1);
	}
	if (is_valid_map(tracker->map, ft_count_lines(tracker->map),
			ft_strlen(tracker->map[0]), tracker))
		ft_free(tracker);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, tracker->y * PXL, tracker->x * PXL,
			"So_long");
	import_xpms(mlx, mlx_win, tracker);
	put_images(tracker);
	mlx_loop_hook(mlx, ft_patrol, tracker);
	mlx_hook(mlx_win, 2, 1L << 0, select_move, tracker);
	mlx_hook(mlx_win, 17, 0, ft_exit, tracker);
	mlx_loop(mlx);
	return (0);
}
