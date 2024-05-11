/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:10:25 by achakour          #+#    #+#             */
/*   Updated: 2024/05/11 19:27:38 by achakour         ###   ########.fr       */
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
    str = ft_itoa(img->moves);
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
        mlx_put_image_to_window(img->mlx, img->win, img->back_ground, (PXL * img->y_player), (PXL * img->x_player));            
        img->x_player = new_x;
        img->y_player = new_y;
        mlx_put_image_to_window(img->mlx, img->win, img->player, (PXL * new_y), (PXL * new_x));
        mlx_put_image_to_window(img->mlx, img->win, img->wall, (PXL * 1), (PXL * 0));
        ft_putstr(str, 'M');
        mlx_string_put(img->mlx, img->win, 10, 25, 200, "MOVES");
        mlx_string_put(img->mlx, img->win, 60, 25, 200, ft_itoa(img->moves));
        img->moves++;
    }
}

int    select_move(int keycode, t_solong *img)
{
    char    **map;
    int x;
    int y;

    if (keycode == ESC)
        exit(0);
    map = img->map;
    x = img->x_player;
    y = img->y_player;
    if ((keycode == UP && map[x - 1][y] && map[x - 1][y] != '1'))
        ft_move(x - 1, y, img);
    else if ((keycode == DOWN && x < img->x && map[x + 1][y] != '1'))
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

int move_enemy(int x, int y ,t_solong *track)
{
    char    **map;
    int     flag;

    map = track->map;
    flag = track->exit;
    if (flag == 1 && map[x][y - 1] != '1' && map[x][y - 1] != 'E' && map[x][y - 1] != 'C')
    {
        mlx_put_image_to_window(track->mlx, track->win, track->back_ground, (PXL * y), (PXL * x));
                usleep(133);
        mlx_put_image_to_window(track->mlx, track->win, track->enem, (PXL * (y - 1)), (PXL * x));
    }
    if (map[x][y - 1] == '1' || map[x][y - 1] == 'E' || map[x][y - 1] == 'C')
        track->exit = 0;
    if (flag == 0 && map[x][y + 1] != '1' && map[x][y + 1] != 'E' && map[x][y + 1] != 'C')
        mlx_put_image_to_window(track->mlx, track->win, track->back_ground, (PXL * y), (PXL * x));
    {
        usleep(133);
        mlx_put_image_to_window(track->mlx, track->win, track->enem, (PXL * (y + 1)), (PXL * x));
        flag = 'V';
    }
    if (map[x][y + 1] == '1' || map[x][y + 1] == 'E' || map[x][y + 1] == 'C')
        track->exit = 1;
    return (1);
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
                move_enemy(i, j,tracker);
            else if (map[i][j] == 'v')
                move_enemy(i, j,tracker);
            ++j;             
        }
        ++i;
    }
    return (1);
}

int ft_exploit(t_solong *tracker)
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
            if (map[i][j] == 'C')
            {
                mlx_put_image_to_window(tracker->mlx, tracker->win, tracker->bomb_on, (PXL * j), (PXL * i));
                usleep(133);
                mlx_put_image_to_window(tracker->mlx, tracker->win, tracker->bomb, (PXL * j), (PXL * i));
                usleep(133);
            }
            ++j;
        }
        ++i;
    }
    return (1);
}

int main(int ac, char **ar)
{
	void	    *mlx_win;
    t_solong    *tracker;
    void	    *mlx;

    if (ac < 2)
        return (0);
    tracker = locate_struct(open(ar[1], O_RDONLY));
    if (!is_valid_map(tracker->map, ft_count_lines(tracker->map), ft_strlen(tracker->map[0]), tracker) || !is_valid_path(get_map(tracker->fd), tracker))
    {
        
        printf("not a valid map\n");
        ft_exit(tracker);
    }
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, tracker->y * PXL , tracker->x * PXL, "so long :)");
    import_xpms(mlx, mlx_win, tracker);
    put_images(tracker);
    mlx_loop_hook(tracker->mlx, ft_patrol, tracker);
    mlx_hook(mlx_win, 2, 1L<<0, select_move, tracker);
	mlx_loop(mlx);
    return (0);
    
}
