void add_value(const double& ref, double value) {
    ref = ref + value; // error: we promised not to change ref
}

int main() {
    double x{1.0};
    add_value(x, 2.0);
    return 0;
}
