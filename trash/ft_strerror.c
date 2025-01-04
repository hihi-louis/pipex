/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:36:40 by tripham           #+#    #+#             */
/*   Updated: 2025/01/02 16:15:47 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
const char *ft_strerror(int errnum)
{
	static const char *error_message[] = {
        "No error",
        "Operation not permitted",
        "No such file or directory",
        "No such process",
        "Interrupted system call",
        "Input/output error",
        "No such device or address",
        "Argument list too long",
        "Exec format error",
        "Bad file descriptor",
        "No child processes",
        "Resource temporarily unavailable",
        "Out of memory",
        "Permission denied",
        "Bad address"
    };

	static const int max_errnum = sizeof(error_message) / sizeof(error_message[0]) -1;

	if (errnum >= 0 && errnum <= max_errnum && error_message[errnum] != NULL)
		return (error_message[errnum]);
	return ("Unknown error");
}

// int main() {
//     printf("Error 2: %s\n", ft_strerror(2));  // Output: No such file or directory
//     printf("Error 13: %s\n", ft_strerror(13)); // Output: Permission denied
//     printf("Error 99: %s\n", ft_strerror(99)); // Output: Unknown error
//     return 0;
// }