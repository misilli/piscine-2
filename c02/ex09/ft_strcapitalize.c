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

void	ft_chrupcase(char *str)
{
	*str = *str - 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		ft_chrupcase(&str[i]);
	}
	i++;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
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

int	main(void)
{
	char a[] = "asdasd asdasd-asdasd -asd  asd+a +a" ;
	ft_strcapitalize(a);
	printf("%s", a);
}
