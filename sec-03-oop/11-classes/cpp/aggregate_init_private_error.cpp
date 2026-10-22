class Foo { // not an aggregate: it has private members
    int x{}, y{};
};

int main() {
    Foo foo{6, 7}; // error: no aggregate initialization for Foo
    return 0;
}
