/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:44 by achakour          #+#    #+#             */
/*   Updated: 2024/05/14 11:07:55 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(char **map, t_solong *tracker, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (c == 'P' && map[i][j] == 'P')
			{
				tracker->x_player = i;
				tracker->y_player = j;
			}
			else if (c == 'E' && map[i][j] == 'E')
			{
				tracker->img_h = i;
				tracker->img_w = j;
			}
			++j;
		}
		++i;
	}
}

void	ft_flood_fill(int x, int y, char **map)
{
	if (map[x][y] != '1' && map[x][y] != 'X' && map[x][y] != 'E')
	{
		map[x][y] = 'X';
		ft_flood_fill(x + 1, y, map);
		ft_flood_fill(x - 1, y, map);
		ft_flood_fill(x, y + 1, map);
		ft_flood_fill(x, y - 1, map);
	}
	if (map[x][y] == 'E')
		map[x][y] = 'X';
}

char	**copy_map(t_solong *tracker)
{
	int		lines;
	int		line_len;
	int		i;
	int		j;
	char	**map;
	char	**copy;

	lines = tracker->x + 1;
	line_len = tracker->y + 1;
	i = -1;
	map = tracker->map;
	copy = malloc(sizeof(char *) * lines);
	if (!copy)
		return (NULL);
	while (copy[++i])
		copy[i] = malloc(line_len);
	copy[i] = NULL;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			copy[i][j] = map[i][j];
		if (map[i][j] == '\0')
			copy[i][j] = '\0';
	}
	return (copy);
}

int	is_valid_path(t_solong *tracker)
{
	char	**map;
	int		found;
	int		i;
	int		j;

	i = -1;
	found = 0;
	map = copy_map(tracker);
	ft_flood_fill(tracker->x_player, tracker->y_player, map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
				++found;
			++j;
		}
		++i;
	}
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	if (found == 0)
		return (0);
	return (1);
}
