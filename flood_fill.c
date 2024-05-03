/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:44 by achakour          #+#    #+#             */
/*   Updated: 2024/05/03 11:19:08 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_player_position(char **map, t_solong *tracker)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                tracker->x_player = i;
                tracker->y_player = j;
            }
            ++j;
        }
        ++i;
    }
}

t_solong    *locate_struct(void)
{
    t_solong    *p;

    p = (t_solong *)malloc(sizeof(t_solong));
    if (!p)
        return (NULL);
    return (p);
}

char    *copy_map(char **map)
{
    int     map_len;
    char    **copy;
    int     lines;
    int     i;
    int     j;

    i = -1;
    map_len = ft_strlen(map[0]);
    lines = ft_count_lines(map);
    copy = malloc(sizeof(char *) * (lines + 1));
    while (map[++i])
        copy[i] = malloc(map_len + 1);
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            copy[i][j] = map[i][j];
            ++j;
        }
        copy[i][j + 1] = '\0';
        ++i;
    }
    return (copy);
}

int check_map(char **map)
{
    int found;
    int i;
    int j;


    i = 0;
    found = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
                found++;
            ++j;
        }
        ++i;
    }
    if (found == 0)
        return (1);
    return (0);
}

int ft_flood_fill(int x, int y, t_solong *tracker)
{
    char    **map;

    map = copy_map(tracker->map);
    map[x][y] = 'X';
    if (map[x + 1][y] != '1' && map[x + 1][y] != 'X')
        ft_flood_fill(x + 1, y, tracker);
    else if (map[x - 1][y] != '1' && map[x - 1][y] != 'X')
        ft_flood_fill(x - 1, y, tracker);
    else if (map[x][y + 1] != '1' && map[x][y + 1] != 'X')
        ft_flood_fill(x, y + 1, tracker);
    else if (map[x][y - 1] != '1' && map[x][y - 1] != 'X')
        ft_flood_fill(x, y - 1, tracker);
    else
        return (0);
}
