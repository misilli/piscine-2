/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumidill <mumidill@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:06:41 by mumidill          #+#    #+#             */
/*   Updated: 2026/06/30 19:59:58 by mumidill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_char_is_alphanum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

void	ft_chrupcase(char *str)
{
	*str = *str - 32;
}

void ft_chrlowcase(char *str)
{
	*str = *str + 32;
}

char *ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	 if (str[0] == '\0')
        return (str);
	ft_strlowcase(&str[i]);
	if (str[i] >= 'a' && str[i] <= 'z')
    ft_chrupcase(&str[i]);
	
	while (str[i] != '\0')
	{
		if (!(ft_char_is_alphanum(str[i]) ))
		{
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
			{
				ft_chrupcase(&str[i + 1]);
			}
		}
		i++;
	}
	return (str);
}

