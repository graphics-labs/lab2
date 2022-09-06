#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//#define field_size 800
//#define sector_size 400

// void init(void);
// void resize(int width, int height);
// void  display(void);
// void display_sector_1();
// void display_sector_2();
// void display_sector_3();
// void display_sector_4();

// int main(int argc, char** argv) {
// glutInit(&argc, argv);
// glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
// glutInitWindowPosition(50, 10);
// glutInitWindowSize(800, 800);
// glutCreateWindow("Hello");
// glutReshapeFunc(resize);
// init();
// glutDisplayFunc(display);
// glutMainLoop();
// return 0;
//}

// void init(void) {
// glEnable(GL_COLOR_MATERIAL);
// glEnable(GL_LIGHTING);
// glEnable(GL_LIGHT0);
// glEnable(GL_DEPTH_TEST);
// glClearColor(0.0, 0.0, 0.0, 0.0);
// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// glMatrixMode(GL_PROJECTION);
// glLoadIdentity();
// glOrtho(-7, 5, -7, 5, 2, 12);

// gluLookAt(0, 0, 5, 0, 1, 0, 0, 1, 0);
// glMatrixMode(GL_MODELVIEW);
//}

// void resize(int width, int height) {}

// void  display(void) {

// display_sector_1();
// display_sector_2();
// display_sector_3();
// display_sector_4();
// glFlush();

//}

// void display_sector_1() {
//}

// void display_sector_2() {

// glViewport(0, 400, 400, 400);
// glPointSize(10);

// glBegin(GL_LINES);{ // рисуем линии

// glColor3d(255, 255, 0); // желтая линия%
// glVertex2d(-5, - 1);
// glVertex2d(4, 5);

// glColor3d(0, 255, 0); // зеленая линия
// glVertex2d(-2, -2);
// glVertex2d(5, 3);
//} glEnd();

// glEnable(GL_LINE_SMOOTH);
// glEnable(GL_LINE_STIPPLE);
// glLineStipple(1, 50055);

// glBegin(GL_LINE_STRIP); { // рисуем прерывистые линии

// glColor3d(255, 0, 0); // красная прерывистая линия
// glVertex2d(-4, 4);
// glVertex2d(5, -3);

//} glEnd();

// glDisable(GL_LINE_STIPPLE);
// glDisable(GL_LINE_SMOOTH);
//}

// void display_sector_3() {
// glBegin(GL_POINTS); { // рисуем линии

// glColor3d(255, 255, 0); // желтая линия%
// glVertex2d(-5, -1);
// glVertex2d(4, 5);

// glColor3d(0, 255, 0); // зеленая линия
// glVertex2d(-2, -2);
// glVertex2d(5, 3);
//} glEnd();
//}

// void display_sector_4() {}

void resize(int width, int height) {}

void display(void) {
  glRotatef(30, 0, 40, 100);

  glColor3d(1, 1, 0);
  glViewport(0, 0, 400, 400);
  glutSolidTeapot(2);

  glColor3d(0, 1, 1);
  glViewport(400, 0, 400, 400);
  glutSolidTorus(1, 2, 40, 16);

  glColor3d(1, 0, 1);
  glViewport(400, 400, 400, 400);
  glutSolidCube(3);

  glColor3d(1, 1, 1);
  glViewport(0, 400, 400, 400);
  glutSolidSphere(2, 40, 16);
  glFlush();
}
void init(void) {
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-5.0, 5.0, -5.0, 5.0, 2.0, 12.0);
  gluLookAt(0, 0, 5, 0, 1, 0, 0, 1, 0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(50, 10);
  glutInitWindowSize(800, 800);
  glutCreateWindow("Hello");
  glutReshapeFunc(resize);
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
