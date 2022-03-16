/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:51:35 by ygbouri           #+#    #+#             */
/*   Updated: 2021/12/05 14:20:58 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	count_nbr(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(long nbr)
{
	char	c;
	long	n;
	int		i;

	n = nbr;
	i = count_nbr(nbr);
	if (n < 0)
	{
		c = '-';
		write (1, &c, 1);
		n = n * (-1);
	}
	if (n > 9)
	{
		ft_putnbr_fd (n / 10);
		ft_putnbr_fd (n % 10);
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	return (i);
}
