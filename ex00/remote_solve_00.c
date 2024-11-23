/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remote_solve_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:24:07 by reriebsc          #+#    #+#             */
/*   Updated: 2024/11/23 22:27:46 by reriebsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_put_4_column_up(int **matriz, int value, int header[])
{
    int i = 0;
    int j;

    while(i< value)
    {
        if(header[i] == value)
        {
            j = 0;
            while(j<value)
            {
                matriz[j][i] = j + 1;
                j++;
            }
        }
        i++;
    }
}



void ft_put_4_column_down(int **matriz, int value, int header[])
{
    int i = 0;
    int j;
    int f = value;
    int k = (value * 2);

    while(i< value)
    {
        if(header[f] == value && f<k)
        {
            j = value - 1 ;
            while(j>=value)
            {
                matriz[j][i] = j + 1;
                j--;
            }
        }
        i++;
        f++;
        k++;
    }
}

void ft_put_4_row_left(int **matriz, int value, int header[])
{
    int i = 0;
    int j;
    int f = (value * 2);
    int k = (value * 3);

    while(i< value)
    {
        if(header[f] == value && f<k)
        {
            j = 0;
            while(j<value)
            {
                matriz[i][j] = j + 1;
                j++;
            }
        }
        i++;
        f++;
        k++;
    }
}

void ft_put_4_row_right(int **matriz, int value, int header[])
{
    int i = 0;
    int j;
    int f = (value * 3);
    int k = (value * 4);

    while(i< value)
    {
        if(header[k] == value && f<k)
        {
            j = value;
            while(value<=j)
            {
                matriz[i][j] = j + 1;
                j--;
            }
        }
        i++;
        k++;
    }
}
