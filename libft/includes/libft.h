/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:29:09 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/12 11:45:47 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

//libft
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_atoi(const char *nptr);
int		ft_isascii(int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_toupper(int c);
void	ft_bzero(void *s, size_t n);
int		ft_isdigit(int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t len);
char	*ft_strrchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isprint(int c);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_isalnum(int c);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isalpha(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list	*lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_printf(const char *s, ...);
int		through_string(char *s, va_list *arguments);
void	check_arguments(const char *arg, va_list *argument, int *len);
void	print_nbr(int arg, int *len);
void	print_hexadecimal(unsigned int arg, int *len, int off);
void	print_void(unsigned long long argument, int *len);
void	print_unsigned(unsigned int arg, int *len);
void	print_c(char argument, int *len);
void	print_str(char *argument, int *len);
void	ft_putchar(char c);

//get_next_line
char	*get_next_line(int fd);
int		is_nl(char *str);
char	*join_str(char *str1, char *str2);

//ft_printf
typedef struct s_prints{
	va_list	args;
	int		hash;
	int		space;
	int		plus;
	int		minus;
	int		zero;
	int		dot;
	int		width;
	int		precision;
	int		ret_value;
	int		pos;
	int		null;
	char	conv;
}	t_prints;

void	print_printer(t_prints *printer);
void	parse_str(const char *str, t_prints *printer);
void	init_printer(t_prints *printer);
void	ft_printf_char(t_prints *printer);
void	ft_printf_str(t_prints *printer);
void	ft_printf_ptr(t_prints *printer);
void	ft_printf_dec(t_prints *printer);
void	ft_printf_uint(t_prints *printer);
void	ft_printf_hex(t_prints *printer);
void	ft_printf_prct(t_prints *printer);
void	print_precision(char *str, t_prints *printer);
void	print_width(t_prints *printer);
void	ft_put_str(char *buffer, t_prints *printer);
void	print_hex_vor(t_prints *printer);
void	swap_buff(char *buffer, int len);
void	parse_nbr(long nbr, char *buffer, t_prints *printer);
void	check_len(char *buffer, t_prints *printer);
void	print_before(t_prints *printer);
#endif
