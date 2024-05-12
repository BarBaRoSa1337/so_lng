/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:12:48 by achakour          #+#    #+#             */
/*   Updated: 2024/05/12 09:53:14 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#  define BUFFER_SIZE 13
#   define PXL 50
#define UP 119
#define DOWN 115
#define RIGHT 100
#define LEFT 97
#define ESC 65307

#include <string.h>
#include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include "./minilibx-linux/mlx.h"

typedef struct s_solong
{
    int     x_player;
    int     y_player;
    int     n_player;
    char    **map;
    int     coins;
    int     exit;
    int     fd;
    int     x;
    int     y;
    void    *win;
    void    *mlx;
    void    *back_ground;
    void    *o_door;
    void    *c_door;
    void    *player;
    void    *bomb;
    void    *bomb_on;
    void    *wall;
    void    *enem;
    void    *enemy_hit;
    int     img_w;
    int     img_h;
    int     moves;
}       t_solong;

int     is_valid_map(char **map, int lines, int line_len, t_solong *tracker);
void    get_player_position(char **map, t_solong *tracker, char c);
void	ft_strlcpy(char *dst, char *src, size_t dstsize);
int     is_valid_path(char **map, t_solong *tracker);
char	*ft_itoa(int n);
void	ft_putstr(char *str, char flag);
void	ft_exit(t_solong *track);
char	**ft_split(char const *s, char c);
int   select_move(int keycode, t_solong *img);
int import_xpms(void *mlx, void *win, t_solong *img);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
t_solong    *locate_struct(int fd);
int     ft_count_lines(char **map);
int     ft_strlen(const char *s); 
char	*get_next_line(int fd);
int     ft_count_lines(char **map);
char	*ft_strdup(char *str);
char	*cut_str(char *s);
char    **get_map(int fd);

#endif