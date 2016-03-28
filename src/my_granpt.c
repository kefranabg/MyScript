/*
** my_granpt.c for my_granpt.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Feb 23 17:14:52 2014 abgral_f
** Last update Tue Feb 25 17:21:01 2014 abgral_f
*/

#include		<sys/stat.h>
#include		<stdlib.h>
#include		"my_script.h"

int			my_granpt(int fd)
{
  if (chmod(my_ptsname(fd), S_IRUSR | S_IWUSR | S_IWGRP) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
