/**
 * @Author: Xia Yunkai
 * @Date:   2024-07-05 10:54:06
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 09:08:10
 */
#ifndef __APP_WINDOW_H__
#define __APP_WINDOW_H__
#include "component/component.h"
#include <string>
struct GLFWwindow;
namespace xviewer::app_window
{
    class AppWindow final : public Component
    {
    public:
        AppWindow(const std::string &name = "");
        ~AppWindow() override;

        void Initialize() override;
        void Update(float deltaTime) override;

        void InitializeGLFW();
        void InitializeIcons();

        GLFWwindow *GetWindow() const;
        bool GetWindowShouldClose() const;
        void SetWindowShouldClose(bool value) const;

        int GetWidth() const;
        int GetHeight() const;

        bool IsFocused() const;

        void SetFramebuffeSizeCallback(void (*fp)(GLFWwindow *window, int width, int height));
        void SetDropCallback(void (*fp)(GLFWwindow *window, int count, const char **paths));
        void SetScrollCallback(void (*fp)(GLFWwindow *window, double xoffset, double yoffset));
        void SetMouseButtonCallback(void (*fp)(GLFWwindow *window, int button, int action, int modes));
        void SetCursorPosCallback(void (*fp)(GLFWwindow *window, double xpos, double ypos));
        void SetWindowCloseCallback(void (*fp)(GLFWwindow *window));
        void SetWaitEventsTimeout(float timeout);

    private:
        GLFWwindow *m_pWindow;
        int m_width;
        int m_height;
        bool m_focused;
        std::string m_name;
        float m_waitEventsTimeout = 0.1f;
    };
}

#endif /* __APP_WINDOW_H__ */
