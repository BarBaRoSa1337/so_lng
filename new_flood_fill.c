/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:44 by achakour          #+#    #+#             */
/*   Updated: 2024/03/22 15:08:30 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// y =   1    2   3
// x = 1 '1' '2' '3'
// x = 2 '1' '2' '3'
// x = 3 '1' '2' '3'

int    ft_flood_fill(char **map, int x, int y)
{
    map[x][y] = '2';

    if (map[x + 1][y] && map[x + 1][y] != '1' && map[x + 1][y] != '2')
        return (ft_flood_fill(map, x + 1, y));
    else if (map[x - 1] != '1' && map[x - 1] != '2')
        return (ft_flood_fill(map, x - 1, y));
    else if (map[x][y + 1] && map[x][y + 1] != '1' && map[x][y + 1] != '2')
        return (ft_flood_fill(map, x, y + 1));
    else if (map[x][y - 1] && map[x][y - 1] != '1' && map[x][y - 1] != '2')
        return (ft_flood_fill(map, x, y - 1));
    else
        return ;
}