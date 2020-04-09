# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 16:47:32 by mabriand          #+#    #+#              #
#    Updated: 2020/03/02 19:39:04 by mabriand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	 libft.a

SRCS = 	ft_memset.c	 \
		ft_bzero.c	 \
		ft_memcpy.c	 \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c	 \
		ft_memcmp.c	 \
		ft_strlen.c	 \
		ft_intlen.c \
		ft_uintlen.c \
		ft_hexintlen.c \
		ft_long_hexintlen.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c	 \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_atoi.c	 \
		ft_calloc.c	 \
		ft_strdup.c	 \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putstr. \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_substr.c \
		ft_itoa.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_strjoin.c \
		ft_split.c \

SRCSBO	=	ft_lstnew.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

OBJS	= ${SRCS:.c=.o}

OBJSBO	= ${SRCSBO:.c=.o}

CC	= gcc

CFLAGS 	= -Wall -Wextra -Werror

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -I -c $< -o $(<:.c=.o)

$(NAME):	${OBJS}
	ar	rc ${NAME} ${OBJS}

bonus: ${OBJS} ${OBJSBO}
	ar	rc ${NAME} ${OBJS} ${OBJSBO}

clean:
	rm -f ${OBJS} ${OBJSBO}

fclean:	clean
	rm -f ${NAME}

re:		fclean all

.PHONY:		all clean fclean
