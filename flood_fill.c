/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:44 by achakour          #+#    #+#             */
/*   Updated: 2024/04/19 10:29:26 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_solong    *ft_struct(t_solong *track, char element)
{
    if (element == 'C')
        track->coins++;
    else if (element == 'E')
        track->exit++;
    else if (element == 'P')
        track->player++;
    return (track);
}

t_solong    *locate_struct(void)
{
    t_solong    *p;

    p = (t_solong *)malloc(sizeof(t_solong));
    if (!p)
        return (NULL);
    return (p);
}

t_solong    *ft_flood_fill(char **map, int x, int y)
{
    t_solong    *track;

    map[x][y] = 'X';
    track = locate_struct();
    if (map[x + 1][y] && map[x + 1][y] != '1' && map[x + 1][y] != '2')
    {
        ft_struct(track, map[x + 1][y]);
        return (ft_flood_fill(map, x + 1, y));
    }
    else if (map[x - 1][y] != '1' && map[x - 1][y] == '2')
    {
        ft_struct(track, map[x + 1][y]);
        return (ft_flood_fill( map, x - 1, y));
    }
    else if (map[x][y + 1] && map[x][y + 1] != '1' && map[x][y + 1] != '2')
    {
        ft_struct(track, map[x + 1][y]);
        return (ft_flood_fill(map, x, y + 1));
    }
    else if (map[x][y - 1] && map[x][y - 1] != '1' && map[x][y - 1] != '2')
    {
        ft_struct(track, map[x + 1][y]);
        return (ft_flood_fill(map, x, y - 1));
    }
    return (track);
}
