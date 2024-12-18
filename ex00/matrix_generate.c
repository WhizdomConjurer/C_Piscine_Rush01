/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_generate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:50:28 by reriebsc          #+#    #+#             */
/*   Updated: 2024/11/24 15:27:34 by reriebsc         ###   ########.fr       */
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

void	ft_free_matrix(struct s_Data_Base data);

int	**ft_matrix_generate(struct s_Data_Base data)
{
	int	**matrix;
	int	x;
	int	y;

	y = 0;
	matrix = (int **)malloc(data.field_size * sizeof(int *));
	if (!matrix)
		return (0);
	while (y < data.field_size)
	{
		matrix[y] = (int *)malloc(data.field_size * sizeof(int));
		if (!matrix[y])
		{
			ft_free_matrix(data);
			return (0);
		}
		x = 0;
		while (x < data.field_size)
		{
			matrix[y][x] = 0;
			x++;
		}
		y++;
	}
	return (matrix);
}

void	ft_free_matrix(struct s_Data_Base data)
{
	int	x;

	x = 0;
	while (x < data.field_size)
	{
		free(data.matrix[x]);
		x++;
	}
	free(data.matrix);
}
