/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:48:06 by adelille          #+#    #+#             */
/*   Updated: 2020/11/26 21:19:53 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		free (str);
	return (res);
}

int		ft_convert_p(t_options options, void *addr)
{
	char	*addr_str;
	long	addr_l;
	int		res;
	char	*final_str;

	addr_l = (long)addr;
	addr_str = ft_itoa_preci(addr_l, options);
}
