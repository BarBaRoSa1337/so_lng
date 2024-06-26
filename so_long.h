/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:12:48 by achakour          #+#    #+#             */
/*   Updated: 2024/06/03 19:04:56 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 13
# define PXL 50
# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define ESC 65307
# define Q 113

# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_solong
{
	char	*file;
	int		x_player;
	int		y_player;
	int		n_player;
	char	**map;
	int		coins;
	int		exit;
	int		fd;
	int		x;
	int		y;
	void	*win;
	void	*mlx;
	void	*back_ground;
	void	*o_door;
	void	*c_door;
	void	*player;
	void	*bomb;
	void	*wall;
	void	*enem;
	void	*enemy_hit;
	int		img_w;
	int		img_h;
	int		moves;
}			t_solong;

int			is_valid_map(char **map, int lines, int line_len,
				t_solong *tracker);
int			is_valid_path(t_solong *tracker);
void		get_player_position(char **map, t_solong *tracker, char c);
void		ft_strlcpy(char *dst, char *src, size_t dstsize);
char		*ft_itoa(int n);
int			check_name(char *str);
int			ft_putchar_fd(char c, int fd);
int			ft_exit(t_solong *track);
void		put_images2(t_solong *s, int i, int j);
char		**ft_split(char const *s, char c);
int			select_move(int keycode, t_solong *img);
int			import_xpms(void *mlx, void *win, t_solong *img);
char		*ft_strjoin(char *s1, char *s2);
int			ft_printf(const char *format, ...);
char		*ft_strchr(char *s, char c);
t_solong	*locate_struct(char *file);
int			ft_count_lines(char **map);
int			ft_strcmp(char *s1, char *s2);
void		put_str(t_solong *s, int x, int y, char *str);
void		handle_coins(char **map, t_solong *img);
void		ft_move(int new_x, int new_y, t_solong *s);
int			ft_strlen(const char *s);
char		*get_next_line(int fd);
int			ft_count_lines(char **map);
void		ft_free(t_solong *track);
char		*ft_strdup(char *str);
char		*cut_str(char *s);
char		**get_map(int fd);

#endif