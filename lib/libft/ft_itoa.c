/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:39:49 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/05/14 13:26:18 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(int n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		len++;
		if (n == -2147483648)
			n = 2147483647;
		else
			n = -n;
	}
	while (n / 10)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*neg_int(char *arr, int n)
{
	int	len;

	len = n_len(n);
	while (len)
	{
		arr[len-- - 1] = "0123456789"[-(n % 10)];
		n = n / 10;
	}
	arr[0] = '-';
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;

	len = n_len(n);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	arr[len] = 0;
	if (n < 0)
	{
		arr = neg_int(arr, n);
	}
	else
	{
		while (len)
		{
			arr[len-- - 1] = "0123456789"[n % 10];
			n = n / 10;
		}
	}
	return (arr);
}
