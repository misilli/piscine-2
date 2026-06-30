/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumidill <mumidill@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:32:04 by mumidill          #+#    #+#             */
/*   Updated: 2026/06/30 17:40:15 by mumidill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	
	unsigned int i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
	
}
int main()
{
	char dest[] = "asdfgh" ;
	char src[] = "qwerty";
	ft_strncpy(dest,src,3);
}