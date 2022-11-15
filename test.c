#include "inc/fractol.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int	mouse_hook(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
}

int	main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
