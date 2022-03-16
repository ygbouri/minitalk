/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichhexa_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:51:19 by ygbouri           #+#    #+#             */
/*   Updated: 2021/12/05 19:55:57 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

void	ft_affichhexa_p(unsigned long nbr)
{
	char	*str;

	str = "0123456789abcdef";
	if (nbr > 15)
	{
		ft_affichhexa_p(nbr / 16);
		ft_affichhexa_p(nbr % 16);
	}
	if (nbr < 16)
	{
		write(1, &str[nbr], 1);
	}
}
