/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remote_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarces- <cgarces-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:01:15 by reriebsc          #+#    #+#             */
/*   Updated: 2024/11/24 17:26:29 by cgarces-         ###   ########.fr       */
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

int	ft_remote_validation_col_row(struct s_Data_Base data, int y, int x, int n)
{
	int	i;

	i = 0;
	while (i < data.field_size)
	{
		if (data.matrix[y][i] == n || data.matrix[i][x] == n)
			return (0);
		i++;
	}
	return (1);
}

int	ft_remote_validation_top(struct s_Data_Base data, int x)
{
	int	i;
	int	max;
	int	count;

	max = 0;
	count = 0;
	i = 0;
	while (i <= x)
	{
		if (data.matrix[i++][x] > max && (++count))
			max = data.matrix[i - 1][x];
	}
	if (x == data.field_size - 1 && count != data.views[x])
		return (0);
	return (1);
}

int	ft_remote_validation_bottom(struct s_Data_Base data, int y, int x)
{
	int	i;
	int	max;
	int	count;

	i = data.field_size -1;
	count = 0;
	while (i >= y)
	{
		if (data.matrix[i--][x] > max && (++count))
			max = data.matrix[i + 1][x];
	}
	if (y == 0 && count != data.views[data.field_size + x])
		return (0);
	return (1);
}

int	ft_remote_validation_left(struct s_Data_Base data, int y, int x)
{
	int	i;
	int	max;
	int	count;

	max = 0;
	count = 0;
	i = 0;
	while (i <= x)
	{
		if (data.matrix[y][i++] > max && (++count))
		{
			max = data.matrix[y][i - 1];
		}
	}
	if (y == data.field_size - 1
		&& count != data.views[2 * data.field_size + y])
		return (0);
	return (1);
}

int	ft_remote_validation_00_right(struct s_Data_Base data, int y, int x, int n)
{
	int	i;
	int	max;
	int	count;

	count = 0;
	ft_remote_validation_col_row(data, y, x, n);
	ft_remote_validation_top(data, x);
	ft_remote_validation_bottom(data, y, x);
	ft_remote_validation_left(data, y, x);
	i = data.field_size -1;
	while (i >= x)
	{
		if (data.matrix[y][i--] > max && (++count))
			max = data.matrix[y][i + 1];
	}
	if (x == 0 && count != data.views[3 * data.field_size + y])
		return (0);
	return (1);
}
