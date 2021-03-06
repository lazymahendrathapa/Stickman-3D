#pragma once
#include "vector.h"

class mat3
{
public:
    float m[3][3];
    
    mat3(const vec3& v1, const vec3& v2, const vec3& v3)
    {
        (*this)[0] = v1;
        (*this)[1] = v2;
        (*this)[2] = v3;
    }
    mat3(float f = 1.0f)
    {
        (*this)[0] = vec3(f, 0.0f, 0.0f);
        (*this)[1] = vec3(0.0f, f, 0.0f);
        (*this)[2] = vec3(0.0f, 0.0f, f);
    }
    mat3(float m11, float m12, float m13,
         float m21, float m22, float m23,
         float m31, float m32, float m33)
    {
        m[0][0] = m11; m[0][1] = m12; m[0][2] = m13;
        m[1][0] = m21; m[1][1] = m22; m[1][2] = m23;
        m[2][0] = m31; m[2][1] = m32; m[2][2] = m33;
    }

    vec3& operator[] (int n)
    {
        return *((vec3*)&m[n]);
    }

    const vec3& operator[] (int n) const
    {
        return *((vec3*)&m[n]);
    }

    mat3 operator+ (const mat3& m2) const
    {
        return mat3(
            m[0][0] + m2.m[0][0], m[0][1] + m2.m[0][1], m[0][2] + m2.m[0][2],
            m[1][0] + m2.m[1][0], m[1][1] + m2.m[1][1], m[1][2] + m2.m[1][2],
            m[2][0] + m2.m[2][0], m[2][1] + m2.m[2][1], m[2][2] + m2.m[2][2]
        );
    }

    mat3 operator- (const mat3& m2) const
    {
        return mat3(
            m[0][0] - m2.m[0][0], m[0][1] - m2.m[0][1], m[0][2] - m2.m[0][2],
            m[1][0] - m2.m[1][0], m[1][1] - m2.m[1][1], m[1][2] - m2.m[1][2],
            m[2][0] - m2.m[2][0], m[2][1] - m2.m[2][1], m[2][2] - m2.m[2][2]
        );
    }

    mat3 operator* (const mat3& m2) const
    {
        return mat3(
            (m[0][0]*m2.m[0][0] + m[0][1]*m2.m[1][0] + m[0][2]*m2.m[2][0]),
            (m[0][0]*m2.m[0][1] + m[0][1]*m2.m[1][1] + m[0][2]*m2.m[2][1]),
            (m[0][0]*m2.m[0][2] + m[0][1]*m2.m[1][2] + m[0][2]*m2.m[2][2]),
            (m[1][0]*m2.m[0][0] + m[1][1]*m2.m[1][0] + m[1][2]*m2.m[2][0]),
            (m[1][0]*m2.m[0][1] + m[1][1]*m2.m[1][1] + m[1][2]*m2.m[2][1]),
            (m[1][0]*m2.m[0][2] + m[1][1]*m2.m[1][2] + m[1][2]*m2.m[2][2]),
            (m[2][0]*m2.m[0][0] + m[2][1]*m2.m[1][0] + m[2][2]*m2.m[2][0]),
            (m[2][0]*m2.m[0][1] + m[2][1]*m2.m[1][1] + m[2][2]*m2.m[2][1]),
            (m[2][0]*m2.m[0][2] + m[2][1]*m2.m[1][2] + m[2][2]*m2.m[2][2])
        );
    }
    vec3 operator* (const vec3& v) const
    {
        return vec3(
            (m[0][0]*v.x + m[0][1]*v.y + m[0][2]*v.z),
            (m[1][0]*v.x + m[1][1]*v.y + m[1][2]*v.z),
            (m[2][0]*v.x + m[2][1]*v.y + m[2][2]*v.z)
        );
    }
    mat3 operator* (float f) const
    {
        return mat3(
            m[0][0]*f, m[0][1]*f, m[0][2]*f,
            m[1][0]*f, m[1][1]*f, m[1][2]*f,
            m[2][0]*f, m[2][1]*f, m[2][2]*f
        );
    }
};

class mat4;
inline std::ostream& operator << (std::ostream &os, const mat4 &m);
class mat4
{
public:
    float m[4][4];
    
    mat4(const vec4& v1, const vec4& v2, const vec4& v3, const vec4& v4)
    {
        (*this)[0] = v1;
        (*this)[1] = v2;
        (*this)[2] = v3;
        (*this)[3] = v4;
    }
    mat4(const mat3& mat)
    {
        (*this)[0] = vec4(mat[0], 0.0f);
        (*this)[1] = vec4(mat[1], 0.0f);
        (*this)[2] = vec4(mat[2], 0.0f);
        (*this)[3] = vec4();
    }
    mat4(float f = 1.0f)
    {
        (*this)[0] = vec4(f, 0.0f, 0.0f, 0.0f);
        (*this)[1] = vec4(0.0f, f, 0.0f, 0.0f);
        (*this)[2] = vec4(0.0f, 0.0f, f, 0.0f);
        (*this)[3] = vec4(0.0f, 0.0f, 0.0f, f);
    }
    mat4(float m11, float m12, float m13, float m14,
         float m21, float m22, float m23, float m24,
         float m31, float m32, float m33, float m34,
         float m41, float m42, float m43, float m44)
    {
        m[0][0] = m11; m[0][1] = m12; m[0][2] = m13; m[0][3] = m14;
        m[1][0] = m21; m[1][1] = m22; m[1][2] = m23; m[1][3] = m24;
        m[2][0] = m31; m[2][1] = m32; m[2][2] = m33; m[2][3] = m34;
        m[3][0] = m41; m[3][1] = m42; m[3][2] = m43; m[3][3] = m44;
    }

