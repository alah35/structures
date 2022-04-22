#include <iostream>
#include <vector>
#include <cmath>
#include <string>

struct Vector {

    Vector() {
        x = 0;
        y = 0;
    }
   
    Vector(double _x, double _y) {
        x = _x;
        y = _y;
    }

    void output() {
        std::cout << "v(" << x << ", " << y << ")" << std::endl;
    }

    Vector& operator+(const Vector &v) {
        x += v.x;
        y += v.y;
        return *this; 
    }

    Vector& operator-(const Vector &v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vector& operator=(const Vector &right) {
       x = right.x;
       y = right.y;
       return *this;
    }

    Vector& operator*(const double a) {
        x *= a;
        y *= a;
        return *this;
    }

    double length() {
        return sqrt(x*x + y*y);
    }

    void normalize() {
        x /= length();
        y /= length();
    }

    double x;
    double y;
};

Vector add(Vector *a, Vector *b) {
    Vector c(a->x + b->x, a->y + b->y);
    return c;
}

Vector subtract(const Vector &a, const Vector &b) {
    Vector c(a.x - b.x, a.y - b.y);
    return c;
}

Vector scale(const Vector &v, double a) {
    Vector c = v;
    c.x = c.x * a;
    c.y = c.y * a;
    return c;
}

double length(Vector &v) {
    return sqrt(v.x * v.x + v.y + v.y);
}

Vector normalize(Vector &v) {
    Vector c = v;
    c.x /= c.length();
    c.y /= c.length();
    return c;
}

enum Commands{
    ERR = -1,
    WAIT,
    QUIT,
    ADD,
    SUBTRACT,
    SCALE,
    LENGTH, 
    NORMALIZE
};

Commands interpret(std::string s) {
    if (s == "q" || s == "quit")
        return QUIT;
    if (s == "add")
        return ADD;
    if (s == "subtract")
        return SUBTRACT;
    if (s == "scale")
        return SCALE;
    if (s == "length")
        return LENGTH;
    if (s == "normalize" || s == "normilize")
        return NORMALIZE;
    return ERR;
}

int main() {
    double x1, x2, y1, y2;
    std::cout << "Enter coordinates of the first vector:" << std::endl;
    std::cin >> x1 >> y1;
    std::cout << "Enter coordinates of the second vector:" << std::endl;
    std::cin >> x2 >> y2;
    Vector v1(x1, y1);
    Vector v2(x2, y2);

    Commands action = WAIT;
    while (action != QUIT) {
        std::cout << "Enter command:" << std::endl;
        std::string s;
        std::cin >> s;
        action = interpret(s);
        
        switch (action) {
            case ADD: 
                {
                    Vector c = add(&v1,&v2);
                    c.output();
                    c = v1 + v2;
                    c.output();
                }
                break;
            case SUBTRACT:
                {
                    Vector c = subtract(v1, v2);
                    c.output();
                    c = v1 - v2;
                    c.output();
                }
                break;
                case SCALE:
                {
                    std::cout << "Enter a scale:" << std::endl;
                    double a;
                    std::cin >> a;
                    Vector c = scale(v1, a);
                    c.output();
                }
                break;
                case LENGTH: 
                {
                    std::cout << "Length of v1 = " << length(v1) << std::endl;
                    std::cout << v1.length() << std::endl;
                }
                break;
                case NORMALIZE:
                {
                    Vector c = normalize(v1);
                    c.output();
                }
                break;
                case QUIT:
                    break;
                case ERR:
                    std::cout << "Something get wrong!" << std::endl;
                    break;
                default:
                    action = WAIT;
                    break;
        }
    }
    return 0;
}
