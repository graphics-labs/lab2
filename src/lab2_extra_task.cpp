#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <cmath>

void init();
void resize(int width, int height);
void draw_ellipse(GLdouble big_radius, GLdouble small_radius, GLdouble x, GLdouble y, GLdouble r, GLdouble g, GLdouble b);
void display();
void draw_map();

void draw_rectangle(
	GLdouble top, GLdouble bottom,
	GLdouble left, GLdouble right,
	GLdouble r, GLdouble g, GLdouble b);

void draw_quadrilateral(
	GLdouble x1, GLdouble y1,
	GLdouble x2, GLdouble y2,
	GLdouble x3, GLdouble y3,
	GLdouble x4, GLdouble y4,
	GLdouble r, GLdouble g, GLdouble b);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(50, 10);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Lab2");
	glutReshapeFunc(resize);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

void init()
{
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-7, 7, -7, 7, 2, 12);

	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}

void resize(int width, int height) {}

void display()
{
	draw_map();

	draw_rectangle(
		2.5, -5,
		-3.5, -2,
		1, 1, 1);

	draw_rectangle(
		3.5, 2.5,
		-5, 3,
		1, 1, 1);

	draw_quadrilateral(
		-3.5, -3.25,
		-3.5, -5,
		-5, -5,
		-4, -4.4,
		1, 1, 1);

	draw_quadrilateral(
		-5, 2.5,
		-4.15, 2.1,
		-3.5, 1,
		-3.5, 2.5,
		1, 1, 1);

	draw_quadrilateral(
		1.8, 2.5,
		2.5, 2.15,
		3, 1.5,
		3, 2.5,
		1, 1, 1);

	draw_ellipse(4, 2, -2, -2, 0, 0, 0);
	draw_ellipse(5, 3, -2, -2, 1, 1, 1);

	glEnd();

	glFlush();
}

void draw_ellipse(GLdouble big_radius, GLdouble small_radius, GLdouble x, GLdouble y, GLdouble r, GLdouble g, GLdouble b)
{

	glBegin(GL_POLYGON);

	glColor3d(r, g, b);

	for (GLdouble i = -M_PI_2; i <= M_PI_2; i += 0.001)
		glVertex2d((cos(i) * big_radius) + x, (sin(i) * small_radius) + y);

	glEnd();
}

void draw_map()
{
	glViewport(0, 0, 800, 800);

	glBegin(GL_LINES);

	glColor3d(1, 1, 1);

	glVertex2d(-400, 0);
	glVertex2d(400, 0);

	glVertex2d(0, -400);
	glVertex2d(0, 400);

	glEnd();
}

void draw_rectangle(
	GLdouble top, GLdouble bottom,
	GLdouble left, GLdouble right,
	GLdouble r, GLdouble g, GLdouble b)
{
	glBegin(GL_QUADS);

	glColor3d(r, g, b);

	glVertex2d(left, top);
	glVertex2d(right, top);
	glVertex2d(right, bottom);
	glVertex2d(left, bottom);

	glEnd();
}

void draw_quadrilateral(
	GLdouble x1, GLdouble y1,
	GLdouble x2, GLdouble y2,
	GLdouble x3, GLdouble y3,
	GLdouble x4, GLdouble y4,
	GLdouble r, GLdouble g, GLdouble b)
{
	glBegin(GL_TRIANGLES);

	glColor3d(r, g, b);

	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glVertex2d(x4, y4);

	glVertex2d(x2, y2);
	glVertex2d(x3, y3);
	glVertex2d(x4, y4);

	glEnd();
}
