
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (i + 1 < size  && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0)
	{
		dest[i] = '\0';
	}
	while (src[j])
	{
		j++;
	}
	
	return (j);
}
