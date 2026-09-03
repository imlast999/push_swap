/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efresnil <efresnil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 17:46:52 by efresnil          #+#    #+#             */
/*   Updated: 2026/09/02 17:46:56 by efresnil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static	void	free_split_partial(char **split, int index)
{
	while (index > 0)
	{
		index--;
		free(split[index]);
	}
	free(split);
}

static	int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static	char	*fill_word(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = word_len(s, c);
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		word;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			split[word++] = fill_word(&s[i], c);
		if (word > 0 && !split[word - 1])
			return (free_split_partial(split, word - 1), NULL);
		while (s[i] && s[i] != c)
			i++;
	}
	split[word] = NULL;
	return (split);
}
