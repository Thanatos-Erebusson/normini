/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:14:31 by vismaily          #+#    #+#             */
/*   Updated: 2022/05/03 13:11:33 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	intra(void)
{
	printf("***************************************************************\n");
	printf("*  .-.   .-..-..-. .-..-.    .----..-. .-..----..-.   .-.     *\n");
	printf("*  |  `.'  || ||  `| || |   { {__  | {_} || {_  | |   | |     *\n");
	printf("*  | |╲ /| || || |╲  || |   .-._} }| { } || {__ | `--.| `--.  *\n");
	printf("*  `-' ` `-'`-'`-' `-'`-'   `----' `-' `-'`----'`----'`----'  *\n");
	printf("***************************************************************\n");
	printf("*        :::      :::::::: ***   Author: Volodya Ismailyan    *\n");
	printf("*      :+:      :+:    :+: ***   E-Mail: nenie_iri@mail.ru    *\n");
	printf("*    +:+ +:+         +:+   ************************************\n");
	printf("*  +#+  +:+       +#+      ***    ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★     *\n");
	printf("*+#+#+#+#+#+   +#+         ************************************\n");
	printf("*     #+#    #+#           ***  Updated: 2022/05/03 13:11:00  *\n");
	printf("*    ###   ########.fr     ***  Created: 2022/03/26 16:14:31  *\n");
	printf("***************************************************************\n");
}

static int	check_status(t_var *env_lst, int *status)
{
	while (env_lst->meaning != '?')
		env_lst = env_lst->next;
	if (env_lst->value != 0)
	{
		if (ft_strncmp(env_lst->value, "exit", 5) == 0)
		{
			*status = env_lst->status;
			return (1);
		}
	}
	return (0);
}

static int	start(int argc, char **argv, char **envp, t_var **env_lst)
{
	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd("The program no needs any argument\n", 2);
		return (1);
	}
	intra();
	signals_init();
	env_to_list(envp, env_lst);
	shlvl(env_lst);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char			*line;
	t_var			*env_lst;
	t_token			*tokens;
	int				status;

	if (start(argc, argv, envp, &env_lst) == 1)
		return (0);
	while (1)
	{
		line = readline("\033[1;32mMinishell$ \033[0m");
		if (!line)
		{
			ft_putstr_fd("exit\n", 1);
			return (EXIT_SUCCESS);
		}
		if (ft_strncmp(line, "", ft_strlen(line)) != 0)
			add_history(line);
		parsing_line(line, &tokens, &env_lst);
		free(line);
		if (check_status(env_lst, &status) == 1)
			break ;
	}
	lst_clear(&env_lst, &free);
	return (status);
}
