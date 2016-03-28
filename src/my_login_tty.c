/*
** my_login_tty.c for my_login_tty.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Feb 23 17:11:44 2014 abgral_f
** Last update Sun Feb 23 20:33:58 2014 abgral_f
*/

#include		<sys/types.h>
#include		<sys/ioctl.h>
#include		<termios.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		"my_script.h"

int			my_login_tty(int fd)
{
  if (setsid() == -1)
    return (EXIT_FAILURE);
  if (dup2(fd, 0) == -1)
    return (EXIT_FAILURE);
  if (dup2(fd, 1) == -1)
    return (EXIT_FAILURE);
  if (dup2(fd, 2) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
