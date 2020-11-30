/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:14:28 by adelille          #+#    #+#             */
/*   Updated: 2020/11/30 20:00:11 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_flag(t_options options, va_list arg_list, int *size)
{
	if (!ft_is_type(options.type))
		*size += ft_print_char(options, options.type);
	else if (options.type == 's' && options.precision < 0
					&& options.precision_star == 0)
	{
		options.len = options.precision * -1;
		options.wid = 0;
		if (options.zero > 0 && options.precision >= 0)
			options.fill_char = '0';
		*size += ft_convert_s(options, "");
	}
	else
		*size += ft_print_arg(options, arg_list);
}

int		ft_detect(va_list arg_list, char const *input)
{
	size_t		i;
	t_options	options;
	int			size;

	i = 0;
	size = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			options = ft_init_options();
			ft_get_options(&input[i], arg_list, &options);
			ft_print_flag(options, arg_list, &size);
			while (input[i] != options.type)
				i++;
		}
		else
		{
			ft_putchar_fd(input[i], 1);
			size++;
		}
		i++;
	}
	return (size);
}

int		ft_printf(const char *input, ...)
{
	va_list	arg_list;
	int		res;

	va_start(arg_list, input);
	res = ft_detect(arg_list, input);
	va_end(arg_list);
	return (res);
}
