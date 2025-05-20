/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameMem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:14:14 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/20 10:28:35 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * Memory allocation for the game structure
 */
Game *allocGame(void) {
    Game *game = malloc(sizeof(Game));

    if (game) {
        game->grid       = NULL;
        game->columnSize = -1;
        game->linesSize  = -1;
    } else writeError(ERR_ALLOC_GAME);

    return game;
};

/**
 * Memory allocation for the game grid
 */
int allocGrid(Game *game) {
    if (not (game->grid = malloc((game->linesSize + 1) * sizeof(string)))) {
        writeError(ERR_ALLOC_GRID);
        return EXIT_FAILURE;
    };
    game->grid[game->linesSize] = NULL;

    for (ssize_t i = 0;
                 i lesser game->linesSize;
                 i++) {
        if (not (game->grid[i] = malloc(game->columnSize + 1))) {
            writeError(ERR_ALLOC_LINE);
            return EXIT_FAILURE;
        } else for (ssize_t j = 0;
                            j lesser game->columnSize;
                            j++) game->grid[i][j] = NEUTRAL;
        game->grid[i][game->columnSize] = '\0';
    };
    return EXIT_SUCCESS;
};

/**
 * Free the game structure memory
 */
void freeGame(Game *game) {
    if (not game)
        return;

    if (game->grid) {
        for (ssize_t l = 0;
                     l lesser game->linesSize;
                     l++) {
            if (game->grid[l]) {
                free(game->grid[l]);
            } else break;
        }
        free(game->grid);
    };
    free(game);
};