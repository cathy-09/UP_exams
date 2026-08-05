//Bahti prostotiqta

#include <iostream>
#include <cmath>

double myAbs(double num) {
    return num > 0 ? num : -num;
}

double sqrt_a(double a, double eps) {
    double xk = a;
    double xk1 = 0.5 * (xk + a / xk);

    while (myAbs(xk1 - xk) >= eps) {
        xk = xk1;
        xk1 = 0.5 * (xk + a / xk);
    }

    return xk1;
}

int main() {
    double a = 25.0;
    double eps = 0.0001;

    double actual = sqrt_a(a, eps);
    double expected = std::sqrt(a);

    std::cout << "Testing sqrt_a function:" << std::endl;
    std::cout << "Number (a): " << a << std::endl;
    std::cout << "Actual value: " << actual << std::endl;
    std::cout << "Expected value: " << expected << std::endl;

    return 0;
}
