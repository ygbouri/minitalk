/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichhexaupper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:25:38 by ygbouri           #+#    #+#             */
/*   Updated: 2021/12/05 12:36:45 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

void	ft_affichhexaupper(unsigned long nbr)
{
	char	*str;

	str = "0123456789ABCDEF";
	nbr = (unsigned long)nbr;
	if (nbr > 15)
	{
		ft_affichhexaupper(nbr / 16);
		ft_affichhexaupper(nbr % 16);
	}
	if (nbr < 16)
	{
		write(1, &str[nbr], 1);
	}
}
