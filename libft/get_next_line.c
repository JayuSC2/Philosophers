/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:29:39 by codespace         #+#    #+#             */
/*   Updated: 2024/04/13 14:23:20 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_join_and_free(char *text, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(text, buffer);
	if (!temp)
		return (free(text), free(buffer), NULL);
	free(text);
	return (temp);
}

char	*read_line(int fd, char *text)
{
	char	*buffer;
	int		bytes_read;

	if (!text)
		text = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(text), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		text = ft_join_and_free(text, buffer);
		if (!text)
			return (NULL);
		if (ft_strchr(text, '\n'))
			break ;
	}
	free (buffer);
	return (text);
}

char	*extract_line(char *text)
{
	int		i;
	char	*output;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] != '\0' && text[i] != '\n')
		i++;
	output = ft_calloc(i + 2, sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	while (text[i] != '\0' && text[i] != '\n')
	{
		output[i] = text[i];
		i++;
	}
	if (text[i] != '\0' && text[i] == '\n')
		output[i++] = '\n';
	return (output);
}

char	*clean_line(char *text)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free (text);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(text) - i + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (text[++i])
		str[j++] = text[i];
	str[j] = '\0';
	free (text);
	return (str);
}

int	get_next_line(int fd, char **line)
{
	static char	*text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	text = read_line(fd, text);
	if (!text)
		return (-1);
	*line = extract_line(text);
	text = clean_line(text);
	return (0);
}

/* int	main(void)
{
	int		file;
	char	*line;

	file = open("basic.ber", O_RDONLY);
	if (file == -1)
	{
		printf("Failed to open file.\n");
		return (1);
	}
	while (get_next_line(file, &line) == 0 && line != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(file);
	return (0);
} */

/* char	*get_next_line(int fd)
{
	char		*output_text;
	static char	*text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = read_line(fd, text);
	if (!text)
		return (NULL);
	output_text = extract_line(text);
	text = clean_line(text);
	return (output_text);
}*/

/* int	main(void)
{
	int	file;
	char *buffer;
	
	buffer = NULL;
	file = open("testtext.txt", O_RDONLY);
	buffer = get_next_line(file);
	if(buffer == NULL)
		return (-1);
	while (buffer != NULL)
	{
		printf("%s", buffer);
		free(buffer);
		buffer = get_next_line(file); 	
	}
	free(buffer);
	close(file);
	return (0);
} */
/* int main()
{
	int fd = open("a.txt", O_RDONLY);
	char *a;

	while ((a = get_next_line(fd)))
	{
		printf("%s", a);
	}

	// printf("%s", get_next_line(fd));

	return 0;
} */
