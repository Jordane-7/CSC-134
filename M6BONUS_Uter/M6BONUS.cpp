#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    const int width = 300;
    const int height = 360;

    ofstream img("bishop_5.ppm");

    // PPM header
    img << "P3\n";
    img << width << " " << height << "\n";
    img << "255\n";

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            // Normalized coordinates (upright)
            double nx = (x - width / 2.0) / (width / 2.0);
            double ny = (height / 2.0 - y) / (height / 2.0);

            // Base
            bool base1 = (fabs(nx) < 0.45 && ny < -0.75 && ny > -0.9);
            bool base2 = (fabs(nx) < 0.35 && ny < -0.65 && ny > -0.75);
            bool base = base1 || base2;

            // Body
            bool body = (fabs(nx) < (0.3 - 0.2 * (ny + 0.2)) && ny > -0.6 && ny < 0.3);

            // Head
            bool head = (nx * nx + pow(ny - 0.40, 2)) < 0.035;

            // Top ball
            bool ball = (nx * nx + pow(ny - 0.65, 2)) < 0.01;

            // ✅ SHORTER SLIT (ONLY CHANGE)
            bool cut =
                (ny > 0.35 && ny < 0.60 && fabs(nx - ny * 0.25) < 0.035);

            bool bishopShape = (base || body || head || ball) && !cut;

            int r, g, b;

            if (bishopShape) {
                r = 40;
                g = 40;
                b = 40;
            } else {
                r = 255;
                g = 255;
                b = 255;
            }

            img << r << " " << g << " " << b << " ";
        }
        img << "\n";
    }

    img.close();

    cout << "PPM image created: bishop.ppm\n";
    return 0;
}
