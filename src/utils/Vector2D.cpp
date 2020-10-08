#include "../../include/utils/Vector2D.hpp"

Vector2D::Vector2D() : x(0), y(0) {}

Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

Vector2D &Vector2D::add(const Vector2D &vector) {
    this->x += vector.x;
    this->y += vector.y;
    return *this;
}

Vector2D &Vector2D::sub(const Vector2D &vector) {
    this->x -= vector.x;
    this->y -= vector.y;
    return *this;
}

Vector2D &Vector2D::mul(const Vector2D &vector) {
    this->x *= vector.x;
    this->y *= vector.y;
    return *this;
}

Vector2D &Vector2D::div(const Vector2D &vector) {
    this->x /= vector.x;
    this->y /= vector.y;
    return *this;
}

Vector2D &operator+(Vector2D &v1, const Vector2D &v2) {
    return v1.add(v2);
}

Vector2D &operator-(Vector2D &v1, const Vector2D &v2) {
    return v1.sub(v2);
}

Vector2D &operator*(Vector2D &v1, const Vector2D &v2) {
    return v1.mul(v2);
}

Vector2D &operator/(Vector2D &v1, const Vector2D &v2) {
    return v1.div(v2);
}

Vector2D &Vector2D::operator+=(const Vector2D &vector) {
    return this->add(vector);
}

Vector2D &Vector2D::operator-=(const Vector2D &vector) {
    return this->sub(vector);
}

Vector2D &Vector2D::operator/=(const Vector2D &vector) {
    return this->div(vector);
}

Vector2D &Vector2D::operator*=(const Vector2D &vector) {
    return this->mul(vector);
}

std::ostream &operator<<(std::ostream &stream, const Vector2D &vector) {
    return stream << "x: " << vector.x << " y: " << vector.y;
}

Vector2D &Vector2D::operator*(const int &i) {
    this->x *= i;
    this->y *= i;
    return *this;
}

Vector2D &Vector2D::zero() {
    this->x = this->y = 0;
    return *this;
}

