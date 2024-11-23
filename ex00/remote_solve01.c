/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remote_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:56:54 by reriebsc          #+#    #+#             */
/*   Updated: 2024/11/23 22:15:56 by reriebsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

ft_remote_validation00(int **matrix, int *views, int y, int x, int n, int size);

int	ft_remote_solve_00(int **matrix, int *views, int size)
{
	int	y;

	y = 0;
	while (y < size)
	{
		ft_remote_solve_01(matrix, views, y, size);
		y++;
	}
	return (0);
}

int	ft_remote_solve_01(int **matrix, int *views, int y, int size)
{
	int	x;
	int	n;

	x = 0;
	while (x < size)
	{
		if (matrix[y][x] == 0)
		{
			n = 1;
			while (n <= size)
			{
				if (ft_remote_validation00(matrix, views, y, x, n, size))
				{
					matrix[y][x] = n;
					if (ft_remote_solve_00(matrix, views, size))
						return (1);
					matrix[y][x] = 0;
				}
				n++;
			}
		}
		x++;
	}
	return (0);
}

// int	ft_remote_solve_02(int **matrix, int *views, int y, int x, int size)
// {
// 	int	n;

// 	n = 1;
// 	while (n <= size)
// 	{
// 		/* code */
// 	}
// 	return (0);
// }
