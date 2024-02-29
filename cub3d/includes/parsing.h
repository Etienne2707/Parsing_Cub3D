/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:01:40 by educlos           #+#    #+#             */
/*   Updated: 2024/02/12 14:09:56 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define BLACK "\033[0;30m"

typedef struct s_pos
{
	char			*arg;
	char			*value;
	int				*range;
	struct s_pos	*next;
	struct s_pos	*back;

}					t_pos;

typedef struct s_malloc
{
	char			*pointer;
	char			**pointer2;
	struct s_malloc	*next;
	struct s_malloc	*back;

}					t_malloc;

typedef struct s_parsing
{
	int				lcount;
	char			**map;
	int				_playerY;
	int 			_playerX;
	char			_playerD;
	t_pos			*begin;
	t_pos			*pos;
	t_malloc		*_malloc;
	t_malloc		*_mbegin;
	int				**_map;
}					t_parsing;

typedef struct s_map
{
	int				_last;
	int				_first;
	char			**_map;
}					t_map;
int					main(int ac, char **argv);

//parsing
int					get_config(t_parsing *p, char *dest);
int					check_arg_before(char *src, char *find);
int					check_arg_after(char *str, int last);
int					check_map(char **map);
char				*put_map_line(char *dest, int start, int end);
void struct_parsing(t_parsing *p, t_map *m);

//check_path
int					check_path(t_pos *pos);

//map
int					parsing_map(t_parsing *p);

//free_global
int					push_malloc(t_parsing *p, char *str);
int					push_malloc_double(t_parsing *p, char **str);
void				free_double_array(char **str);
void				free_double_array_dest(char **str, int index_max);

void				free_structs(t_parsing *p);
void				free_map(t_map *m);

//wall_checker
int					only_wall(char *str);
int					check_wall_posx(t_map *m, int y, int x);
int					check_wall_posy(t_map *m, int y, int x);
int					check_wall_pos(t_map *m, int y, int x);
int					check_wall(t_map *m);

//utils_line
int					ft_endlinelen(char *dest, int index);
int					ft_line_count(char *str);

//Initialisation
char				**init_config(void);
int					init_map(char *dest, t_parsing *p);

//position
char				*get_pos(char *map, char *config);
int					set_pos(t_parsing *p, char *map, char *config);
char				**get_pos_remove(t_parsing *p, char **map, char *config,
						int index);

//utils
int					skip_space(char *str, int i);
int					check_only_space(char *str, int index);
int					ft_strlen_double(char **str);
int					ft_strstr(char *str, char *to_find);
char				*get_nmalloc(char *str, int start, int end);
int					skip_string(char *str);
int					ft_check_format(char *src, char *format);

//utils_print
void				printdoubletab(char **str);
void				printtab(char *str);

//utils_list
int					get_list(t_pos **pos, t_parsing *p, char *arg, char *value);
int					push_front_list(t_pos **pos, t_pos *new, t_parsing *p);
void				print_list(t_pos *pos);
#endif