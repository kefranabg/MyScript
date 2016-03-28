/*
** run_script.c for run_script.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Feb 23 12:18:11 2014 abgral_f
** Last update Tue Feb 25 17:51:36 2014 abgral_f
*/

#include		<signal.h>
#include                <sys/ioctl.h>
#include		<stdlib.h>
#include		"my_script.h"

int			run_script(t_script *script)
{
  int			ret;

  if (open_file(script) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (header(script) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  ret = get_commands(script);
  ioctl(0, TCSETS, &script->old_cap);
  if (footer(script) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  close(script->fd_script);
  return (ret);
}
