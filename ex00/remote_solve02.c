/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remote_solve02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarces- <cgarces-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:56:54 by reriebsc          #+#    #+#             */
/*   Updated: 2024/11/24 17:07:08 by cgarces-         ###   ########.fr       */
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

int	ft_remote_validation_00_right(struct s_Data_Base data, int y, int x, int n);

int	ft_remote_solve_01(struct s_Data_Base data, int y);

int	ft_remote_solve_00(struct s_Data_Base data)
{
	int	y;

	y = 0;
	while (y < data.field_size)
	{
		ft_remote_solve_01(data, y);
		y++;
	}
	return (0);
}

int	ft_remote_solve_01(struct s_Data_Base data, int y)
{
	int	x;
	int	n;

	x = 0;
	while (x < data.field_size)
	{
		if (data.matrix[y][x] == 0)
		{
			n = 1;
			while (n <= data.field_size)
			{
				if (ft_remote_validation_00_right(data, y, x, n))
				{
					data.matrix[y][x] = n;
					if (ft_remote_solve_00(data))
						return (1);
					data.matrix[y][x] = 0;
				}
				n++;
			}
		}
		x++;
	}
	return (0);
}
