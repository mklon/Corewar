/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nC.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 14:40:58 by oposhiva          #+#    #+#             */
/*   Updated: 2017/08/02 14:41:01 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLUT/GLUT.h>

void display()
{
        glClear(GL_COLOR_BUFFER_BIT);
       
        glColor3ub( 239, 211, 52);
		glRectf(-0.2f, 0.4f, 0.2f, 0.0f);
		glEnd();
       
        glutSwapBuffers();
}

void reshape(int w, int h)
{
        glViewport(0, 0, w, h);
       
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, w, 0, h);
       
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
}

int main (int argc, char * argv[])
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
       
        glutInitWindowSize(800, 600);
        glutCreateWindow("OpenGL lesson 1");
       
        //glutReshapeFunc(reshape);
        glutDisplayFunc(display);
       
        glutMainLoop();
 
        return 0;
}
