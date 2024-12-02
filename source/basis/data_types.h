/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-01 22:18:42
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-02 11:51:05
 */

#ifndef __DATA_TYPES_H__
#define __DATA_TYPES_H__

#include <vector>
#include <Eigen/Geometry>
#include <Eigen/StdVector>
#include <map>
#include <string>

namespace xviewer::basis
{
    template <int N>
    using Vecd = Eigen::Matrix<double, N, 1>;

    typedef Vecd<2> Vec2d;
    typedef Vecd<3> Vec3d;
    typedef Vecd<4> Vec4d;

    template <int N>
    using Vecf = Eigen::Matrix<float, N, 1>;

    typedef Vecf<2> Vec2f;
    typedef Vecf<3> Vec3f;
    typedef Vecf<4> Vec4f;

    template <int N>
    using Veci = Eigen::Matrix<int, N, 1>;
    typedef Veci<2> Vec2i;
    typedef Veci<3> Vec3i;
    typedef Veci<4> Vec4i;

    template <int M, int N>
    using Matd = Eigen::Matrix<double, M, N>;

    typedef Matd<2, 2> Mat2d;
    typedef Matd<3, 3> Mat3d;
    typedef Matd<4, 4> Mat4d;

    template <int M, int N>
    using Matf = Eigen::Matrix<float, M, N>;

    typedef Matf<2, 2> Mat2f;
    typedef Matf<3, 3> Mat3f;
    typedef Matf<4, 4> Mat4f;

    typedef Eigen::Quaternion<double> Quatd;

    typedef Eigen::Quaternion<float> Quatf;

    template <typename T>
    using vec_E = std::vector<T, Eigen::aligned_allocator<T>>;

    typedef vec_E<Vec2f> Points2f;
    typedef vec_E<Vec3f> Points3f;

    typedef Vec3d Pose2d;
    typedef Vec3f Pose2f;

}

#endif /* __DATA_TYPES_H__ */
