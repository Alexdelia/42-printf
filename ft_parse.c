/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:30:27 by adelille          #+#    #+#             */
/*   Updated: 2020/11/30 21:58:50 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char const	*ft_is_minus_or_zero(char const *ptr, t_options *options)
{
	if (*ptr == '-' || *ptr == '0')
	{
		while (*ptr == '-')
		{
			options->minus++;
			ptr += 1;
		}
		while (*ptr == '0')
		{
			options->zero++;
			ptr += 1;
		}
		ptr--;
		return (ptr);
	}
	return (ptr);
}

int			ft_get_precision(char const *ptr)
{
	if ((*ptr < '0' || *ptr > '9') && *ptr != '*' && *ptr != '-')
		return (0);
	if ((*ptr >= '0' && *ptr <= '9') || *ptr == '-')
		return (ft_atoi(ptr));
	return (0);
}

void		ft_is_dot(char const *ptr, va_list arg_list, t_options *options)
{
	char const	*tmp;

	options->dot = 1;
	while (*ptr == '.')
		ptr++;
	tmp = ptr;
	if (*tmp == '*')
	{
		options->precision_star = 1;
		ft_is_star(arg_list, options, 0);
		ptr += 1;
	}
	else
		options->precision = ft_get_precision(ptr);
	while (*ptr == '-' || (*ptr >= '0' && *ptr <= '9'))
		ptr += 1;
	options->type = *ptr;
	if (*ptr == '.')
		ft_is_dot(ptr, arg_list, options);
	return ;
}

void		ft_is_star(va_list arg_list, t_options *options, int bol)
{
	int	star_val;

	star_val = 0;
	star_val = va_arg(arg_list, int);
	if (star_val < 0)
	{
		star_val *= -1;
		if (bol == 1)
			options->minus = 1;
		if (bol == 0)
		{
			options->precision = -1;
			options->dot = 0;
		}
		else
			options->zero = 0;
	}
	else if (bol == 0)
		options->precision = star_val;
	if (bol == 1)
	{
		options->wid = star_val;
		options->wid_bol = 1;
	}
}

void		ft_get_options(char const *input, va_list arg_list,
				t_options *options)
{
	char const	*ptr;

	ptr = input;
	while ((ft_isdigit(*ptr) || *ptr == '*' ||
					*ptr == '.' || *ptr == '-') && *ptr)
	{
		ptr = ft_is_minus_or_zero(ptr, options);
		if (*ptr == '.')
			return (ft_is_dot(ptr, arg_list, options));
		if (*ptr == '*')
			ft_is_star(arg_list, options, 1);
		if (*ptr >= '1' && *ptr <= '9')
		{
			options->wid_bol = 1;
			options->wid = ft_atoi(ptr);
			ptr += nbr_len(options->wid) - 1;
		}
		ptr += 1;
	}
	options->type = *ptr;
}
