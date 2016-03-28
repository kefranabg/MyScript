/*
** my_script.c for my_script.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Feb 22 23:13:59 2014 abgral_f
** Last update Tue Apr  8 15:41:27 2014 abgral_f
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"my_script.h"

int			my_script(char **argv)
{
  t_script		script;
  pid_t			pid;
  char			*shell_name;

  if (parsing(&script, argv) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((shell_name = getenv(SHELL_ENV)) == NULL)
    shell_name = BOURNE_SHELL;
  pid = my_forkpty(&script.master);
  if (pid == -1)
    return (error(FORKPTY_ERR, &script));
  if (pid == 0)
    {
      if (script.opt_c == 0)
	execl(shell_name, shell_name, NULL);
      else
	execl(shell_name, shell_name, "-c", script.cmd, NULL);
    }
  else
    return (run_script(&script));
  return (EXIT_SUCCESS);
}
