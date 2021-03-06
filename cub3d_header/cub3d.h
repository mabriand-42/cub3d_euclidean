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
** -------------------------------------------------------------------PARSING---
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
void				ft_update_player(char c, t_map *m);
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
int				ft_text(char *line, size_t *pos, char **path, t_bool *check);
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

/*
** ---------------------------------------------------------------RAY CASINTG---
*/

/*
** Utils
*/
double  ft_deg_to_rad(double degree);
size_t	ft_column_len(char **tab); // 
/*
** Player
*/
void    ft_init_player(t_cub *cub);
int     ft_get_player_data(t_cub *cub);
int     ft_get_player_pos(t_cub *cub);
int		ft_iscardinal(char c);
/*
** Affine
*/
void	ft_affine(t_cub *cub, t_bool right);
double  ft_hypotenuse(t_coor  start, t_coor new, t_cub *cub);
double  ft_dist_to_plane(t_cub *cub);
double	ft_opposite(double dist_to_plane, t_angle angle); //
/*
** Wall search
*/
int     ft_north_left_h_hit(t_cub *cub);
int     ft_north_left_v_hit(t_cub *cub);
int     ft_north_right_h_hit(t_cub *cub);
int     ft_north_right_v_hit(t_cub *cub);
int     ft_south_left_h_hit(t_cub *cub);
int     ft_south_left_v_hit(t_cub *cub);
int     ft_south_right_h_hit(t_cub *cub);
int     ft_south_right_v_hit(t_cub *cub);
void    ft_search_v_hit(double *dist, int *v_bound, t_cub *cub, int (*f)(t_cub *));
void    ft_search_h_hit(double *dist, int *h_bound, t_cub *cub, int (*f)(t_cub *));
void    ft_closer(double *dist, t_cub *cub, double dist_h, double dist_v);
double  ft_search_wall(t_cub *cub, int (*ft_h_hit)(t_cub *), int (*ft_v_hit)(t_cub *));
double  ft_search_wall_cp(t_cub *cub);
/*
** Raycasting
*/
void   	ft_init_cast(t_cub *cub);
void	ft_raycasting(t_cub *cub);

void	ft_new_angle_minus(t_cub *cub, t_bool right);


void	ft_cast_right_side(t_cub *cub, int (*ft_rh)(t_cub *), int (*ft_rv)(t_cub *));
void	ft_cast_left_side(t_cub *cub, int (*ft_lh)(t_cub *), int (*ft_lv)(t_cub *));
/*
** Draw
*/
void	ft_init_draw(t_cub *cub);
int		ft_scale(double	d_to_plane, double d_to_wall);
void	ft_get_draw_data(t_cub *cub, double d_to_wall);
void	ft_draw_pxl_line(t_cub *cub, double d_to_wall);
int		ft_create_color(int r, int g, int b);
void	ft_v_wall_orient(t_cub *cub, double	coor_x, int	box_y);
void	ft_h_wall_orient(t_cub *cub, double	coor_y, int	box_x);
void	ft_draw_left(t_cub *cub, int (*ft_lh)(t_cub *), int (*ft_lv)(t_cub *));
void	ft_draw_right(t_cub *cub, int (*ft_rh)(t_cub *), int (*ft_rv)(t_cub *));
int		ft_get_wall_color(t_cub *cub);
/*
** Hook
*/


/*void	ft_init_move(t_move *move);*/

int		ft_press_mana(int keycode, t_cub *cub);
void	ft_event(t_cub *cub);
void	ft_close_pgm(t_cub *cub);

void	ft_x_plus(t_cub *cub);
void	ft_x_minus(t_cub *cub);
void	ft_y_plus(t_cub *cub);
void	ft_y_minus(t_cub *cub);
int		ft_key_wads(int keycode, t_cub *cub);
void	ft_move(t_cub *cub, void (*ft_n)(t_cub *), void (*ft_s)(t_cub *), 
							void (*ft_w)(t_cub *), void (*ft_e)(t_cub *));

void	ft_move_wads(int keycode, t_cub *cub);




/*int    ft_north_cp(t_cub *cub);
int    ft_south_cp(t_cub *cub);
int    ft_west_cp(t_cub *cub);
int    ft_east_cp(t_cub *cub);
double    ft_NS_search_wall_cp(t_cub *cub, int (*ft)(t_cub *));
double    ft_WE_search_wall_cp(t_cub *cub, int (*ft)(t_cub *));
double	ft_search_wall_cp(t_cub *cub);
void	ft_new_angle_plus(t_cub *cub, t_bool right);*/

/*
** -------------------------------------------------------------------PROGRAM---
*/

/*
** Argument
*/
int		ft_file_type(const char *type, const char *fd_path);
int     ft_check_arg(int ac, char **av, t_pars_data  *ptr);
/*
** Init
*/
void    ft_equivalent_data(t_pars_data *pars_data, t_cub *cub);
/*
** Run
*/
void    ft_init_parse_struct(t_pars_data *ptr);
int		ft_parse_fd(char *fd_path, t_pars_data *cub);
int     ft_pre_start(t_pars_data *pars_data, t_cub *cub, int ac, char **av);
int     ft_start(t_cub  *cub);







#endif