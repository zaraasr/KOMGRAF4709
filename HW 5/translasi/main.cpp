#include <GL/glut.h>

// Koordinat titik-titik awal
GLfloat point1[2] = {1.0, 3.0};
GLfloat point2[2] = {6.0, 9.0};

// Faktor translasi
GLfloat translateX = 2.0; // Ubah sesuai kebutuhan
GLfloat translateY = 2.0; // Ubah sesuai kebutuhan

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

    // Translasi
    point1[0] += translateX;
    point1[1] += translateY;
    point2[0] += translateX;
    point2[1] += translateY;

    // Gambar garis setelah translasi (biru)
    glColor3f(0.0, 0.0, 1.0); // Warna biru
    drawLine(point1[0], point1[1], point2[0], point2[1]);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Translasi Titik ke Garis");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0.0, 20.0, 0.0, 20.0); // Sesuaikan dengan jangkauan koordinat yang diperlukan
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
