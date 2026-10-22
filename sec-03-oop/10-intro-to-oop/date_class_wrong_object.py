class Date:
    def __init__(self, year, month, day):
        self.year, self.month, self.day = year, month, day

    def print(self):
        print(f"{self.year}/{self.month}/{self.day}")


Date.print("khiem")  # Python only complains when the line runs
