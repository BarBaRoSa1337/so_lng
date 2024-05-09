/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:44 by achakour          #+#    #+#             */
/*   Updated: 2024/05/09 11:54:36 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_player_position(char **map, t_solong *tracker, char c)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (c == 'P' && map[i][j] == 'P')
            {
                tracker->x_player = i;
                tracker->y_player = j;
            }
            else if (c == 'E' && map[i][j] == 'E')
            {
                tracker->img_h = i;
                tracker->img_w = j;
            }
            ++j;
        }
        ++i;
    }
}
    
void    ft_flood_fill(int x, int y, char **map)
{
    if (map[x][y] != '1' && map[x][y] != 'X' && map[x][y] != 'E')
    {
        map[x][y] = 'X';
        ft_flood_fill(x + 1, y, map);
        ft_flood_fill(x - 1, y, map); 
        ft_flood_fill(x, y + 1, map);
        ft_flood_fill(x, y - 1, map);
    }
    if (map[x][y] == 'E')
        map[x][y] = 'X';
}

int is_valid_path(char **map, t_solong *tracker)
{
    int found;
    int i;
    int j;

    i = 0;
    found = 0;
    ft_flood_fill(tracker->x_player, tracker->y_player, map);
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
                ++found;
            ++j;
        }
        ++i;
    }
    i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        ++i;
        /* code */
    }
    if (found == 0)
        return (1);
    return (0);
}