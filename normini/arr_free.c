/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:33:18 by vismaily          #+#    #+#             */
/*   Updated: 2022/04/09 16:30:57 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	arr_free(char **arr)
{
	int	i;

	i = -1;
	if (arr != 0)
	{
		while (arr[++i] != 0)
			free(arr[i]);
		free(arr);
	}
}
