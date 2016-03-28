/*
** set_capabilities.c for set_capabilities.c in /home/abgral_f/dev/my_script/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Feb 23 00:03:50 2014 abgral_f
** Last update Mon Feb 24 13:36:43 2014 abgral_f
*/

#include		<sys/ioctl.h>
#include		<stdlib.h>
#include		"my_script.h"

int   			set_capabilities(t_script *script)
{
  struct termios	cap;

  if (ioctl(0, TCGETS, &cap) == -1)
    return (error(IOCTL_ERR, script));
  script->old_cap = cap;
  cap.c_lflag &= ~(ICANON | ECHO | ISIG);
  if (ioctl(0, TCSETS, &cap) == -1)
    return (error(IOCTL_ERR, script));
  script->set = 1;
  return (EXIT_SUCCESS);
}
