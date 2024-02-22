/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:00:06 by goda-sil          #+#    #+#             */
/*   Updated: 2023/01/19 17:27:58 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	identify_flag(va_list	argument, const char type)
{
	int	len;
	int	temporary;

	len = 0;
	if (type == 'c')
	{
		temporary = va_arg(argument, int);
		return (write(1, &temporary, 1));
	}
	else if (type == 's')
		len = len + print_string(va_arg(argument, char *));
	else if (type == 'd' || type == 'i')
		len = len + print_decimal_integer(va_arg(argument, int));
	else if (type == 'u')
		len = len + print_decimal_unsigned(va_arg(argument, unsigned int));
	else if (type == 'x' || type == 'X')
		len = len + print_hex(va_arg(argument, unsigned int), type);
	else if (type == 'p')
		len = len + print_pointer(va_arg(argument, unsigned long long));
	else if (type == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (len);
}

int	ft_printf(const char *input, ...)
{
	int			counter;
	int			bytes;
	va_list		argument;

	counter = 0;
	bytes = 0;
	va_start(argument, input);
	while (input[counter])
	{
		if (input[counter] == '%')
		{
			bytes = bytes + identify_flag(argument, 's');
			counter++;
		}
		else
			bytes = bytes + write(1, &input[counter], 1);
		counter++;
	}
	va_end(argument);
	return (bytes);
}