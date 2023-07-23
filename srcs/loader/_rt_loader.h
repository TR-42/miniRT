/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rt_loader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:41:48 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/16 23:22:40 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RT_LOADER_H
# define _RT_LOADER_H

# include <rt_loader.h>

t_amb_light	_load_amb_light(
				char *const arr[],
				t_lderr *err
				)
			__attribute__((nonnull))
			;

t_cam		_load_camera(
				char *const arr[],
				t_lderr *err
				)
			__attribute__((nonnull))
			;

t_light		_load_light(
				char *const arr[],
				t_lderr *err
				)
			__attribute__((nonnull))
			;

t_spher		_load_sphere(
				char *const arr[],
				t_lderr *err
				)
			__attribute__((nonnull))
			;

t_plane		_load_plane(
				char *const arr[],
				t_lderr *err
				)
			__attribute__((nonnull))
			;

t_cylnd		_load_cylinder(
				char *const arr[],
				t_lderr *err
				)
			__attribute__((nonnull))
			;

t_lderr		_parse_rgb(
				const char *input,
				t_rgb *dst,
				t_lderr *err
				)
			__attribute__((nonnull(1, 2)))
			;

t_lderr		_parse_vec3(
				const char *input,
				bool is_normalized,
				t_vec3 *dst,
				t_lderr *err
				)
			__attribute__((nonnull(1, 3)))
			;

#endif
