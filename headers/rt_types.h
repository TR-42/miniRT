/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:56:14 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/09 00:40:39 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TYPES_H
# define RT_TYPES_H

# include <stdbool.h>
# include <stddef.h>

# include <ft_vect/ft_vect.h>

# include "vect3d.h"

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
	t_byte	fov;
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

typedef struct s_objs_comm
{
	t_tobj	type;
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
	t_vec3		center;
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

typedef union u_objs
{
	t_byte		_[U_OBJ_SIZE];
	t_objs_comm	comm;
	t_spher		sphere;
	t_plane		plane;
	t_cylnd		cylinder;
}	t_objs;

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
