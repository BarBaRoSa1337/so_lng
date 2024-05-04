/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:10:25 by achakour          #+#    #+#             */
/*   Updated: 2024/05/04 11:52:38 by achakour         ###   ########.fr       */
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
    t_solong    *tracker;
    // char        **map;

    // if (ac != 2)
    //     return (1);
    tracker = locate_struct(open("v_map01.ber", O_RDONLY));
    if (!is_valid_map(tracker->map, ft_count_lines(tracker->map), ft_strlen(tracker->map[0]), tracker))
        printf("not valid");
    // is_valid_path(tracker->map, tracker);
    return (0);
}