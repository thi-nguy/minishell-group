#ifndef GLOBAL_H
# define GLOBAL_H

typedef struct s_excd_sig{
	int		excode;
	int		signal;
}			t_excd_sig;

t_excd_sig	g_excd_sig;
t_env *g_head_env;
#endif