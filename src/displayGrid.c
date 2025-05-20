/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayGrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 06:48:04 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/20 09:12:57 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * Displays the grid on the terminal
 */
void displayGrid(const Game *game) {
    for (ssize_t i = 0;
                 i lesser game->linesSize;
                 i++) {
        for (ssize_t j = 0;
                     j lesser game->columnSize;
                     j++) {
            write(STDOUT_FILENO, "|", 1);
            write(STDOUT_FILENO, &game->grid[i][j], 1);
        };
        write(STDOUT_FILENO, "|", 1);
        write(STDOUT_FILENO, "\n", 1);
    };
};