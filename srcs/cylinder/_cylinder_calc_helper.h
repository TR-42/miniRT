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

// helper for top and bottom
// 末尾アンスコは、1と2のより近い方を表す
typedef struct s_cyl_hlp2
{
	double	d_n_m;
	double	radius;
	double	h_half;
	t_vec3	n1;
	t_vec3	p1;
	double	t1;
	t_vec3	n2;
	t_vec3	p2;
	double	t2;
	t_vec3	n_;
	t_vec3	p_;
	double	t_;
	t_vec3	hit_at;
	double	hit_r;
}	t_cyl_hlp2;

t_cyl_hlp	cyl_hlp_new(
				const t_cylnd *cylnd,
				const t_ray *ray
				)
			;

t_cyl_hlp2	cyl_hlp_top_btm_new(
				const t_cylnd *cylnd,
				const t_ray *ray
				)
			;

#endif
