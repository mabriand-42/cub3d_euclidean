/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:01:14 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/12 13:20:22 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>
# include "../libft/libft_header/libft.h"
# include "cub3d_struct.h"
# include "cub3d_macro.h"


/*
** -----------------------------------------------------------------PROTOTYPE---
*/

/*
** Basic
*/
void			ft_skip_spaces(char *str, size_t *pos);
int				ft_find_char(char c, char *str);
int				ft_isvalidchar(char c);
char			*ft_join_bis(char *s1, char *s2);
char			*ft_str_null_bis(char *s1, char *s2);
int				gnl(int fd, char **line);
/*
** Config
*/
int				ft_check_id(char c1, char c2);
int				ft_find_id(char *line, char *id, size_t *pos);
int				ft_id_s(size_t *pos, char *line, char *id);
int				ft_id_rfc(size_t *pos, char *line, char *id);
int				ft_id_nwe(size_t *pos, char *line, char *id);
int				ft_check_config(t_check check);
void			ft_update_player(char c, t_map *m);
/*
** Init
*/
void			ft_init_config(t_config *config);
void			ft_init_check(t_check *check);
void			ft_init_map(t_map *map);
/*
** Resolution
*/
size_t			ft_axis(char *line, size_t *pos);
int				ft_r(char *line, size_t *pos, t_resolution *resolution, t_bool *check);
int				ft_xy(char *line, size_t *pos, t_resolution *R);
/*
** Color
*/
int				ft_color(char *line, size_t *pos);
int				ft_rgb(char *line, size_t *pos, t_color *C);
int				ft_cf(char *line, size_t *pos, t_color *color, t_bool *check);
/*
** Texture
*/
int				ft_path(char *line, size_t *pos, char **path);
int				ft_t(char *line, size_t *pos, char **path, t_bool *check);
/*
** Map
*/
int				ft_closed_map(char *line, size_t *pos);
int				ft_cmp_char(char c1, char c2, t_map *map);
int				ft_cmp_prev_next(char c1, char *line, size_t index);
int				ft_duo_line(char *prev, char *next, t_map *map);
int				ft_duo_line_cp(char *prev, char *next, size_t *ptr_i, size_t *ptr_j);
void			ft_create_map(t_map *map, char *next, int *ret);
int				ft_lines(char *line, char *next, t_map *map, t_config *config);
void			ft_transform_map(t_map *map);
/*
** Parsing
*/
int				ft_elem_parsing(char *line, t_config *config);
int				ft_orient_gnl(int ret_gnl, t_map *map, t_config *config, t_duo duo);
int				ft_get_config(char *id, char *line, size_t *pos, t_config *c);
int				ft_parse_fd(char *fd_path, t_pars_data *cub);











int		ft_file_type(const char *type, const char *fd_path);
int     ft_check_arg(int ac, char **av, t_pars_data  *ptr);
void    ft_init_parse_struct(t_pars_data *ptr);

void    ft_equivalent_data(t_pars_data *pars_data, t_cub *cub);

int     ft_start(t_cub  *cub);


int     ft_pre_start(t_pars_data *pars_data, t_cub *cub, int ac, char **av);
/////////////////////////////////////////////////////////////SOLO TRY


void    ft_get_box_map(t_cub *cub, t_pars_data *pars_data);






// player.c
int     ft_get_player_data(t_cub *cub);
double     ft_dist_to_plane(/*t_cub *cub*/);

int     ft_get_player_pos(t_cub *cub);
void    ft_get_player_dir(t_cub *cub, char c);
int		ft_iscardinal(char c);
void    ft_init_player(t_cub *cub);

// raycsting.c
void    ft_init_cast(t_cub *cub);
void    ft_affine_no_l(t_cub *cub);
void    ft_affine_no_r(t_cub *cub);
int    ft_raycasting_no_g(t_cub *cub);

int    ft_no_cp_bound(t_cub *cub);
int     ft_no_horizontal_l(t_cub *cub);
int    ft_no_vertical_l(t_cub *cub);
double  ft_no_wall_l(t_cub *cub);
double    ft_no_perp_wall(t_cub *cub);

int    ft_cp_bound_no_r(t_cub *cub);
int    ft_h_bound_no_r(t_cub *cub);
int    ft_v_bound_no_r(t_cub *cub);
void    ft_search_wall_no_r(t_cub *cub);
void    ft_perpendicular_wall_no_r(t_cub *cub);

double    ft_hypotenuse(t_coor start, t_coor new);


double  ft_deg_to_rad(double degree);
////////////////////////////////////////////////////////////// LODEV
/*int     ft_get_img(t_cub *cub);
void    ft_init_keys(t_key *key);
void    ft_init_speed(t_speed *speed);*/

/*void    ft_key_relase(int keycode, t_key *key);
void    ft_key_press(int keycode, t_key *key);*/

/*void    ft_init_player_dir(t_pars_data *pars_data, t_cub *cub);
void    ft_init_player_plane(t_pars_data *data, t_cub *cub);
void    ft_init_img(t_cub *cub);
int     ft_img_data(void *mlx_ptr, char *t_path, t_image t_img);*/


#endif