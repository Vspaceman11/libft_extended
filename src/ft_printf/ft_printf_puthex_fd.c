/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthex_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:22:01 by vpushkar          #+#    #+#             */
/*   Updated: 2025/03/28 13:41:16 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/**
 * @brief Writes an unsigned integer in lowercase hexadecimal to fd.
 *
 * This function recursively converts the unsigned integer `n` into a
 * lowercase hexadecimal string and writes it to the file descriptor `fd`.
 *
 * @param n The unsigned integer to convert.
 * @param fd The file descriptor to write to.
 * @return The number of characters written, or -1 if error occurs.
 */
int	ft_printf_puthex_lower_fd(unsigned int n, int fd)
{
	char	*hex_digits;
	int		count;
	int		result;

	hex_digits = "0123456789abcdef";
	count = 0;
	result = 0;
	if (n >= 16)
	{
		result = ft_printf_puthex_lower_fd(n / 16, fd);
		if (result == -1)
			return (-1);
		count += result;
	}
	if (write(fd, &hex_digits[n % 16], 1) == -1)
		return (-1);
	count++;
	return (count);
}

/**
 * @brief Writes an unsigned integer in uppercase hexadecimal to fd.
 *
 * This function recursively converts the unsigned integer `n` into a
 * uppercase hexadecimal string and writes it to the file descriptor `fd`.
 *
 * @param n The unsigned integer to convert.
 * @param fd The file descriptor to write to.
 * @return The number of characters written, or -1 if error occurs.
 */
int	ft_printf_puthex_upper_fd(unsigned int n, int fd)
{
	char	*hex_digits;
	int		count;
	int		result;

	hex_digits = "0123456789ABCDEF";
	count = 0;
	result = 0;
	if (n >= 16)
	{
		result = ft_printf_puthex_upper_fd(n / 16, fd);
		if (result == -1)
			return (-1);
		count += result;
	}
	if (write(fd, &hex_digits[n % 16], 1) == -1)
		return (-1);
	count++;
	return (count);
}
