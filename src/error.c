/*
** error.c for error.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Feb 22 23:26:24 2014 abgral_f
** Last update Sun Feb 23 16:07:29 2014 abgral_f
*/

#include		<sys/ioctl.h>
#include		<string.h>
#include		<stdlib.h>
#include		<stdio.h>
#include		"my_script.h"

int			error(const char *message, t_script *script)
{
  if (script->set == 1)
    ioctl(0, TCSETS, &script->old_cap);
  write(2, message, strlen(message));
  return (EXIT_FAILURE);
}
