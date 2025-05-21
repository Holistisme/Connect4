/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_ai.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:52:19 by tritter           #+#    #+#             */
/*   Updated: 2025/05/20 15:58:56 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int is_full(char c)
{
    if (c == '1' || c == '2')
        return (1);
    else 
        return (0);
}

int legal_placement(Game *data, t_grid_pos origin)
{
    if (origin.x == data->lines - 1)
        return (1);
    else
        return (is_full(data->grid[origin.x + 1][origin.y]));
}

t_grid_pos check_optimal(Game *data)
{
    t_grid_pos optimal;
    t_grid_pos to_evaluate;
    t_grid_pos curr;
    
    optimal.length = -1;
    curr.x = 0;
    curr.y = 0;
    curr.length = 0;
    while (curr.x < data->lines)
    {
        while (curr.y < data->columns)
        {
            to_evaluate = optimal_move_check(data, curr);
            if (to_evaluate.length > optimal.length)
                optimal = to_evaluate;
            if (optimal.length == 4)
                return (optimal);
            curr.y++;
        }
        curr.y = 0;
        curr.x++;
    }
    return (optimal);
}

t_grid_pos optimal_move_check(Game *data, t_grid_pos origin)
{
    t_grid_pos optimal;
    t_grid_pos curr;
    
    optimal.length = -1;
    curr = left_check(data, origin);
    if (curr.length > optimal.length)
        optimal = curr;
    curr = right_check(data, origin);
    if (curr.length > optimal.length)
        optimal = curr;
    curr = diagonal_left_check(data, origin);
    if (curr.length > optimal.length)
        optimal = curr;
    curr = diagonal_right_check(data, origin);
    if (curr.length > optimal.length)
        optimal = curr;
    curr = up_check(data, origin);
    if (curr.length > optimal.length)
        optimal = curr;
    return (optimal);
}
t_grid_pos left_check(Game *data, t_grid_pos origin)
{
    t_grid_pos  curr;
    int         i;
    
    i = 0;
    curr = origin;
    curr.length = 0;
    while (i < 4)
    {
        if (curr.y >= 0)
        {
            if (data->grid[curr.x][curr.y] == AI)
            {
                curr.y--;
                curr.length++;
            }
            else if (data->grid[curr.x][curr.y] == NEUTRAL)
            {
                if (legal_placement(data, curr))
                    return (curr);
                else 
                {
                    curr.length = -1;
                    return (curr);
                }
            }
        }
        else
        {
            curr.length = -1;
            return (curr);
        }
        i++; 
    }

    return curr;
}

t_grid_pos right_check(Game *data, t_grid_pos origin)
{
    t_grid_pos  curr;
    int         i;
    
    i = 0;
    curr = origin;
    curr.length = 0;
    while (i < 4)
    {
        if (curr.y < data->lines)
        {
            if (data->grid[curr.x][curr.y] == AI)
            {
                curr.y++;
                curr.length++;
            }
            else if (data->grid[curr.x][curr.y] == NEUTRAL)
            {
                if (legal_placement(data, curr))
                    return (curr);
                else 
                {
                    curr.length = -1;
                    return (curr);
                }
            }
        }
        else
        {
            curr.length = -1;
            return (curr);
        }
        i++;
    }

    return curr;
}

t_grid_pos diagonal_right_check(Game *data, t_grid_pos origin)
{
    t_grid_pos  curr;
    int         i;
    
    i = 0;
    curr = origin;
    curr.length = 0;
    while (i < 4)
    {
        if (curr.x < data->lines && curr.y < data->columns)
        {
            if (data->grid[curr.x][curr.y] == AI)
            {
                curr.x++;
                curr.y++;
                curr.length++;
            }
            else if (data->grid[curr.x][curr.y] == NEUTRAL)
            {
                if (legal_placement(data, curr))
                    return (curr);
                else 
                {
                    curr.length = -1;
                    return (curr);
                }
            }
        }
        else
        {
            curr.length = -1;
            return (curr);
        } 
        i++;
    }

    return curr;
}

t_grid_pos diagonal_left_check(Game *data, t_grid_pos origin)
{
    t_grid_pos  curr;
    int         i;
    
    i = 0;
    curr = origin;
    curr.length = 0;
    while (i < 4)
    {
        if (curr.x < data->lines && curr.y > 0)
        {
            if (data->grid[curr.x][curr.y] == AI)
            {
                curr.x++;
                curr.y--;
                curr.length++;
            }
            else if (data->grid[curr.x][curr.y] == NEUTRAL)
            {
                if (legal_placement(data, curr))
                    return (curr);
                else 
                {
                    curr.length = -1;
                    return (curr);
                }
            }
        }
        else
        {
            curr.length = -1;
            return (curr);
        }
        i++;
    }

    return curr;
}

t_grid_pos up_check(Game *data, t_grid_pos origin)
{
    t_grid_pos  curr;
    int         i;
    
    i = 0;
    curr = origin;
    curr.length = 0;
    while (i < 4)
    {
        if (curr.x < data->lines)
        {
            if (data->grid[curr.x][curr.y] == AI)
            {
                curr.x++;
                curr.length++;
            }
            else if (data->grid[curr.x][curr.y] == NEUTRAL)
            {
                if (legal_placement(data, curr))
                    return (curr);
                else 
                {
                    curr.length = -1;
                    return (curr);
                }
            }
        }
        else
        {
            curr.length = -1;
            return (curr);
        } 
        i++;
    }

    return curr;
}
