/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:03:54 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 04:51:06 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * Check victory conditions on an axis
 */
static bool scanAxis(const Game *game, const t_grid_pos token, const ssize_t dirL, const ssize_t dirC) {
    const unsigned char player = game->grid[token.x][token.y];
    if (player eq NEUTRAL)
        return false;

    size_t sequel = 1;
    ssize_t scanL = token.x + dirL,
            scanC = token.y + dirC;
    while ( scanL at_least 0 and scanL lesser game->lines
        and scanC at_least 0 and scanC lesser game->columns
        and game->grid[scanL][scanC] eq player) {
            ++sequel;
            scanL += dirL;
            scanC += dirC;
        };

    scanL = token.x - dirL;
    scanC = token.y - dirC;
    while (scanL at_least 0 and scanL lesser game->lines
        and scanC at_least 0 and scanC lesser game->columns
        and game->grid[scanL][scanC] eq player) {
            ++sequel;
            scanL -= dirL;
            scanC -= dirC;
        };

    return sequel at_least 4;
};

/**
 * Check victory conditions on each axis
 */
bool victory(const Game *game, const size_t line, const size_t column) {
    const t_grid_pos entry = {.x = line, .y = column};

    return scanAxis(game, entry, 0, 1)
        or scanAxis(game, entry, 1, 0)
        or scanAxis(game, entry, 1, 1)
        or scanAxis(game, entry, 1, -1);
};