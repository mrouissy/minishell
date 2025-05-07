#ifndef FT_MALLOC_H
#define FT_MALLOC_H

#include "head.h"

typedef struct s_mem_node
{
	void				*address;
	struct s_mem_node	*next;
}				t_mem_node;

void	*ft_safe_malloc(size_t size, int key, int exit_status, void *to_delete);

#define ALLOCATE 1
#define FREE_ALL 0
#define FREE_ONE 2

#endif
