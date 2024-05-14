/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:20:16 by achakour          #+#    #+#             */
/*   Updated: 2024/05/14 10:33:04 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_get_lengh(int nb)
{
	int	i;

	if (nb < 0)
		i = 1;
	else
		i = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static char	*ft_putnbr(long n, char *nbr)
{
	int		len;
	int		i;

	len = ft_get_lengh(n);
	i = 0;
	if (n < 0)
	{
		nbr[0] = '-';
		n *= -1;
	}
	while (i < len && n > 0)
	{
		nbr[(len - 1) - i] = (n % 10) + '0';
		n = (n - (n % 10)) / 10;
		i++;
	}
	nbr[len] = '\0';
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;

	if (n == 0)
		return (ft_strdup("0"));
	nbr = malloc((ft_get_lengh(n) + 1) * sizeof(char));
	if (nbr == NULL)
		return (0);
	nbr = ft_putnbr(n, nbr);
	return (nbr);
}

int import_xpms(void *mlx, void *win, t_solong *img)
{
    img->mlx = mlx;
    img->win = win;
    img->exit = 1337;
    img->back_ground = mlx_xpm_file_to_image(mlx, "./images/back_ground.xpm", &img->img_w, &img->img_h);
    img->player = mlx_xpm_file_to_image(mlx, "./images/player.xpm",  &img->img_w, &img->img_h);
    img->c_door = mlx_xpm_file_to_image(mlx, "./images/c_door.xpm",  &img->img_w, &img->img_h);
    img->o_door = mlx_xpm_file_to_image(mlx, "./images/o_door.xpm",  &img->img_w, &img->img_h);
    img->bomb = mlx_xpm_file_to_image(mlx, "./images/bomb.xpm",  &img->img_w, &img->img_h);
	img->enem = mlx_xpm_file_to_image(mlx, "./images/enemy.xpm",  &img->img_w, &img->img_h);
	img->enemy_hit = mlx_xpm_file_to_image(mlx, "./images/enemy_hit.xpm",  &img->img_w, &img->img_h);
	img->bomb_on = mlx_xpm_file_to_image(mlx, "./images/bomb_on.xpm",  &img->img_w, &img->img_h);
    img->wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm",  &img->img_w, &img->img_h);
    if (!img->bomb || !img->wall || !img->o_door || !img->c_door || !img->player || !img->back_ground)
        return (0);
    return (1);
} 


int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

char    **get_map(int fd)
{
    char    **map;
    char    *buff;
    char    *tmp;

    tmp = get_next_line(fd);
    buff = NULL;
    while (tmp)
    {
		if (tmp[0] == '\n')
			return (free(buff), NULL);
        buff = ft_strjoin(buff, tmp);
        free (tmp);
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
		mlx_destroy_image(track->mlx, track->bomb_on);
		mlx_destroy_image(track->mlx, track->player);
		mlx_destroy_image(track->mlx, track->enem);
		mlx_destroy_image(track->mlx, track->enemy_hit);
		mlx_destroy_image(track->mlx, track->c_door);
		mlx_destroy_image(track->mlx, track->o_door);
		mlx_destroy_image(track->mlx, track->wall);
		mlx_clear_window(track->mlx, track->win);
	mlx_destroy_window(track->mlx, track->win);
	mlx_destroy_display(track->mlx);
	free (track->mlx);
	map = track->map;
	while (map[++i])
		free (map[i]);
	free (map);
	free (track);
	exit(0);
	return (0);
}