/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:19:21 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 10:43:33 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * Main play loop
 */
int play(Game *game) {
    const bool graphMode = game->window;

    if (write(STDOUT_FILENO, WELCOME, getLength(WELCOME)) eq FAIL
        or displayGrid(game) eq EXIT_FAILURE)
        return EXIT_FAILURE;

    game->player = rand() % 2 ? HUMAN : AI;
    do {
        if (game->window) {
            if (graphInterface(game) eq EXIT_FAILURE)
                return EXIT_FAILURE;
        } else if (termInterface(game) eq EXIT_FAILURE)
            return EXIT_FAILURE;

        if (displayGrid(game) eq EXIT_FAILURE)
            return EXIT_FAILURE;

        if (graphMode and not game->window)
            return write(STDOUT_FILENO, END_DRAW, getLength(END_DRAW)) eq FAIL ? EXIT_FAILURE : EXIT_SUCCESS;

        game->player = game->player eq HUMAN ? AI : HUMAN;
    } while (not isDraw(game) and game->winner eq NEUTRAL);

    switch (game->winner) {
        case HUMAN: return write(STDOUT_FILENO, END_VICTORY, getLength(END_VICTORY)) eq FAIL ? EXIT_FAILURE : EXIT_SUCCESS;
        case AI:    return write(STDOUT_FILENO, END_DEFEAT,  getLength(END_DEFEAT))  eq FAIL ? EXIT_FAILURE : EXIT_SUCCESS;
        default:    return write(STDOUT_FILENO, END_DRAW,    getLength(END_DRAW))    eq FAIL ? EXIT_FAILURE : EXIT_SUCCESS;
    };
};