/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lbft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:13:18 by achakour          #+#    #+#             */
/*   Updated: 2024/04/08 17:22:21 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_strlcpy(char *dst, char *src, size_t dstsize)
// {
// 	size_t	i;

// 	if (dstsize != 0)
// 	{
// 		i = 0;
// 		while (*(src + i) != '\0' && --dstsize)
// 		{
// 			*(dst + i) = *(src + i);
// 			++i;
// 		}
// 		*(dst + i) = '\0';
// 	}
// }

static size_t	ft_count_words(char *str, int c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			++words;
		++i;
	}
	return (words);
}

static size_t	ft_word_len(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (0);
	while (s[i] == c)
		++i;
	j = 0;
	while (s[i] != c)
	{
		++j;
		++i;
	}
	return (j);
}

static char	*ft_word_pos(const char *s, char c)
{
	size_t		i;
	const char	*p;

	p = s;
	i = 0;
	if (!s)
		return (NULL);
	while (p[i] == c)
		++i;
	return ((char *)&p[i]);
}

static int	locate_words(char const *s, char c, char **buffer, size_t words)
{
	size_t	word_len;
	char	*word_pos;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	word_pos = ft_word_pos(s, c);
	while (i < words)
	{
		word_len = ft_word_len(word_pos, c);
		buffer[i] = (char *)malloc(word_len + 1);
		if (!buffer[i])
			return (0);
		ft_strlcpy(buffer[i], word_pos, word_len + 1);
		word_pos = ft_word_pos(word_pos + word_len + 1, c);
		++i;
	}
	buffer[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**buffer;
	int		error;
	size_t	i;

	i = 0;
	if (!s || !s[i])
		return (NULL);
	words = ft_count_words((char *)s, c);
	buffer = malloc((words + 1) * sizeof(char *));
	if (buffer)
		error = locate_words(s, c, buffer, words);
	if (!buffer || error == 0)
	{
		while (i < words)
		{
			free(buffer[i]);
			++i;
		}
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
