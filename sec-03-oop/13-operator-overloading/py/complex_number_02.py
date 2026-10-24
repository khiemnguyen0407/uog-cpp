class ComplexNumber:
    def __init__(self, real=0, imag=0):
        self.real = real
        self.imag = imag

    def __str__(self):  # used by print()
        return f"{self.real} + {self.imag}i"

    def __add__(self, other):  # used by +
        return ComplexNumber(self.real + other.real, self.imag + other.imag)


a, b = ComplexNumber(42, 24), ComplexNumber(24, 42)
print(f"a = {a}")
print(f"a + b = {a + b}")
