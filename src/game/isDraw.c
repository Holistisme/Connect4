/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isDraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:16:56 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 08:56:38 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * Return true if no more columns can be played
 */
bool isDraw(const Game *game) {
    for (ssize_t c = 0; c lesser game->columns; c++)
        if (game->grid[0][c] eq NEUTRAL)
            return false;

    return true;
};