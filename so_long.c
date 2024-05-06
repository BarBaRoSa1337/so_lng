/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:10:25 by achakour          #+#    #+#             */
/*   Updated: 2024/05/06 15:50:14 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_moove(t_img img, t_solong *tracker)
{
    char    **map;
    int     i;
    int     j;

    i = 0;
    map = tracker->map;
    while (i < tracker->x)
    {
        j = 0;
        while (j < tracker->y)
        {
            if (i == tracker->x_player && j == tracker->y_player)
            {
                mlx_put_image_to_window(img.mlx, img.win, img.back_ground, (PXL * i), (PXL * j));
                return ;
            }
            ++j;
        }
        ++i;
    }
}

void    put_images(t_img img, t_solong *tracker)
{
    char    **map;
    int     i;
    int     j;

    i = 0;
    map = tracker->map;
    while (i < tracker->x)
    {
        j = 0;
        while (j < tracker->y)
        {
            if (map[i][j] == '0')
                mlx_put_image_to_window(img.mlx, img.win, img.back_ground, (PXL * i), (PXL * j));
            else if (map[i][j] == '1')
                mlx_put_image_to_window(img.mlx, img.win, img.wall, (PXL * i), (PXL * j));
            else if (map[i][j] == 'P')
                mlx_put_image_to_window(img.mlx, img.win, img.player, (PXL * i), (PXL * j));
            else if (map[i][j] == 'E')
                mlx_put_image_to_window(img.mlx, img.win, img.c_door, (PXL * i), (PXL * j));
            else if (map[i][j] == 'C')
                mlx_put_image_to_window(img.mlx, img.win, img.bomb, (PXL * i), (PXL * j));
            ++j;
        }
        ++i;
    }
}

int main(int ac, char **ar)
{
	void	    *mlx_win;
    t_solong    *tracker;
    t_img       img;
    void	    *mlx;

    // if (ac != 2)
    //     return (1);
    tracker = locate_struct(open(ar[1], O_RDONLY));
    // if (!is_valid_map(tracker->map, ft_count_lines(tracker->map), ft_strlen(tracker->map[0]), tracker) || !is_valid_path(get_map(tracker->fd), tracker))
    //     printf("not valid\n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, tracker->x * PXL , tracker->y * PXL, "so long :)");
    import_xpms(mlx, mlx_win, &img);
    put_images(img, tracker);
    mlx_hook(mlx_win, 2, 1L<<0, ft_handle_esc, NULL);
	mlx_loop(mlx);
    return (0);
}
