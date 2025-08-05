/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:01:12 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/05 11:56:21 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct s_cmd
{
	char			*cmd;
	char			**argv;
	int				fd[2];
	struct s_cmd	*next;
}					t_cmd;

int					ft_tunelling(int fd_infile, int fd_outfile, char *argv[]);
void				ft_check_files(char *argv[], int *fd_infile,
						int *fd_outfile);

t_cmd				*ft_init_stack(char **argv);
t_cmd				*ft_lstnew(char *cmd_with_args);
void				ft_lstadd_front(t_cmd **lst, t_cmd *new);
void				ft_lstclear(t_cmd **lst);

#endif
