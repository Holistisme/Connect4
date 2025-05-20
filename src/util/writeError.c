/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeError.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:18:19 by aheitz            #+#    #+#             */
/*   Updated: 2025/05/20 09:19:10 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */

/**
 * Write an error code on the stderr output followed by a newline
 */
inline void writeError(string err) {
    if (err) {
        const ssize_t len = getLength(err);
        if (write(STDERR_FILENO, err, len) eq len)
            write(STDERR_FILENO, "\n", 1);
    }
};