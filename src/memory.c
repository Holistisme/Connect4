/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:14:14 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 09:28:12 by aheitz           ###   ########.fr       */
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
        game->grid     = NULL;
        game->columns  = -1;
        game->lines    = -1;
        game->winner   = NEUTRAL;
        game->player   = NEUTRAL;
        game->renderer = NULL;
        game->window   = NULL;
    } else writeError(ERR_ALLOC_GAME);

    return game;
};

/**
 * Memory allocation for the game grid
 */
int allocGrid(Game *game) {
    if (not (game->grid = malloc((game->lines + 1) * sizeof(*game->grid)))) {
        writeError(ERR_ALLOC_GRID);
        return EXIT_FAILURE;
    };
    game->grid[game->lines] = NULL;

    for (ssize_t i = 0; i lesser game->lines; i++) {
        if (not (game->grid[i] = malloc(game->columns + 1))) {
            writeError(ERR_ALLOC_LINE);
            return EXIT_FAILURE;
        } else for (ssize_t j = 0;
                            j lesser game->columns;
                            j++) game->grid[i][j] = NEUTRAL;
        game->grid[i][game->columns] = 0;
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
        for (ssize_t l = 0; l lesser game->lines; l++) {
            if (game->grid[l]) {
                free(game->grid[l]);
            } else break;
        }
        free(game->grid);
    };
    free(game);
};