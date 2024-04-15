/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:44 by achakour          #+#    #+#             */
/*   Updated: 2024/04/08 16:50:12 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_flood_fill(char **map, int x, int y)
{
    map[x][y] = '2';

    if (map[x + 1][y] && map[x + 1][y] != '1' && map[x + 1][y] != '2')
        return (ft_flood_fill(map, x + 1, y));
    else if (map[x - 1][y] != '1' && map[x - 1][y] == '2')
        return (ft_flood_fill(map, x - 1, y));
    else if (map[x][y + 1] && map[x][y + 1] != '1' && map[x][y + 1] != '2')
        return (ft_flood_fill(map, x, y + 1));
    else if (map[x][y - 1] && map[x][y - 1] != '1' && map[x][y - 1] != '2')
        return (ft_flood_fill(map, x, y - 1));
    else
        return ;
}
