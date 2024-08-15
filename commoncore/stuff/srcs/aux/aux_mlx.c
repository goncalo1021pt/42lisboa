

int	interpolate(float ratio, int start, int end)
{
	return (start * (1 - ratio) + end * ratio);
}

int	create_rgb(float ratio, int start, int end)
{
	int	r;
	int	g;
	int	b;

	r = interpolate(ratio, (start >> 16) & 0xFF, (end >> 16) & 0xFF);
	g = interpolate(ratio, (start >> 8) & 0xFF, (end >> 8) & 0xFF);
	b = interpolate(ratio, start & 0xFF, end & 0xFF);
	return ((r << 16) | (g << 8) | b);
}