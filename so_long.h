/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:12:48 by achakour          #+#    #+#             */
/*   Updated: 2024/04/08 17:22:53 by achakour         ###   ########.fr       */
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

void	ft_strlcpy(char *dst, char *src, size_t dstsize);
int     is_valid_map(char **map, int row, int sides);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
char    **get_map(char *file_name);
int     ft_strlen(const char *s); 
char	*get_next_line(int fd);
int ft_count_lines(char **map);
char	*ft_strdup(char *str);
char	*cut_str(char *s);

#endif