/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 12:24:00 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:48:51 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		detection_type_fichier(mode_t st_mode, t_datafile *fileinfo)
{
	if (S_ISLNK(st_mode))
		fileinfo->filenumber = 1;
	else if (S_ISREG(st_mode))
		fileinfo->filenumber = 2;
	else if (S_ISDIR(st_mode))
		fileinfo->filenumber = 3;
	else if (S_ISBLK(st_mode))
		fileinfo->filenumber = 4;
	else if (S_ISFIFO(st_mode))
		fileinfo->filenumber = 5;
	else if (S_ISSOCK(st_mode))
		fileinfo->filenumber = 6;
	else if (S_ISCHR(st_mode))
		fileinfo->filenumber = 7;
	else
		fileinfo->filenumber = 0;
}

char		filetype(int mode)
{
	if (mode == 1)
		return ('l');
	else if (mode == 2)
		return ('-');
	else if (mode == 3)
		return ('d');
	else if (mode == 4)
		return ('b');
	else if (mode == 5)
		return ('p');
	else if (mode == 6)
		return ('s');
	else if (mode == 7)
		return ('c');
	else
		return ('X');
}

void		handle_rights(t_datafile *fileinfo, struct stat buf)
{
	fileinfo->mode[0] = filetype(fileinfo->filenumber);
	fileinfo->mode[1] = (buf.st_mode & S_IRUSR) ? 'r' : '-';
	fileinfo->mode[2] = (buf.st_mode & S_IWUSR) ? 'w' : '-';
	if (buf.st_mode & S_ISUID)
		fileinfo->mode[3] = (buf.st_mode & S_IXUSR) ? 's' : 'S';
	else
		fileinfo->mode[3] = (buf.st_mode & S_IXUSR) ? 'x' : '-';
	fileinfo->mode[4] = (buf.st_mode & S_IRGRP) ? 'r' : '-';
	fileinfo->mode[5] = (buf.st_mode & S_IWGRP) ? 'w' : '-';
	if (buf.st_mode & S_ISGID)
		fileinfo->mode[6] = (buf.st_mode & S_IXGRP) ? 's' : 'S';
	else
		fileinfo->mode[6] = (buf.st_mode & S_IXGRP) ? 'x' : '-';
	fileinfo->mode[7] = (buf.st_mode & S_IROTH) ? 'r' : '-';
	fileinfo->mode[8] = (buf.st_mode & S_IWOTH) ? 'w' : '-';
	if (buf.st_mode & S_ISVTX)
		fileinfo->mode[9] = (buf.st_mode & S_IXOTH) ? 't' : 'T';
	else
		fileinfo->mode[9] = (buf.st_mode & S_IXOTH) ? 'x' : '-';
	fileinfo->mode[10] = '\0';
	fileinfo->mode[11] = '\0';
}

void		stock_data_bis(t_datafile *fileinfo, struct stat buf)
{
	struct group	*guser;
	struct passwd	*user;

	fileinfo->nb_links = buf.st_nlink;
	fileinfo->nb_blocks = buf.st_blocks;
	fileinfo->size = buf.st_size;
	fileinfo->time_modif = buf.st_mtime;
	fileinfo->last_change = handle_time(ctime(&buf.st_mtime));
	user = getpwuid(buf.st_uid);
	fileinfo->username = ft_strdup(user->pw_name);
	fileinfo->gid = user->pw_gid;
	guser = getgrgid(fileinfo->gid);
	fileinfo->usergroup = ft_strdup(guser->gr_name);
}

t_datafile	stock_data(char *str)
{
	struct stat		buf;
	t_datafile		fileinfo;

	lstat(str, &buf);
	if (errno)
	{
		return_error(str);
		fileinfo.filename = NULL;
		errno = 0;
	}
	else
	{
		fileinfo.path = ft_strdup(str);
		detection_type_fichier(buf.st_mode, &fileinfo);
		handle_device(buf.st_rdev, &fileinfo);
		handle_rights(&fileinfo, buf);
		fileinfo.filename = handle_filename(fileinfo.path, &fileinfo);
		if (fileinfo.mode[0] == 'l')
			fileinfo.link = handle_links(fileinfo.path);
		else
			fileinfo.link = ft_strnew(0);
		stock_data_bis(&fileinfo, buf);
	}
	return (fileinfo);
}
