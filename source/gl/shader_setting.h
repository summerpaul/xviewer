/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-03 09:39:22
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 13:12:34
 */
#include <stdint.h>

#ifndef __SHADER_SETTING_H__
#define __SHADER_SETTING_H__
#include "glsl_shader.h"
#include "make_shared.h"
namespace xviewer::gl
{
    struct ColorMode
    {
        enum MODE
        {
            RAINBOW = 0,
            FLAT_COLOR = 1,
            VERTEX_COLOR = 2,
            TEXTURE_COLOR = 3
        };
    };

    struct PointScaleMode
    {
        enum MODE
        {
            SCREENSPACE = 0,
            METRIC = 1
        };
    };

    struct PointShapeMode
    {
        enum MODE
        {
            RECTANGLE = 0,
            CIRCLE = 1
        };
    };

    struct ShaderParameterInterface
    {
    public:
        using Ptr = std::shared_ptr<ShaderParameterInterface>;
        ShaderParameterInterface(const std::string &name) : name(name) {}
        virtual ~ShaderParameterInterface() {}

        virtual void set(GLSLShader &shader) const = 0;
        virtual Ptr clone() const = 0;

    public:
        std::string name;
    };

    template <typename T>
    struct ShaderParameter : public ShaderParameterInterface
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        ShaderParameter(const std::string &name, const T &value) : ShaderParameterInterface(name), value(value) {}
        virtual ~ShaderParameter() override {}

        virtual void set(glk::GLSLShader &shader) const override { shader.set_uniform(name, value); }

        virtual Ptr clone() const override { return make_shared<ShaderParameter<T>>(name, value); }

    public:
        T value;
    };

}

#endif /* __SHADER_SETTING_H__ */
