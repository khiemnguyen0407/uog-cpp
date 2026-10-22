class Date:
    def __init__(self, year, month, day):
        self.year, self.month, self.day = year, month, day

    def print(self):
        print(f"{self.year}/{self.month}/{self.day}")


class Foo:
    def __init__(self):
        self.year, self.month, self.day = "one", "two", 3


Date.print(Foo())  # runs without complaint... and prints nonsense
