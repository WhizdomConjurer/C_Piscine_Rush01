/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarces- <cgarces-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:32:40 by reriebsc          #+#    #+#             */
/*   Updated: 2024/11/24 17:50:03 by cgarces-         ###   ########.fr       */
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

int	ft_input_optimizer();
int	*ft_remote_view(char *str);
int	**ft_matrix_generate(int n);
int	ft_remote_solve_00(struct s_Data_Base data);
int	ft_put_n_row_00_right(struct s_Data_Base data);
int	ft_put_1_row_right(struct s_Data_Base data);
void	ft_print_matrix(struct s_Data_Base data);

void	ft_write_error(void)
{
	write(1, &"Error\n", 6);
}

int	ft_manage_solvings(struct s_Data_Base data)
{
	ft_put_n_row_00_right(data);
	ft_put_1_row_right(data);
	ft_remote_solve_00(data);
	ft_print_matrix(data);

	return (0);
}

int	main(int argc, char **argv)
{
	struct s_Data_Base	data;

	if (argc != 2)
		ft_write_error();
	data.input_size = ft_input_optimizer(&argv[1]);
	data.field_size = data.input_size / 4;
	data.views = ft_remote_view(*argv);
	data.matrix = ft_matrix_generate(data.field_size);
	ft_manage_solvings(data);

	return (0);
}
