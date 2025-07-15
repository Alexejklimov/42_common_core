/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:49:16 by oklimov           #+#    #+#             */
/*   Updated: 2025/02/05 18:20:38 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	n;

	if (!nmemb || !size)
		return (malloc(0));
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	n = 0;
	while (n < nmemb * size)
		ptr[n++] = 0;
	return (ptr);
}

size_t	ft_strlen(const char	*s)

{
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++ ;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	if ((char)c == '\0')
		return ((char *)(s + ft_strlen((char *)s)));
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	if (*s1 == '\0' && *s2 == '\0')
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)

{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[len] != '\0')
	{
		len++ ;
	}
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++ ;
	}
	dest[i] = '\0';
	return (dest);
}
