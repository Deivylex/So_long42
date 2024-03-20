/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:20:56 by dzurita           #+#    #+#             */
/*   Updated: 2023/11/28 16:21:56 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_list(char format, va_list args, int *check_error)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int), check_error);
	else if (format == 's')
		count += ft_putstr (va_arg(args, char *), check_error);
	else if (format == 'p')
	{
		count += ft_putstr("0x", check_error);
		count += ft_print_p(va_arg(args, unsigned long), 16, check_error);
	}
	else if (format == 'd' || format == 'i')
		count += ft_print_num((long)va_arg(args, int), 10, 0, check_error);
	else if (format == 'u')
		count += ft_print_num(va_arg(args, unsigned int), 10, 0, check_error);
	else if (format == 'x')
		count += ft_print_num(va_arg(args, unsigned int), 16, 0, check_error);
	else if (format == 'X')
		count += ft_print_num(va_arg(args, unsigned int), 16, 1, check_error);
	else if (format == '%')
		count += ft_putchar('%', check_error);
	return (count);
}

int	ft_putchar(const char c, int *check_error)
{
	if (*check_error == -1)
		return (-1);
	if (write (1, &c, 1) == -1)
	{
		*check_error = -1;
		return (-1);
	}
	return (1);
}

int	ft_putstr(const char *str, int *check_error)
{
	int	count;

	if (!str)
		return (ft_putstr("(null)", check_error));
	count = 0;
	while (*str)
		count += ft_putchar(*str++, check_error);
	return (count);
}

int	ft_print_num(long nbr, int base, int upc, int *check_error)
{
	int		count;
	char	*ascii_lwc;
	char	*ascii_upc;

	ascii_lwc = "0123456789abcdef";
	ascii_upc = "0123456789ABCDEF";
	if (nbr < 0)
	{
		ft_putchar('-', check_error);
		return (ft_print_num(-nbr, base, upc, check_error) + 1);
	}
	else if (nbr < base)
	{
		if (upc == 0)
			return (ft_putchar(ascii_lwc[nbr], check_error));
		else
			return (ft_putchar(ascii_upc[nbr], check_error));
	}
	else
	{
		count = ft_print_num((nbr / base), base, upc, check_error);
		count += ft_print_num((nbr % base), base, upc, check_error);
		return (count);
	}
}

int	ft_print_p(unsigned long nbr, unsigned int base, int *check_error)
{
	int		count;
	char	*ascii;

	ascii = "0123456789abcdef";
	if (nbr < 16)
		return (ft_putchar(ascii[nbr], check_error));
	else
	{
		count = ft_print_p((nbr / base), base, check_error);
		count += ft_print_p((nbr % base), base, check_error);
		return (count);
	}
}
