
ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < ' ' || str[i] > '~')
			return (0);
		i++;
	}
	return (1);
}

void ft_putstr_non_printable(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (ft_str_is_printable(&str[i]) == 0)
        {
            ft_putchar('\\');
            ft_putchar("0123456789abcdef"[str[i] / 16]);
            ft_putchar("0123456789abcdef"[str[i] % 16]);
        }
        else
        {
            ft_putchar(str[i]);
        }
        i++;
    }
}