/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:20:16 by achakour          #+#    #+#             */
/*   Updated: 2024/05/06 15:23:58 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int import_xpms(void *mlx, void *win, t_img *img)
{
    img->mlx = mlx;
    img->win = win;
    img->back_ground = mlx_xpm_file_to_image(mlx, "./images/back_ground.xpm", &img->img_w, &img->img_h);
    img->player = mlx_xpm_file_to_image(mlx, "./images/player.xpm",  &img->img_w, &img->img_h);
    img->c_door = mlx_xpm_file_to_image(mlx, "./images/c_door.xpm",  &img->img_w, &img->img_h);
    img->o_door = mlx_xpm_file_to_image(mlx, "./images/o_door.xpm",  &img->img_w, &img->img_h);
    img->bomb = mlx_xpm_file_to_image(mlx, "./images/bomb.xpm",  &img->img_w, &img->img_h);
    img->wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm",  &img->img_w, &img->img_h);
    // if (!img->bomb || !img->wall || !img->o_door || !img->c_door || !img->player || !img->back_ground)
    //     return (0);
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

int ft_handle_esc(int keycode, void *ptr)
{
    (void)ptr;
    printf("%d\n", keycode);
    if (keycode == 65307)
        exit(0);
    return (0);
}