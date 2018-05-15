/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:09:28 by yhemme            #+#    #+#             */
/*   Updated: 2018/04/18 11:29:37 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../mlx/mlx.h"
# include <pthread.h>
# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define WIDTH 1000
# define HEIGHT 800
# define HEIGHTHUD (HEIGHT + (HEIGHT / 4))
# define WIDTHHUD (WIDTH + (WIDTH / 4))
# define RATIO WIDTH / HEIGHT
# define D_MAX 1037.0f
# define D_MIN -1037.0f
# define FOV 30
# define SPHERE 1
# define PLAN 2
# define CYLINDER 3
# define CONE 4
# define DISK 5
# define PARABOLOID 6

# include <stdio.h>

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_cam
{
	t_vec3		pos;
	double		rotx;
	double		roty;
}				t_cam;

typedef struct	s_rgb
{
	double		red;
	double		green;
	double		blue;
}				t_rgb;

typedef struct	s_ray
{
	t_vec3		org;
	t_vec3		dir;
}				t_ray;

typedef struct	s_obj
{
	t_vec3			pos;
	t_vec3			n;
	t_vec3			nsave;
	t_vec3			inter;
	t_vec3			dir;
	double			r;
	int				type;
	t_rgb			color;
	t_rgb			f_col;
	double			t;
	double			amb;
	double			dif;
	double			spec;
	double			reflect;
	double			transp;
	double			perlin;
	int				text;
	struct s_obj	*next;
}				t_obj;

typedef struct	s_light
{
	t_vec3			pos;
	double			i;
	struct s_light	*next;
}				t_light;

typedef struct	s_quadra
{
	double		a;
	double		b;
	double		c;
	double		q;
	double		discr;
	double		x0;
	double		x1;
}				t_quadra;

typedef struct	s_key
{
	unsigned int	up : 1;
	unsigned int	left : 1;
	unsigned int	down : 1;
	unsigned int	right : 1;
	unsigned int	w : 1;
	unsigned int	a : 1;
	unsigned int	s : 1;
	unsigned int	d : 1;
	unsigned int	bw : 1;
	unsigned int	sepia : 1;
	unsigned int	cartoon : 1;
	unsigned int	blur : 1;
	unsigned int	sin : 1;
	unsigned int	chess : 1;
	unsigned int	pix : 1;
	unsigned int	msaa : 1;
	unsigned int	rainbow : 1;
	unsigned int	wave : 1;
	unsigned int	repeat : 1;
	t_vec3			move_tex;
	t_vec3			stretch;
}				t_key;

typedef struct	s_chess
{
	t_vec3		p;
	int			x1;
	int			y1;
	int			z1;
}				t_chess;

typedef struct	s_perlin
{
	int				X;
	int				Y;
	int				Z;
	double			x;
	double			y;
	double			z;
	double	g000;
	double	g001;
	double	g010;
	double	g011;
	double	g100;
	double	g101;
	double	g110;
	double	g111;
	double	u;
	double	v;
	double	w;
	double	x00;
	double	x10;
	double	x01;
	double	x11;
	double	xy0;
	double	xy1;
	double	xyz;
}				t_perlin;

typedef struct	s_env
{
	t_key		key;
	t_obj		*obj_null;
	t_obj		*obj;
	t_light		*lights;	
	t_chess		chess;
	double		ang_y;
	double		ang_x;
	t_cam		*cam;
	void		*mlx;
	void		*win;
	void		*image;
	char		*img;
	int			bpp;
	int			ed;
	int			i;
	int			sl;
	double		amb;
	int			thread_id;
	double		percent;
	double		percent2;
	void		*image2;
	char		*img2;
	int			t[2];
	int			tmp[3];
	int			px;
}				t_env;
void			solve_quadratic(t_quadra *s);
void			compute_normal_cylinder(t_ray ray, t_obj *s);
void			compute_normal_sphere(t_env *e, t_ray *ray, t_obj *s);
void			compute_normal_plan(t_env *e, t_ray *ray, t_obj *p);
void			compute_normal_cone(t_ray ray, t_obj *c);
void			compute_normal_paraboloid(t_ray ray, t_obj *c);
double			inter_cone(t_vec3 ray, t_vec3 cam_p, t_obj *obj);
double			inter_cylinder(t_vec3 ray, t_vec3 cam_p, t_obj *obj);
double			inter_paraboloid(t_vec3 ray, t_vec3 cam_p, t_obj *obj);
double			inter_sphere(t_env *e, t_vec3 ray, t_obj *obj, t_vec3 o);
double			inter_plan(t_env *e, t_vec3 ray, t_obj *obj, t_vec3 o);
double			inter_disk(t_env *e, t_vec3 ray, t_obj *obj, t_vec3 o);
int				key_release(int key, t_env *e);
int				key_press(int key, t_env *e);
void			*raytrace(void *ev);
void			lights_apply(t_env *e, t_ray *prim, t_obj *obj);
t_obj			find_nearest(t_env *e, t_vec3 dir, t_ray *ray);
t_obj			*fill(char *str, t_obj *obj);
double			max(double a, double b);
double			min(double a, double b);
void			angle_increase(t_env *e, double x, double y);
void			rotation_apply(t_env *e, t_vec3 *dir);
void			forward_vec_create(t_vec3 *vec);
void			move(t_env *e);
void			rotate(t_env *e);
void			up_vec_create(t_vec3 *vec);
void			right_vec_create(t_vec3 *vec);
t_vec3			y_rotation(t_vec3 vec, double angle);
t_vec3			x_rotation(t_vec3 vec, double angle);
void			pixel_to_img(t_env *e, int x, int y, t_rgb *color);
void			malloc_error(void);
t_vec3			vector_add(t_vec3 v1, t_vec3 v2);
t_vec3			vector_sub(t_vec3 v1, t_vec3 v2);
t_vec3			vector_mult(t_vec3 v1, double coef);
t_vec3			vector_div(t_vec3 v1, double div);
double			vector_dot(t_vec3 v1, t_vec3 v2);
t_vec3			vector_cross(t_vec3 v1, t_vec3 v2);
double			vector_len(t_vec3 v1);
t_vec3			normalize(t_vec3 v);
void			init_obj(t_env *e, char *file);
void			init_cam(t_env *e);
void			clean_tab(char **tab);
void			fill_plan(char *str, t_obj *obj);
void			fill_disk(char *str, t_obj *obj);
void			fill_sphere(char *str, t_obj *obj);
void			fill_cone(char *str, t_obj *obj);
void			fill_paraboloid(char *str, t_obj *obj);
void			fill_cylinder(char *str, t_obj *obj);
void			ft_error();
void			check_error_s(char **tab);
void			check_error_d(char **tab);
void			check_error_p(char **tab);
void			check_error_l(char **tab);
void			check_error(char **tab);
void			init_obj_null(t_env *e);
void			add_obj(t_env *e, t_obj *obj);
void			add_light(t_env *e, t_light *light);
void			fill_light(char *str, t_light *light);
void			fill_cylinder2(char **tab, t_obj *obj);
void			fill_sphere2(char **tab, t_obj *obj);
void			fill_disk2(char **tab, t_obj *obj);
void			fill_cone2(char **tab, t_obj *obj);
void			fill_plan2(char **tab, t_obj *obj);
void			stock(char **tab, char *line, char *file);
void			filterbw(t_rgb *color, t_env *e);
void			filter_cartoon(t_rgb *color, t_env *e);
void			filter_sepia(t_rgb *color, t_env *e);
void			apply_filters(t_env *e);
void			apply_blur(t_env *e);
void			get_color(char *img, int x, int y, t_rgb *color);
void			get_color_sq(t_env *e, int x, int y, t_rgb *color);
void			get_color_msaa(t_env *e, int x, int y, t_rgb *color);
void			saveppm(char *filename, unsigned char *img);
void			screenshot(t_env *e);
void			moveset(int key, t_env *e);
void			key_filters(int key, t_env *e);
void			chess(t_env *e, t_obj *obj);
void			pixel(t_env *e);
void			put_pixelisation(t_env *e, int x, int y, t_rgb *rgb);
void			antialiasing(t_env *e);
void			compute_normal(t_env *e, t_ray *ray, t_obj *obj);
void			randomize(t_rgb *color, t_env *e);
void			hud(t_env *e);
void			readobject(t_env *e);
void			wave(t_env *e, t_obj *obj, int x);
double			smooth_noise_3d(double x, double y, double z, double res);
void			mlx(t_env *e);
t_rgb			reflection(t_env *e, t_ray *ray, t_obj *c_obj, int depth);
t_rgb			transparency(t_env *e, t_ray *ray, t_obj *c_obj);
void			perlin(t_env *e, t_obj *obj);
void			linear_interpolations(t_perlin *p);
double			linear_interpolate(double a, double b, double t);
double			quintic_poly(double t);
void			apply_transp(t_env *e, t_obj *obj, t_ray *primary);
void			apply_reflect(t_env *e, t_obj *obj, t_ray *primary);
t_rgb			intersect(t_env *e, t_ray *primary);
void			compute_primary(double x, double y, t_env *e, t_ray *ray);
t_rgb			a_a(int x, int y, t_env *e);
t_rgb			choose_tex_type(t_obj *obj, t_env *e, t_ray *ray);
void			get_color2(t_env *e, int x, int y, t_rgb *color);
void			parse2(t_env *e, char **tab, int *i, t_obj *obj);
#endif
