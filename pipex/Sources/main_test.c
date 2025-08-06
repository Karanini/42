/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:37:50 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/06 13:41:15 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	(void)argc;
	char *exec_argv[] = {argv[1], argv[2], NULL};
	char *env = NULL;
	execve(argv[1], exec_argv, &env);
	perror("Error");
	return(0);
}

// int	main(int argc, char *argv[])
// {
// 	(void)argc;

// }
