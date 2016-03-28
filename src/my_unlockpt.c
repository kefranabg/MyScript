/*
** my_unlockpt.c for my_unlockpt.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Feb 23 17:15:38 2014 abgral_f
** Last update Sun Mar  2 12:15:22 2014 abgral_f
*/


#include		<termios.h>
#include		<sys/ioctl.h>
#include		<stdlib.h>
#include		"my_script.h"

int			my_unlockpt(int fd)
{
  int			op;

  op = 0;
  if (ioctl(fd, TIOCSPTLCK, &op) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
