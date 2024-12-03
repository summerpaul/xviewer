/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-02 13:36:09
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-02 13:40:58
 */
#include <stdint.h>

#ifndef __CAMERA_CONTROL_H__
#define __CAMERA_CONTROL_H__
#include <memory>
#include <iostream>
namespace xviewer::camera
{
    class CameraControl
    {
    public:
        virtual ~CameraControl() {}
    };
}

#endif /* __CAMERA_CONTROL_H__ */
