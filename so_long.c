/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:10:25 by achakour          #+#    #+#             */
/*   Updated: 2024/05/14 10:27:25 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    handle_coins(char **map, t_solong *img)
{
    if (img->coins > 0 && map[img->x_player][img->y_player] == 'C')
    {
        map[img->x_player][img->y_player] = '0';
        img->coins--;
    }
    get_player_position(map, img, 'E');
    if (img->coins == 0)
    {
        mlx_put_image_to_window(img->mlx, img->win, img->o_door, (PXL * img->img_w), (PXL * img->img_h));
    }
}

void    ft_move(int new_x, int new_y, t_solong *img)
{
    char        *str;
    char        **map;

    map = img->map;
    handle_coins(map, img);
    if (map[new_x][new_y] == 'V')
        ft_exit(img);
    if (map[new_x][new_y] == 'E')
    {
        if (img->coins == 0)
            ft_exit(img);
    }
    else
    {
        str = ft_itoa(img->moves);
        mlx_put_image_to_window(img->mlx, img->win, img->back_ground, (PXL * img->y_player), (PXL * img->x_player));            
        img->x_player = new_x;
        img->y_player = new_y;
        mlx_put_image_to_window(img->mlx, img->win, img->player, (PXL * new_y), (PXL * new_x));
        mlx_put_image_to_window(img->mlx, img->win, img->wall, (PXL * 1), (PXL * 0));
        mlx_string_put(img->mlx, img->win, 10, 25, 200, "MOVES");
        mlx_string_put(img->mlx, img->win, 70, 25, 200, str);
        img->moves++;
        free(str);
    }
}

int    select_move(int keycode, t_solong *img)
{
    char    **map;
    int     x;
    int     y;

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
        ft_move(x, y - 1 , img);
    return (1);
}

void    put_images(t_solong *img)
{
    char    **map;
    int     i;
    int     j;

    i = -1;
    map = img->map;
    while (++i < img->x)
    {
        j = -1;
        while (++j < img->y)
        {
            if (map[i][j] == '0')
                mlx_put_image_to_window(img->mlx, img->win, img->back_ground, (PXL * j), (PXL * i));
            else if (map[i][j] == '1')
                mlx_put_image_to_window(img->mlx, img->win, img->wall, (PXL * j), (PXL * i));
            else if (map[i][j] == 'P')
                mlx_put_image_to_window(img->mlx, img->win, img->player, (PXL * j), (PXL * i));
            else if (map[i][j] == 'E')
                mlx_put_image_to_window(img->mlx, img->win, img->c_door, (PXL * j), (PXL * i));
            else if (map[i][j] == 'C')
                mlx_put_image_to_window(img->mlx, img->win, img->bomb, (PXL * j), (PXL * i));
            else if (map[i][j] == 'V')
                mlx_put_image_to_window(img->mlx, img->win, img->enem, (PXL * j), (PXL * i));
        }
    }
}

void    move_enemy(int x, int y, t_solong *track)
{
    int i;

    i = 0;
    while (i < 100000)
    {
        if ((i % 10000))
            mlx_put_image_to_window(track->mlx, track->win, track->enemy_hit, (PXL * y), (PXL * x));
        i += 4;
    }
    mlx_put_image_to_window(track->mlx, track->win, track->enem, (PXL * y), (PXL * x));
}

int ft_patrol(t_solong *tracker)
{
    char    **map;
    int i;
    int j;

    i = 0;
    map = tracker->map;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'V')
                move_enemy(i, j, tracker);
            ++j;
        }
        ++i;
    }
    return (1);
}

void    ft_free(t_solong *track)
{
    char    **map;
    int     i;

    map = track->map;
    i = -1;
    while (map[++i])
        free (map[i]);
    free (map);
    free (track);
    ft_printf("Error\nالخريطة تخالف المعايير الوطنية\n");
    exit(1);
}

int main(int ac, char **ar)
{
    t_solong    *tracker;
	void	    *mlx_win;
    void	    *mlx;

    if (ac < 2)
        return (0);
    tracker = locate_struct(ar[1]);
    if (!check_name(ar[1]) || !tracker)
    {
        ft_printf("Error\nاسم الخريطة غير صحيح\n");
        return (1);
    }
    if (is_valid_map(tracker->map, ft_count_lines(tracker->map), ft_strlen(tracker->map[0]), tracker))
    {
        ft_free(tracker);
    }
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, tracker->y * PXL , tracker->x * PXL, "So_long");
    import_xpms(mlx, mlx_win, tracker);
    put_images(tracker);
    mlx_loop_hook(mlx, ft_patrol, tracker);
    mlx_hook(mlx_win, 2, 1L<<0, select_move, tracker);
    mlx_hook(mlx_win, 17, 0, ft_exit, tracker);
	mlx_loop(mlx);
    return (0);
}
