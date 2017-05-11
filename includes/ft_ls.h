/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:36:30 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:49:16 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include "../libft/libft.h"

typedef struct			s_datafile
{
	int					nb_links;
	time_t				time_modif;
	char				*last_change;
	char				*link;
	blkcnt_t			nb_blocks;
	char				*username;
	gid_t				gid;
	char				*usergroup;
	char				mode[12];
	char				*path;
	char				*filename;
	int					filenumber;
	unsigned int		minor;
	unsigned int		major;
	long long			size;
}						t_datafile;

typedef struct			s_options
{
	int					opt[9];
}						t_options;

t_options				g_flag_int;

static const char		g_optionflags[9] =
{
	'l',
	'R',
	'r',
	't',
	'a',
	'F',
	'U',
	'f',
	's'
};

char					*handle_dirname(char *path, char *tabpath);
void					info_file(t_datafile fileinfo);
t_datafile				stock_data(char *str);
int						malloc_tab(char	*path);
char					*handle_filename(char *p, t_datafile *f);
int						no_file(char **argv);
void					print_error(int argc, char **argv);
int						ascii_order(char *str1, char *str2);
int						print_error_bis(char **argv);
char					**get_arg_file(int argc, char **argv);
char					**get_arg_dir(int argc, char **argv);
int						cmp_optionflag(char c);
int						handle_options(char **argv);
void					sort_ascii(char **tab);
t_datafile				*fill_table_rec(char *path, int count);
void					sort_tab_struct(t_datafile *tab);
void					display_tab(t_datafile *tab);
t_datafile				*fill_table(char *path);
void					free_tab(t_datafile *tab);
void					initiate_fileinfo(t_datafile fileinfo);
void					free_char_tab(char **str);
int						size_tab(t_datafile *tab);
char					*handle_time(char *str);
void					sort_tab_ascii_rev(t_datafile *tab);
int						count_links_size(t_datafile *tab);
int						count_file_size(t_datafile *tab);
int						count_username_size(t_datafile *tab);
void					sort_tab_ascii(t_datafile *tab);
t_datafile				*return_error(char *path);
int						print_error_options(char c);
char					*handle_links(char *path);
void					sort_tab_ascii_rev(t_datafile *tab);
int						ft_issort_struct_rev(t_datafile *tab);
void					handle_device(dev_t st_rdev, t_datafile *fileinfo);
void					end_fill(DIR *dir, t_datafile *tab);
int						count_block_size(t_datafile *tab);
void					colors_no_options(t_datafile fileinfo, int i);
int						count(t_datafile *tab);
void					print_count(t_datafile file, t_datafile *tab);
t_datafile				*fill_table_file(char *path);
char					**no_arg_2(char **args);
char					**no_arg(char **args);
int						print_error_no_file(char **argv);
int						stock_files_l(char **tab);
void					sort_rev(t_datafile *tab);
void					sort_time(t_datafile *tab);
int						replace_name(t_datafile *tabus);
char					**sort_dir(char **tab);

#endif
