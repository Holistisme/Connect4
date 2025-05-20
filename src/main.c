/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 04:33:42 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/20 10:18:40 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * Processing and verifying an unsigned integer argument
 */
static int atoui(string ascii) {
    while (*ascii eq SPACE or (*ascii at_least TAB and *ascii at_most CARRIAGE))
        ++ascii;

    if (*ascii eq '+')
        ++ascii;

    long result = 0;
    while (*ascii at_least '0' and *ascii at_most '9') {
        result = result * 10 + *ascii++ - '0';

        if (result greater INT_MAX)
            return -1;
    };
    
    if (*ascii)
        return -1;
    
    return result;
};

/* ************************************************************************** */

/**
 * Define the size of the grid and return code for the validity of the arguments
 */
static int setSize(Game *game, int argc, char *argv[]) {
    if (argc not_eq 3) {
        writeError(ERR_ARGC);
        return EXIT_FAILURE;
    };

    game->linesSize  = atoui(argv[1]);
    game->columnSize = atoui(argv[2]);

    if (game->linesSize eq FAIL or game->columnSize eq FAIL) {
        writeError(ERR_ARGV);
        return EXIT_FAILURE;
    };

    if (game->linesSize lesser MIN_LINES or game->linesSize greater MAX_LINES) {
        writeError(game->linesSize lesser MIN_LINES ? ERR_LINES_MIN : ERR_LINES_MAX);
        return EXIT_FAILURE;
    };

    if (game->columnSize lesser MIN_COLUMNS or game->columnSize greater MAX_COLUMNS) {
        writeError(game->columnSize lesser MIN_COLUMNS ? ERR_COLUMNS_MIN : ERR_COLUMNS_MAX);
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

    if (setSize(game, argc, argv) eq EXIT_FAILURE) {
        freeGame(game);
        return EXIT_FAILURE;
    };

    if (allocGrid(game) eq EXIT_FAILURE) {
        freeGame(game);
        return EXIT_FAILURE;
    };

    displayGrid(game);
    freeGame(game);
    return EXIT_SUCCESS;
};