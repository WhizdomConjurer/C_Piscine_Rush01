/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:56:22 by reriebsc          #+#    #+#             */
/*   Updated: 2024/11/23 21:04:18 by reriebsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_print_matrix(int **matrix, int size)
{
	int	y;
	int	x;

	y = 0;
	while (y <= size -1)
	{
		x = 0;
		while (x <= size -1)
		{
			if (x > 0)
				write(1, &" ", 1);
			write(1, &(char){matrix[y][x] + 48}, 1);
			x++;
		}
		write(1, &"\n", 1);
		y++;
	}
}
