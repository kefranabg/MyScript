/*
** init_select.c for init_select.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Feb 23 12:09:52 2014 abgral_f
** Last update Sun Feb 23 12:13:47 2014 abgral_f
*/

#include		<stdlib.h>
#include		"my_script.h"

int			init_select(t_script *script, fd_set *readfds)
{
  FD_ZERO(readfds);
  FD_SET(script->master, readfds);
  FD_SET(0, readfds);
  if (select(script->master + 1, readfds, NULL, NULL, NULL) == -1)
    return (error(SELECT_ERR, script));
  return (EXIT_SUCCESS);
}
