class UniPerson:
    next_id = 100000  # a class variable, like a static member in C++

    def __init__(self, name="", age=18):
        self.name, self.age = name, age
        self.id = UniPerson.next_id
        UniPerson.next_id += 1


class Lecturer(UniPerson):
    def __init__(self, name="", age=18):
        super().__init__(name, age)  # run the parent's constructor first
        print(f"Lecturer {self.name} is recruited.")


khiem = Lecturer("Khiem", 42)
print(f"ID assigned to {khiem.name}: {khiem.id}")
