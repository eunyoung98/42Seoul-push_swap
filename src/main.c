/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/07/14 20:22:38 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	emptystr(int i, char **argv)
{
	int	chk;
	int	j;

	j = 0;
	chk = 0;
	while (argv[i][j])
	{
		if (argv[i][j] == ' ')
			chk++;
		j++;
	}
	if (chk == j)
		return (1);
	else
		return (0);
}

int	parse(int argc, char **argv)
{
	int	len;
	int	i;
	int	flag;

	i = 1;
	len = 0;
	flag = 0;
	while (i < argc)
	{
		flag = emptystr(i, argv);
		if (flag == 1)
			break ;
		if (argv[i][0] != '\0' && ft_strchr(argv[i], ' ') != 0)
			len += count_word(argv[i], ' ');
		else if (argv[i][0] != '\0')
			len++;
		i++;
	}
	if (len == 0 || flag != 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (len);
}

char	**r_arr(char const *s, char c, char **result, int res_idx)
{
	int	idx;

	while (*s && count_word(s, c))
	{
		while (*s && (*s == c))
			s++;
		result[res_idx] = (char *)malloc(count_len(s, c) + 1);
		if (!result[res_idx])
			return (ft_clear(result, count_word(s, c) + 1));
		idx = 0;
		while (*s && !(*s == c))
			result[res_idx][idx++] = *s++;
		result[res_idx++][idx] = '\0';
		while (*s && (*s == c))
			s++;
	}
	result[res_idx] = 0;
	return (result);
}

char	**insert_arg(int argc, char **argv, char **arg)
{
	int	i;
	int	arg_idx;

	i = 1;
	arg_idx = 0;
	while (i < argc)
	{
		if (argv[i][0] == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		if (ft_strchr(argv[i], ' ') != 0)
		{
			arg = r_arr(argv[i], ' ', arg, arg_idx);
			arg_idx += count_word(argv[i], ' ');
		}
		else
			arg[arg_idx++] = argv[i];
		i++;
	}
	arg[arg_idx] = 0;
	return (arg);
}

void	last_free(int argc, char **argv, char **arg)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	j = 1;
	while (argc-- > 1)
	{
		if (ft_strchr(argv[j], ' '))
		{
			word = count_word(argv[j], ' ');
			while (word-- > 0)
				free(arg[i++]);
		}
		else
			i++;
		j++;
	}
	free(arg);
}
