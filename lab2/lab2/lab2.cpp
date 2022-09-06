#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define field_size 800
#define sector_size 400

void init(void);
void resize(int width, int height);
void display(void);
void draw_map();
void display_sector_1();
void display_sector_2();
void display_sector_3();
void display_sector_4();

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

void init(void) {
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

void  display(void) {
    draw_map();
    
    display_sector_1();
    display_sector_2();
    display_sector_3();
    display_sector_4();
    glFlush();
}

void draw_map() {
    glViewport(0, 0, 800, 800);

    glBegin(GL_LINES); {
        glColor3d(1, 1, 1);
        glVertex2d(-400, 0);
        glVertex2d(400, 0);

        glVertex2d(0, -400);
        glVertex2d(0, 400);
    } glEnd();
}

void display_sector_1() {
    glViewport(400, 400, 400, 400);
}

void display_sector_2() {
    glViewport(0, 400, 400, 400);
    glPointSize(10);

    glBegin(GL_LINES); { // рисуем линии
        glColor3d(1, 1, 0); // желтая линия
        glVertex2d(-5, -1);
        glVertex2d(4, 5);

        glColor3d(0, 1, 0); // зеленая линия
        glVertex2d(-2, -2);
        glVertex2d(5, 3);
    } glEnd();

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 50055);

    glBegin(GL_LINE_STRIP); { // рисуем прерывистые линии
        glColor3d(1, 0, 0); // красная прерывистая линия
        glVertex2d(-4, 4);
        glVertex2d(5, -3);
    } glEnd();

    glDisable(GL_LINE_STIPPLE);
    glDisable(GL_LINE_SMOOTH);
}
void display_sector_3() {
    glViewport(0, 0, 400, 400); // выделили область экрана для отрисовки
    glPointSize(10);
    
    glBegin(GL_POINTS); { // рисуем точки
        glColor3d(1, 0, 0); // красная квадратная
        glVertex2d(3, 3);

        glColor3d(0, 1, 0); // зеленая квадратная
        glVertex2d(3, -4);
    } glEnd();

    glEnable(GL_POINT_SMOOTH); { // рисуем круглые точки
        glBegin(GL_POINTS); {
            glColor3d(1, 1, 0); // желтая круглая
            glVertex2d(-3, 4);
        } glEnd();

        glPointSize(20);
        glBegin(GL_POINTS); { // рисуем круглые точки
            glColor3d(0, 0, 1); // желтая круглая
            glVertex2d(-5, -5);
        } glEnd();
    } glDisable(GL_POINT_SMOOTH);
}
void display_sector_4() {
    glViewport(400, 0, 400, 400);
   
    glBegin(GL_LINE_STRIP); {
        glColor3d(1, 1, 1);

        glVertex2d(-5, 4);
        glVertex2d(-3, 5);
        glVertex2d(-3, 3);
        glVertex2d(-5, 2);
        glVertex2d(-2, 5);
        glVertex2d(-2, 2);
    } glEnd();

    glBegin(GL_TRIANGLES); {
        glColor3d(0, 0, 1);

        glVertex2d(2, 4);
        glVertex2d(4, 5);
        glVertex2d(2, 5);
    } glEnd();

    glBegin(GL_QUADS); {
        glColor3d(1, 0.5, 0);

        glVertex2d(-4, -3);
        glVertex2d(1, -1);
        glVertex2d(4, -4);
        glVertex2d(0, -5);
    } glEnd();
}
