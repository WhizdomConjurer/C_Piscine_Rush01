/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remote_solve01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:29:40 by reriebsc          #+#    #+#             */
/*   Updated: 2024/11/24 15:27:40 by reriebsc         ###   ########.fr       */
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

void	ft_put_1_column_up(struct s_Data_Base data)
{
	int	i;

	i = 0;
	while (i < data.field_size)
	{
		if (data.views[i] == 1)
			data.matrix[0][i] = data.field_size;
		i++;
	}
}

void	ft_put_1_column_down(struct s_Data_Base data)
{
	int	i;
	int	f;
	int	k;

	i = 0;
	f = data.field_size;
	k = (data.field_size * 2);
	while (i < data.field_size)
	{
		if (data.views[f] == 1 && f < k)
			data.matrix[data.field_size - 1][i] = data.field_size;
		i++;
		f++;
		k++;
	}
}

void	ft_put_1_row_left(struct s_Data_Base data)
{
	int	i;
	int	f;
	int	k;

	i = 0;
	f = (data.field_size * 2);
	k = (data.field_size * 3);
	while (i < data.field_size)
	{
		if (data.views[f] == 1 && f < k)
			data.matrix[i][0] = data.field_size;
		i++;
		k++;
		f++;
	}
}

void	ft_put_1_row_right(struct s_Data_Base data)
{
	int	i;
	int	f;
	int	k;

	ft_put_1_column_up(data);
	ft_put_1_column_down(data);
	ft_put_1_row_left(data);
	i = 0;
	f = (data.field_size * 3);
	k = (data.field_size * 4);
	while (i < data.field_size)
	{
		if (data.views[f] == 1 && f < k)
			data.matrix[i][data.field_size - 1] = data.field_size;
		i++;
		f++;
		k++;
	}
}
