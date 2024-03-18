# include "../../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct      s_liist
{
    struct s_liist   *next;
    void            *data;
}                   t_liist;


int	test(void *d, void *e)
{
	return (d != e);
}

void	ft_remove(t_liist *a, t_liist **b)
{
	t_liist	*tmp;
	t_liist	*before;

	tmp = *b;
	before = NULL;
	while (tmp)
	{
		if (tmp->data == a->data)
		{
			if (!before)
				*b = (*b)->next;
			else
				before->next = tmp->next;
		}
		before = tmp;
		tmp = tmp->next;
	}
	free(a);
}

void ft_list_remove_if(t_liist **begin_list, void *data_ref, int (*cmp)())
{
	t_liist	*tmp;
	t_liist	*f;

	tmp = *begin_list;
	while (tmp)
	{
		f = tmp->next;
		if (!cmp(tmp->data, data_ref))
			ft_remove(tmp, begin_list);
		tmp = f;
	}
}



int	main(void)
{
	t_liist	*list;
	t_liist	*tmp;
	t_liist *aa;

	tmp = malloc(sizeof(t_liist));
	tmp->data = "content";
	tmp->next = NULL;
	list = tmp;

	aa = malloc(sizeof(t_liist));
	aa->data = "pas content";
	aa->next = NULL;
	list->next = aa;

	tmp = malloc(sizeof(t_liist));
	tmp->data = "pas du tout content";
	tmp->next = NULL;
	list->next->next = tmp;

	tmp = list;
	ft_list_remove_if(&list, aa->data, &test);
	while (list)
	{
		printf("%s\n", (char *)list->data);
		list = list->next;
	}
	return (0);
}