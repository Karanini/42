/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:01:12 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/04 13:03:12 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

int	ft_check_infile(char* filename);
int	ft_check_outfile(char *filename);

#endif
