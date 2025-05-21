/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 06:36:37 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 06:13:31 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION
#define FUNCTION

/* ************************************************************************** */

#include "lib.h"
#include "type.h"
#include "Game.h"

/* ************************************************************************** */

int  play(Game *game);
bool victory(const Game *game, const size_t line, const size_t column);
int  displayGrid(const Game *game);

Game *allocGame(void);
int   allocGrid(Game *game);
void  freeGame (Game *game);

int    atoui(string ascii);
size_t getLength(const string str);
void   writeError(const string err);

/* ************************************************************************** */

#endif