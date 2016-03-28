/*
** my_script.h for my_script.h in /home/abgral_f/dev/my_script/include
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Feb 22 23:06:35 2014 abgral_f
** Last update Thu Feb 27 17:52:33 2014 abgral_f
*/

#ifndef			MY_SCRIPT_H_
# define		MY_SCRIPT_H_

/* Includes */

#include                <unistd.h>
#include		<termios.h>

/* Defines */

#define	BOURNE_SHELL	"/bin/sh"

#define	PATH		"/dev/ptmx"

#define	SHELL_ENV	"SHELL"
#define	SCRIPT_NAME	"typescript"
#define SCRIPT_START_FD	"Script started on "
#define	SCRIPT_START	"Script started, file is "
#define SCRIPT_DONE_FD	"Script done on "
#define	SCRIPT_DONE	"Script done, file is "

#define	OPT_A		"-a"
#define	OPT_Q		"-q"
#define	OPT_C		"-c"

#define FORMAT		"%a %d %b %Y %I:%M:%S %p %Z"

#define	SIZE_BUFF	1
#define SIZE_DATE	512

/* Flags */

#define FLAG_O_OPEN	O_WRONLY | O_CREAT | O_TRUNC
#define FLAG_S_OPEN	S_IWUSR | S_IRUSR | S_IROTH | S_IRGRP
#define FLAG_OPT_A	O_WRONLY | O_CREAT | O_APPEND

/* Error */

#define USAGE_ONE	"script: invalid option '"
#define USAGE_TWO	"'\n\nUsage:\n script [options] [file]\n\n"
#define USAGE_THREE	"Options:\n\t-a, --append\tappend the output\n"
#define USAGE_FOUR	"\t-q, --quiet\tbe quiett\n"
#define USAGE_FIVE	"\t-c, --command <command>\tbe quiett\n"

#define FORKPTY_ERR	"script: Error on my_forkpty.\n"
#define	SHELL_NAME_ERR	"script: Shell name not found on the environnement.\n"
#define IOCTL_ERR	"script: Error on ioctl.\n"
#define	SELECT_ERR	"script: Error on select.\n"
#define	READ_ERR	"script: Error on read.\n"
#define	OPEN_ERR	"script: Error on open.\n"
#define	ACCESS_ERR	"script: Open failed: Permission denied.\n"
#define TIME_ERR	"script: Error on time.\n"

/* Structures */

typedef	struct		s_struct
{
  int			opt_a;
  int			opt_q;
  int			opt_c;
  char			*cmd;
  int			fd_script;
  int			master;
  char			*file_name;
  int			set;
  struct termios	old_cap;
}			t_script;

/* Functions */

int                     error(const char *, t_script *);
int			my_script(char **);
int			get_commands(t_script *);
int			set_capabilities(t_script *);
int			fd_select(t_script *, fd_set *);
int			init_select(t_script *, fd_set *);
int			run_script(t_script *);
int			open_file(t_script *);
int			header(t_script *);
int			footer(t_script *);
int			parsing(t_script *, char **);

/* Pseudo Terminals */

pid_t			my_forkpty(int *);
int			my_openpty(int *, int *);
int			my_login_tty(int);
int			my_granpt(int);
int			my_unlockpt(int);
char			*my_ptsname(int);


#endif /* MY_SCRIPT */
