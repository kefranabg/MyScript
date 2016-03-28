/*
** my_ptsname.c for my_ptsname.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Feb 23 17:12:50 2014 abgral_f
** Last update Mon Feb 24 13:32:01 2014 abgral_f
*/

#include		<stdio.h>
#include		<sys/ioctl.h>
#include		<stdlib.h>
#include		"my_script.h"

char			*my_ptsname(int fd)
{
  static char		name[516];
  int			op;

  if (ioctl(fd, TIOCGPTN, &op) == -1)
    return (NULL);
  if (sprintf(name, "/dev/pts/%i", op) < 0)
    return (NULL);
  return (name);
}
