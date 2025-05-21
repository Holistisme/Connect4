/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:41:07 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 09:25:41 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * Game turn management if GUI is disabled
 */
int termInterface(Game *game) {
    t_grid_pos aiChoice;

    switch (game->player) {
        case HUMAN:
            if (humanTurn(game) eq EXIT_FAILURE)
                return EXIT_FAILURE;
            break;
        case AI:
            aiChoice = check_optimal(game);
            dropPiece(game, aiChoice.y);
    };

    return EXIT_SUCCESS;
};