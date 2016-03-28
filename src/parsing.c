/*
** parsing.c for parsing.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Feb 23 15:21:52 2014 abgral_f
** Last update Fri Feb 28 14:15:03 2014 abgral_f
*/

#include		<string.h>
#include		<stdlib.h>
#include		"my_script.h"

int			usage(char *cmd)
{
  write(2, USAGE_ONE, strlen(USAGE_ONE));
  write(2, cmd, strlen(cmd));
  write(2, USAGE_TWO, strlen(USAGE_TWO));
  write(2, USAGE_THREE, strlen(USAGE_THREE));
  write(2, USAGE_FOUR, strlen(USAGE_FOUR));
  write(2, USAGE_FIVE, strlen(USAGE_FIVE));
  return (EXIT_FAILURE);
}

int			opt_c(t_script *script, int *count, char **argv)
{
  if (argv[*count + 1] != NULL)
    {
      script->cmd = argv[*count + 1];
      (*count)++;
    }
  else
    return (usage(argv[*count]));
  script->opt_c = 1;
  return (EXIT_SUCCESS);
}

void			init_opt(t_script *script)
{
  script->opt_a = 0;
  script->opt_q = 0;
  script->opt_c = 0;

}

int			check_opt(t_script *script, int *count, char **argv)
{
  if (strcmp(argv[*count], OPT_A) == 0)
    script->opt_a = 1;
  else if (strcmp(argv[*count], OPT_Q) == 0)
    script->opt_q = 1;
  else if (strcmp(argv[*count], OPT_C) == 0)
    {
      if (opt_c(script, count, argv) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    return (usage(argv[*count]));
  return (EXIT_SUCCESS);
}

int			parsing(t_script *script, char **argv)
{
  int			count;

  init_opt(script);
  script->file_name = NULL;
  count = 1;
  while (argv[count] != NULL)
    {
      if (argv[count][0] == '-')
	{
	  if (check_opt(script, &count, argv) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      else
	{
	  if (script->file_name == NULL)
	    script->file_name = argv[count];
	}
      count++;
    }
  return (EXIT_SUCCESS);
}
