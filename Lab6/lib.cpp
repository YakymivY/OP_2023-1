#include "lib.h"

using namespace std;

int hashh (int key, int size) {
    const double A = 0.6180339887;
    double product = static_cast<double>(key) * A;
    product -= static_cast<int>(product);
    return static_cast<int>(product * size);
}