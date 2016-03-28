/*
** open_file.c for open_file.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Feb 23 12:22:48 2014 abgral_f
** Last update Tue Feb 25 17:18:48 2014 abgral_f
*/

#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<stdlib.h>
#include		"my_script.h"

int			open_file(t_script *script)
{
  if (script->file_name == NULL)
    script->file_name = SCRIPT_NAME;
  if (access(script->file_name, F_OK) == 0)
    {
      if (access(script->file_name, W_OK) == -1)
	return (error(ACCESS_ERR, script));
    }
  if (script->opt_a == 0)
    {
      if ((script->fd_script = open(script->file_name,
				    FLAG_O_OPEN, FLAG_S_OPEN)) == -1)
	return (error(OPEN_ERR, script));
    }
  else
    {
      if ((script->fd_script = open(script->file_name,
				    FLAG_OPT_A, FLAG_S_OPEN)) == -1)
	return (error(OPEN_ERR, script));
    }
  return (EXIT_SUCCESS);
}