    vec4& operator[] (int n)
    {
        return *((vec4*)&m[n]);
    }

    const vec4& operator[] (int n) const
    {
        return *((vec4*)&m[n]);
    }

    mat4 operator+ (const mat4& m2) const
    {
#ifndef USE_SSE
        return mat4(
            m[0][0] + m2.m[0][0], m[0][1] + m2.m[0][1], m[0][2] + m2.m[0][2], m[0][3] + m2.m[0][3],
            m[1][0] + m2.m[1][0], m[1][1] + m2.m[1][1], m[1][2] + m2.m[1][2], m[1][3] + m2.m[1][3],
            m[2][0] + m2.m[2][0], m[2][1] + m2.m[2][1], m[2][2] + m2.m[2][2], m[2][3] + m2.m[2][3],
            m[3][0] + m2.m[3][0], m[3][1] + m2.m[3][1], m[3][2] + m2.m[3][2], m[3][3] + m2.m[3][3]
        );
#else
        return mat4(
            (*this)[0] + m2[0],
            (*this)[1] + m2[1],
            (*this)[2] + m2[2],
            (*this)[3] + m2[3]
        );
#endif
    }

    mat4 operator- (const mat4& m2) const
    {
#ifndef USE_SSE
        return mat4(
            m[0][0] - m2.m[0][0], m[0][1] - m2.m[0][1], m[0][2] - m2.m[0][2], m[0][3] - m2.m[0][3],
            m[1][0] - m2.m[1][0], m[1][1] - m2.m[1][1], m[1][2] - m2.m[1][2], m[1][3] - m2.m[1][3],
            m[2][0] - m2.m[2][0], m[2][1] - m2.m[2][1], m[2][2] - m2.m[2][2], m[2][3] - m2.m[2][3],
            m[3][0] - m2.m[3][0], m[3][1] - m2.m[3][1], m[3][2] - m2.m[3][2], m[3][3] - m2.m[3][3]
        );
#else
        return mat4(
            (*this)[0] - m2[0],
            (*this)[1] - m2[1],
            (*this)[2] - m2[2],
            (*this)[3] - m2[3]
        );
#endif
    }

