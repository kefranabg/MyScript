##
## Makefile for Makefile in /home/abgral_f/dev/my_script
## 
## Made by abgral_f
## Login   <abgral_f@epitech.net>
## 
## Started on  Sat Feb 22 23:01:39 2014 abgral_f
## Last update Tue Feb 25 17:12:07 2014 abgral_f
##

CC	= gcc

RM	= rm -f

NAME	= my_script

PATH1	= include/

PATH2	= src/

SRCS	= $(PATH2)main.c				\
	  $(PATH2)my_script.c				\
	  $(PATH2)error.c				\
	  $(PATH2)get_commands.c			\
	  $(PATH2)set_capabilities.c			\
	  $(PATH2)select_fd.c				\
	  $(PATH2)init_select.c				\
	  $(PATH2)run_script.c				\
	  $(PATH2)open_file.c				\
	  $(PATH2)header.c				\
	  $(PATH2)footer.c				\
	  $(PATH2)parsing.c				\
	  $(PATH2)my_forkpty.c				\
	  $(PATH2)my_openpty.c				\
	  $(PATH2)my_login_tty.c			\
	  $(PATH2)my_ptsname.c				\
	  $(PATH2)my_granpt.c				\
	  $(PATH2)my_unlockpt.c				\

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -W -Wall -Werror -Wextra -Wshadow -I$(PATH1)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
