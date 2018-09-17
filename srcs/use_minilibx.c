/*int	mouse_press(int button, int x, int y, void *param)
{
	(void)param;
	ft_printf("Key press is %d\ncoordinates are %d-%d\n", button, x, y);
	return (0);
}*/

/*	void *init;
	void *window;
	void *image;
	(void)argc;
	init = mlx_init();
	window = mlx_new_window(init, 500, 500, argv[1]);
	image = mlx_new_image(init, 500, 500);

	int bpp, sl, endian;

	int	*array;
	array = (int*)mlx_get_data_addr(image, &bpp, &sl, &endian);
	int i = 75250;
	while (i < 125350)
	{
		array[i] = 0x00BBBB00;
		i = i + 501;
	}
	while (i < 175250)
	{
		array[i] = 0x00791CF8;
		i = i + 499;
	}
	while (i > 125150)
	{
		array[i] = 0x00FF7F00;
		i = i - 501;
	}
	while (i > 75250)
	{
		array[i] = 0x00DE2916;
		i = i - 499;
	}
	mlx_put_image_to_window(init, window, image, 0, 0);
	mlx_mouse_hook(window, mouse_press, (void*)0);
	mlx_loop(init);*/