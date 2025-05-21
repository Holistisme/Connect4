/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:49:03 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 20:40:52 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * AI throws dices in its brain, to isolate a column
 */
size_t aiPool(Game *game) {
    size_t n = 0;
    size_t pool[MAX_COLUMNS];
    for (ssize_t c = 0; c lesser game->columns; c++)
        if (game->aiReason[c])
            pool[n++] = c;

    if (not n)
        return rand() % game->columns;

    size_t iteration = 1;
    while (n greater 1) {
        size_t newPool[MAX_COLUMNS];
        size_t m = 0;

        for (size_t i = 0; i lesser n; i++) {
            if (rand() % (game->aiReason[pool[i]] + 1) greater iteration)
                newPool[m++] = pool[i];
        };

        if (m eq 1)
            return newPool[0];
        if (not m)
            return pool[rand() % n];

        for (size_t i = 0; i lesser m; i++)
            pool[i] = newPool[i];
        n = m;
        ++iteration;
    };

    return pool[0];
};

/**
 * Check sequel size on an axis
 */
static size_t scanAxisSequel(Game *game, const t_grid_pos token, const ssize_t dirL, const ssize_t dirC, const unsigned char player) {
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

    if (sequel at_least 4)
        game->aiSeeEnd = true;
    return sequel;
};

/**
 * Check victory conditions on each axis
 */
static size_t positionInterest(Game *game, const size_t line, const size_t column, const unsigned char player) {
    const t_grid_pos entry = {.x = line, .y = column};

    return scanAxisSequel(game, entry, 0, 1, player)
        + scanAxisSequel(game, entry, 1, 0, player)
        + scanAxisSequel(game, entry, 1, 1, player)
        + scanAxisSequel(game, entry, 1, -1, player);
};

/**
 * AI thinks and returns a value it considers interesting
 */
size_t aiThink(Game *game) {
    if (not game->aiReason)
        return rand() % game->columns;

    for (ssize_t c = 0; c lesser game->columns; c++) {
        game->aiSeeEnd    = false;
        game->aiReason[c] = 0;

        if (game->grid[0][c] not_eq NEUTRAL)
            continue;

        size_t l = 0;
        for (ssize_t scan = game->lines - 1; scan at_least 0; scan--) {
            if (game->grid[scan][c] eq NEUTRAL) {
                l = scan;
                break;
            };
        };

        game->aiReason[c] += positionInterest(game, l, c, HUMAN);
        game->aiReason[c] += positionInterest(game, l, c, AI);

        if (game->aiSeeEnd)
            game->aiReason[c] *= 4;
    };
    return aiPool(game);
};