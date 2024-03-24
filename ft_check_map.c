/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:12:51 by achakour          #+#    #+#             */
/*   Updated: 2024/03/22 17:02:17 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void    ft_fill_buff(char **buff, int fd, int lines)
// {
//     int i;

//     // lseek(fd, );
//     i = 0;
//     while (i < lines)
//     {
//         buff[i] = get_next_line(fd);
//         ++i;
//     }
//     buff[i] = NULL;
// }

// char    *get_map(char *file_name)
// {
//     char    **buff;
//     char    *tmp;
//     int     len;
//     int     fd;
//     int     i;

//     i = 1;
//     len = 0;
//     fd = open(file_name, O_WRONLY);
//     tmp = get_next_line(fd);
//     if (!tmp)
//         return (NULL);
//     while (tmp)
//     {
//         tmp = get_next_line(fd);
//         free (tmp);
//         ++len;
//         ++i;
//     }
//     if (len > 0)
//         buff = (char *)malloc(sizeof(char) * len + 1);
//     if (!buff)
//         return (NULL);
//     ft_fill_buff(buff, fd, i);
//     return (buff);
// }

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
                return (0);
            }
            ++j;
        }
        ++i;
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
    if (player > 1 || exit > 1)
        return (0);
    return (1);
}

                            //n_lines //ft_strlen(map[0])
int is_valid_map(char **map, int row, int sides)
{
    int i;
    int j;

    i = -1;
    while (map[++i])
    {
        j = 0;
        while (map[i][j])
        {
            if ((i == 0 || i == row) && map[i][j] != '1')
            {
                return (0);
            }
            else if ((j == 0 || j == sides) && map[i][j] != '1')
            {
                return (0);
            }
            else if (!check_exit_player(map) || !check_coins(map))
            {
                return (0);
            }
            ++j;
        }
    }
    return (1);
}
