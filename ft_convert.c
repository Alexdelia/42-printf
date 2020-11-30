/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:48:06 by adelille          #+#    #+#             */
/*   Updated: 2020/11/30 20:17:34 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_hexa_prefix(t_options *options, char *addr_str)
{
	char	*res;
	int		len;

	len = ft_strlen(addr_str) + 3;
	if (!(res = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_bzero(res, len);
	res[0] = '0';
	if (options->type == 'p' || options->type == 'x')
		res[1] = 'x';
	else
		res[1] = 'X';
	ft_strlcat(res, addr_str, len);
	if (options->precision == 0)
		options->precision = 2;
	return (res);
}

int		ft_convert_s(t_options options, char *str)
{
	int		res;
	int		to_free;

	to_free = 0;
	if (!str)
	{
		str = ft_strdup("(null)");
		to_free++;
	}
	if (options.type == 'p' && ft_strlen(str) > options.precision)
		options.len = ft_strlen(str);
	else
		options.len = options.precision;
	if (options.precision > ft_strlen(str) || options.dot == 0)
		options.len = ft_strlen(str);
	if (options.wid > options.len)
		options.nb_of_fill = options.wid - options.len;
	else
		options.nb_of_fill = 0;
	if (options.zero > 0 && options.precision >= 0)
		options.fill_char = '0';
	res = ft_print(options, str);
	if (to_free == 1)
		free(str);
	return (res);
}

int		ft_convert_p(t_options options, void *addr)
{
	char	*addr_str;
	long	addr_l;
	int		res;
	char	*final_str;

	addr_l = (long)addr;
	addr_str = printf_ft_itoa(addr_l, options);
	final_str = ft_add_hexa_prefix(&options, addr_str);
	if (!addr && options.precision == 2 && options.dot == 1)
		res = ft_convert_s(options, "0x");
	else
		res = ft_convert_s(options, final_str);
	free(addr_str);
	free(final_str);
	return (res);
}

int		ft_convert_diux(t_options options, long nb)
{
	char	*nbr;
	int		res;

	if (options.dot == 0 && options.wid > 0 && options.zero == 1)
	{
		options.fill_char = '0';
		options.precision = options.wid;
		if (nb < 0)
			options.precision--;
	}
	nbr = printf_ft_itoa(nb, options);
	ft_get_options_len(&options, &nbr, nb);
	if (options.wid > ft_strlen(nbr))
		options.nb_of_fill = options.wid - ft_strlen(nbr);
	res = ft_print(options, nbr);
	if (!(options.dot == 1 && options.precision == 0 && nb == 0))
		free(nbr);
	return (res);
}
