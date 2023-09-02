void	swap(int *a, int *b){
	int aux;
	aux = a;
	a = b;
	b = aux;
}
void ft_rev_int_tab(int *tab, int size)
{
	int ctd;
	int reverse;
	int aux;

	ctd = 0;
	reverse = size -1;
	while (ctd < size/2)
	{
		aux = tab[ctd];
		tab[ctd] = tab[reverse];
		tab[reverse] = aux;
		ctd++;
		reverse--;
	}
}