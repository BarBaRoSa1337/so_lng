/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:10:25 by achakour          #+#    #+#             */
/*   Updated: 2024/04/15 15:02:42 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **ar)
{
    char    **map;
    // int     lines;
    (void)ac;

    map = get_map(ar[1]);
    (void)map;
    // printf("%s\n", map[0]);
    // lines = count_lines(map);
    // if (is_valid_map(map, lines, ft_strlen(map[0])))
    // {
        
    // }
    // int i = 0;
    // while (map[i])
    // {
    //    printf("%s\n", map[i]);
    //    ++i;
    // }
    return (0);
}