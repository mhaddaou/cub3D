#include "../../headers/cub3d.h"



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void ft_print(t_cub cub, int i, int j, int color)
{
    int l = 0;
    int t;
    i++;
    j++;
    int x = i * 80;
    int y = j * 40;
    while (l < x)
    {
        t = 0;
        while (t < y)
        {
            my_mlx_pixel_put(&cub.data, t,l,color);
            t++;
            
        }
        l++;
    }
}

void check_map_and_print(t_cub cub, int c1, int c2)
{
    int i = 0 ;
    int j;

    while (i < cub.map_height / 80)
    {
        j = 0;
        while (j < cub.map_width / 40)
        {
            if (cub.map[i][j] == '1')
            {
                ft_print(cub, i, j, c1);
                j++;
            }
            if (cub.map[i][j] == '0')
            {
                ft_print(cub,i,j, c2);
            }
            j++;
        }
        i++;
    }

    
}
void print_element(t_cub cub, int x, int y, int color)
{
    int i = 0;
    while (i < y)
    {
        int j = 0;
        while (j < y)
        {
            my_mlx_pixel_put(&cub.data, j, i, color);
            j++;
        }
        i++;
    }
}


void    background(t_cub cub, int color)
{
    int i;
    int j;

    i = 0;
    while (i < cub.map_height)
    {
        j = 0;
        while (j < cub.map_width)
        {
            my_mlx_pixel_put(&cub.data, j, i, color);
            j++;
        }
        i++;
    }
}
void check_and_print(t_cub cub, int cb, int cw)
{
    cub.i = 0;
	cub.y = 80;
	while (cub.i < cub.map_height / 80)
	{
		cub.j = 0;
		cub.x = 40;
		while (cub.j < cub.map_width / 40)
		{
			
			if (cub.map[cub.i][cub.j] == '1')
				print_element(cub,cub.x, cub.y, cb);
            if (cub.map[cub.i][cub.j] == '0')
                print_element(cub,cub.x, cub.y, cw );

			cub.x += 40;
			cub.j++;
		}
		cub.y += 80;
		cub.i++;
	}
}

// void printtt(t_cub cub)
// {
//     cub.p_x += 1;
//     cub.p_y += 1;
//     int x = 0;
//     int y ;
//     while (x < 20)
//     {
//         y = 0;
//         while (y < 20)
//         {
//             my_mlx_pixel_put(&cub.data, cub.p_y, cub.p_x, WHITE_PIXEL);
//             y++;
//         }
//         x++;
//     }
    
    
// }

int ground(t_cub all)
{
    // background(all, GREEN_PIXEL);
    // check_and_print(all, BLACK_PIXEL, WHITE_PIXEL);
    int i = 0;
    int j;
    while (i < all.map_height * 30)
    {
        j = 0;
        while (j < all.map_width * 30)
        {
            my_mlx_pixel_put(&all.data, j,i, GREEN_PIXEL);
            j++;
        } 
        i++;
        mlx_put_image_to_window(all.mlx, all.win, all.data.img,0,0);
        // mlx_clear_window(all.mlx, all.win);   
    }
    // mlx_clear_window(all.mlx,all.win);
    return (0);
}
int len(t_cub cub)
{
    int i = 0;
    while (cub.map[1][i])
        i++;
    return (i);
}
int len_y(t_cub cub)
{
    int i = 0;
    while (cub.map[i])
        i++;
    return (i);
}
void    setup(t_cub *cub)
{
    cub->player.width = 5;
    cub->player.height = 5;
    cub->player.turnDirection = 0;
    cub->player.walkDirection = 0;
    cub->player.rotationAngle = PI / 2;
    cub->player.walkSpeed = 100;
    cub->player.turnSpeed = 45 * (PI / 180); 
}
void renderMap(t_cub cub, int x, int y, int color)
{
    int x1;
    x1 = cub.y + 1;
    
    while (cub.x < x)
    {
        cub.y = x1;
        while (cub.y < y )
        {
            my_mlx_pixel_put(&cub.data, cub.y,cub.x, color);
            cub.y++;
        }
        cub.x++;
    }
    
    mlx_put_image_to_window(cub.mlx, cub.win, cub.data.img, 0, 0);
    // printf("%d\n", cub.map_width);
    // printf("kdjf\n");
    // mlx_clear_window(cub.mlx, cub.win);
    
}
void giVal(t_cub cub, int i, int j, int color, int p)
{
    int x, y;
    if (p == 0)
    {
        cub.x = i * 30;
        cub.y = j * 30;
        x = cub.x + 30;
        y = cub.y + 30;    
    }
    renderMap(cub, x , y , color);
    
}
void printPlayer( t_cub cub)
{
    int x = cub.player.x;
}
void check_map(t_cub cub)
{
    printPlayer(cub);
    int i;
    int j;

    i = 0;
    while (cub.map[i])
    {
        j = 0;
        while (cub.map[i][j])
        {
            if (cub.map[i][j] == '1')
                giVal(cub, i, j, WHITE_PIXEL, 0);
            if (cub.map[i][j] == '0')
                giVal(cub, i, j, GREEN_PIXEL, 0);
            j++;
        }
        i++;
    }    
}
int len_height(t_cub cub)
{
    int i = 0;
    while (cub.map[i])
        i++;
    return (i);
}
void calculateY(t_cub *cub)
{
    float x = sin(cub->player.rotationAngle);
    printf("%f", x);

    float y = cub->player.y * sin(cub->player.rotationAngle) * 30;
    // printf("%f\n",y );
}

void put_player(t_cub *cub)
{
    // calculateY(&cub);
    float x = (cub->player.x * 30) + (cos(cub->player.rotationAngle) * 30);
    float y = x + (cub->player.x * 30) + (cos(cub->player.rotationAngle) * 30);
    printf("%f\n", cub->player.x * 30);
    printf("%f\n", x);
    
    while (x < (cub->player.x * 30) + 100)
    {
        my_mlx_pixel_put(&cub->data, x, cub->player.y * 30, RED_PIXEL);
        x++;
    }
    mlx_put_image_to_window(cub->mlx, cub->win, cub->data.img, 0, 0);
}

void    initializeWindow(t_cub cub)
{
    // renderMap()
    
    cub.mlx = mlx_init();
    
    cub.win = mlx_new_window(cub.mlx, 1500, 1000 , "cub");
    if (!cub.win)
        ft_strerror(3);
    cub.data.img = mlx_new_image(cub.mlx, 1500, 1000);
    cub.data.addr = mlx_get_data_addr(cub.data.img,&cub.data.bits_per_pixel, &cub.data.line_length, &cub.data.endian);
    cub.map_width = (int)ft_strlen(cub.map[0]);
    cub.map_height = len_height(cub);
    ground(cub);
    check_map(cub);
    getPosition(&cub);
    // printf("%f\n", cub.player.x);
    // printf("%f\n", cub.player.y);
    setup(&cub);
    ddaAlgo(cub, 10*30,10*30, 4*30,4*30);
    // put_player(&cub);
    // ground(cub);
    // mlx_loop_hook(cub.mlx, &ground, &cub);
    
    mlx_loop(cub.mlx);
}