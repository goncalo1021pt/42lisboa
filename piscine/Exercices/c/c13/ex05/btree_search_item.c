/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:42:06 by gfontao-          #+#    #+#             */
/*   Updated: 2024/09/17 01:21:18 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *,
			void *))
{
	void	*found;

	if (root)
	{
		found = btree_search_item(root->left, data_ref, cmpf);
		if (found != NULL)
			return (found);
		if (cmpf(root->item, data_ref) == 0)
			return (root->item);
		btree_search_item(root->right, data_ref, cmpf);
	}
}
