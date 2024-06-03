

void	put_images2(t_solong *s, int i, int j)
{
	if (map[i][j] == 'C')
		mlx_put_image_to_window(s->mlx, s->win, s->bomb, (PXL * j), (PXL * i));
	else if (map[i][j] == 'V')
		mlx_put_image_to_window(s->mlx, s->win, s->enem, (PXL * j), (PXL * i));
	else if (map[i][j] == 'E')
		mlx_put_image_to_window(s->mlx, s->win, s->c_door, (PXL * j), (PXL
				* i));
}

int	ft_get_lengh(int nb)
{
	int	i;

	if (nb < 0)
		i = 1;
	else
		i = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_putnbr(long n, char *nbr)
{
	int	len;
	int	i;

	len = ft_get_lengh(n);
	i = 0;
	if (n < 0)
	{
		nbr[0] = '-';
		n *= -1;
	}
	while (i < len && n > 0)
	{
		nbr[(len - 1) - i] = (n % 10) + '0';
		n = (n - (n % 10)) / 10;
		i++;
	}
	nbr[len] = '\0';
	return (nbr);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		++i;
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*nbr;

	if (n == 0)
		return (ft_strdup("0"));
	nbr = malloc((ft_get_lengh(n) + 1) * sizeof(char));
	if (nbr == NULL)
		return (0);
	nbr = ft_putnbr(n, nbr);
	return (nbr);
}
