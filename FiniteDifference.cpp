#include <iostream>
#include <cmath>

void FiniteDifference(int N, double h) {
    double *u = new double[N + 1];
    double *x = new double[N + 1];

    u[0] = 0.0;
    u[N] = 1.0;

    for (int i = 0; i <= N; ++i) {
        x[i] = i * h;
    }

    for (int i = 1; i < N; ++i) {
        u[i + 1] = 2 * u[i] - u[i - 1] + h * h * (std::pow(u[i], 3) - std::sin(x[i]));
    }

    std::cout << "Solution:\n";
    for (int i = 0; i <= N; ++i) {
        std::cout << "u(" << x[i] << ") = " << u[i] << std::endl;
    }

    delete[] u;
    delete[] x;
}

int main() {
    int N = 1000;
    double h = 1.0/1000.0; 

    FiniteDifference(N, h);

    return 0;
}
