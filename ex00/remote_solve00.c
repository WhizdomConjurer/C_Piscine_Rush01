/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remote_solve00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarces- <cgarces-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:24:07 by reriebsc          #+#    #+#             */
/*   Updated: 2024/11/24 16:38:14 by cgarces-         ###   ########.fr       */
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

void	ft_put_n_column_up(struct s_Data_Base data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.field_size)
	{
		if (*data.views == data.field_size)
		{
			j = 0;
			while (j < data.field_size)
			{
				data.matrix[j][i] = j + 1;
				j++;
			}
		}
		i++;
	}
}

void	ft_put_n_column_down(struct s_Data_Base data)
{
	int	i;
	int	j;
	int	f;
	int	k;

	i = 0;
	f = data.field_size;
	k = (data.field_size * 2);
	while (i < data.field_size)
	{
		if (data.views[f] == data.field_size && f < k)
		{
			j = data.field_size - 1;
			while (j >= data.field_size)
			{
				data.matrix[j][i] = j + 1;
				j--;
			}
		}
		i++;
		f++;
		k++;
	}
}

void	ft_put_n_row_left(struct s_Data_Base data)
{
	int	i;
	int	j;
	int	f;
	int	k;

	i = 0;
	f = (data.field_size * 2);
	k = (data.field_size * 3);
	while (i < data.field_size)
	{
		if (data.views[f] == data.field_size && f < k)
		{
			j = 0;
			while (j < data.field_size)
			{
				data.matrix[i][j] = j + 1;
				j++;
			}
		}
		i++;
		f++;
		k++;
	}
}

void	ft_put_n_row_00_right(struct s_Data_Base data)
{
	int	i;
	int	j;
	int	f;
	int	k;

	ft_put_n_column_up(data);
	ft_put_n_column_down(data);
	ft_put_n_row_left(data);
	i = 0;
	f = (data.field_size * 3);
	k = (data.field_size * 4);
	while (i < data.field_size)
	{
		if (data.views[k] == data.field_size && f < k)
		{
			j = data.field_size;
			while (data.field_size <= j)
			{
				data.matrix[i][j] = j + 1;
				j--;
			}
		}
		i++;
		k++;
	}
}
