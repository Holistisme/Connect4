/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 06:32:28 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/21 10:44:37 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO
#define MACRO

/* ************************************************************************** */

#define SPACE    ' '
#define TAB      '\t'
#define CARRIAGE '\r'

#define MAX_LINES   20
#define MIN_LINES   6
#define MAX_COLUMNS 20
#define MIN_COLUMNS 7

#define NEUTRAL '0'
#define HUMAN   '1'
#define AI      '2'

#define RED   "\033[41m  \033[0m"
#define BLUE  "\033[44m  \033[0m"
#define RESET "\033[0m"
#define ERASE "\033[2K\r\033[1A"

#define CHOICE_PROMPT "\nYour column choice: "
#define END_VICTORY   "\n\033[41mCongratulations, you've won!\033[0m\n"
#define END_DEFEAT    "\n\033[44mThe AI has unfortunately defeated you!\033[0m\n"
#define END_DRAW      "\n\033[47mEquality on both sides!\033[0m\n"
#define WELCOME       "Welcome \033[41mhuman\033[0m, you must defeat this stupid \033[44mAI\033[0m!\n\n"

#define CELL_SIZE 100

#define SUCCESS  0
#define FAIL    -1

/* ************************************************************************** */

#endif