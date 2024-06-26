/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:12:51 by achakour          #+#    #+#             */
/*   Updated: 2024/06/06 11:15:07 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_lines(char **map)
{
	int	lines;
	int	i;

	i = 0;
	lines = 0;
	while (map[i])
	{
		++lines;
		++i;
	}
	return (lines);
}

int	check_dimentions(char **map)
{
	int	line_len;
	int	lines;
	int	i;

	i = -1;
	lines = ft_count_lines(map);
	line_len = ft_strlen(map[i + 1]);
	while (map[++i])
	{
		if (ft_strlen(map[i]) != line_len)
		{
			return (1);
		}
	}
	i = 0;
	if ((lines < 3 && line_len < 5) || line_len > 38 || lines > 20)
	{
		return (1);
	}
	return (0);
}

t_solong	*locate_struct(char *file)
{
	t_solong	*tracker;

	tracker = malloc(sizeof(t_solong));
	if (!tracker)
		return (NULL);
	tracker->fd = open(file, O_RDWR);
	if (tracker->fd == -1)
		return (free(tracker), NULL);
	tracker->map = get_map(tracker->fd);
	if (!tracker->map)
		return (free(tracker), NULL);
	tracker->file = file;
	tracker->exit = 0;
	tracker->coins = 0;
	tracker->n_player = 0;
	tracker->moves = 1;
	tracker->exit = 0;
	tracker->y = ft_strlen(tracker->map[0]);
	get_player_position(tracker->map, tracker, 'P');
	tracker->x = ft_count_lines(tracker->map);
	return (tracker);
}

int	check_elements(char **map, t_solong *tracker)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				tracker->coins += 1;
			else if (map[i][j] == 'E')
				tracker->exit += 1;
			else if (map[i][j] == 'P')
				tracker->n_player += 1;
			else if (map[i][j] != '1' && map[i][j] != 'V' && map[i][j] != '0')
				return (1);
			++j;
		}
		++i;
	}
	if (tracker->coins < 1 || tracker->n_player != 1 || tracker->exit != 1)
		return (1);
	return (0);
}

int	is_valid_map(char **map, int lines, int line_len, t_solong *tracker)
{
	int	i;
	int	j;

	i = -1;
	if (!map)
		return (1);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((i == 0 || i == (lines - 1)) && map[i][j] != '1')
			{
				return (1);
			}
			else if ((j == 0 || j == line_len - 1) && map[i][j] != '1')
			{
				return (1);
			}
		}
	}
	if ((check_elements(map, tracker) || check_dimentions(map))
		|| is_valid_path(tracker))
		return (1);
	return (0);
}
