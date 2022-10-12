/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:31:13 by jpicron           #+#    #+#             */
/*   Updated: 2022/10/11 13:11:11 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *file, char *tmp, int indic)
{
	char	*str;
	int		i;
	int		j;

	if (!file)
	{
		file = malloc(sizeof(char) * 1);
		file[0] = '\0';
	}
	if (!file || !tmp)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(file) + ft_strlen(tmp)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (file[++i])
		str[i] = file[i];
	while (tmp[j])
		str[i++] = tmp[j++];
	str[i] = '\0';
	if (indic == 1)
		free(file);
	return (str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size -1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

char	**ft_filldup(char **dup, int j, int i)
{
	int	k;

	k = 0;
	while (k < i)
	{
		dup[k] = malloc((j + 1) * sizeof(char) + 1);
		if (!dup[k])
		{
			while (k >= 0)
				free(dup[k]);
			free(dup);
			return (NULL);
		}
		k++;
	}
	return (dup);
}

char	**ft_arrdup(char **s, char	**dup)
{	
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i][j])
		j++;
	while (s[i])
		i++;
	dup = malloc((i + 1) * sizeof(char *));
	if (!dup)
		return (NULL);
	if (!ft_filldup(dup, j, i + 1))
		return (NULL);
	while (s[k])
	{
		ft_strlcpy(dup[k], s[k], j + 1);
		k++;
	}
	while (dup[k])
		k++;
	return (dup);
}
