/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:41:07 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 15:49:22 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * Game turn management if GUI is disabled
 */
int termInterface(Game *game) {
    switch (game->player) {
        case HUMAN:
            if (humanTurn(game) eq EXIT_FAILURE)
                return EXIT_FAILURE;
            break;
        case AI:
            dropPiece(game, aiThink(game));
    };

    return EXIT_SUCCESS;
};