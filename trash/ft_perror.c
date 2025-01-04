/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:12:22 by tripham           #+#    #+#             */
/*   Updated: 2025/01/02 19:37:40 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "mylib/includes/libft.h"
#include <errno.h>
#include <fcntl.h> 

void ft_perror(int fd, const char *message)
{
	if (message && *message)
		ft_printf_fd(fd, "%s : %s\n", message, ft_strerror(errno));
	else
		ft_printf_fd(fd, "%s\n", ft_strerror(errno));
}

// int main(void)
// {
//     int fd;

//     // Example 1: Trying to open a non-existent file
//     fd = open("nonexistent.txt", O_RDONLY);
//     if (fd == -1) {
//         ft_perror(2, "Error opening file"); // Write error message to stderr
//     }

//     // Example 2: Trying to close an invalid file descriptor
//     if (close(-1) == -1) {
//         ft_perror(2, "Error closing file descriptor"); // Write error message to stderr
//     }

//     // Example 3: Open an existing file successfully
//     fd = open("haha.txt", O_CREAT | O_WRONLY, 0644);
//     if (fd == -1) {
//         ft_perror(2, "Error opening example.txt");
//     } else {
//         write(fd, "Hello, world!\n", 14); // Write to the file
//         if (close(fd) == -1) {
//             ft_perror(2, "Error closing example.txt");
//         }
//     }

//     return 0;
// }