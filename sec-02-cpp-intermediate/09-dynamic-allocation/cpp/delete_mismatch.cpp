int main() {
    int* numbers{new int[5]{}};
    delete numbers; // wrong: this should be delete[]
    return 0;
}
