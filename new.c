/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 15:09:38 by oposhiva          #+#    #+#             */
/*   Updated: 2017/08/07 15:09:42 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <GLUT/GLUT.h>

void *font = GLUT_BITMAP_HELVETICA_18;

char	*str;

void	draw_string_bitmap(void *font, const char* str)
{
	int		i;
	float	x;
	float	y;

	i = 1;
	x = -0.98;
	y = 0.93;
	while (*str)
	{
		glRasterPos2f(x, y);
		glutBitmapCharacter(font, *str++);
		glutBitmapCharacter(font, *str++);
		if (i % 32 == 0)
		{
			y -= 0.03;
			x = -1.02;
		}
		x += 0.04;
		i++;
	}
}

void	renderScene(void) {
 
	// очистить буфер цвета и глубины.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// обнулить трансформацию
	glLoadIdentity();
	// установить камеру
	glColor3f(0.4, 0.4, 0.4);
	glLineWidth(10);
	glPointSize(8);
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINE_LOOP);
		glVertex2d(-0.99, 0.98);
		glVertex2d(0.60, 0.98);
		glVertex2d(0.60, -0.98);
		glVertex2d(-0.99, -0.98);
	glEnd();
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
		glVertex2d(-0.99, 0.98);
		glVertex2d(0.60, 0.98);
		glVertex2d(0.60, -0.98);
		glVertex2d(-0.99, -0.98);
	glEnd();
	glColor3f(0, 1, 1);
	glLineWidth(17);
	glBegin(GL_LINES);
		glColor3f(0, 0, 1);
		glVertex2d(-0.98, 0.94);
		glColor3f(0, 1, 0);
		glVertex2d(-0.92, 0.94);
		glVertex2d(-0.98, 0.91);
		glColor3f(1, 0, 0);
		glVertex2d(-0.92, 0.91);	
	glEnd();
	glColor3f(0.7, 0.7, 0.7);
	draw_string_bitmap(font, str);
	glutSwapBuffers();
}
 
void	processNormalKeys(unsigned char key, int x, int y) {
 
	if (key == 27)
		exit(0);
}

int		main(int argc, char **argv)
{
	// инициализация
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(5120,2880);
	glutCreateWindow("COREWAR");
	
	str = (char*)malloc(sizeof(char) * 4096 + 1);
	for (int i = 0; i < 4096; i++)
		str[i] = '0';
	// регистрация
	glutDisplayFunc(renderScene);

	// наши новые функции
	glutKeyboardFunc(processNormalKeys);

	// основной цикл
	glutMainLoop();

	return 1;
}
