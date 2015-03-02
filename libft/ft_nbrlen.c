unsigned int	ft_nbrlen(int nbr)
{
	unsigned int	res;

	res = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		++res;
	}
	return (res);
}
