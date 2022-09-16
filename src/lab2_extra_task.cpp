#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <cmath>

void init();
void resize(int width, int height);
void display();   // отрисовка всего поля
void draw_map();  // отрисовка разделителей секторов

void draw_triangle(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2,
                   GLdouble x3, GLdouble y3, GLdouble r, GLdouble g,
                   GLdouble b);
void draw_rectangle(GLdouble top, GLdouble bottom, GLdouble left,
                    GLdouble right, GLdouble r, GLdouble g, GLdouble b);

int main(int argc, char** argv) {
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

void init() {
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

void display() {
  draw_map();

  draw_rectangle(3.5, 2.5, -5, 3, 0.99, 0.14, 0.29);
  draw_triangle(2, 2.5, 3, 2.5, 3, 1.5, 0.21, 0.3, 0.46);

  draw_rectangle(2.5, -5, -3.5, -2, 0.29, 0.81, 0.44);
  draw_triangle(-5, 2.5, -2, 2.5, -2, 1, 0.71, 0.39, 0.126);
  draw_triangle(-3, 2.5, -2, 2.5, -3, 1, 0.34, 0.5, 0.36);
  // -5 -2 start

  glColor3d(1, 1, 0);

  glBegin(GL_POLYGON);
  {
    // GLdouble x = -5, y = -2;

    double angle = 0.0f;
    int points = 1000;
    for (int i = 1; i < points; i++) {
      angle = M_PI * i / points;

      // glVertex2d((cos(angle) - 2), (sin(angle) - 3));
    }
  }

  float radius = 3;
  for (float i = 0.0; i <= M_PI; i += 0.001)
    glVertex2d((sin(i) * radius * 1.9) - 3, (cos(i) * radius) - 2);

  glEnd();

  // display_sector_1();

  glFlush();
}

void draw_map() {
  glViewport(0, 0, 800, 800);

  glBegin(GL_LINES);
  {
    glColor3d(1, 1, 1);
    glVertex2d(-400, 0);
    glVertex2d(400, 0);

    glVertex2d(0, -400);
    glVertex2d(0, 400);
  }
  glEnd();
}

void draw_triangle(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2,
                   GLdouble x3, GLdouble y3, GLdouble r, GLdouble g,
                   GLdouble b) {
  glBegin(GL_TRIANGLES);
  {
    glColor3d(r, g, b);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glVertex2d(x3, y3);
  }
  glEnd();
}

void draw_rectangle(GLdouble top, GLdouble bottom, GLdouble left,
                    GLdouble right, GLdouble r, GLdouble g, GLdouble b) {
  glBegin(GL_QUADS);
  {
    glColor3d(r, g, b);

    glVertex2d(left, top);
    glVertex2d(right, top);
    glVertex2d(right, bottom);
    glVertex2d(left, bottom);
  }
  glEnd();
}
