/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-02 11:28:31
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-02 11:29:09
 */

#ifndef __DATA_TYPES_UTILS_H__
#define __DATA_TYPES_UTILS_H__

#include "data_types.h"
namespace xviewer::basis
{
    inline Quatd RollPitchYawDouble(const double roll, const double pitch,
                                    const double yaw)
    {
        const Eigen::AngleAxisd roll_angle(roll, Eigen::Vector3d::UnitX());
        const Eigen::AngleAxisd pitch_angle(pitch, Eigen::Vector3d::UnitY());
        const Eigen::AngleAxisd yaw_angle(yaw, Eigen::Vector3d::UnitZ());
        return yaw_angle * pitch_angle * roll_angle;
    }

    inline Quatf RollPitchYawFloat(const float roll, const float pitch,
                                   const float yaw)
    {
        const Eigen::AngleAxisf roll_angle(roll, Eigen::Vector3f::UnitX());
        const Eigen::AngleAxisf pitch_angle(pitch, Eigen::Vector3f::UnitY());
        const Eigen::AngleAxisf yaw_angle(yaw, Eigen::Vector3f::UnitZ());
        return yaw_angle * pitch_angle * roll_angle;
    }
}

#endif /* __DATA_TYPES_UTILS_H__ */
