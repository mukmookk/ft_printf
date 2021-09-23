/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_hex_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:44:00 by youngmki          #+#    #+#             */
/*   Updated: 2021/09/23 19:44:34 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(unsigned int nbr, t_print *tab)
{
	const char	*hex;

	hex = "0123456789abcdef";
	if (nbr >= 16)
		ft_puthex(nbr / 16, tab);
	tab->total_length += write(1, &hex[nbr % 16], 1);
}

void	ft_proc_hex_lower(t_print *tab)
{
	unsigned int	nbr;

	nbr = va_arg(tab->args, unsigned int);
	ft_puthex(nbr, tab);
}
