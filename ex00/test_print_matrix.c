/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:56:43 by reriebsc          #+#    #+#             */
/*   Updated: 2024/11/23 19:44:55 by reriebsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_print_matrix(int **matrix, int size)
{
	int	y;
	int	x;

	y = 0;
	while (y < size -1)
	{
		x = 0;
		while (x < size -1)
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
	while (y <= n)
	{
		matrix[y] = (int *)malloc(n * sizeof(int));
		if (!matrix[y])
		{
			ft_free_matrix(matrix, x);
			return (0);
		}
		x = 0;
		while (x <= n)
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

int	main(void)
{
	int	**matrix;
	int	size;

	size = 5;
	matrix = ft_matrix_generate(size);
	ft_print_matrix(matrix, size);
	return (0);
}
