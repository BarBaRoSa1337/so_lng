/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:19:44 by achakour          #+#    #+#             */
/*   Updated: 2024/06/03 19:05:21 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(&str[i], ".ber") == 0)
		{
			if (ft_strlen(&str[i]) == 4 && ft_strlen(str) > 9)
				return (0);
			else
				return (1);
		}
		++i;
	}
	return (1);
}

char	*cut_str(char *s)
{
	char	*buff;
	size_t	i;

	i = 0;
	if (!s || !s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		++i;
	if (s[i] == '\n')
		++i;
	buff = malloc((size_t)i + 1);
	if (!buff)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		buff[i] = s[i];
		++i;
	}
	if (s[i] == '\n')
		buff[i++] = '\n';
	buff[i] = '\0';
	return (buff);
}

char	*ft_strchr(char *s, char c)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == c)
				return (&s[i]);
			i++;
		}
	}
	return (NULL);
}

char	*process_str(char *buff, char **tmp)
{
	*tmp = cut_str(buff);
	return (ft_strdup(buff + ft_strlen(*tmp)));
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*tmp;
	char		*swap;
	ssize_t		count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = malloc((size_t)BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (!ft_strchr(buff, '\n'))
	{
		count = read(fd, tmp, BUFFER_SIZE);
		if (count == 0 || count == -1)
			break ;
		tmp[count] = '\0';
		buff = ft_strjoin(buff, tmp);
	}
	free(tmp);
	if (!buff || !buff[0])
		return (free(buff), NULL);
	swap = buff;
	buff = process_str(buff, &tmp);
	return (free(swap), tmp);
}
