POUR DESSINER UN SOLEIL AVEC LA SOURIS

main//
//	point.x0 = 50;
//	point.x1 = 50;
//	point.y0 = 200;
//	point.y1 = 20;
//
//	plot_line(point.x0, point.y0, point.x1, point.y1, &data);

mlx_mouse_hook(vars.win_ptr, ft_mouse_line, &data);

--

events
int ft_mouse_line(int button, int x1, int y1, t_data *data)
{

	int x0 = WIDTH / 2;
	int y0 = HEIGH / 2;
	if (button == 1)
	{
		plot_line(x0, y0, x1, y1, data);
		mlx_put_image_to_window(data->vars->mlx_ptr, data->vars->win_ptr, data->img, 0, 0);
	}
	return (0);
}

//---------------------------------------------
//	mlx_hook(vars.win_ptr, 2, 1L<<0, ft_key_close, &vars); pour close



//WKIPEDIA
//point.x1 = 50;
//point.x2 = 800;
//point.y1 = 0;
//point.y2 = 50;
//int dx = point.x2 - point.x1;
//int dy = point.y2 - point.y1;
//int yi = 1;
//
////CAS 1
//if (dy < 0)
//{
//yi = -1;
//dy = -dy;
//}
//int D = (2 * dy) - dx;
//int y = point.y1;
//
//for (point.x1; point.x1 <= point.x2; point.x1++)
//{
//my_mlx_pixel_put(&img, point.x1, point.y1, 0x002ecc71);
//if (D > 0)
//{
//y = y + yi;
//D = D + (2 * (dy - dx));
//}
//else
//D = D + 2 * dy;
//}
//
////---------------------------------------------
////CAS 2
//int xi = 1;
//if (dx < 0)
//{
//xi = -1;
//dx = -dx;
//}
//D = (2 * dx) - dy;
//int x = point.x1;
//
//for (point.y1; point.y1 <= point.y2; point.y1++)
//{
//my_mlx_pixel_put(&img, point.x1, point.y1, 0x002ecc71);
//if (D > 0)
//{
//x = x + xi;
//D = D + (2 * (dx - dy));
//}
//else
//D = D + 2 * dx;
//}
//
//// CHOIX DECISION
//if (abs(point.y2 - point.y1) < abs(point.x2 - point.x1))
//{
//if (point.x1 > point.x2)
//my_mlx_pixel_put(&img, point.x1, point.y1, 0x002ecc71); // A REVOIR
//else
//my_mlx_pixel_put(&img, point.x1, point.y1, 0x002ecc71); // A REVOIR
//}
//else
//{
//if (point.y1 > point.y2)
//my_mlx_pixel_put(&img, point.x1, point.y1, 0x002ecc71); // A REVOIR
//else
//my_mlx_pixel_put(&img, point.x1, point.y1, 0x002ecc71); // A REVOIR
//}


// YOUTUBE
//	int x1 = 10;
//	int x2 = 200;
//	int y1 = 10;
//	int y2 = 150;
//	int ex = abs(x2-x1);
//	int ey = abs(y2-y1);
//	int dx = 2*ex;
//	int dy = 2*ey;
//	int Dx = ex;
//	int Dy = ey;
//	int i = 0;
//	int Xincr = 1;
//	int Yincr = 1;
//	if (x1 > x2)
//		Xincr = -1;
//	if (y1 > y2)
//		Yincr = -1;
//
//	if (Dx > Dy)
//	{
//		while (i <= Dx)
//		{
//			my_mlx_pixel_put(&img, x1, y1, 0x002ecc71);
//			i++;
//			x1 += Xincr;
//			ex -= dy;
//			if (ex < 0)
//			{
//				y1 += Yincr;
//				ex += dx;
//			}
//		}
//	}
//	if (Dx < Dy)
//	{
//		while (i <= Dy)
//		{
//			my_mlx_pixel_put(&img, x1, y1, 0x002ecc71);
//			i++;
//			y1 += Yincr;
//			ey -= dx;
//			if (ey < 0)
//			{
//				x1 += Xincr;
//				ey += dy;
//			}
//		}
//	}






// CARRE
//	while (x < 500 )
//	{
//		my_mlx_pixel_put(&img, x, y, 0x00267390);
//		x++;
//	}
//	while (y < 500)
//	{
//		my_mlx_pixel_put(&img, x, y, 0x00267390);
//		y++;
//	}
//	x = 15;
//	while (y > 15)
//	{
//		my_mlx_pixel_put(&img, x, y, 0x00267390);
//		x = 15;
//		while (x < 500)
//		{
//			my_mlx_pixel_put(&img, x, y, 0x00267390);
//			x++;
//		}
//		y--;
//	}



// TRIANGLE NON REMPLI
//while (y < 820 && x > 100)
//{
//my_mlx_pixel_put(&img, x, y, 0x00267390);
//y++;
//x--;
//}
//y = 20;
//x = 250;
//while (y < 1620 && x < 400)
//{
//my_mlx_pixel_put(&img, x, y, 0x00267390);
//y++;
//x++;
//}
//x = 100;
//while (x < 400)
//{
//my_mlx_pixel_put(&img, x, y, 0x00267390);
//x++;
//}


//	TRIANGLE PLEIN
//	int x = 860;
//	int y = 440;
//	int end_x = x + 400;
//	int x_start = x;
//	while (y > 140)
//	{
//		while (x <= end_x)
//		{
//			my_mlx_pixel_put(&img, x, y, 0x00267390);
//			x++;
//		}
//		x_start++;
//		end_x--;
//		x = x_start;
//		y--;
//	}
//	x = 860;
//	y = 440;
//	end_x = x + 400;
//	x_start = x;
//	while (y < 740)
//	{
//		while (x <= end_x)
//		{
//			my_mlx_pixel_put(&img, x, y, 0x002ecc71);
//			x++;
//		}
//		x_start++;
//		end_x--;
//		x = x_start;
//		y++;
//	}

//TRACER UN SEGMENT
//	for (x = 0; x<500; x++)
//	{
//		y = 2*x + y1;
//		my_mlx_pixel_put(&img, x, y, 0x002ecc71);
//	}
