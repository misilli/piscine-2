/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumidill <mumidill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 16:00:05 by mumidill          #+#    #+#             */
/*   Updated: 2026/06/28 18:55:59 by mumidill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;

	i = 0;
	size = size - 1;
	while (i < size)
	{
		tmp = tab[size];
		tab[size] = tab[i];
		tab[i] = tmp;
		i++;
		size--;
	}
}
