/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 11:16:46 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/03 09:41:53 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

# define INT_MAX 2147483647
# define INT_MIN -2147483648

/**
 * @brief Read the text available on the file descriptor one line at a time
 * until the end of it.
 *
 * @param fd File descriptor to read from.
 * @return char* A line read from a file descriptor. NULL if error or not else
 * to read.
 */
char	*get_next_line(int fd);

/**
 * @brief Checks if c is alphabetic
 *
 * @param c Character to be analysed
 * @return int 1 if is true, 0 if false
 */
int		ft_isalpha(int c);

/**
 * @brief Checks if c is a number
 *
 * @param c Character to be verified
 * @return int 1 if is true, 0 if false
 */
int		ft_isdigit(int c);

/**
 * @brief Checks if c is an alphanumeric character
 *
 * @param c Character to be verified
 * @return int 1 if is true, 0 if false
 */
int		ft_isalnum(int c);

/**
 * @brief Checks if c is an unsigned char value from ASCII character set
 *
 * @param c Character to be verified
 * @return int 1 if is true, 0 if false
 */
int		ft_isascii(int c);

/**
 * @brief Checks if c is a printable character, including space
 *
 * @param c character to be verified
 * @return int 1 if is true, 0 if false
 */
int		ft_isprint(int c);

/**
 * @brief Calculates the length of the string
 * pointed to by str, excluding the terminating null byte
 *
 * @param str Pointer to the initial area of the string
 * @return size_t The number of bytes in the
 * string pointed to by str
 */
size_t	ft_strlen(const char *str);

/**
 * @brief Fills the first n bytes of the memory area pointed by dest with the
 * constant byte c
 * @param dest Pointer of memory area
 * @param c Constant byte to fill the memory area
 * @param size Number of bytes to fill
 * @return void* A pointer to the memory area
 */
void	*ft_memset(void *dest, int c, size_t size);

/**
 * @brief Erases the data in the n bytes of the memory starting at the location
 * pointed to by src, by writing 0 to that area
 * @param src Pointer to the start of memory location
 * @param n Buffer size
 */
