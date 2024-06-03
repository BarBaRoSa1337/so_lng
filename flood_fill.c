/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:44 by achakour          #+#    #+#             */
/*   Updated: 2024/06/03 18:55:55 by achakour         ###   ########.fr       */
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
	if (map[x][y] != '1' && map[x][y] != 'X' && map[x][y] != 'E'
		&& map[x][y] != 'V')
	{
		map[x][y] = 'X';
		ft_flood_fill(x + 1, y, map);
		ft_flood_fill(x - 1, y, map);
		ft_flood_fill(x, y + 1, map);
		ft_flood_fill(x, y - 1, map);
	}
	if (map[x][y] == 'E')
	{
		map[x][y] = 'X';
	}
}

char	**copy_map(t_solong *tracker, char **map)
{
	int		line_len;
	char	**copy;
	int		lines;
	int		i;
	int		j;

	map = tracker->map;
	lines = tracker->x + 1;
	line_len = tracker->y + 1;
	copy = malloc(sizeof(char *) * lines);
	if (!copy)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		j = -1;
		copy[i] = malloc(line_len);
		while (map[i][++j])
			copy[i][j] = map[i][j];
		copy[i][j] = '\0';
	}
	copy[i] = NULL;
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
	map = copy_map(tracker, tracker->map);
	ft_flood_fill(tracker->x_player, tracker->y_player, map);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
				++found;
		}
	}
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	if (found == 0)
		return (0);
	return (1);
}
