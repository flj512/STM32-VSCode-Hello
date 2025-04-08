#include "cpplib.h"

namespace cpplib {
    int add_(int a, int b) {
        return a + b;
    }
}

int add(int a, int b) {
    return cpplib::add_(a, b);
}