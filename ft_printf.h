/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:25:40 by adelille          #+#    #+#             */
/*   Updated: 2020/11/26 21:20:04 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struc	s_options
{
	int			minus;
	int			zero;
	int			dot;
	int			star;
	int			wid;
	int			wid_bol;
	int			precision;
	int			precision_star;
	char		type;
	int			nb_of_fill;
	char		fill_char;
	int			len;
}

#endif
