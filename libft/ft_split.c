/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteizag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:40:49 by esteizag          #+#    #+#             */
/*   Updated: 2023/11/02 21:40:51 by esteizag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	state;
	int	wcount;

	state = 0;
	wcount = 0;
	while (*s != '\0')
	{
		if (*s != c && state == 0)
		{
			state = 1;
			wcount++;
		}
		else if (*s == c)
		{
			state = 0;
		}
		s++;
	}
	return (wcount);
}

static char	*extract_word(char const *s, char c)
{
	int		len;
	char	*word;
	char	*word_address;

	len = 0;
	while (s[len] != c && s[len] != '\0')
	{
		len++;
	}
	word = (char *)malloc(sizeof(char) * (len +1));
	word_address = word;
	if (word != NULL)
	{	
		while (len > 0)
		{
			*word = *s;
			word++;
			s++;
			len--;
		}
		*word = '\0';
	}
	return (word_address);
}

static char const	*next_word_start(char const *s, char c)
{
	while (*s != c && *s != '\0')
	{
		s++;
	}
	while (*s == c && *s != '\0')
	{
		s++;
	}
	return (s);
}

static void	free_words(char **words, int word_ind)
{
	while (word_ind >= 0)
	{
		free(words[word_ind]);
		word_ind--;
	}
	free(words);
}

char	**ft_split(char const *s, char c)
{
	int		word_ind;
	char	**words;

	words = malloc(sizeof(char *) * (word_count(s, c) + 1));
	word_ind = 0;
	if (words != NULL)
	{
		if (*s == c)
		{
			s = next_word_start(s, c);
		}
		while (*s != '\0')
		{
			words[word_ind] = extract_word(s, c);
			if (words[word_ind] == NULL)
			{
				free_words(words, word_ind);
				return (NULL);
			}
			s = next_word_start(s, c);
			word_ind++;
		}
		words[word_ind] = NULL;
	}
	return (words);
}

/* int main(void)
{
	char **my_words = ft_split("!hola!!!que!tal!<<<", '!');
	char **words_og = my_words;
	while(*my_words != NULL)
	{
		printf("%s\n", *my_words);
		char *current_word = *my_words;
		my_words++;
		free(current_word);
	}
	free(words_og);
} */

/* #include <stdio.h>

int main()
{
    char **words;
    int i;

    // Test case 1: Normal string with space as separator
    words = ft_split("Hello World! This is a test.", ' ');
    i = 0;
    while (words[i] != NULL)
    {
        printf("%s\n", words[i]);
        free(words[i]); // Don't forget to free each word
        i++;
    }
    free(words); // And the array itself

    // Test case 2: String with no occurrences of separator
    words = ft_split("HelloWorld!", ' ');
    i = 0;
    while (words[i] != NULL)
    {
        printf("%s\n", words[i]);
        free(words[i]);
        i++;
    }
    free(words);

    // Test case 3: String with only the separator
    words = ft_split("     ", ' ');
    if (words != NULL) // Check if ft_split returned NULL
    {
        i = 0;
        while (words[i] != NULL)
        {
            printf("%s\n", words[i]);
            free(words[i]);
            i++;
        }
        free(words);
    }

    return 0;
} */
