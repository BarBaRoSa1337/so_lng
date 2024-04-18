/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:12:48 by achakour          #+#    #+#             */
/*   Updated: 2024/04/18 13:12:31 by achakour         ###   ########.fr       */
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

void	ft_strlcpy(char *dst, char *src, size_t dstsize);
int is_valid_map(char **map, int lines, int line_len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
char    **get_map(int fd);
int ft_count_lines(char **map);
int     check_coins(char **map);/////////remo
int check_exit_player(char **map);/////////////ve
int check_dimentions(char **map);///////////this
int     ft_count_lines(char **map);
int     ft_strlen(const char *s); 
char	*get_next_line(int fd);
char	*ft_strdup(char *str);
char	*cut_str(char *s);

#endif