/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:28:44 by adelille          #+#    #+#             */
/*   Updated: 2020/11/30 20:22:09 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_fill_nbr(t_options options, unsigned long *nb)
{
	char		c;
	static char	base_lowcase[] = "0123456789abcdef";
	static char	base_upcase[] = "0123456789ABCDEF";

	if (options.type == 'u' || options.type == 'd' || options.type == 'i')
	{
		c = *nb % 10 + 48;
		*nb /= 10;
	}
	if (options.type == 'x' || options.type == 'X' || options.type == 'p')
	{
		if (options.type == 'X' || options.type == 'p')
			c = base_lowcase[*nb % 16];
		else
			c = base_upcase[*nb % 16];
		*nb /= 16;
	}
	return (c);
}

char	*ft_create_nbr(t_options *options, int size, long n)
{
	char	*nbr;
	int		malloc_size;

	if (options->dot == 0 && options->zero == 1)
		options->precision = options->wid;
	if (options->precision > size)
	{
		malloc_size = options->precision + 1;
		options->precision = options->precision - size;
	}
	else
	{
		options->precision = 0;
		malloc_size = size + 1;
	}
	if (!(nbr = malloc(sizeof(char) * (malloc_size))))
		return (NULL);
	ft_bzero(nbr, malloc_size);
	if (options->type != 'p' && n < 0)
		nbr[0] = '-';
	return (nbr);
}

char	*ft_init_itoa(long n, t_options options, int *size, int *i)
{
	int		j;
	char	*nbr;

	j = 0;
	if (n < 0)
	{
		options.precision++;
		*i = 1;
		j = 1;
		*size += 1;
	}
	nbr = ft_create_nbr(&options, *size, n);
	while (options.precision > 0)
	{
		nbr[j] = '0';
		j++;
		*size += 1;
		options.precision--;
	}
	return (nbr);
}

char	*printf_ft_itoa(long n, t_options options)
{
	char			*nbr;
	unsigned long	nb;
	int				size;
	int				i;

	nb = n;
	if (nb < 0)
		nb = -nb;
	i = 0;
	size = ft_nbr_len_base(options, nb);
	nbr = ft_init_itoa(n, options, &size, &i);
	nbr[size] = '\0';
	size--;
	while (size >= i)
	{
		nbr[size] = ft_fill_nbr(options, &nb);
		size--;
	}
	return (nbr);
}
