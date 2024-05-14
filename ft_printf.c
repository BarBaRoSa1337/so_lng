/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:28:06 by achakour          #+#    #+#             */
/*   Updated: 2024/05/14 11:08:42 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr_fd(int n, int *len)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		*len += ft_putchar_fd('-', 1);
		nbr = -n;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, len);
		*len += ft_putchar_fd((nbr % 10 + '0'), 1);
	}
	if (nbr <= 9)
		*len += ft_putchar_fd((nbr % 10 + '0'), 1);
}

void	ft_putstr_fd(const char *s, int *len)
{
	size_t	i;

	if (!s)
	{
		ft_putstr_fd("(null)", len);
		return ;
	}
	i = -1;
	while (s[++i])
		*len += write(1, &s[i], 1);
}

static int	check(char c)
{
	char	*set;
	int		i;

	i = 0;
	set = "%cspdiuxX";
	while (set[i])
	{
		if (set[i] == c)
			return (1337);
		++i;
	}
	return (-42);
}

static int	put_type_in_place(char c, va_list args)
{
	int	count;

	count = 42;
	if (c == 's')
		ft_putstr_fd(va_arg(args, char *), &count);
	else if (c == 'd')
		ft_putnbr_fd(va_arg(args, int), &count);
	return (count - 42);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	size_t count;
	size_t i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] && check(format[i + 1]) == 1337)
		{
			++i;
			count += put_type_in_place(format[i], args);
		}
		else if (format[i] != '%')
			count += ft_putchar_fd(format[i], 1);
		else if (format[i] == '%' && format[i + 1] == '\0')
			count = -1;
		++i;
	}
	va_end(args);
	return (count);
}