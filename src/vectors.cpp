#include <Arduino.h>
#include "vectors.h"

void vec_2::from_angel(float angle, float length) {
    angle = radians(angle);
    x = cos(angle) * length;
    y = sin(angle) * length;
}

float vec_2::length() const { return sqrt((x * x) + (y * y)); }
float vec_2::angle()  const { return degrees(atan2(y, x)); }

void vec_2::length(float new_length) {
    float current_len = length();
    if (current_len > 0.00001f) {
        float scale = new_length / current_len;
        x *= scale;
        y *= scale;
    } else {
        x = new_length;
        y = 0.0f;
    }
}

void vec_2::angle(float new_angle) {
    float length_ = length();
    from_angel(new_angle, length_);
}

vec_2 vec_2::operator+(const vec_2& other) const { return {x + other.x, y + other.y}; }
vec_2 vec_2::operator-(const vec_2& other) const { return {x - other.x, y - other.y}; }
vec_2 vec_2::operator*(float k) const { return {x * k, y * k}; }
vec_2 vec_2::operator/(float k) const { return (fabs(k) > 0.00001f) ? vec_2{x / k, y / k} : vec_2{0.0f, 0.0f}; }

vec_2& vec_2::operator+=(const vec_2& other) { x += other.x; y += other.y; return *this; }
vec_2& vec_2::operator-=(const vec_2& other) { x -= other.x; y -= other.y; return *this; }
vec_2& vec_2::operator*=(float k) { x *= k; y *= k; return *this; }
vec_2& vec_2::operator/=(float k) { 
    if (fabs(k) > 0.00001f) { x /= k; y /= k; } 
    return *this; 
}

bool vec_2::operator==(const vec_2& other) const {
    return (fabs(x - other.x) < 0.0001f) && (fabs(y - other.y) < 0.0001f);
}
bool vec_2::operator!=(const vec_2& other) const {
    return !(*this == other);
}