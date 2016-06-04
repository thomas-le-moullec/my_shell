/*
** define.h for define in /home/le-mou_t/rendu/PSU_2015_42sh/include
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat Jun  4 17:17:27 2016 Thomas LE MOULLEC
** Last update Sat Jun  4 20:36:13 2016 Thomas LE MOULLEC
*/

#ifndef DEFINE_H_
# define DEFINE_H_

#ifndef READ_SIZE
# define READ_SIZE (4096)
#endif

# define STOP           -2
# define ERROR          -1
# define SUCCESS        0

# define ALONE          0
# define BEGIN          1
# define MIDDLE         2
# define END            3

# define DEFAUT         0
# define AND            1
# define OR             2

# define LCTRL          12
# define DCTRL          4
# define ACTRL          1
# define ECTRL          5
# define UCTRL          21

# define NB_SIGNALS     5

# define BUILT_WHI      ": shell built-in command.\n"
# define BUILT_WHE      " is a shell built-in\n"
# define EXIT_FAIL      "exit: Expression Syntax.\n"
# define NO_MATCH       ": No match.\n"
# define SHOW_ALIAS     "alias "
# define EXIT_THIS      "exit\n"
# define INTRO_RE	"There are "
# define LIST_ROW	" rows, list them anyway? [n/y] "
# define ERROR_ALIAS    "Invalid alias name.\n"
# define NULL_CMD       "Invalid null command.\n"
# define ERROR_UNALIAS  "unalias: Too few arguments.\n"
# define AMBI_INPUT     "Ambiguous input redirect.\n"
# define AMBI_OUTPUT    "Ambiguous output redirect.\n"
# define ER_UNSETENV    "unsetenv: Too few arguments.\n"
# define ER_SETENV      "setenv: Too many arguments.\n"
# define ERR_SET        "unset: Too few arguments.\n"
# define NOT_FOUND      ": Command not found.\n"
# define NOT_DIR        ": Not a directory.\n"
# define PERM_DENIED    ": Permission denied.\n"
# define IS_DIR         ": Is a directory.\n"
# define FOUND_DIR      ": No such file or directory.\n"
# define FOUND_ENV      ": No such file or directory\n"
# define MISSING_NAME   "Missing name for redirect.\n"
# define EVENT          ": Event not found.\n"
# define MAGIC_ERROR    "Unmatched `.\n"
# define EXEC_ERROR     ": Exec format error. Binary file not executable.\n"
# define REPEAT_FEW     "repeat: Too few arguments.\n"
# define UNDEF_VAR      ": Undefined variable.\n"
# define SET_LETTER     "setenv: Variable name must begin with a letter.\n"
# define SET_ALPHA      "setenv: Variable name must contain alphanumeric " \
  "characters.\n"
# define BAD_FORM       "repeat: Badly formed number.\n"
# define ERR_WHERE      "where: Too few arguments.\n"
# define ERR_WHICH      "which: Too few arguments.\n"
# define ERR_QUOTE      "Unmatched "
# define ERR_GLOB	"Error Global.\n"
# define IEOF           "Use \"exit\" to leave 42sh.\n"

# define SIG_SIGABRT    "Aborted\n"
# define SIG_SIGFPE     "Floating exception\n"
# define SIG_SIGQUIT    "Quit\n"
# define SIG_SIGSEGV    "Segmentation fault\n"
# define SIG_SIGILL     "Illegal Instruction\n"
# define SIG_USR1       "User defined signal 1\n"
# define SIG_USR2       "User defined signal 2\n"

# define ERR_SIGINT     "ERROR SIGINT\n"
# define ERR_SIGTERM    "ERROR SIGTERM\n"
# define ERR_SIGSEGV    "ERROR SIGSEGV\n"
# define ERR_SIGQUIT    "ERROR SIGQUIT\n"
# define ERR_SIGUSR1    "ERROR SIGUSR1\n"
# define ERR_SIGUSR2    "ERROR SIGUSR2\n"
# define ERR_SIGTSTP    "ERROR SIGTSTP\n"

#endif
