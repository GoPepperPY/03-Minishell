/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:04:34 by lbordona          #+#    #+#             */
/*   Updated: 2024/05/07 03:19:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/**
 * Comando echo.
 *
 * @param string Array de strings com tudo o que é passado.
 */
int	echo_cmd(char **string) //reduzir função
{
	size_t	i;
	size_t	j;
	size_t	args;
	t_bool	flag_n;

	i = 1;
	j = 0;
	args = ft_array_size(string);
	flag_n = false;
	if (*string == NULL)
		return (0);
	while (j < args)
	{
		if (!check_quotes(string[j]))
			return (1);
		j++;
	}
	if (ft_strcmp_2("-n\0", string[1]))
	{
		flag_n = true;
		i++;
	}
	printf("%s", string[i++]);
	while (i < args)
		printf(" %s", string[i++]);
	if (!flag_n)
		printf("\n");
	return (0);
}

/**
 * Retorna o tamanho do array.
 *
 * @param array Array de strings a ser medido.
 * @return		Tamanho do array.
 */
size_t	ft_array_size(char *const *array)
{
	size_t	size;

	size = 0;
	while (array && *array)
	{
		size++;
		array++;
	}
	return (size);
}

/**
 * Verifica se as aspas (' e/ou ") estão corretas
 *
 * @param str String a ser analisada.
 * @return 1 se as aspas estão corretas, 0 caso contrário.
*/
int	check_quotes(const char *str) //reduzir função
{
	int		i;
	int		in_quotes;
	char	expected_quote;

	i = 0;
	in_quotes = 0;
	expected_quote = '\0';
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			if (!in_quotes)
			{
				in_quotes = 1;
				expected_quote = str[i];
			}
			else
			{
				if (str[i] == expected_quote)
				{
					in_quotes = 0;
					expected_quote = '\0';
				}
			}
		}
		else if (str[i] == '\\' && in_quotes)
			i++;
		i++;
	}
	return (check_quotes_cont(in_quotes, expected_quote));
}

int	check_quotes_cont(int in_quotes, char expected_quote)
{
	if (in_quotes == 0 && expected_quote == '\0')
		return (1);
	else
		return (0);
}
