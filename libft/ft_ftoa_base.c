/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:14:48 by iwillens          #+#    #+#             */
/*   Updated: 2020/02/04 20:01:23 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	set_precision(long long int n, size_t precision)
{
	size_t			total_digits;
	long long int	number;
	long long int	number2;
	number = n;
	total_digits = 1;
	while (number > 9)
	{
		number = number / 10;
		total_digits += 1;
	}
	if (precision >= total_digits)
		return n;
	number = n;
	number2 = n;
	while (total_digits > precision + 1)
	{
		number2 = number2 / 10;
		precision ++;
	}
	if ((number2 % 10) > 5)
		number += 10;
	number = number / 10;
	return (number);
}

char			*ft_ftoa_base(long double n, size_t precision)
{
	char *str;
	char *str2;
	char *str3;
	size_t len1;
	size_t len2;
	long long int n1;
	long double n2;
	size_t i;
	n1 = (long long int)n;
	n2 = n - (long double)n1;
	
	i = 0;
	while (i <= precision)
	{
			n2 = n2 * 10.0;
			i++;
	}

	str = ft_itoa_base((long long int)n1, 10, 0);
	n1 = set_precision(n2, precision);
	str2 = ft_itoa_base(n1, 10, 0);
	len1 = ft_strlen(str);
	str2 = ft_fillnchr_end(str2, '0', precision);
	len2 = ft_strlen(str2);
	str3 = (char*)malloc((len1 + len2 + 2) * sizeof(char));
	str3[0] = '\0';
	ft_strlcat(str3, str, len1 + 1);
	str3[len1] = '.';
	str3[len1+1] = '\0';
	ft_strlcpy(&str3[len1 + 1], str2, len2 + 1);
	free(str);
	free(str2);
	return (str3);
}