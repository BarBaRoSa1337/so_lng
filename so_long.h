/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:12:48 by achakour          #+#    #+#             */
/*   Updated: 2024/04/19 10:16:10 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_solong
{
    int     x_player;
    int     y_player;
    int     player;
    char    **map;
    int     coins;
    int     exit;
}   t_solong;

t_solong    *ft_flood_fill(char **map, int x, int y);
int     is_valid_map(char **map, int lines, int line_len);
void	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
int     ft_count_lines(char **map);
int     ft_strlen(const char *s); 
char	*get_next_line(int fd);
char	*ft_strdup(char *str);
char	*cut_str(char *s);
char    **get_map(int fd);

#endif