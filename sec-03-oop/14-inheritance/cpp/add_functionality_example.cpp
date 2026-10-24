#include "base_derived.h"

int main() {
    Derived derived{24.0, 42};
    derived.identify(); // inherited from Base
    derived.print();    // added by Derived
    return 0;
}
