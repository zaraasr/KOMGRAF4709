#include <iostream>
#include <cmath>


void koorGaris(int x1, int y1, int x2, int y2){
    // Steps 1
    float dx = x2 - x1;
    float dy = y2 - y1;

    // Steps 2
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    //
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    //
    float x = x1;
    float y = y1;

    //
    std::cout << "Titik pada garis:\n";
    for (int i = 0; i <= steps; i++){
        std::cout << "(" << round(x) << ", " << round(y) << ")\n";
        x += xIncrement;
        y += yIncrement;
    }
}

int main()
{
    int x1, y1, x2, y2;

    std::cout << "Masukkan koordinat titik pertama (x1, y1): ";
    std::cin >> x1 >> y1;

    std::cout << "Masukkan koordinat titik kedua (x2, y2):";
    std::cin >> x2 >> y2;

    koorGaris(x1, y1, x2, y2);

    return 0;
}
