/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:01:12 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/29 13:35:00 by bkaras-g         ###   ########.fr       */
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
	int				exit_status;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_fdes
{
	int				fd_infile;
	int				fd_outfile;
}					t_fdes;

t_fdes				*ft_check_files(char *argv[], int argc);
int					ft_check_path(t_cmd *cmd, char **env);

t_cmd				*ft_init_cmd_list(char **argv, int nb_cmds);
t_cmd				*ft_lstnew(char *cmd_with_args);
void				ft_lstadd_back(t_cmd **lst, t_cmd *new);
t_cmd				*ft_lstlast(t_cmd *lst);
int					ft_lstsize(t_cmd *lst);
void				ft_print_list_complete(t_cmd *lst);

int					ft_create_pipes(t_cmd *cmd);
int					ft_fork(t_fdes *fdes, t_cmd *cmd, char *env[]);

void				ft_lstclear(t_cmd **lst);
int					ft_close_unused_fdes(t_fdes *fdes, t_cmd *cmd);
void				ft_cleanup_and_exit_child(t_fdes *fdes, t_cmd *head);

int					ft_cmd_name_not_valid(char *cmd_name);

#endif
