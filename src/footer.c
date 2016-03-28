/*
** footer.c for footer.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Feb 23 13:51:42 2014 abgral_f
** Last update Thu Feb 27 17:28:05 2014 abgral_f
*/

#include                <stdio.h>
#include                <time.h>
#include                <string.h>
#include                <unistd.h>
#include		<stdlib.h>
#include		"my_script.h"

int			footer(t_script *script)
{
  char                  date[SIZE_DATE];
  time_t                timestamp;

  if ((timestamp = time(NULL)) == -1)
    return (error(TIME_ERR, script));
  strftime(date, sizeof(date), FORMAT, localtime(&timestamp));
  if (script->opt_q == 0)
    {
      write(1, SCRIPT_DONE, strlen(SCRIPT_DONE));
      write(1, script->file_name, strlen(script->file_name));
      write(1, "\n", 1);
    }
  write(script->fd_script, "\n", 1);
  write(script->fd_script, SCRIPT_DONE_FD, strlen(SCRIPT_DONE_FD));
  write(script->fd_script, date, strlen(date));
  write(script->fd_script, "\n", 1);
  return (EXIT_SUCCESS);
}
