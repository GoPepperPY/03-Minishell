/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:42:55 by lbordona          #+#    #+#             */
/*   Updated: 2024/04/23 12:13:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* getcwd -> On success, these functions return a
pointer to a string containing the pathname of
the current working directory */

void	pwd_cmd()
{
	printf("%s\n", getcwd(0, 0));
}
