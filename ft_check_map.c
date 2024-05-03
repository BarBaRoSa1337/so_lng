/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:12:51 by achakour          #+#    #+#             */
/*   Updated: 2024/04/19 09:38:13 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_coins(char **map)
{
    int coins;
    int i;
    int j;

    i = 0;
    coins = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
            {
                ++coins;
            }
            ++j;
        }
        ++i;
    }
    if (coins == 0)
    {
        return (0);   
    }
    return (1);
}

int ft_count_lines(char **map)
{
    int lines;
    int i;

    i = 0;
    lines = 0;
    while (map[i])
    {
        ++lines;
        ++i;
    }
    return (lines);
}

int check_dimentions(char **map)
{
    int line_len;
    int lines;
    int i;

    i = -1;
    lines = ft_count_lines(map);
    line_len = ft_strlen(map[i + 1]);
    while (map[++i])
    {
        if (ft_strlen(map[i]) != line_len)
        {
            return (0);
        }
    }
    i = 0;
    if ((line_len == lines) || (lines < 3 || line_len < 5))
    {
        return (0);
    }
    return (1);
}

int check_exit_player(char **map)
{
    int player;
    int exit;
    int i;
    int j;

    i = -1;
    exit = 0;
    player = 0;
    while (map[++i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                player += 1;
            }
            else if (map[i][j] == 'E')
                exit += 1;
            ++j;
        }
    }
    if ((player > 1 || exit > 1) || (player == 0 || exit == 0))
        return (0);
    return (1);
}

int is_valid_map(char **map, int lines, int line_len)
{
    int i;
    int j;

    i = -1;
    if (!check_exit_player(map) || !check_coins(map) || !check_dimentions(map))
    {
        return (0);
    }
    while (map[++i])
    {
        j = 0;
        while (map[i][j])
        {
            if ((i == 0 || i == (lines - 1)) && map[i][j] != '1')
            {
                return (0);
            }
            else if ((j == 0 || j == line_len - 1) && map[i][j] != '1')
            {
                return (0);
            }
            ++j;
        }
    }
    return (1);
}
