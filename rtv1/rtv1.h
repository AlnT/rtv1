/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:30:44 by ataftai           #+#    #+#             */
/*   Updated: 2017/11/01 20:08:04 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define THR 8
# define W_W 1000
# define W_H 1000
# define BUFF_SIZE 100

# include <mlx.h>
# include <pthread.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"

typedef	struct	s_v
{
	double x;
	double y;
	double z;
}				t_v;

typedef	struct	s_col
{
	double	r;
	double	g;
	double	b;
}				t_col;

typedef	struct	s_ob
{
	double		size;
	t_v			p;
	t_v			r;
	t_col		col;
	int			tp;
	struct s_ob *next;
}				t_ob;

typedef struct	s_rt
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bite;
	int		size;
	int		end;
	char	*data;
	char	**sc;
	int		n_l;
	t_ob	*ob;
	t_ob	*l;
	t_v		c_p;
	t_v		c_d;
	t_v		r_d;
	t_v		k;
	t_v		i;
	t_v		j;
	int		h;
	int		m_r;
	int		p_r;
	int		sel;
	int		a;
	double	sp;

}				t_rt;

typedef	struct	s_t_h
{
	float	t;
	float	t_0;
	float	t_1;
	float	a0;
	float	b0;
	float	c0;
	char	*data;
	int		cp;
	int		m_r;
	int		p_r;
	t_v		c_p;
	t_v		c_d;
	t_v		r_d;
	t_v		nm;
	t_v		ref;
	t_v		ref_p;
	t_v		dis;
	t_v		i;
	t_v		k;
	t_v		j;
	t_ob	*ob;
	t_ob	*l;
	int		bite;
	int		size;
	int		a;
	double	sp;
	int		t_y;
	int		t_x;

}				t_t_h;

typedef	struct	s_tab
{
	int		in;
	t_rt	*rt;
}				t_tab;

void			fzer(float *m, int i);
void			pixel_put(t_t_h *rt, int j, int i, int col);
float			c_l(float v, float mn, float mx);
int				del_l(t_ob *l, t_ob *t);
void			init(t_rt *rt);
int				nft_atoi(char *str, int *i);
int				get_next_line(const int fd, char **line);
void			usage_error(void);
void			mem_error(void);
void			f_error(void);
char			*read_scene(t_rt *rt, char *file);
int				len_l(char *str, int i);
int				check(t_rt *rt, char *str);
int				create_scene(t_rt *rt, char *file);
void			create_rt(char *file);
int				colnp(t_rt *rt, t_ob *o, int m);
int				check_o(t_rt *rt, t_ob *obj);
int				check_s(t_rt *rt, int i);
int				p_ob(t_rt *rt, int i);
int				pars(t_rt *rt);
int				add_l(t_rt *rt, int *m, int i);
int				add_pl(t_rt *rt, int *m, int i);
int				add_con(t_rt *rt, int *m, int n, int i);
int				add_sp(t_rt *rt, int *m, int i);
t_ob			*add_ll(t_rt *rt, t_ob *o);
t_ob			*add_ol(t_rt *rt, t_ob *o);
void			mlx_controle(t_rt *rt);
int				paint_rt(t_rt *rt);
void			*t_p(void *a);
t_ob			*ob_cpy(t_ob *ob);
void			copy(t_rt *rt, t_t_h *t);
int				rayt(t_t_h *rt, t_ob *el, double j, double i);
float			*lmrt(t_t_h *rt, t_ob *temp, t_ob *l, float *t);
float			*rayn(t_t_h *rt, float *t, double j, double i);
float			*avg(float *rm, float *t);
t_ob			*intrs(t_t_h *rt, t_ob *el, t_v r, t_v p);
float			*reflect(t_t_h *rt, t_ob *temp, t_v *p, float *t);
float			*lend(t_ob *temp, t_ob *l, float *t, float i);
float			spec(t_t_h *rt, t_v dst, float i, float l);
int				shadow(t_t_h *rt, t_ob *temp, t_ob *l, t_v p);
t_v				norm(t_t_h *rt, t_ob *temp, t_v p);
t_ob			*r_int(t_t_h *rt, t_ob *el, t_ob *temp, t_v p);
t_ob			*rinit(t_t_h *rt, t_ob *temp, t_v *p);
int				del_l(t_ob *l, t_ob *t);
int				nft_atoi(char *str, int *i);
t_ob			*add_ll(t_rt *rt, t_ob *o);
t_ob			*add_ol(t_rt *rt, t_ob *o);
t_v				s_vect(t_v *f, t_v *l);
void			n_vect(t_v *f);
t_v				cr_vect(t_v *f, t_v *l);
t_v				scale_vect(t_v *f, float i);
float			d_vect(t_v *f, t_v *l);
double			sp_int(t_t_h *rt, t_ob *temp, t_v r, t_v p);
double			pl_int(t_t_h *rt, t_ob *temp, t_v r, t_v p);
double			cyl_int(t_t_h *rt, t_ob *temp, t_v r, t_v p);
double			cone_int(t_t_h *rt, t_ob *temp, t_v r, t_v p);
#endif
