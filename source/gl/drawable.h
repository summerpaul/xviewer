/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-02 13:32:17
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-02 13:33:26
 */

#ifndef __DRAWABLE_H__
#define __DRAWABLE_H__

#include "glsl_shader.h"
namespace xviewer::gl
{
    class Drawable
    {
    public:
        using Ptr = std::shared_ptr<Drawable>;
        using ConstPtr = std::shared_ptr<const Drawable>;

        virtual ~Drawable() {}

        virtual void draw(GLSLShader &shader) const {}
    };
}

#endif /* __DRAWABLE_H__ */
