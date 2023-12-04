/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:56:14 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/04 21:52:09 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TYPES_H
# define RT_TYPES_H

# include <stdbool.h>
# include <stddef.h>

# include <ft_vect/ft_vect.h>

# include "vect3d.h"
# include "ray.h"

typedef unsigned char	t_byte;

typedef struct s_rgb
{
	t_byte	r;
	t_byte	g;
	t_byte	b;
}	t_rgb;

typedef struct s_ambient_lighting
{
	double	ratio;
	t_rgb	color;
}	t_amb_light;

typedef struct s_cam
{
	t_vec3	point;
	t_vec3	orientation;
	double	fov;
}	t_cam;

typedef struct s_light
{
	t_vec3	point;
	double	brightness;
	t_rgb	color;
}	t_light;

typedef enum e_tobj
{
	T_OBJ_UNKNOWN,
	T_OBJ_SPHERE,
	T_OBJ_PLANE,
	T_OBJ_CYLINDER,
}	t_tobj;

typedef union u_objs	t_objs;

typedef struct s_hit
{
	double			t;
	t_vec3			at;
	t_vec3			normal;
	const t_objs	*obj;
}	t_hit;

typedef bool			(*t_hit_func)(
	const t_objs *obj,
	const t_ray *ray,
	const double t_range[2],
	t_hit *hit_rec
) __attribute__((nonnull));

typedef t_rgb			(*t_rgb_func)(
	const t_objs *obj,
	const t_ray *ray,
	double hit_at
) __attribute__((nonnull));

typedef struct s_objs_comm
{
	t_tobj		type;
	t_hit_func	hit_func;
	t_rgb_func	rgb_func;
}	t_objs_comm;

typedef struct s_sphere
{
	t_objs_comm	comm;
	t_vec3		center;
	double		diameter;
	t_rgb		color;
}	t_spher;

typedef struct s_plane
{
	t_objs_comm	comm;
	t_vec3		point;
	t_vec3		orientation;
	t_rgb		color;
}	t_plane;

typedef struct s_cylinder
{
	t_objs_comm	comm;
	t_vec3		center;
	t_vec3		axis;
	double		diameter;
	double		height;
	t_rgb		color;
}	t_cylnd;

# define U_OBJ_SIZE 64

union u_objs
{
	t_objs_comm	comm;
	t_spher		sphere;
	t_plane		plane;
	t_cylnd		cylinder;
};

typedef struct s_scene
{
	bool		is_amb_l_set;
	t_amb_light	amb_light;
	bool		is_camera_set;
	t_cam		camera;
	bool		is_light_set;
	t_light		light;
	t_vect		objs;
}	t_scene;

#endif
