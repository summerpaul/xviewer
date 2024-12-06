/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-02 13:36:09
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-04 15:21:16
 */
#include <stdint.h>

#ifndef __CAMERA_CONTROL_H__
#define __CAMERA_CONTROL_H__
#include <memory>
#include <iostream>
#include "basis/data_types.h"
namespace xviewer::camera
{
    using namespace basis;
    class CameraControl
    {
    public:
        virtual ~CameraControl() {}

        virtual void ResetCenter() {}

        virtual void Lookat(const Vec3f &pt) {}

        virtual void Mouse(const Vec2f &p, int button, bool down) {}
        virtual void Drag(const Vec2f &p, int button) {}
        virtual void Scroll(const Vec2f &rel) {}

        virtual void Update() {}
        virtual void Updown(double p) {}
        virtual void Arrow(const Vec2f &p) {}
    };
}

#endif /* __CAMERA_CONTROL_H__ */
