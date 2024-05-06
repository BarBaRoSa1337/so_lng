/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:10:25 by achakour          #+#    #+#             */
/*   Updated: 2024/05/06 14:19:12 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **ar)
{
	void	    *mlx_win;
    t_solong    *tracker;
    t_img       img;
    void	    *mlx;

    // if (ac != 2)
    //     return (1);
    // tracker = locate_struct(open(ar[1], O_RDONLY));
    // if (!is_valid_map(tracker->map, ft_count_lines(tracker->map), ft_strlen(tracker->map[0]), tracker) || !is_valid_path(get_map(tracker->fd), tracker))
    //     printf("not valid\n");
    // if (!import_xpms(mlx, img))
    //     exit(1);
	mlx = mlx_init();
    import_xpms(mlx, img);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so long :)");
    mlx_put_image_to_window(mlx, mlx_win, img.back_ground, 192 * 1 , 192 * 1);
    mlx_hook(mlx_win, 2, 1L<<0, ft_handle_esc, NULL);
	mlx_loop(mlx);
    return (0);
}
