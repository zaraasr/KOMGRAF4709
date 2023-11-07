#include <GL/glut.h>
#include <math.h>

// Koordinat titik-titik awal
GLfloat point1[2] = {9.0, 6.0};
GLfloat point2[2] = {7.0, 3.0};

// Sudut rotasi dalam derajat
GLfloat rotationAngle = 45.0; // Ubah sesuai kebutuhan

// Fungsi untuk menggambar garis
void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// Fungsi display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Warna merah

    // Gambar garis titik awal (merah)
    drawLine(point1[0], point1[1], point2[0], point2[1]);

    // Rotasi
    GLfloat radians = (rotationAngle * M_PI) / 180.0;
    GLfloat tempX1 = point1[0];
    GLfloat tempY1 = point1[1];
    point1[0] = tempX1 * cos(radians) - tempY1 * sin(radians);
    point1[1] = tempX1 * sin(radians) + tempY1 * cos(radians);

    GLfloat tempX2 = point2[0];
    GLfloat tempY2 = point2[1];
    point2[0] = tempX2 * cos(radians) - tempY2 * sin(radians);
    point2[1] = tempX2 * sin(radians) + tempY2 * cos(radians);

    // Gambar garis setelah rotasi (biru)
    glColor3f(0.0, 0.0, 1.0); // Warna biru
    drawLine(point1[0], point1[1], point2[0], point2[1]);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotasi Titik ke Garis");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0); // Sesuaikan dengan jangkauan koordinat yang diperlukan
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
