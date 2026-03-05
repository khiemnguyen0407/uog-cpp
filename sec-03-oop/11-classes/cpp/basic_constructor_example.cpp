#include <iostream>
class Vector2D
{
private:
    double x { 24 }; // let remove {} to illustrate non-initialized members for students
    double y {};
    
public:
    Vector2D(double x, double y) 
    {
        this->x = x;
        this->y = y;
        std::cout << "Vector2D(" << this->x << ", " << this->y << ") constructed\n";
    }
    void print() const {
        std::cout << "Vector2D(" << x << ", " << y << ")\n";
    }
};

int main()
{
    Vector2D v {42, 24};    // call Vector2D(double, double)
    v.print();
    return 0;
}
