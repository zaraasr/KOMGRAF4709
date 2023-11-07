#include <GL/glut.h>

// Koordinat titik-titik awal
GLfloat point1[2] = {9.0, 6.0};
GLfloat point2[2] = {7.0, 3.0};

// Faktor skala
GLfloat scaleX = 1.5; // Ubah sesuai kebutuhan
GLfloat scaleY = 0.5; // Ubah sesuai kebutuhan

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

    // Skala
    point1[0] *= scaleX;
    point1[1] *= scaleY;
    point2[0] *= scaleX;
    point2[1] *= scaleY;

    // Gambar garis setelah scaling (biru)
    glColor3f(0.0, 0.0, 1.0); // Warna biru
    drawLine(point1[0], point1[1], point2[0], point2[1]);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Scaling Titik ke Garis");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0.0, 20.0, 0.0, 20.0); // Sesuaikan dengan jangkauan koordinat yang diperlukan
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