    mat4 operator* (const mat4& m2) const
    {
#ifndef USE_SSE
        return mat4(
            (m[0][0]*m2.m[0][0] + m[0][1]*m2.m[1][0] + m[0][2]*m2.m[2][0] + m[0][3]*m2.m[3][0]),
            (m[0][0]*m2.m[0][1] + m[0][1]*m2.m[1][1] + m[0][2]*m2.m[2][1] + m[0][3]*m2.m[3][1]),
            (m[0][0]*m2.m[0][2] + m[0][1]*m2.m[1][2] + m[0][2]*m2.m[2][2] + m[0][3]*m2.m[3][2]),
            (m[0][0]*m2.m[0][3] + m[0][1]*m2.m[1][3] + m[0][2]*m2.m[2][3] + m[0][3]*m2.m[3][3]),
            (m[1][0]*m2.m[0][0] + m[1][1]*m2.m[1][0] + m[1][2]*m2.m[2][0] + m[1][3]*m2.m[3][0]),
            (m[1][0]*m2.m[0][1] + m[1][1]*m2.m[1][1] + m[1][2]*m2.m[2][1] + m[1][3]*m2.m[3][1]),
            (m[1][0]*m2.m[0][2] + m[1][1]*m2.m[1][2] + m[1][2]*m2.m[2][2] + m[1][3]*m2.m[3][2]),
            (m[1][0]*m2.m[0][3] + m[1][1]*m2.m[1][3] + m[1][2]*m2.m[2][3] + m[1][3]*m2.m[3][3]),
            (m[2][0]*m2.m[0][0] + m[2][1]*m2.m[1][0] + m[2][2]*m2.m[2][0] + m[2][3]*m2.m[3][0]),
            (m[2][0]*m2.m[0][1] + m[2][1]*m2.m[1][1] + m[2][2]*m2.m[2][1] + m[2][3]*m2.m[3][1]),
            (m[2][0]*m2.m[0][2] + m[2][1]*m2.m[1][2] + m[2][2]*m2.m[2][2] + m[2][3]*m2.m[3][2]),
            (m[2][0]*m2.m[0][3] + m[2][1]*m2.m[1][3] + m[2][2]*m2.m[2][3] + m[2][3]*m2.m[3][3]),
            (m[3][0]*m2.m[0][0] + m[3][1]*m2.m[1][0] + m[3][2]*m2.m[2][0] + m[3][3]*m2.m[3][0]),
            (m[3][0]*m2.m[0][1] + m[3][1]*m2.m[1][1] + m[3][2]*m2.m[2][1] + m[3][3]*m2.m[3][1]),
            (m[3][0]*m2.m[0][2] + m[3][1]*m2.m[1][2] + m[3][2]*m2.m[2][2] + m[3][3]*m2.m[3][2]),
            (m[3][0]*m2.m[0][3] + m[3][1]*m2.m[1][3] + m[3][2]*m2.m[2][3] + m[3][3]*m2.m[3][3])
        );
#else
        mat4 temp = m2.Transpose();
        return mat4(
            (*this)[0].Dot(temp[0]), (*this)[0].Dot(temp[1]), (*this)[0].Dot(temp[2]), (*this)[0].Dot(temp[3]), 
            (*this)[1].Dot(temp[0]), (*this)[1].Dot(temp[1]), (*this)[1].Dot(temp[2]), (*this)[1].Dot(temp[3]), 
            (*this)[2].Dot(temp[0]), (*this)[2].Dot(temp[1]), (*this)[2].Dot(temp[2]), (*this)[2].Dot(temp[3]), 
            (*this)[3].Dot(temp[0]), (*this)[3].Dot(temp[1]), (*this)[3].Dot(temp[2]), (*this)[3].Dot(temp[3])
        );
#endif
    }
    vec4 Column(int i) const
    {
#ifndef USE_SSE
        return vec4(m[0][i], m[1][i], m[2][i], m[3][i]);
#else
        float fs[4] = { m[0][i], m[1][i], m[2][i], m[3][i] };
        return vec4(_mm_load_ps(fs));
#endif
    }
    vec4 Row(int i) const
    {
        return (*this)[i];
    }
    vec4 operator* (const vec4& v) const
    {
#ifndef USE_SSE
        return vec4(
            (m[0][0]*v.x + m[0][1]*v.y + m[0][2]*v.z + m[0][3]*v.w),
            (m[1][0]*v.x + m[1][1]*v.y + m[1][2]*v.z + m[1][3]*v.w),
            (m[2][0]*v.x + m[2][1]*v.y + m[2][2]*v.z + m[2][3]*v.w),
            (m[3][0]*v.x + m[3][1]*v.y + m[3][2]*v.z + m[3][3]*v.w)
        );
#else
        return vec4(
            (*this)[0].Dot(v), 
            (*this)[1].Dot(v), 
            (*this)[2].Dot(v), 
            (*this)[3].Dot(v)
        );
#endif
    }
    mat4 operator* (float f) const
    {
#ifndef USE_SSE
        return mat4(
            m[0][0]*f, m[0][1]*f, m[0][2]*f, m[0][3]*f,
            m[1][0]*f, m[1][1]*f, m[1][2]*f, m[1][3]*f,
            m[2][0]*f, m[2][1]*f, m[2][2]*f, m[2][3]*f,
            m[3][0]*f, m[3][1]*f, m[3][2]*f, m[3][3]*f
        );
#else
        vec4 v(_mm_set1_ps(f));
        return mat4(
            (*this)[0] * v,
            (*this)[1] * v,
            (*this)[2] * v,
            (*this)[3] * v
        );
#endif
    }

    mat4 Transpose() const
    {
#ifndef USE_SSE
        return mat4(
            m[0][0], m[1][0], m[2][0], m[3][0],
            m[0][1], m[1][1], m[2][1], m[3][1],
            m[0][2], m[1][2], m[2][2], m[3][2],
            m[0][3], m[1][3], m[2][3], m[3][3]
        );
#else
        mat4 temp = *this;
        _MM_TRANSPOSE4_PS(temp[0].xyzw, temp[1].xyzw, temp[2].xyzw, temp[3].xyzw);
        return temp;
#endif
    }

    operator mat3() const
    {
        return mat3(
            m[0][0], m[0][1], m[0][2],
            m[1][0], m[1][1], m[1][2],
            m[2][0], m[2][1], m[2][2]
        );
    }

    mat4 AffineInverse() const
    {
        mat4 temp(*this);
        temp = temp.Transpose();
        temp[3] = vec4(0,0,0,1);
        vec3 tv = -this->Column(3);
        vec4 translation = temp * vec4(tv, (*this)[3][3]);
        temp[0][3] = translation[0];
        temp[1][3] = translation[1];
        temp[2][3] = translation[2];
        temp[3][3] = translation[3];
        return temp;
    }
};

inline std::ostream& operator << (std::ostream &os, const mat4 &m)
{
    for (int i=0; i<4; ++i)
    {
        os << std::endl;
        for (int j=0; j<4; ++j)
            os << m.m[i][j] << "  ";
    }
    return os;
}

