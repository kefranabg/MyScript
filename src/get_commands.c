/*
** get_commands.c for get_commands.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Feb 22 23:58:30 2014 abgral_f
** Last update Wed Apr  9 14:22:21 2014 abgral_f
*/

#include	        <sys/ioctl.h>
#include		<stdlib.h>
#include		"my_script.h"

int			get_commands(t_script *script)
{
  fd_set		readfds;

  if (set_capabilities(script) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while (42)
    {
      if (init_select(script, &readfds) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      else
	{
	  if (fd_select(script, &readfds) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  }
    }
  return (EXIT_SUCCESS);
}
