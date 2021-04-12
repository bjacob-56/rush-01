#include "rush01.h"

void	init_struct(t_rush *t)
{
	t->c = 0;
	t->i_max = 0;
	t->j_max = 0;
	t->map_modif = NULL;
	t->map_origin = NULL;
	t->max = 1;
	t->size = 0;
}

int	main(void)
{
	t_rush	r;

	init_struct(&r);
	pars(&r);
	algo(&r);
	return (0);
}
