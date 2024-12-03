/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-02 13:17:13
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-02 13:22:34
 */

#ifndef __GLSL_SHADER_H__
#define __GLSL_SHADER_H__

#include <thread>
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <optional>
#include <unordered_set>
#include <unordered_map>
#include <glad/glad.h>
#include <Eigen/Core>
#include "make_shared.h"
#include "basis/data_types.h"
namespace xviewer::gl
{
    class GLSLShader
    {
    public:
        GLSLShader();
        ~GLSLShader();

    private:
        std::vector<GLuint> m_shaders;
        std::vector<std::string> m_feedbackVaryings;
        GLuint m_shaderProgram;
        std::unordered_map<std::string, GLint> m_attribCache;
        std::unordered_map<std::string, GLint> m_uniformCache;
        std::unordered_map<std::string, GLint> m_subroutineCache;
        std::unordered_map<std::string, std::shared_ptr<void>> m_uniformVariableCache;
    };
}
#endif /* __GLSL_SHADER_H__ */
