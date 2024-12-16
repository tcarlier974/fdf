/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:27:56 by tcarlier          #+#    #+#             */
/*   Updated: 2024/12/14 18:04:37 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* get_next_line_utils.c */
/* get_next_line_utils.c */
#include "../includes/get_next_line.h"

size_t	_gnl_ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*_gnl_ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;
	size_t	len;

	len = _gnl_ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*_gnl_ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= _gnl_ft_strlen(s))
		return (_gnl_ft_strdup(""));
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_init(t_gnl *f)
{
	if (!f)
		return ;
	if (!f->buf)
	{
		f->buf = _gnl_ft_strdup("");
		f->eof = 0;
	}
}

void	cleanup_fd(t_gnl *f)
{
	if (!f)
		return ;
	if (f->buf)
	{
		free(f->buf);
		f->buf = NULL;
	}
	f->eof = 0;
}