void	ft_bzero(void *src, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest. Not treating
 * overlapping memory case
 * @param dest Destination pointer of memory area
 * @param src Source pointer of memory area
 * @param n Buffer size in bytes
 * @return void* A pointer to the start of dest memory area
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest. Treating
 * overlapping memory case
 * @param dest Destination pointer of memory area
 * @param src Source pointer of memory area
 * @param n Buffer size in bytes
 * @return void* A pointer to the start of dest memory area
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief copies up to (size - 1) characters from the NUL-terminated string src
 * to dst, NUL-terminat‐ing the result
 *
 * @param dest Pointer to the destination area of memory
 * @param src  Pointer to the source area of memory
 * @param size BUffer size in bytes
 * @return size_t The length of src
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief Converts uppercase character to lowercase
 * @param c Character to be converted
 * @return int The converted character if uppercase, or c if lowercase
 */
int		ft_tolower(int c);

/**
 * @brief Converts lowercase character to uppercase
 * @param c Character to be converted
 * @return int The converted character if lowercase, or c if uppercase
 */
int		ft_toupper(int c);

/**
 * @brief Appens the NUL-terminates string src to the end of dest. It will
 * append most (size - strlen(dst) - 1) bytes, NUL-terminating the result
 * @param dest Pointer to the destination area of memory
 * @param src  Pointer to the source area of memory
 * @param size BUffer size in bytes
 * @return size_t The total length of initial dest + initial src
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size);

/**
 * @brief Finds the first occurrence of the character c in the string str
 * @param str Pointer to the string memory area
 * @param c Character to be searched inside the string s
 * @return char* A pointer to the matched character
 * or NULL if the character is not found
 */
char	*ft_strchr( const char *str, int c );

/**
 * @brief Finds the last occurrence of the character c in the string str
 * @param str Pointer to the string memory area
 * @param c Character to be searched inside the string s
 * @return char* A pointer to the matched character
 * or NULL if the character is not found
 */
char	*ft_strrchr(const char *str, int c);

/**
 * @brief Compares the two strings s1 and s2
 *
 * @param s1 Pointer to the area of memory of the first string
 * @param s2 Pointer to the area of memory of the second string
 * @param n Buffer size in bytes to compare both strings
 * @return int 0, if the s1 and s2 are equal;
 * A negative value if s1 < s2; A positive value if s1 > s2
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Scans the initial n bytes of the memory area
 * pointed to by ptr for the first instance of c
 *
 * @param ptr Pointer to the initial memory area
 * @param c Character to be searched
 * @param n Buffer size in bytes
 * @return A pointer str to the matching byte or NULL if it does not occur
 */
void	*ft_memchr(const void *ptr, int c, size_t n);

/**
 * @brief Compares the first n bytes (each interpreted as unsigned char) of the
 * memory areas s1 and s2
 * @param s1 Pointer to the first memory area to be compared
 * @param s2 Pointer to the second memory area to be compared
 * @param n Buffer size in bytes
 * @return int 0, if the s1 and s2 are equal or if n value is 0
 * A negative value if s1 < s2
 * A positive value if s1 > s2

 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Locates the first occurrence of the null-terminated
 * string little in the string big, where not more than `n` characters
 * are checked. Characters that appear after a `\\0` character are not
 * checked
 *
 * @param big String to be searched by `little`
 * @param little String to search in `big`
 * @param n Number of bytes to search
 * @return char* If little is an empty string, big is returned
 * If little occurs nowhere in big, NULL is returned
 * Otherwise a pointer to the first character of the first occurrence
 * of little is returned
 */
char	*ft_strnstr(const char *big, const char *little, size_t n);

/**
 * @brief Converts the initial portion of the string pointed
 * by str to int
 *
 * @param str Pointer to the string to be converted
 * @return int The converted value or 0 on error
 */
int		ft_atoi(const char *str);

/**
 * @brief Allocates memory for an array
 * of nmemb elements of size bytes each and set them to zero.
 *
 * @param nmemb Number of elements in array
 * @param size Size of bytes for each element
 * @return void* A pointer to the
 * allocated memory, which is suitably aligned for any built-in
 * type. Return NULL on allocation error or with size 0.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Duplicates the string pointed by s in a new string
 *
 * @param s Pointer to the start of the string to be copied
 * @return char* A pointer to the duplicated string.
 * It returns NULL if insufficient memory was available
 */
char	*ft_strdup(const char *s);

/**
 * @brief Allocates a substring from the string ’s’.
 * The substring begins at index ’start’ and is of maximum size ’len’.
 *
 * @param s		The string from which to create the substring.
 * @param start	The start index of the substring in the string’s’.
 * @param len	The maximum length of the substring.
 * @return char* The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates a newstring, which is the result of the concatenation of
 * ’s1’ and ’s2’.
 *
 * @param s1 The prefix string
 * @param s2 The suffix string
 * @return char* The new string or NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates (with malloc(3)) and returns
 * a copy of ’s1’ with the characters specified
 * in ’set’ removed from the beginning and the
 * end of the string.
 *
 * @param s1 The string to be trimmed
 * @param set The set of characters to trim
 * @return char* Returns the trimmed string,
 * or NULL if allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates (with malloc) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter. The array must be
 * ended by a NULL pointer.
 *
 * @param s The string to be split
 * @param c The delimiter character
 * @return char** The array of new strings resulting from the split.
 * NULL if allocation fails.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Allocates (with malloc()) a string representing the integer
 * received as an argument. Negative numbers must be handled.
 *
 * @param n The integer to convert
 * @return char* Returns the string representing the integer.
 * NULL if the allocation fails.
 */
char	*ft_itoa(int n);

/**
 * @brief Applies the function ’f’ to each character of the string ’s’
 * to create a new string (with malloc) resulting from successive
 * applications of ’f’.
 *
 * @param s The string on which to iterate
 * @param f The function to apply to each character
 * @return char* The string created from the successive applications of ’f’.
 * Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function f to each character of the string passes as
 * argument, and passing its index as first argument. Each character is passed
 * by address to f to be modified if necessary.
 *
 * @param s The string on which to interate
 * @param f The function to apply to each character
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Outputs the character ’c’ to the given filedescriptor.
 *
 * @param c The character to output
 * @param fd The file descriptor on which to write
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string ’s’ to the given file descriptor.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string ’s’ to the given file descriptor,
 * followed by a newline.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer ’n’ to the given file descriptor.
 *
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief Allocates and returns a new element of t_list with the value of
 * CONTENT. Variable NEXT is initialized to NULL.
 *
 * @param content The string to be created to the new t_list.
 * @return The address of the new t_list element.
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Add a new element to the start of the linked list appointed by lst.
 *
 * @param lst List of address of t_lists.
 * @param new Element to be add to the start of the LST.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Find the length of the linked list appointed by LST
 *
 * @param lst Linked list to be count.
 * @return Length of LST
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Find the last element of the linked list.
 *
 * @param lst Address of a linked list.
 * @return The address of the linked list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Add a new element to the linked list in the end.
 *
 * @param lst Appointed a linked list.
 * @param new The new element to be added.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Aplies the function DEL to the LST content and them free the LST.
 *
 * @param lst Linked element to be deleted and free.
 * @param del Function to delete the element.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Applies the del function to the all elements of the linked list and
 * the free all
 *
 * @param lst list be clear and deleted.
 * @param del Functions to delete the elements.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ to the content
 * of each element.
 *
 * @param lst The address of a pointer to an element.
 * @param f The address of the function used to iterate on the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ to the content
 * of each element. Creates a new list resulting of the successive applications
 * of the function ’f’.
 *
 * @param lst The address of a pointer to an element.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of an
 * element if needed.
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Convert string to lowercase.
 *
 * @param str String to be converted.
 * @return The new string.
 */
char	*ft_strlower(char *str);

/**
 * @brief Compares the two strings s1 and s2
 *
 * @param s1 Pointer to the area of memory of the first string
 * @param s2 Pointer to the area of memory of the second string
 * @return int 0, if the s1 and s2 are equal;
 * A negative value if s1 < s2; A positive value if s1 > s2
 */
int		ft_strcmp(const char *s1, const char *s2);

/**
 * @brief Compares two numbers and returns the highest one.
 *
 * @param a Number to be compare.
 * @param b Number to be compare.
 * @return The highest number.
 */
int		ft_max(int a, int b);

/**
 * @brief Compares two numbers and returns the lowest one.
 *
 * @param a Number to be compare.
 * @param b Number to be compare.
 * @return The lowest number.
 */
int		ft_min(int a, int b);

/**
 * @brief Converts the number for its absolute value.
 *
 * @param num Number to be converted.
 * @return The absolute value of num.
 */
int		ft_absolute(int num);

/**
 * @brief Verify if the value is a white-space
 *
 * @param num char to be verified..
 * @return 1 if true, 0 if false.
 */
int		ft_isspace(char c);

/**
 * @brief Converts the initial portion of the string pointed
 * by str to double
 *
 * @param str Pointer to the string to be converted
 * @return double The converted value or 0 on error
 */
double	ft_atof(const char *str);

#endif
