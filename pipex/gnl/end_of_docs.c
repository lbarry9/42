/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_docs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:19:32 by lbarry            #+#    #+#             */
/*   Updated: 2024/02/10 18:19:51 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*end_of_heredoc(t_stock *stash)
{
	free_stash(stash);
	stash = NULL;
	return (NULL);
}

char	*end_of_doc(t_stock *stash, char *line)
{
	free_stash(stash);
	stash = NULL;
	free(line);
	return (NULL);
}
