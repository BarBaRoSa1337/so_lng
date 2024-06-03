/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:20:16 by achakour          #+#    #+#             */
/*   Updated: 2024/06/03 18:40:57 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	import_xpms(void *mlx, void *win, t_solong *img)
{
	img->mlx = mlx;
	img->win = win;
	img->exit = 1337;
	img->back_ground = mlx_xpm_file_to_image(mlx, "./textures/back_ground.xpm",
			&img->img_w, &img->img_h);
	img->player = mlx_xpm_file_to_image(mlx, "./textures/player.xpm",
			&img->img_w, &img->img_h);
	img->c_door = mlx_xpm_file_to_image(mlx, "./textures/c_door.xpm",
			&img->img_w, &img->img_h);
	img->o_door = mlx_xpm_file_to_image(mlx, "./textures/o_door.xpm",
			&img->img_w, &img->img_h);
	img->bomb = mlx_xpm_file_to_image(mlx, "./textures/bomb.xpm", &img->img_w,
			&img->img_h);
	img->enem = mlx_xpm_file_to_image(mlx, "./textures/enemy.xpm", &img->img_w,
			&img->img_h);
	img->enemy_hit = mlx_xpm_file_to_image(mlx, "./textures/enemy_hit.xpm",
			&img->img_w, &img->img_h);
	img->wall = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &img->img_w,
			&img->img_h);
	if (!img->bomb || !img->wall || !img->o_door || !img->c_door || !img->player
		|| !img->back_ground || !img->enem || !img->enemy_hit)
	{
		exit(1);
	}
	return (1);
}

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

char	**get_map(int fd)
{
	char	**map;
	char	*buff;
	char	*tmp;

	tmp = get_next_line(fd);
	buff = NULL;
	while (tmp)
	{
		if (tmp[0] == '\n')
			return (free(buff), NULL);
		buff = ft_strjoin(buff, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	buff = ft_strjoin(buff, "\n");
	map = ft_split(buff, '\n');
	return (free(buff), map);
}

int	ft_exit(t_solong *track)
{
	char	**map;
	int		i;

	i = -1;
	mlx_destroy_image(track->mlx, track->back_ground);
	mlx_destroy_image(track->mlx, track->bomb);
	mlx_destroy_image(track->mlx, track->player);
	mlx_destroy_image(track->mlx, track->enem);
	mlx_destroy_image(track->mlx, track->enemy_hit);
	mlx_destroy_image(track->mlx, track->c_door);
	mlx_destroy_image(track->mlx, track->o_door);
	mlx_destroy_image(track->mlx, track->wall);
	mlx_clear_window(track->mlx, track->win);
	mlx_destroy_window(track->mlx, track->win);
	mlx_destroy_display(track->mlx);
	free(track->mlx);
	map = track->map;
	while (map[++i])
		free(map[i]);
	free(map);
	free(track);
	exit(0);
	return (0);
}
