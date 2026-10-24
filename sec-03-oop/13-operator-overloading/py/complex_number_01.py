class ComplexNumber:
    def __init__(self, real=0, imag=0):
        self.real = real
        self.imag = imag


a = ComplexNumber(42, 24)
b = ComplexNumber(24, 42)
print(a)      # we'd like something meaningful here...
print(a + b)  # ...and we'd like Python to understand a + b
