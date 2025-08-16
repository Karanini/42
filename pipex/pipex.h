/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:01:12 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/16 13:29:36 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd
{
	char			*cmd_name;
	char			**argv;
	int				pfd[2];
	int				fd_in;
	int				fd_out;
	int				first;
	pid_t			pid;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_fdes
{
	int				fd_infile;
	int				fd_outfile;
}					t_fdes;

t_fdes				*ft_check_files(char *argv[], int argc);
int					ft_check_path(t_cmd *cmd, char **env);

t_cmd				*ft_init_stack(char **argv, int nb_cmds);
t_cmd				*ft_lstnew(char *cmd_with_args);
void				ft_lstadd_back(t_cmd **lst, t_cmd *new);
t_cmd				*ft_lstlast(t_cmd *lst);
void				ft_print_list_complete(t_cmd *lst);

int					ft_create_pipes(t_cmd *cmd, int argc);
int					ft_fork(t_fdes *fdes, t_cmd *cmd, char *env[]);
void				ft_lstclear(t_cmd **lst);

#endif
