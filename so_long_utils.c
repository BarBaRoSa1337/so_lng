/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:20:16 by achakour          #+#    #+#             */
/*   Updated: 2024/05/11 19:28:35 by achakour         ###   ########.fr       */
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
	img->bomb_on = mlx_xpm_file_to_image(mlx, "./images/bomb_on.xpm",  &img->img_w, &img->img_h);
    img->wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm",  &img->img_w, &img->img_h);
    if (!img->bomb || !img->wall || !img->o_door || !img->c_door || !img->player || !img->back_ground)
        return (0);
    return (1);
} 

char    **get_map(int fd)
{
    char    **map;
    char    *buff;
    char    *tmp;

    buff = NULL;
    tmp = get_next_line(fd);
    while (tmp)
    {
        buff = ft_strjoin(buff, tmp);
        free (tmp);
        tmp = get_next_line(fd);
    }
    close(fd);
    buff = ft_strjoin(buff, "\n");
    map = ft_split(buff, '\n');
    return (free(buff), map);
}

void	ft_putstr(char *str, char flag)
{
	int	i;

	if (flag == 'M')
		ft_putstr("Moves:", 'N');
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

// void	ft_exit(t_solong *track)
// {
// 	char **map;
// 	int	i;

// 	i = -1;
// 	mlx_clear_window(track->mlx, track->win);
// 	map = track->map;
// 	while (map[++i])
// 		free (map[i]);
// 	free (map);
// 	free (track);
// }