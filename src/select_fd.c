/*
** select_fd.c for select_fd.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Feb 23 12:01:36 2014 abgral_f
** Last update Tue Apr  8 18:38:28 2014 abgral_f
*/

#include		<stdlib.h>
#include		"my_script.h"

int			fd_select(t_script *script, fd_set *readfds)
{
  char                  buffer[SIZE_BUFF];
  int                   ret;

  if (FD_ISSET(0, readfds))
    {
      if ((ret = read(0, buffer, SIZE_BUFF)) == -1)
	return (EXIT_FAILURE);
      else
	write(script->master, buffer, SIZE_BUFF);
    }
  if (FD_ISSET(script->master, readfds))
    {
      if ((ret = read(script->master, buffer, SIZE_BUFF)) == -1)
	return (EXIT_FAILURE);
      else
	{
	  write(1, buffer, SIZE_BUFF);
	  write(script->fd_script, buffer, SIZE_BUFF);
	}
    }
  return (EXIT_SUCCESS);
}
