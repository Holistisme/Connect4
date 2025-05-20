/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 06:36:37 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/20 10:09:55 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION
#define FUNCTION

/* ************************************************************************** */

#include "lib.h"
#include "type.h"
#include "Game.h"

/* ************************************************************************** */

size_t getLength (string str);
void   writeError(string err);

void displayGrid(const Game *game);

Game *allocGame(void);
int   allocGrid(Game *game);
void  freeGame (Game *game);

/* ************************************************************************** */

#endif