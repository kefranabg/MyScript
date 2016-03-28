/*
** my_openpty.c for my_openpty.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Feb 23 17:09:45 2014 abgral_f
** Last update Sun Feb 23 18:42:12 2014 abgral_f
*/

#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<stdlib.h>
#include		"my_script.h"

int			my_openpty(int *amaster, int *aslave)
{
  char			*path;

  if ((*amaster = open(PATH, O_RDWR)) == -1)
    return (EXIT_FAILURE);
  if ((path = my_ptsname(*amaster)) == NULL)
    return (EXIT_FAILURE);
  if (my_granpt(*amaster) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (my_unlockpt(*amaster) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((*aslave = open(path, O_RDWR)) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
