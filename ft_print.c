/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:37:05 by adelille          #+#    #+#             */
/*   Updated: 2020/11/27 11:01:33 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_options options, int c)
{
	int		size;
	char	fill;

	fill = ' ';
	if (options.zero > 0 && options.minus == 0)
		fill = '0';
	size = 1;
	if (options.minus == 0)
		while (options.wid - 1 > 0)
		{
			ft_putchar_fd(fill, 1);
			options.wid--;
			size++;
		}
	ft_putchar_fd(c, 1);
	if (options.minus == 1)
		while (options.wid - 1 > 0)
		{
			ft_putchar_fd(fill, 1);
			options.wid--;
			size++;
		}
	return (size);
}

int	ft_print_arg(t_options options, va_list arg_list)
{
	(void)arg_list;
	(void)options;
	if (options.type == '%')
		return (ft_print_char(options, '%'));
	if (options.type == 'c')
		return (ft_print_char(options, va_arg(arg_list, int)));
	if (options.type == 's')
		return (ft_convert_s(options, va_arg(arg_list, char *)));
	if (options.type == 'p')
		return (ft_convert_p(options, va_arg(arg_list, void *)));
	if (options.type == 'd' || options.type == 'i')
		return (ft_print_char(options, va_arg(arg_list, int)));
	if (options.type == 'u')
		return (ft_print_char(options, va_arg(arg_list, int)));
	if (options.type == 'x' || option.type == 'X')
		return (ft_print_char(options, va_arg(arg_list, int)));
}
