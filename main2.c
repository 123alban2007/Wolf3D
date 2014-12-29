/*
** main2.c for Wolf3D in /home/meuric_a/Project_Igraph/Wolf3d
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Wed Dec 17 14:59:03 2014 alban meurice
** Last update Mon Dec 29 18:39:18 2014 alban meurice
*/

#include <stdio.h>
#include <math.h>
#include "main2.h"

int	laby[][6] = 
  {
    {1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 1},
    {1, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1},
  };

int	calc_equation(t_pers *sangoku, t_angle *result, t_vector *vector, int x)
{
  float	k;
  int	y;
  float	line_y;

  x = 0;
  y = 0;
  vector->vx = (sangoku->x + 0.5) - sangoku->x;
  vector->vy = (sangoku->y + 0,5) - sangoku->y;
  //printf("(%f, %f)\n", vector->vx, vector->vy);
  while (x <= 6)
    {
      k = (x - sangoku->x) / vector->vx;
      if (k > 0)
	{
	  line_y = sangoku->y + (k * vector->vy);
	  if (laby[x][(int)line_y] == 1)
	    {
	      printf("%f %d %d\n", k, x, (int)line_y);
	      return (0);
	    }
	}
      /*y = 0;
	while (y <= 6)
	{
	  y = sangoku->y + (k * vector->vy);
	  printf("y=%d, k=%f\n", y, k);
	  if (laby[x][y] = 0)
	    printf("'''for y=%d & x=%d / Wall'''\n", y, x);
	  k = k + 1;
	  }*/
      //printf("%f\n", k);
      x = x + 1;
      }
}

int	main()
{
  t_pers	sangoku;
  t_angle	result;
  t_vector	vector;
  float		x;

  x = 640;
  sangoku.x = 2.5;
  sangoku.y = 4.5;
  while (x >= 0)
    {
      result.pix_x = (float)(((640 / 2) - x) / 640) + sangoku.y;
      result.pix_y = (float)(((640 / 2) - x) / 640) + sangoku.x;
      //printf("(%f, %f)\n", (sangoku.x + 0.5), result.pix_x);
      x = x - 1;
    }
  calc_equation(&sangoku, &result, &vector, x);
  return (0);
}
