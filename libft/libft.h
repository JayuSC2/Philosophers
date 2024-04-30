/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:57:28 by juitz             #+#    #+#             */
/*   Updated: 2024/04/10 15:54:06 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 1337

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
int		ft_printf(const char *str, ...);
int		ft_isnumber(char *str);
int		ft_isalnum(int input);
int		ft_isascii(int input);
int		ft_isalpha(int input);
int		ft_isdigit(int input);
int		ft_isprint(int input);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memset(void *s, int x, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	**ft_strarraydup(char **strarray);
void	ft_free(char **strarray);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
char	*ft_itoa(int len);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
int		get_next_line(int fd, char **line);
//char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_join_and_free(char *text, char *buffer);
char	*ft_strchr(const char *s, int c);
char	*read_line(int fd, char *text);
char	*extract_line(char *text);
char	*clean_line(char *text);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_join_and_free(char *text, char *buffer);
int		ft_printf(const char *str, ...);
int		ft_printnbr(int n);
int		ft_printchar(int c);
int		ft_printstr(char *s);
int		ft_print_hex_lc(unsigned int num);
int		ft_print_hex_uc(unsigned int num);
int		ft_print_unsigned(unsigned int n);
int		ft_print_pointer(unsigned long long ptr);

#endif
