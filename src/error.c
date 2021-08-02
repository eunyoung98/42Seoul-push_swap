/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	chk_dup(char **argv, int i)
{
	int	start;

	start = i - 1;
	while (start >= 0)
	{
		if (ft_atoi(argv[i]) == ft_atoi(argv[start]))
			return (0);
		start--;
	}
	return (1);
}

int	chk_asc(int len, char **argv)
{
	int	cnt;
	int	i;
	int	start;

	cnt = 0;
	start = 0;
	while (start < len)
	{
		i = start + 1;
		if (i != len)
		{
			if (ft_atoi(argv[start]) < ft_atoi(argv[i]))
				cnt++;
		}
		start++;
	}
	if (cnt == len - 1)
		return (0);
	return (1);
}

int	is_zero(char **argv, int i)
{
	int	j;

	j = 0;
	if (argv[i][j] == '-' || argv[i][j] == '+')
		j++;
	while (argv[i][j])
	{
		if (argv[i][j] != '0')
			return (0);
		j++;
	}
	return (1);
}

int	before_atoi(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '\0' && !(*str >= '0' && *str <= '9'))
		return (0);
	return (1);
}

int	check_arr(char **argv, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (argv[i] == 0 || before_atoi(argv[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		if (ft_atoi(argv[i]) == 0 && is_zero(argv, i) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		if (chk_dup(argv, i) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (chk_asc(len, argv));
}
