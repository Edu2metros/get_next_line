/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:26:13 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/08/28 11:26:19 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = 0;
}

void	*ft_calloc(size_t nitems, size_t size)
{
	int		*p;
	size_t	overflow;

	overflow = nitems * size;
	if (nitems != 0 && (overflow / nitems) != size)
		return (NULL);
	p = malloc(nitems * size);
	if (p == NULL)
		return (p);
	ft_bzero(p, size * nitems);
	return (p);
}

char	*ft_strchr(const char *str, int c)
{
	int					i;
	const unsigned char	*str_ptr;
	unsigned char		chr;

	str_ptr = (const unsigned char *)str;
	chr = (unsigned char)c;
	if (str_ptr == NULL)
		return (NULL);
	i = 0;
	while (str_ptr[i] != '\0')
	{
		if (chr == str_ptr[i])
			return ((char *)&str_ptr[i]);
		i++;
	}
	if (chr == '\0')
		return ((char *)&str_ptr[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*result;

	len1 = 0;
	len2 = 0;
	if (!s1 && !s2)
		return (NULL);
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	while (s1 != NULL && s1[len1] != '\0')
	{
		result[len1] = s1[len1];
		len1++;
	}
	while (s2 != NULL && s2[len2] != '\0')
	{
		result[len1 + len2] = s2[len2];
		len2++;
	}
	result[len1 + len2] = '\0';
	free((void *)s1);
	return (result);
}
