/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 06:28:27 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 15:50:03 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR
#define ERROR

/* ************************************************************************** */

#define ERR_ARGV "Game board sizes are not unsigned integers"
#define ERR_ARGC "Game should be executed as ./connect4 <lines> <columns> (-g)"

#define ERR_LINES_MIN   "Number of lines too few (<6)"
#define ERR_LINES_MAX   "Number of lines too high (>20)"
#define ERR_COLUMNS_MIN "Number of columns too few (<7)"
#define ERR_COLUMNS_MAX "Number of columns too high (>20)"

#define ERR_ALLOC_GAME "malloc() failed on game allocation"
#define ERR_ALLOC_GRID "malloc() failed on grid allocation"
#define ERR_ALLOC_LINE "malloc() failed on a line allocation"
#define ERR_AI_REASON  "malloc() failed for ai reasons"

#define ERR_WRITE_CLEAN  "write() failed when terminal cleaning"
#define ERR_WRITE_LINE   "write() failed when printing grid"
#define ERR_WRITE_PROMPT "write() failed on prompt invite"

#define ERR_INVALID_POS "\nNo tokens may be dropped from this column"

#define ERR_READ       "Unable to read user entry"
#define ERR_ERASE_READ "Unable to erase user entry"

#define ERR_AI_DROP "AI tries to make dubious drops"

#define ERR_SDL_INIT     "Unable to initialize SDL for video display"
#define ERR_SDL_WINDOW   "Unable to initialize SDL window"
#define ERR_SDL_RENDERER "Unable to initialize SDL renderer"
#define ERR_SDL_COLOR    "SDL_SetRenderDrawColor() failed"
#define ERR_SDL_CLEAR    "SDL_RenderClear() failed"
#define ERR_SDL_FILL     "SDL_RenderFillRect() failed"

/* ************************************************************************** */

#endif