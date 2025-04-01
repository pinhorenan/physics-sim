#include "Vector2D.h"

Vector2D::Vector2D() : x(0), y(0) {}

Vector2D::Vector2D(const double xVal, const double yVal) : x(xVal), y(yVal) {}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return {x + other.x, y + other.y};
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return {x - other.x, y - other.y};
}

Vector2D Vector2D::operator*(double scalar) const {
    return {x * scalar, y * scalar};
}

Vector2D Vector2D::operator/(double scalar) const {
    return {x / scalar, y / scalar};
};

double Vector2D::magnitude() const {
    return std::sqrt(x * x + y * y);
}

Vector2D Vector2D::normalized() const {
    const double mag = magnitude();
    if (mag == 0) return Vector2D{0, 0};
    return *this / mag;
}

void Vector2D::print() const {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
