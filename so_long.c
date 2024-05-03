/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:10:25 by achakour          #+#    #+#             */
/*   Updated: 2024/04/19 10:19:02 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_map(char ***map)
{
    int i;

    i = -1;
    while (*map[++i])
        free(*map[i]);
    free (*map);
}

char    **get_map(int fd)
{
    char    **map;
    char    *buff;
    char    *tmp;

    buff = NULL;
    tmp = get_next_line(fd);
    while (tmp)
    {
        buff = ft_strjoin(buff, tmp);
        free (tmp);
        tmp = get_next_line(fd);
    }
    close(fd);
    buff = ft_strjoin(buff, "\n");
    map = ft_split(buff, '\n');
    return (free(buff), map);
}

int main(int ac, char **ar)
{
    char    **map;

    if (ac != 2)
        return (1);
    map =  get_map(open(ar[1], O_RDONLY));
    if (!is_valid_map(map, ft_count_lines(map), ft_strlen(map[0])))
        return (free_map(&map), 1);
    t_solong *track = ft_flood_fill(map, 1, 1);
    return (0);
}