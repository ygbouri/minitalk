/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 04:23:52 by ygbouri           #+#    #+#             */
/*   Updated: 2021/12/05 19:52:25 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

void	ft_affichhexa(unsigned int nbr)
{
	char	*str;

	str = "0123456789abcdef";
	if (nbr > 15)
	{
		ft_affichhexa(nbr / 16);
		ft_affichhexa(nbr % 16);
	}
	if (nbr < 16)
	{
		write(1, &str[nbr], 1);
	}
}
