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

# include <rt_types.h>

void	_load_amb_light(
			char *const arr[],
			t_scene *scene
			)
		__attribute__((nonnull))
		;

void	_load_camera(
			char *const arr[],
			t_scene *scene
			)
		__attribute__((nonnull))
		;

void	_load_light(
			char *const arr[],
			t_scene *scene
			)
		__attribute__((nonnull))
		;

void	_load_sphere(
			char *const arr[],
			t_scene *scene
			)
		__attribute__((nonnull))
		;

void	_load_plane(
			char *const arr[],
			t_scene *scene
			)
		__attribute__((nonnull))
		;

void	_load_cylinder(
			char *const arr[],
			t_scene *scene
			)
		__attribute__((nonnull))
		;

t_rgb	_parse_rgb(
			const char *input
			)
		__attribute__((nonnull))
		;

t_vec3	_parse_vec3(
			const char *input,
			bool is_normalized
			)
		__attribute__((nonnull))
		;

void	_err_notnum_exit(void)
		__attribute__((noreturn))
		;

void	_err_val_out_of_range_exit(void)
		__attribute__((noreturn))
		;

void	_err_too_few_param_exit(void)
		__attribute__((noreturn))
		;

#endif
