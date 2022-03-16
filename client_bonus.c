/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 01:32:26 by ygbouri           #+#    #+#             */
/*   Updated: 2022/03/08 23:47:45 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	confirm(int sig);

int	ft_atoi(const char *str)
{
	int	i;
	int	moins;
	int	res;

	i = 0;
	moins = 0;
	res = 0;
	while ((str[i]) && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			moins++;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (moins % 2 == 0)
		return (res);
	return (-res);
}

void	sendnull(int pid)
{
	int	dec;

	dec = 7;
	while (dec >= 0)
	{
		if (('\0' >> dec) & 1)
		{
			if (kill (pid, SIGUSR1) == -1)
				exit(0);
		}
		else
		{
			if (kill (pid, SIGUSR2) == -1)
				exit(0);
		}
		usleep (500);
		dec--;
	}
}

void	traiter(char **str)
{
	int	pid;
	int	i;
	int	dec;

	i = -1;
	pid = ft_atoi(str[1]);
	while (str[2][++i])
	{
		dec = 8;
		while (--dec >= 0)
		{
			if (((str[2][i] >> dec) & 1))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(0);
			}
			else
				if (kill(pid, SIGUSR2) == -1)
					exit(0);
			usleep (500);
		}
	}
	if (str[2][i] == '\0')
		sendnull(pid);
}

int	main(int ar, char **argv)
{
	if (ar == 3)
	{
		signal(SIGUSR1, confirm);
		signal(SIGUSR2, confirm);
		if (ft_atoi(argv[1]) <= 0)
			return (0);
		traiter(argv);
		while (1)
		{
			pause();
		}
	}
	else
		ft_printf("erreur d'entree! saisir 3 argument");
	return (0);
}

void	confirm(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Le message est envoyee\n");
		exit(0);
	}
}
