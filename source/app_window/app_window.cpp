/**
 * @Author: Xia Yunkai
 * @Date:   2024-07-05 10:54:14
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 09:25:03
 */
#include "app_window.h"
#include "basis/logger.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cassert>
namespace xviewer::app_window
{

    AppWindow::AppWindow(const std::string &name)
        : m_pWindow(nullptr),
          m_width(1),
          m_height(1),
          m_focused(false),
          m_name(name)
    {
    }
    AppWindow::~AppWindow()
    {
        glfwTerminate();
    }

    void AppWindow::Initialize()
    {
        InitializeGLFW();
        InitializeIcons();
        LOG_INFO("Initialize");
    }
    void AppWindow::Update(float deltaTime)
    {

        glfwGetFramebufferSize(m_pWindow, &m_width, &m_height);
        glfwWaitEventsTimeout(m_waitEventsTimeout);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glViewport(0, 0, m_width, m_height);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_focused = (bool)glfwGetWindowAttrib(m_pWindow, GLFW_FOCUSED);
    }

    void AppWindow::InitializeGLFW()
    {
        glfwInit();
        glfwWindowHint(GLFW_VISIBLE, false);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        m_pWindow = glfwCreateWindow(1600, 900, m_name.data(), nullptr, nullptr);
        assert(m_pWindow != NULL);

        glfwMaximizeWindow(m_pWindow);
        glfwMakeContextCurrent(m_pWindow);
        auto ret = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        assert(ret);
        glfwSwapInterval(1);
    }
    void AppWindow::InitializeIcons() {}

    GLFWwindow *AppWindow::GetWindow() const
    {
        return m_pWindow;
    }
    bool AppWindow::GetWindowShouldClose() const
    {
        return glfwWindowShouldClose(m_pWindow);
    }
    void AppWindow::SetWindowShouldClose(bool value) const
    {
        glfwSetWindowShouldClose(m_pWindow, value);
    }

    int AppWindow::GetWidth() const
    {
        return m_width;
    }
    int AppWindow::GetHeight() const
    {
        return m_height;
    }

    bool AppWindow::IsFocused() const
    {
        return m_focused;
    }

    // 设置各类回调函数
    void AppWindow::SetFramebuffeSizeCallback(void (*fp)(GLFWwindow *window, int width, int height))
    {
        glfwSetFramebufferSizeCallback(m_pWindow, fp);
    }
    void AppWindow::SetDropCallback(void (*fp)(GLFWwindow *window, int count, const char **paths))
    {
        glfwSetDropCallback(m_pWindow, fp);
    }
    void AppWindow::SetScrollCallback(void (*fp)(GLFWwindow *window, double xoffset, double yoffset))
    {
        glfwSetScrollCallback(m_pWindow, fp);
    }
    void AppWindow::SetMouseButtonCallback(void (*fp)(GLFWwindow *window, int button, int action, int modes))
    {
        glfwSetMouseButtonCallback(m_pWindow, fp);
    }
    void AppWindow::SetCursorPosCallback(void (*fp)(GLFWwindow *window, double xpos, double ypos))
    {
        glfwSetCursorPosCallback(m_pWindow, fp);
    }

    void AppWindow::SetWindowCloseCallback(void (*fp)(GLFWwindow *window))
    {
        glfwSetWindowCloseCallback(m_pWindow, fp);
    }

    void AppWindow::SetWaitEventsTimeout(float timeout)
    {
        m_waitEventsTimeout = timeout;
    }
}