#include "libft.h"
#include <stdio.h>

int main() {

	int a;
	int *data;
	t_list *head;
	t_list *current;
	
	a = 42;
	head = ft_lstnew(&a);
	current = head;
	while (current != NULL) {
		data = (int *)(current->content);
		printf("%d -> ", *data);
		current = current->next;
	}
	printf("NULL\n");
	current = head;
	while (current != NULL) {
		t_list *temp = current;
		current = current->next;
		free(temp);
	}

	return 0;
}