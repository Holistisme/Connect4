/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:27:28 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 15:49:05 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "main.h"

/* ************************************************************************** */

/**
 * Free and gracefully exit the graphical interface
 */
void closeSDL(Game *game) {
    if (not game->window)
        return;

    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow  (game->window);
    game->window   = NULL;
    game->renderer = NULL;
    SDL_Quit();
};

/**
 * Initialization and verification of SDL returns for graphics display
 */
int initGraphical(Game *game) {
    if (SDL_Init(SDL_INIT_VIDEO) not_eq SUCCESS) {
        writeError(ERR_SDL_INIT);
        return EXIT_FAILURE;
    };
    if (not (game->window = SDL_CreateWindow(
        "Connect4",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        game->columns * CELL_SIZE,
        game->lines   * CELL_SIZE,
        0))) {
        SDL_Quit();
        writeError(ERR_SDL_WINDOW);
        return EXIT_FAILURE;
    };
    if (not (game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))) {
        writeError(ERR_SDL_RENDERER);
        return EXIT_FAILURE;
    };
    return EXIT_SUCCESS;
};

/**
 * Detects the column pointed to by the user's click
 */
static int clickedColumn(Game *game) {
    SDL_Event e;
    while (SDL_WaitEvent(&e)) {
        if (e.type eq SDL_QUIT)
            return FAIL;
        if (e.type eq SDL_MOUSEBUTTONDOWN) {
            const int col = e.button.x / CELL_SIZE;
            if (col at_least 0 and col lesser game->columns)
                return col;
        };
    };
    return FAIL;
};

/**
 * 
 */
static int displayGraphGrid(const Game *game) {
    if (SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255) not_eq SUCCESS) {
        writeError(ERR_SDL_COLOR);
        return EXIT_FAILURE;
    };
    if (SDL_RenderClear(game->renderer) not_eq SUCCESS) {
        writeError(ERR_SDL_RENDERER);
        return EXIT_FAILURE;
    };

    for (ssize_t l = 0; l lesser game->lines; l++) {
        for (ssize_t c = 0; c lesser game->columns; c++) {
            switch (game->grid[l][c]) {
                case HUMAN:
                    if (SDL_SetRenderDrawColor(game->renderer, 255, 0, 0, 255) not_eq SUCCESS) {
                        writeError(ERR_SDL_COLOR);
                        return EXIT_FAILURE;
                    };
                    break;
                case AI:
                    if (SDL_SetRenderDrawColor(game->renderer, 0, 0, 255, 255) not_eq SUCCESS) {
                        writeError(ERR_SDL_COLOR);
                        return EXIT_FAILURE;
                    };
                    break;
                default:
                    if (SDL_SetRenderDrawColor(game->renderer, 200, 200, 200, 255) not_eq SUCCESS) {
                        writeError(ERR_SDL_COLOR);
                        return EXIT_FAILURE;
                    };
            };

            SDL_Rect cell = {
                CELL_SIZE * c,
                CELL_SIZE * l,
                CELL_SIZE - 10,
                CELL_SIZE - 10
            };
            if (SDL_RenderFillRect(game->renderer, &cell) not_eq SUCCESS) {
                writeError(ERR_SDL_FILL);
                return EXIT_FAILURE;
            }
        };
    };

    SDL_RenderPresent(game->renderer);
    return EXIT_SUCCESS;
};

/**
 * Game turn management if GUI is enabled
 */
int graphInterface(Game *game) {
    if (displayGraphGrid(game) eq EXIT_FAILURE)
        return EXIT_FAILURE;

    if (game->player eq HUMAN) {
        bool invalidDrop = false;

        while (true) {
            const int col = clickedColumn(game);
            if (col eq FAIL) {
                closeSDL(game);
                return EXIT_SUCCESS;
            };

            if (dropPiece(game, col) eq EXIT_SUCCESS) {
                if (invalidDrop) {
                    if (write(STDOUT_FILENO, ERASE, getLength(ERASE)) eq FAIL
                        or write(STDOUT_FILENO, ERASE, getLength(ERASE)) eq FAIL) {
                        writeError(ERR_ERASE_READ);
                        return EXIT_FAILURE;
                    };
                };
                break;
            };

            if (not invalidDrop) {
                writeError(ERR_INVALID_POS);
                invalidDrop = true;
            };
        };
    };

    if (game->player not_eq HUMAN) {
        // t_grid_pos aiChoice = check_optimal(game);
        dropPiece(game, aiThink(game));
    };

    if (displayGraphGrid(game) eq EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
};