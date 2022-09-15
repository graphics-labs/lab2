#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init();
void resize(int width, int height);
void display();   // отрисовка всего поля
void draw_map();  // отрисовка разделителей секторов
void display_sector_1();  // отрисовка всех секторов
void display_sector_2();
void display_sector_3();
void display_sector_4();
void draw_triangle(
    int x1, int y1, int x2, int y2, GLdouble r, GLdouble g,
    GLdouble b);  // вспомогательная функция - отрисовка треугольника из 0,0
                  // сделана только для отрисовки веера в 4 секторе
void draw_rectangle(
    int top, int bottom, int left, int right, GLdouble r, GLdouble g,
    GLdouble b);  // вспомогательная функция - отрисовка четырехугольника
                  // сделана только для отрисовки фигуры в 4 секторе

void draw_text_on_sectors();  // ДОПОЛНИТЕЛЬНО - вывод текста
void drawString(GLdouble x, GLdouble y, char* string);

int main(int argc, char** argv) {
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

  display_sector_1();
  display_sector_2();
  display_sector_3();
  display_sector_4();

  draw_text_on_sectors();
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

void draw_triangle(int x1, int y1, int x2, int y2, GLdouble r, GLdouble g,
                   GLdouble b) {
  glBegin(GL_TRIANGLES);
  {
    glColor3d(r, g, b);

    glVertex2d(0, 0);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
  }
  glEnd();
}

void draw_rectangle(int top, int bottom, int left, int right, GLdouble r,
                    GLdouble g, GLdouble b) {
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

void display_sector_1() {
  glViewport(400, 400, 400, 400);

  draw_rectangle(5, 3, -5, -3, 0.58, 0.21, 0.13);
  draw_rectangle(3, 1, -5, -3, 0.24, 0.81, 0.28);
  draw_rectangle(1, -1, -5, -3, 0.85, 0.11, 0.95);
  draw_rectangle(-1, -3, -5, -3, 0.71, 0.64, 0.29);

  draw_triangle(2, 4, 3, 3, 1, 0, 0);
  draw_triangle(3, 3, 3, 2, 0, 1, 0);
  draw_triangle(3, 2, 3, 0, 0, 0, 1);
  draw_triangle(3, 0, 3, -1, 1, 0, 0);
  draw_triangle(3, -1, 2, -2, 0, 1, 0);
  draw_triangle(2, -2, 1, -3, 0, 0, 1);

  glDisable(GL_LINE_STIPPLE);
  glDisable(GL_LINE_SMOOTH);
}

void display_sector_2() {
  glViewport(0, 400, 400, 400);
  glPointSize(10);

  glBegin(GL_LINES);
  {                      // рисуем линии
    glColor3d(1, 1, 0);  // желтая линия
    glVertex2d(-5, -1);
    glVertex2d(4, 5);

    glColor3d(0, 1, 0);  // зеленая линия
    glVertex2d(-2, -2);
    glVertex2d(5, 3);
  }
  glEnd();

  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1, 50055);

  glBegin(GL_LINE_STRIP);
  {                      // рисуем прерывистые линии
    glColor3d(1, 0, 0);  // красная прерывистая линия
    glVertex2d(-4, 4);
    glVertex2d(5, -3);
  }
  glEnd();

  glDisable(GL_LINE_STIPPLE);
  glDisable(GL_LINE_SMOOTH);
}

void display_sector_3() {
  glViewport(0, 0, 400, 400);  // выделили область экрана для отрисовки
  glPointSize(10);

  glBegin(GL_POINTS);
  {                      // рисуем точки
    glColor3d(1, 0, 0);  // красная квадратная
    glVertex2d(3, 3);

    glColor3d(0, 1, 0);  // зеленая квадратная
    glVertex2d(3, -4);
  }
  glEnd();

  glEnable(GL_POINT_SMOOTH);
  {  // рисуем круглые точки
    glBegin(GL_POINTS);
    {
      glColor3d(1, 1, 0);  // желтая круглая
      glVertex2d(-3, 4);
    }
    glEnd();

    glPointSize(20);
    glBegin(GL_POINTS);
    {                      // рисуем круглые точки
      glColor3d(0, 0, 1);  // желтая круглая
      glVertex2d(-5, -5);
    }
    glEnd();
  }
  glDisable(GL_POINT_SMOOTH);
}

void display_sector_4() {
  glViewport(400, 0, 400, 400);

  glBegin(GL_LINE_STRIP);
  {
    glColor3d(1, 1, 1);

    glVertex2d(-5, 4);
    glVertex2d(-3, 5);
    glVertex2d(-3, 3);
    glVertex2d(-5, 2);
    glVertex2d(-2, 5);
    glVertex2d(-2, 2);
  }
  glEnd();

  glBegin(GL_TRIANGLES);
  {
    glColor3d(0, 0, 1);

    glVertex2d(2, 4);
    glVertex2d(4, 5);
    glVertex2d(2, 5);
  }
  glEnd();

  glBegin(GL_QUADS);
  {
    glColor3d(1, 0.5, 0);

    glVertex2d(-4, -3);
    glVertex2d(1, -1);
    glVertex2d(4, -4);
    glVertex2d(0, -5);
  }
  glEnd();
}

void draw_text_on_sectors() {  // ДОПОЛНИТЕЛЬНО - вывод текста
  glViewport(400, 400, 400, 400);
  glColor3d(1, 1, 1);
  char sec1[] = "sector_1";
  drawString(-1, -4, sec1);

  glViewport(0, 400, 400, 400);
  glColor3d(1, 1, 1);
  char sec2[] = "sector_2";
  drawString(-1, -2, sec2);

  glViewport(0, 0, 400, 400);
  glColor3d(1, 1, 1);
  char sec3[] = "sector_3";
  drawString(1, 0, sec3);

  glViewport(400, 0, 400, 400);
  glColor3d(1, 1, 1);
  char sec4[] = "sector_4";
  drawString(0, 0, sec4);
}

void drawString(GLdouble x, GLdouble y, char* string) {
  glRasterPos2d(x, y);

  for (char* c = string; *c != '\0'; c++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
  }
}