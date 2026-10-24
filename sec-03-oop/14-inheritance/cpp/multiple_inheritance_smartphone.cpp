#include <iostream>
#include <string>

class Camera {
  public:
    void take_photo() const { std::cout << "Taking a photo!\n"; }
};

class Phone {
  public:
    void make_call() const { std::cout << "Making a phone call!\n"; }
};

class SmartPhone : public Camera, public Phone { // two base classes
  public:
    void use_app(const std::string& app) const {
        std::cout << "Using " << app << "!\n";
    }
};

int main() {
    SmartPhone my_phone{};
    my_phone.take_photo(); // from Camera
    my_phone.make_call();  // from Phone
    my_phone.use_app("Moodle");
    return 0;
}
