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
