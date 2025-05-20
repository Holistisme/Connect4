/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 06:28:27 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/20 07:16:07 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR
#define ERROR

/* ************************************************************************** */

#define ERR_ARGV "Game board sizes are not unsigned integers"
#define ERR_ARGC "Game should be executed as ./connect4 <lines> <columns>"

#define ERR_LINES_MIN   "Number of lines too few (<6)"
#define ERR_LINES_MAX   "Number of lines too high (>20)"
#define ERR_COLUMNS_MIN "Number of columns too few (<7)"
#define ERR_COLUMNS_MAX "Number of columns too high (>20)"

#define ERR_ALLOC_GAME "malloc() failed on game allocation"
#define ERR_ALLOC_GRID "malloc() failed on grid allocation"
#define ERR_ALLOC_LINE "malloc() failed on a line allocation"

/* ************************************************************************** */

#endif