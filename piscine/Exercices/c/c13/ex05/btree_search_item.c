/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:42:06 by gfontao-          #+#    #+#             */
/*   Updated: 2024/01/23 14:12:49 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	void	*found;
	
	if(root)
	{
		found = btree_search_item(root->left, data_ref, cmpf);
		if (found != NULL)
            return found;
		if (cmpf(root->item, data_ref) == 0)
            return root->item;
		btree_search_item(root->right, data_ref, cmpf);
	}
}
