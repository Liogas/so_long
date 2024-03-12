typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

t_img	new_file_img(char * path, t_win window) {
	t_img image;

	image.win = window;
	image.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, path, &image.w, &image.h);
	if (!image.img_ptr)
		write(2, "File could not be read\n", 23);
	else
		image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	return (image);
}

void	destroy_image(t_img img) {
	if (img.img_ptr && img.win.mlx_ptr) 
       mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h) {
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

unsigned int	get_pixel_img(t_img img, int x, int y) {
	return (*(unsigned int *)((img.addr
			+ (y * img.line_len) + (x * img.bpp / 8))));
}

void	put_img_to_img(t_img dst, t_img src, int x, int y) {
	int i;
	int j;

	i = 0;
	while(i < src.w) {
		j = 0;
		while (j < src.h) {
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}
t_win new_window(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

int main(void)
{
 	t_win	tutorial;
	t_img	base_image;
	t_img	bg;
	t_img	ring;

	signal(SIGINT, sig_handler);
	tutorial = new_window(1000, 650, "transparency");
	if (!tutorial.win_ptr)
		return (2);
	base_image = new_img(1000, 650, tutorial);

	{
		bg = new_file_img("lotr_map.xpm", tutorial);
		if (!bg.img_ptr)
			return (2);
		put_img_to_img(base_image, bg, 0, 0);
	}
	{
		ring = new_file_img("ring.xpm", tutorial);
		if (!ring.img_ptr)
			return (2);
		put_img_to_img(base_image, ring, 50, 100);
	}
	mlx_put_image_to_window (base_image.win.mlx_ptr, base_image.win.win_ptr, base_image.img_ptr, 0, 0);
	mlx_loop(tutorial.mlx_ptr);
	mlx_destroy_window(tutorial.mlx_ptr, tutorial.win_ptr);
	return (0);
}
