/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 01:32:41 by ygbouri           #+#    #+#             */
/*   Updated: 2022/03/05 03:50:23 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_i;
void	traiter(int sig, siginfo_t *info, void *cont);

void	ft_bzero(void *str, size_t arg)
{
	char	*ptr;

	ptr = str;
	while (arg > 0)
	{
		*ptr = 0;
		ptr++;
		arg--;
	}
}

int	main(void)
{
	struct sigaction	ss;

	g_i = 0;
	ss.sa_sigaction = &traiter;
	ss.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &ss, 0);
	sigaction(SIGUSR2, &ss, 0);
	while (1)
	{
		pause();
	}
	return (0);
}

void	printchar(char *str, int pidclient)
{
	char	k;
	int		j;
	int		a;

	j = 0;
	k = 0;
	a = 128;
	while (str[j])
	{
		k += (str[j] - 48) * a;
		a /= 2;
		j++;
	}
	if (k != 0)
		ft_printf("%c", k);
	if (k == 0)
		kill(pidclient, SIGUSR1);
}

void	backspace(void)
{
	char	c;

	c = 8;
	ft_printf("%c", c);
}

void	traiter(int sig, siginfo_t *info, void *cont)
{
	static int	pidclient;
	static char	str[9];

	(void)cont;
	if (pidclient == 0)
		pidclient = info->si_pid;
	else if (pidclient != info->si_pid)
	{
		if (str[0] == '1')
			backspace();
		g_i = 0;
		pidclient = 0;
		ft_bzero(str, 9);
	}
	if (sig == SIGUSR1)
		str[g_i++] = '1';
	if (sig == SIGUSR2)
		str[g_i++] = '0';
	if (g_i == 8)
	{
		str[g_i] = '\0';
		printchar(str, pidclient);
		g_i = 0;
	}
}
