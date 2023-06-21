/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:12:54 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/21 12:12:57 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

static int	digits(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i = 1;
	while (n)
	{
		n /= 10;
		i += 1;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;

	i = digits(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = malloc(digits(n) + 1);
	if (!(num))
		return (NULL);
	num[i] = 0;
	if (n < 0)
	{
		n *= -1;
		num[0] = '-';
	}
	i -= 1;
	while (n > 0)
	{
		num[i--] = n % 10 + '0';
		n /= 10;
	}
	return (num);
}
