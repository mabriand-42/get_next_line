/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:13:43 by mabriand          #+#    #+#             */
/*   Updated: 2019/12/12 14:46:38 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** ft_strlen(1)
** =========
*/

size_t		ft_strlen_gnl(char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*
** Cherche la première occurence de '\n' dans la chaîne de caractères s.
** =========
** #1 : une chaîne de caractères.
** =========
** Retourne la taille de s.
*/

ssize_t		ft_search_line(char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/*
** ft_strdup(1)
** =========
*/


char		*ft_strdup_gnl(char *s1)
{
	size_t	i;
	char	*s;
	size_t	size;
	char	*copy;

	i = 0;
	s = (char *)s1;
	size = ft_strlen_gnl(s);
	copy = ((char *)malloc(sizeof(*copy) * (size + 1)));
	if (copy == NULL)
		return (NULL);
	while (i < size)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*
** Alloue un emplacement mémoire dans lequelle elle copie
** les n premiers caractères de s1.
** =========
** #1 : une chaîne de caractères à copier.
** #2 : la taille de la partie à copier.
** =========
** Retourne la nouvelle chaîne de caractères.
*/

char		*ft_strndup_gnl(char *s1, size_t size)
{
	size_t	i;
	char	*copy;

	i = 0;
	copy = ((char *)malloc(sizeof(*copy) * (size + 1)));
	if (copy == NULL)
		return (NULL);
	while (i < size)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*
** ft_strjoin(2) et libère la chaîne de caractère s1.
** =========
*/

char		*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	i = 0;
	j = 0;
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
