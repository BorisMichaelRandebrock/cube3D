
#include <stdlib.h>
#include "cube3d.h"
#define NUL_SZ	1

size_t	ft_strlen(const char	*s)
{
	size_t	length;

	length = 0;
	while (*s)
	{
		length++;
		s++;
	}
	return (length);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;

	dst_len = 0;
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (*src && dst_len < (size - NUL_SZ))
		{
			*dst = *src;
			dst_len++;
			dst++;
			src++;
		}
		*dst = '\0';
	}
	return (src_len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str_ptr;
	char	target_chr;

	str_ptr = (char *)s;
	target_chr = (char)c;
	while (*str_ptr)
	{
		if (*str_ptr == target_chr)
		{
			return (str_ptr);
		}
		str_ptr++;
	}
	if (target_chr == '\0')
	{
		return (str_ptr);
	}
	return (NULL);
}
char	*ft_strdup(const char *s)
{
	char	*duplicate;
	size_t	s_length;

	s_length = (size_t) ft_strlen(s) + NUL_SZ;
	duplicate = (char *)malloc(s_length);
	if (duplicate == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(duplicate, s, s_length);
	return (duplicate);
}