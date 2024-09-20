#ifndef RUSH02_H
# define RUSH02_H

//# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

# define HASH_SIZE 1048583
# define MAX_VALUE_SIZE 1024
# define DICT_CANT_OPEN_ERROR "Dict Error : Cannot open dict file\n"
# define DICT_CANT_PARSE_ERROR "Dict Error : Cannot parsing dict file\n"
# define ARG_LEN_ERROR "Dict Error : Too long number\n"
# define ARG_NUM_S_ERROR "Arg Error : Not enough arguments\n"
# define ARG_NUM_L_ERROR "Arg Error : Too Many arguments\n"
# define ARG_FORM_ERROR "Arg Error : Wrong arugument form\n"

typedef struct	s_node
{
	int		address;
	char* key;
	char* value;
}				t_node;

typedef	struct	s_hashtable
{
	t_node* node;
	int		hashsize;
}				t_hashtable;

t_hashtable* g_dict;

int				g_nbr_sep_size;
int				g_flag;

int				ft_getlen(char* str);
void			ft_putstr(char* str);
int				ft_cmp(char* a, char* b);
int				ft_isspace(char c);
void			ft_strcpy(char* dest, char* b, char* e);

void			print_value(char* str);
int				ft_atoi(char* nbr);
int				ft_atov(char* key);
int				ft_getunit_val(int cur);
char* ft_getunit_str(int cur);

char* trim_side(char* str);
char* trim_left(char* str);
char* trim_right(char* str);

t_hashtable* createhash(int val);
int				makehash(int val, int hashsize);
void			sethash(t_hashtable* htable, int val, char* key, char* value);
t_node* gethash(t_hashtable* htable, int val, char* key);

int				create_dictionary_hash(char* file);

void			print_nbr_by_value(char* nbr, int cur);

char** ft_seperate(char* input, int cnt);
void			string_distribute(char** string_array, char* input, int mod);
void			free_string_array(char** string_array, int cnt);

int				ft_is_valid(char* value);
void			ft_check_argu(int argc, char** argv, char** file, char** value);
#endif
