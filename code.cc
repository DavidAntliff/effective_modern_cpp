#include <future>

double factorial(unsigned int limit) {
    double ret = 1;
    for (unsigned int n = 1; n <= limit; ++n) {
        ret *= n;
    }
    return ret;
}

double main_factorial(int a, int b) {
    auto future1 = std::async(factorial, a);
    auto future2 = std::async(factorial, b);
    double result = future1.get() + future2.get();
    return result;
}
