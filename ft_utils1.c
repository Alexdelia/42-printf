/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:23:04 by adelille          #+#    #+#             */
/*   Updated: 2020/11/26 20:36:01 by adelille         ###   ########.fr       */
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
