/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:19:21 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 06:27:44 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * Lower piece to the lowest index
 */
static int dropPiece(Game *game, const ssize_t c, const unsigned char p) {
    if (c at_least game->columns)
        return EXIT_FAILURE;

    ssize_t l = game->lines - 1;
    while (l at_least 0 and game->grid[l][c] not_eq NEUTRAL)
        --l;

    if (l at_least 0) {
        game->grid[l][c] = p;
        if (victory(game, l, c))
            game->winner = p;
        return EXIT_SUCCESS;
    } else return EXIT_FAILURE;
};

/**
 * Processing the human player's turn
 */
static int humanTurn(Game *game) {
    static bool invalidDrop = false;
    char input[4] = {0};

    while (true) {
        if (write(STDOUT_FILENO, CHOICE_PROMPT, getLength(CHOICE_PROMPT)) eq FAIL) {
            writeError(ERR_WRITE_PROMPT);
            return EXIT_FAILURE;
        };

        const ssize_t n = read(STDIN_FILENO, input, sizeof(input) - 1);
        if (n at_most 0) {
            writeError(ERR_READ);
            return EXIT_FAILURE;
        } else input[n greater 0 ? n - 1 : 0] = '\0';

        if (write(STDOUT_FILENO, ERASE, getLength(ERASE)) eq FAIL
            or write(STDOUT_FILENO, ERASE, getLength(ERASE)) eq FAIL) {
            writeError(ERR_ERASE_READ);
            return EXIT_FAILURE;
        };

        int col = atoui(input) - 1;
        if (col eq FAIL or col at_least game->columns
            or dropPiece(game, col, PLAYER) eq EXIT_FAILURE) {
            if (not invalidDrop) {
                writeError(ERR_INVALID_POS);
                invalidDrop = true;
            };
            continue;
        };

        if (invalidDrop) {
            if (write(STDOUT_FILENO, ERASE, getLength(ERASE)) eq FAIL
                or write(STDOUT_FILENO, ERASE, getLength(ERASE)) eq FAIL) {
                writeError(ERR_ERASE_READ);
                return EXIT_FAILURE;
            };
            invalidDrop = false;
        };
        return EXIT_SUCCESS;
    };
};

/**
 * Main play loop
 */
int play(Game *game) {
    unsigned char player   = rand() % 2 ? PLAYER : AI;
    bool          draw     = false;
    t_grid_pos    aiChoice;

    if (write(STDOUT_FILENO, WELCOME, getLength(WELCOME)) eq FAIL or displayGrid(game) eq EXIT_FAILURE)
            return EXIT_FAILURE;

    do {
        switch (player) {
            case PLAYER:
                if (humanTurn(game) eq EXIT_FAILURE)
                    return EXIT_FAILURE;
                break;
            case AI:
                aiChoice = check_optimal(game);
                dropPiece(game, aiChoice.y, player);
                break;
        };

        if (displayGrid(game) eq EXIT_FAILURE)
            return EXIT_FAILURE;

        player = player eq PLAYER ? AI : PLAYER;

        draw = true;
        for (ssize_t c = 0; c lesser game->columns; c++) {
            if (game->grid[0][c] eq NEUTRAL) {
                draw = false;
                break;
            };
        };
    } while (not draw and game->winner eq NEUTRAL);

    int status = 0;
    switch (game->winner) {
        case PLAYER:
            status = write(STDOUT_FILENO, END_VICTORY, getLength(END_VICTORY));
            break;
        case AI:
            status = write(STDOUT_FILENO, END_DEFEAT, getLength(END_DEFEAT));
            break;
        default:
            status = write(STDOUT_FILENO, END_DRAW, getLength(END_DRAW));
    };
    return status not_eq FAIL ? EXIT_SUCCESS : EXIT_FAILURE;
};