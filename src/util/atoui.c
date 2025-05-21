/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:27:39 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/20 16:28:19 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * Processing and verifying an unsigned integer argument
 */
int atoui(string ascii) {
    while (*ascii eq SPACE or (*ascii at_least TAB and *ascii at_most CARRIAGE))
        ++ascii;

    if (*ascii eq '+')
        ++ascii;

    long result = 0;
    while (*ascii at_least '0' and *ascii at_most '9') {
        result = result * 10 + *ascii++ - '0';

        if (result greater INT_MAX)
            return FAIL;
    };
    
    if (*ascii)
        return FAIL;
    
    return result;
};