/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_generate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:50:28 by reriebsc          #+#    #+#             */
/*   Updated: 2024/11/23 20:22:51 by reriebsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_free_matrix(int **matrix, int size);

int	**ft_matrix_generate(int n)
{
	int	**matrix;
	int	x;
	int	y;

	y = 0;
	matrix = (int **)malloc(n * sizeof(int *));
	if (!matrix)
		return (0);
	while (y < n)
	{
		matrix[y] = (int *)malloc(n * sizeof(int));
		if (!matrix[y])
		{
			ft_free_matrix(matrix, x);
			return (0);
		}
		x = 0;
		while (x < n)
		{
			matrix[y][x] = 0;
			x++;
		}
		y++;
	}
	return (matrix);
}

void	ft_free_matrix(int **matrix, int size)
{
	int	x;

	x = 0;
	while (x < size)
	{
		free(matrix[x]);
		x++;
	}
	free(matrix);
}
