/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:39:04 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/05/17 12:32:44 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_clear(char **arr, unsigned int len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

unsigned int	count_word(char const *s, char c)
{
	unsigned int	idx;
	unsigned int	cnt;

	cnt = 0;
	idx = 0;
	while (s[idx])
	{
		while (s[idx] && (s[idx] == c))
			idx++;
		if (s[idx] && !(s[idx] == c))
			cnt++;
		while (s[idx] && !(s[idx] == c))
			idx++;
	}
	return (cnt);
}

unsigned int	count_len(char const *s, char c)
{
	unsigned int	len;

	len = 0;
	while (s[len] && !(s[len] == c))
		len++;
	return (len);
}

char	**r_result(char const *s, char c, char **result)
{
	unsigned int	idx;
	unsigned int	res_idx;

	res_idx = 0;
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

char	**ft_split(char const *s, char c)
{
	char			**result;

	if (!s)
		return (0);
	result = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!result)
		return (0);
	result = r_result(s, c, result);
	return (result);
}
