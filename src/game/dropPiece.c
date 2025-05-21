/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropPiece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:24:47 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 08:53:46 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * Lower piece to the lowest index
 */
int dropPiece(Game *game, const ssize_t c) {
    if (c at_least game->columns)
        return EXIT_FAILURE;

    ssize_t l = game->lines - 1;
    while (l at_least 0 and game->grid[l][c] not_eq NEUTRAL)
        --l;

    if (l at_least 0) {
        game->grid[l][c] = game->player;
        if (victory(game, l, c))
            game->winner = game->player;
        return EXIT_SUCCESS;
    } else return EXIT_FAILURE;
};