/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:57:10 by jcaetano          #+#    #+#             */
/*   Updated: 2021/09/13 14:48:31 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			word_count(char const *s, char c);
static char const	*next_word(char const *s, char c);
static char			**ft_splitter(char **s_array, char const *s,
						char c, size_t len);

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**s_array;

	if (s == NULL)
		return (NULL);
	size = word_count(s, c);
	s_array = malloc(sizeof(char **) * (size + 1));
	if (!s_array)
		return (NULL);
	return (ft_splitter(s_array, s, c, size));
}

/**
 * @brief Counts the number of words in 's'
 * by using the character 'c' as word delimiter.
 *
 * @param s Pointer to the area of memory of the string
 * @param c Word delimiter
 * @return int Returns the number of words in string 's'.
 */
int	word_count(char const *s, char c)
{
	size_t	len;
	size_t	is_c;

	len = 0;
	is_c = 1;
	while (*s)
	{
		if (*s != c && is_c)
		{
			is_c = 0;
			len++;
		}
		else if (*s == c)
			is_c = 1;
		s++;
	}
	return (len);
}

/**
 * @brief Find the first word after 'c', if the string begins with it
 *
 * @param s Pointer to the area of memory of the string
 * @param c Character to skip occurrences in the string 's'
 * @return char const* A pointer to first character different from 'c'.
 * NULL-terminated byte if all 's' characters equal 'c'.
 */
static char const	*next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

/**
 * @brief Splits the words into a list of strings by using
 * the 'c' delimiter.
 *
 * @param s_array Pointer to receive the list of strings
 * @param s String containing the list of words
 * @param c Character to split the words
 * @param len Size of the s_array
 * @return char** Returns a NULL-terminated list of words
 * separated by the character 'c'.
 */
static char	**ft_splitter(char **s_array, char const *s, char c, size_t len)
{
	char	*c_pos;
	char	**s_array_start;

	s_array_start = s_array;
	s = next_word(s, c);
	while (len--)
	{
		c_pos = ft_strchr(s, c);
		if (c_pos != NULL)
		{
			*s_array = ft_substr(s, 0, c_pos - s);
			s = next_word(c_pos, c);
		}
		else
			*s_array = ft_substr(s, 0, ft_strlen(s) + 1);
		s_array++;
	}
	*s_array = NULL;
	return (s_array_start);
}
