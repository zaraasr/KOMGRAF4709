#include <GL/glut.h>
#include <iostream>

using namespace std;

int xn, yn, x0, y0;

void titikKoordinat() {
    glBegin(GL_POINTS);
    // Set warna
    glColor3f(1.0, 2.0, 0.0);

    int dx = xn - x0;
    int dy = yn - y0;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = static_cast<float>(dx) / static_cast<float>(steps);
    float yIncrement = static_cast<float>(dy) / static_cast<float>(steps);

    float x = xn;
    float y = yn;

    for (int i = 0; i <= steps; i++) {
        glVertex2i(x, y);
        x += xIncrement;
        y += yIncrement;
    }

    glEnd();
    glFlush();
}

void tampilan() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    titikKoordinat();
    glFlush();
}

int main(int argc, char** argv)
{
    cout << "Masukkan koordinat x1: ";
    cin >> xn;
    cout << "Masukkan koordinat y1: ";
    cin >> yn;
    cout << "Masukkan koordinat x2: ";
    cin >> x0;
    cout << "Masukkan koordinat y2: ";
    cin >> y0;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Gradien DDA");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);

    glutDisplayFunc(tampilan);
    glutMainLoop();

    return 0;
}
