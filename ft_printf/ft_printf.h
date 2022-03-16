/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 02:38:56 by ygbouri           #+#    #+#             */
/*   Updated: 2021/12/05 20:07:43 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t				ft_strlen(const char *s);
int					ft_putchar_fd(char c);
int					ft_putstr_fd(char *s);
int					ft_putnbr_fd(long n);
void				ft_affichhexa(unsigned int nbr);
void				ft_affichhexa_p(unsigned long nbr);
int					ft_count_nbr(long nbr);
int					ft_count_nbr_hexa(unsigned long n);
void				ft_affichhexaupper(unsigned long nbr);
int					ft_printf(const char *str, ...);

#endif
