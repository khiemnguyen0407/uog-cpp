#ifndef MAX_H
#define MAX_H

// The whole template lives here
template <typename T>
T max(T x, T y) {
    return (x < y) ? y : x;
}

#endif
