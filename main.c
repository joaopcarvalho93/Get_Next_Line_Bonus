/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpcarvalho <jpcarvalho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:32:39 by jpcarvalho        #+#    #+#             */
/*   Updated: 2024/02/02 14:53:34 by jpcarvalho       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;
	int		i;

    // Open the test file
    fd = open("file_1.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening test file");
        return (1);
    }

    // Read and print each line until get_next_line returns NULL
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("numero: %d, %s",i, line);
        free(line);
		i++;
    }

    // Close the file
    close(fd);

    return (0);
}