#ifndef VECTORS_H
#define VECTORS_H

struct vec_2 {
    float x = 0.0f;
    float y = 0.0f;

    void from_angel(float angle, float length = 1.00f);

    float length() const;
    float angle()  const;

    void length(float new_length);

    void angle(float new_angle);

    vec_2 operator+(const vec_2& other) const;
    vec_2 operator-(const vec_2& other) const;
    vec_2 operator*(float k) const;
    vec_2 operator/(float k) const;

    vec_2& operator+=(const vec_2& other);
    vec_2& operator-=(const vec_2& other);
    vec_2& operator*=(float k);
    vec_2& operator/=(float k);

    bool operator==(const vec_2& other) const;
    bool operator!=(const vec_2& other) const;
};

#endif //VECTORS_H