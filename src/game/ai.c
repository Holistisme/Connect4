/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:49:03 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 15:51:35 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

size_t aiPool(Game *game) {
    size_t n = 0;
    size_t pool[MAX_COLUMNS];
    for (ssize_t c = 0; c lesser game->columns; c++)
        if (game->aiReason[c])
            pool[n++] = c;

    if (not n)
        return rand() % game->columns;

    int iteration = 1;
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
static size_t scanAxisSequel(const Game *game, const t_grid_pos token, const ssize_t dirL, const ssize_t dirC, const unsigned char p) {
    const unsigned char player = p;
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

    return sequel;
};

/**
 * Check victory conditions on each axis
 */
size_t longestSequel(const Game *game, const size_t line, const size_t column, const unsigned char p) {
    const t_grid_pos entry = {.x = line, .y = column};
    const size_t hor = scanAxisSequel(game, entry, 0, 1, p);
    const size_t vert = scanAxisSequel(game, entry, 1, 0, p);
    const size_t diag1 = scanAxisSequel(game, entry, 1, 1, p);
    const size_t diag2 = scanAxisSequel(game, entry, 1, -1, p);
    size_t longest = hor;
    if (longest < vert) longest = vert;
    if (longest < diag1) longest = diag1;
    if (longest < diag2) longest = diag2;

        // printf("%zu\n", longest);
    return longest;
};

size_t aiThink(Game *game) {
    for (ssize_t c = 0; c lesser game->columns; c++) {
        game->aiReason[c] = 0;

        if (game->grid[0][c] not_eq NEUTRAL)
            continue;

        size_t l = 0;
        for (ssize_t scan = game->lines - 1;
            scan at_least 0;
            scan--) {
            if (game->grid[scan][c] eq NEUTRAL) {
                l = scan;
                break;
            };
        };

        if (longestSequel(game, l, c, AI) at_least 4)
            game->aiReason[c] += 10;

        if (longestSequel(game, l, c, HUMAN) at_least 4)
            game->aiReason[c] += 10;

        game->aiReason[c] += longestSequel(game, l, c, HUMAN);
        game->aiReason[c] += longestSequel(game, l, c, AI);
    };
    return aiPool(game);
};