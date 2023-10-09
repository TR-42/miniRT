/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cylinder_calc_helper.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:11:10 by kfujita           #+#    #+#             */
/*   Updated: 2023/10/09 20:09:11 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CYLINDER_CALC_HELPER_H
# define _CYLINDER_CALC_HELPER_H

# include <rt_types.h>

typedef struct s_cyl_hlp
{
	t_vec3	l;
	t_vec3	v;
	t_vec3	s;
	t_vec3	p;
	t_vec3	p2;
	double	d_vv;
	double	d_sv;
	double	d_ss;
	double	d_pv;
	double	d_ps;
	double	d_pp;
	double	tmp_a;
	double	tmp_b;
	double	tmp_c;
	double	is_hit_val;
}	t_cyl_hlp;

t_cyl_hlp	cyl_hlp_new(
				const t_cylnd *cylnd,
				const t_ray *ray
				)
			;

#endif
