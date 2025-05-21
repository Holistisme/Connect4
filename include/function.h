/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 06:36:37 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 15:47:09 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION
#define FUNCTION

/* ************************************************************************** */

#include "lib.h"
#include "type.h"
#include "Game.h"

/* ************************************************************************** */


Game *allocGame(void);
int   allocGrid(Game *game);
void  freeGame (Game *game);

int    atoui     (string ascii);
size_t getLength (const string str);
void   writeError(const string err);

int play(Game *game);

int  initGraphical (Game *game);
int  graphInterface(Game *game);
void closeSDL      (Game *game);
int  termInterface (Game *game);
int  displayGrid   (const Game *game);

int  dropPiece(Game *game, const ssize_t c);
int  humanTurn(Game *game);
bool isDraw   (const Game *game);
bool victory  (const Game *game, const size_t line, const size_t column);

size_t aiThink(Game *game);

/* ************************************************************************** */

#endif