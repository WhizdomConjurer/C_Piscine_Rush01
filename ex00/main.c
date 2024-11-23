/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:32:40 by reriebsc          #+#    #+#             */
/*   Updated: 2024/11/23 22:30:07 by reriebsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_input_optimizer(char *str);
int	*ft_remote_view(char *str);
int	**ft_matrix_generate(int n);

void	ft_write_error(void)
{
	write(1, &"Error\n", 6);
}

int	main(int argc, char argv[])
{
	int	size;
	int	**matrix;
	int	*views;

	if (argc != 2)
		ft_write_error();
	size = ft_input_optimizer(argv[1]);
	views = *ft_remote_view(argv[1]);
	matrix = **ft_matrix_generate(size);
}
