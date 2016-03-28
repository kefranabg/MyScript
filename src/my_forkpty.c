/*
** my_forkpty.c for my_forkpty.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Feb 23 16:34:04 2014 abgral_f
** Last update Tue Feb 25 17:16:39 2014 abgral_f
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"my_script.h"

pid_t			my_forkpty(int *amaster)
{
  int			aslave;
  pid_t			pid;

  if (my_openpty(amaster, &aslave) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((pid = fork()) == -1)
    {
      close(*amaster);
      close(aslave);
      return (EXIT_FAILURE);
    }
  if (pid == 0)
    {
      close(*amaster);
      if (my_login_tty(aslave) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    {
      close(aslave);
      return (pid);
    }
  return (EXIT_SUCCESS);
}
