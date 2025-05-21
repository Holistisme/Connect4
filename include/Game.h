/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 05:51:16 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 20:50:57 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME
#define GAME

/* ************************************************************************** */

#include "lib.h"

/* ************************************************************************** */

typedef struct Game {
    ssize_t         lines;
    ssize_t         columns;
    unsigned char **grid;
    unsigned char   player;
    unsigned char   winner;

    size_t *aiReason;
    bool    aiSeeEnd;

    SDL_Window   *window;
    SDL_Renderer *renderer;
} Game;

typedef struct grid_pos
{
    int x;
    int y; 
} t_grid_pos;

/* ************************************************************************** */

#endif