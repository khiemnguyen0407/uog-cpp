// T is a type template parameter
// double is a non-template parameter
// We don't need to provide names for these parameters since they aren't used
template <typename T>
int print(T x, double y)
{
    std::cout << "first argument: " << x << "-- 2nd argument = " << y;
}

int main()
{
    print(1, 3.4);      // print(int, double)
    print(1, 3.4f);     // print(int, double) -- float is promoted to double
    print(1.2, 3.4);    // print(double, double)
    print(1.2f, 3.4);   // print(float, double)
    print(1.2f, 3.4f);  // print(float, double) --  float is promoted to double

    return 0;
}