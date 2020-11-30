/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:29:10 by adelille          #+#    #+#             */
/*   Updated: 2020/11/30 19:59:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_options	ft_init_options(void)
{
	t_options	options;

	options.minus = 0;
	options.zero = 0;
	options.dot = 0;
	options.star = 0;
	options.wid = 0;
	options.wid_bol = 0;
	options.precision = 0;
	options.precision_star = 0;
	options.nb_of_fill = 0;
	options.fill_char = ' ';
	options.len = 0;
	return (options);
}

int			ft_is_type(char c)
{
	return ((c == '%') ||
					(c == 'c') ||
					(c == 's') ||
					(c == 'p') ||
					(c == 'd') ||
					(c == 'i') ||
					(c == 'u') ||
					(c == 'x') ||
					(c == 'X'));
}

int			nbr_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int			ft_nbr_len_base(t_options options, long nb)
{
	int	divider;
	int	size;

	if (options.type == 'd' || options.type == 'i' || options.type == 'u')
		divider = 10;
	else if (options.type == 'X' || options.type == 'x' || options.type == 'p')
		divider = 16;
	size = 0;
	if (nb <= 0)
		size++;
	while (nb)
	{
		nb /= divider;
		size++;
	}
	return (size);
}

void		ft_get_options_len(t_options *options, char **nbr, int nb)
{
	if (options->dot == 1 && options->precision == 0 && nb == 0)
	{
		options->len = 0;
		free(*nbr);
		*nbr = "";
	}
	else
		options->len = ft_strlen(*nbr);
	if (options->precision < 0 && options->precision_star == 0)
	{
		options->minus = 1;
		options->nb_of_fill = options->precision * -1 - options->len;
		options->wid = 0;
	}
}
