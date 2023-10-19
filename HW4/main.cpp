#include <GL/glut.h>
#include <iostream>

// Fungsi Bresenham untuk menggambar garis
void BresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    bool slope = dy > dx;

    if (slope) {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }

    if (x1 > x2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    dx = std::abs(x2 - x1);
    dy = std::abs(y2 - y1);
    int error = dx / 2;
    int ystep = (y1 < y2) ? 1 : -1;
    int y = y1;

    glBegin(GL_POINTS);
    for (int x = x1; x <= x2; x++) {
        if (slope) {
            glVertex2i(y, x);  // Jika slope, tukar kembali x dan y
        } else {
            glVertex2i(x, y);
        }

        error = error - dy;
        if (error < 0) {
            y = y + ystep;
            error = error + dx;
        }
    }
    glEnd();
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    BresenhamLine(6, 9, 3, 7);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(30, 200);
    glutCreateWindow("Algoritma Bresenham");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 30.0, 0.0, 200.0);

    glutDisplayFunc(drawScene);
    glutMainLoop();

    return 0;
}
