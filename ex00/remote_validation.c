/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remote_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:01:15 by reriebsc          #+#    #+#             */
/*   Updated: 2024/11/23 23:12:46 by reriebsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_remote_validation00(int **matrix, int *views, int y, int x, int n, int size)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	while (i < size)
	{
		if (matrix[y][i++] == n || matrix[i][x] == n)
			return (0);
	}
	
}

ft_remote_validation_top(int **matrix, int *views, int y, int x, int n, int size)
{
	int	i;
	int	max;
	int	count;

	max = 0;
	count = 0;
	i = 0;
	while (i <= x)
	{
		if (matrix[i++][x] > max && (++count))
			max = matrix[i - 1][x];
	}
	if (x == size - 1 && count != views[size + y])
		return (0);
}

ft_remote_validation_bottom(int **matrix, int *views, int y, int x, int n, int size)
{
	int	i;
	int	max;
	int	count;

	i = size -1;
	while(i >= y)
	{
		if(matrix[i--][x] > max && (++count))
			max = matrix[i + 1][x];
	}
	if (y == 0 && count != views[3 * size + x])
		return (0);
}

ft_remote_validation_left(int **matrix, int *views, int y, int x, int n, int size)
{
	int	i;
	int	max;
	int	count;

	max = 0;
	count = 0;
	i = 0;
	while (i <= x)
	{
		if (matrix[y][i++] > max && (++count))
			max = matrix[y][i - 1];	
	}
	if (y == size - 1 && count != views[size + x])
		return (0);
}

ft_remote_validation_right(int **matrix, int *views, int y, int x, int n, int size)
{
	int	i;
	int	max;
	int	count;

	i = size -1;
	while (i >= x)
	{
		if(matrix[y][i--] > max && (++count))
			max = matrix[y][i + 1];
	}
	if(x == 0 && count != views[2 * size + x])
		return (0);
}