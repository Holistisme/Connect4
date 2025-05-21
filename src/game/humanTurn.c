/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanTurn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:25:52 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 10:02:31 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * Processing the human player's turn
 */
int humanTurn(Game *game) {
    bool invalidDrop = false;
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
            or dropPiece(game, col) eq EXIT_FAILURE) {
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
        };
        return EXIT_SUCCESS;
    };
};