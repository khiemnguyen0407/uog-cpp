class Date:
    def __init__(self, year=2026, month=2, day=28):
        self.year = year
        self.month = month
        self.day = day

    def print(self):
        print(f"{self.year}/{self.month}/{self.day}")


today = Date(2026, 2, 26)
today.print()      # the usual way...
Date.print(today)  # ...and what it really means: today is passed as self
