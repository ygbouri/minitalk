/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:06:48 by ygbouri           #+#    #+#             */
/*   Updated: 2021/12/05 20:08:24 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

int	ft_checktwo(char *s, int i, va_list list)
{
	unsigned int	a;
	unsigned long	b;

	a = 0;
	b = 0;
	if (s[i] == 'p')
	{
		b = va_arg(list, unsigned long);
		write(1, "0x", 2);
		ft_affichhexa_p(b);
		return (ft_count_nbr_hexa(b) + 2);
	}
	else if (s[i] == 'x')
	{
		a = va_arg(list, unsigned int);
		ft_affichhexa(a);
		return (ft_count_nbr_hexa(a));
	}
	else if (s[i] == 'u')
	{
		a = (unsigned int)va_arg(list, int);
		ft_putnbr_fd(a);
		return (ft_count_nbr(a));
	}
	return (0);
}

int	ft_check(char *s, int i, va_list list)
{
	long	a;

	a = 0;
	if (s[i] == 'd' || s[i] == 'i')
	{
		a = va_arg(list, int);
		ft_putnbr_fd(a);
		return (ft_count_nbr(a));
	}
	else if (s[i] == 's')
	{
		return (ft_putstr_fd(va_arg(list, char *)));
	}
	else if (s[i] == 'c')
	{
		return (ft_putchar_fd(va_arg(list, int)));
	}
	else if (s[i] == 'X')
	{
		a = va_arg(list, unsigned int);
		ft_affichhexaupper(a);
		return (ft_count_nbr_hexa(a));
	}
	else
		return (ft_checktwo(s, i, list));
}

int	ft_boucle(const char *s, va_list list)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		j = i + 1;
		if (s[i] != '%')
		{
			write(1, &s[i], 1);
			res++;
		}
		else if (s[j] == '%' && s[j] != '\0')
		{
			write(1, &s[j], 1);
			res++;
			i++;
		}		
		else
			res += ft_check((char *)s, ++i, list);
		i++;
	}
	return (res);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		res;

	res = 0;
	va_start(list, s);
	res = ft_boucle(s, list);
	va_end(list);
	return (res);
}
