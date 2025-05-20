/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tritter <tritter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:52:42 by tritter           #+#    #+#             */
/*   Updated: 2025/05/20 14:35:13 by tritter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct grid_pos
{
    int x;
    int y; 
    int length;
} t_grid_pos;

int         is_full(char c);
int         legal_placement(char **grid, t_grid_pos origin);
t_grid_pos  check_optimal(Game *data);
t_grid_pos  optimal_move_check(Game *data, t_grid_pos origin);
t_grid_pos  left_check(Game *data, t_grid_pos origin);
t_grid_pos  right_check(Game *data, t_grid_pos origin);
t_grid_pos  diagonal_right_check(Game *data, t_grid_pos origin);
t_grid_pos  diagonal_left_check(Game *data, t_grid_pos origin);
t_grid_pos  up_check(Game *data, t_grid_pos origin);
