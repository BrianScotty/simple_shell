#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

/* MACROS */
#define prompt "$ "

/* PROTOTYPES */
int main(void);
char **tokenize_input(char *buff);
int exe_input(char **argv);
void interactive(void);
void non_interactive(void);
char *get_input(void);
char *read_stream(void);
int execute_cmd(char **args, int cmd_num);
char *get_line(void);
char *get_path(char *arg);
void print_err(int cmd_no, char *prog_name);
int print_num(unsigned int n);

/* BUILT-IN FUNCSTIONS */
int func_cd(char **argv);
int func_exit(char **argv);
int func_env(char **argv);

/* STRING MANUPULATION */
char *str_cat(char *dest, char *src);
char *str_cpy(char *dest, char *src);
char *str_dup(char *s);
int str_len(char *str);
int str_cmp(char *s1, char *s2);
int _putstr(char *str, int fd);
int _putchar(char z);

extern char **environ;
extern char *prog_name;
extern int cmd_num;


#endif
