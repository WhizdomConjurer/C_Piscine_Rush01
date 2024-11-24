/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarces- <cgarces-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:56:22 by reriebsc          #+#    #+#             */
/*   Updated: 2024/11/24 18:09:13 by cgarces-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

struct s_Data_Base
{
	int	input_size;
	int	field_size;
	int	*views;
	int	**matrix;
};

void	ft_print_matrix(struct s_Data_Base data)
{
	int	y;
	int	x;

	y = 0;
	while (y <= data.field_size - 1)
	{
		x = 0;
		while (x <= data.field_size - 1)
		{
			if (x > 0)
				write(1, " ", 1);
			write(1, &(char){data.matrix[y][x] + 48}, 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
