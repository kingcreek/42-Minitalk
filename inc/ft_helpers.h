/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:03:30 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/06 15:58:27 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HELPERS_H
# define FT_HELPERS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_message
{
	char	c;
	size_t	i;
}	t_message;

t_message	g_msg;

#endif