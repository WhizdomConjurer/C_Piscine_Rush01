/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remote_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarces- <cgarces-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:47:52 by reriebsc          #+#    #+#             */
/*   Updated: 2024/11/24 18:06:19 by cgarces-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_input_optimizer(char *str)
{
	int	v_count;
	int	x;

	v_count = 0;
	while (str[v_count] != '\0')
		v_count++;
	x = (v_count + 1) / 2;
	return (x);
}

int	*ft_remote_view(char *str)
{
	int	*views;
	int	size;
	int	x;
	int	x2;

	size = ft_input_optimizer(str);
	views = (int *)malloc(size * sizeof(int));
	if (!views)
		return (0);
	x = 0;
	x2 = -1;
	while (str[x] != '\0' && x2 <= size)
	{
		if (str[x] >= '1' && str[x] <= '9')
			views[x2++] = str[x] - '0';
		else if (!(str[x] == ' ' || (str[x] >= '1' && str[x] <= '9')))
		{
			free(views);
			break ;
		}
		x++;
	}
	write(1, "a\n", 2);
	return (views);
}
