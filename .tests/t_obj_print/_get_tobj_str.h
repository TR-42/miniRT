/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _get_tobj_str.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 22:11:22 by kfujita           #+#    #+#             */
/*   Updated: 2023/07/18 00:27:51 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_TOBJ_STR_H
# define _GET_TOBJ_STR_H

# include <rt_loader.h>

# define IF_RET_ERR_STR(_err) \
if (err == _err)\
	return (#_err);

static const char	*_get_tobj_str(t_tobj err)
{
	IF_RET_ERR_STR(T_OBJ_UNKNOWN)
	else IF_RET_ERR_STR(T_OBJ_SPHERE)
	else IF_RET_ERR_STR(T_OBJ_PLANE)
	else IF_RET_ERR_STR(T_OBJ_CYLINDER)
	else
		return ("(Unknown load_error id)");
}

static const char	*_get_tobj_str_of(t_objs obj)
{
	return (_get_tobj_str(obj.comm.type));
}

#endif