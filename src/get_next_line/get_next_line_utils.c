/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:10:27 by vpushkar          #+#    #+#             */
/*   Updated: 2025/04/08 17:33:39 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/**
 * @brief Joins two strings into a newly allocated string.
 *
 * This function allocates memory and joins two strings, @p s1 and @p s2,
 * into a single new string. The contents of @p s1 are followed by the
 * contents of @p s2. The resulting string is null-terminated.
 *
 * @param s1 The first string to join.
 * @param s2 The second string to join.
 *
 * @return A pointer to the newly allocated string containing the concatenation
 * 			of @p s1 and @p s2, or NULL if memory allocation fails.
 */
char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;
	char	*result_str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	result_str = (char *)malloc((s1_len + s2_len + 1) * (sizeof(char)));
	if (result_str == NULL)
		return (NULL);
	while (i < s1_len)
	{
		result_str[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		result_str[i++] = s2[j++];
	result_str[i] = '\0';
	return (result_str);
}

/**
 * @brief Calculates the length of a string.
 *
 * This function returns the number of characters in the string @p s,
 * excluding the null-terminator.
 *
 * @param s The string whose length is to be calculated.
 *
 * @return The length of the string @p s.
 */
size_t	ft_strlen_gnl(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * @brief Searches for the first occurrence of character @p c in string @p s.
 *
 * This function iterates through the string @p s and returns a pointer to the
 * first occurrence of the character @p c. If @p c is the null terminator,
 * the function returns a pointer to the null terminator itself.
 *
 * @param s The string to search in.
 * @param c The character to find.
 *
 * @return A pointer to the first occurrence of @p c,
 * 			or NULL if @p c is not found.
 */
char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

/**
 * @brief Duplicates the string @p s1.
 *
 * This function allocates memory for a new string and copies the contents
 * of string @p s1 into the newly allocated memory. The new string is
 * null-terminated.
 *
 * @param s1 The string to duplicate.
 *
 * @return A pointer to the newly allocated string, or NULL if memory
 *			allocation fails.
 */
char	*ft_strdup_gnl(const char *s1)
{
	int		s1_len;
	int		i;
	char	*new_str;

	s1_len = ft_strlen_gnl(s1);
	i = 0;
	new_str = (char *)malloc((s1_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/**
 * @brief Copies a string to a destination with a size limit.
 *
 * This function copies the @p src string to the @p dst string, ensuring that
 * the copied string is null-terminated and that the total size of @p dst
 * does not exceed @p dstsize characters. If @p dstsize is 0, it returns
 * the length of @p src without modifying @p dst.
 *
 * @param dst The destination string to copy the content to.
 * @param src The source string to be copied.
 * @param dstsize The size of the destination buffer.
 *
 * @return The total length of the string it tried to create (i.e., the length
 * 			of @p src).
 */
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen_gnl(src);
	i = 0;
	if (dstsize == 0)
		return (src_len);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
