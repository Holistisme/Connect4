/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 04:33:42 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 06:16:43 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * Define the size of the grid and return code for the validity of the arguments
 */
static int setSize(Game *game, int argc, char *argv[]) {
    if (argc not_eq 3) {
        writeError(ERR_ARGC);
        return EXIT_FAILURE;
    };

    game->lines   = atoui(argv[1]);
    game->columns = atoui(argv[2]);

    if (game->lines eq FAIL or game->columns eq FAIL) {
        writeError(ERR_ARGV);
        return EXIT_FAILURE;
    };

    if (game->lines lesser MIN_LINES or game->lines greater MAX_LINES) {
        writeError(game->lines lesser MIN_LINES ? ERR_LINES_MIN : ERR_LINES_MAX);
        return EXIT_FAILURE;
    };

    if (game->columns lesser MIN_COLUMNS or game->columns greater MAX_COLUMNS) {
        writeError(game->columns lesser MIN_COLUMNS ? ERR_COLUMNS_MIN : ERR_COLUMNS_MAX);
        return EXIT_FAILURE;
    };

    return EXIT_SUCCESS;
};

/* ************************************************************************** */

/**
 * A simple Connect4 game with AI
 */
int main(int argc, char *argv[]) {
    Game *game = allocGame();

    if (not game)
        return EXIT_FAILURE;

    if (setSize(game, argc, argv) eq EXIT_FAILURE or allocGrid(game) eq EXIT_FAILURE) {
        freeGame(game);
        return EXIT_FAILURE;
    };

    srand((unsigned)time(NULL));
    int status = play(game);
    freeGame(game);

    return status;
};