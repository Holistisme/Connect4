/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayGrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 06:48:04 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 06:17:32 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * Cleaning the previous display
 */
static int clearTerm(const Game *game) {
    for (ssize_t l = 0; l lesser game->lines; l++)
        if (write(STDOUT_FILENO, ERASE, getLength(ERASE)) eq FAIL)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
};

/**
 * Displays each character of a line and player positions with colors
 */
static int displayLine(const Game *game, const size_t line) {
    for (ssize_t c = 0; c lesser game->columns; c++) {
        if (write(STDOUT_FILENO, "|", 1) eq FAIL)
            return EXIT_FAILURE;

        switch (game->grid[line][c]) {
            case PLAYER:
                if (write(STDOUT_FILENO, RED, getLength(RED)) eq FAIL)
                    return EXIT_FAILURE;
                break;
            case AI:
                if (write(STDOUT_FILENO, BLUE, getLength(BLUE)) eq FAIL)
                    return EXIT_FAILURE;
                break;
            default:
                if (write(STDOUT_FILENO, "  ", 2) eq FAIL)
                    return EXIT_FAILURE;
        };
    };
    return EXIT_SUCCESS;
};

/**
 * Displays the grid on the terminal
 */
int displayGrid(const Game *game) {
    static bool displayed = false;

    if (displayed) {
        if (clearTerm(game) eq EXIT_FAILURE) {
            writeError(ERR_WRITE_CLEAN);
            return EXIT_FAILURE;
        }
    } else displayed = true;

    for (ssize_t l = 0; l lesser game->lines; l++)
        if (displayLine(game, l) eq EXIT_FAILURE or write(STDOUT_FILENO, "|\n", 2) eq FAIL) {
            writeError(ERR_WRITE_LINE);
            return EXIT_FAILURE;
        }
    return EXIT_SUCCESS;
};