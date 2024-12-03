/**
 * @Author: Xia Yunkai
 * @Date:   2024-07-05 11:08:13
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 09:24:40
 */

#include "app_window_presenter.h"
#include "app_window.h"
#include "basis/logger.h"
#include <GLFW/glfw3.h>
using namespace std;

namespace xviewer::app_window
{

    void AppWindowPresenter::Initialize()
    {
        glfwShowWindow(Get<AppWindow>()->GetWindow());
        LOG_INFO("Initialize");
    }
    void AppWindowPresenter::Update(float deltaTime)
    {
        const auto window = Get<AppWindow>();
        glfwPollEvents();
        glfwSwapBuffers(window->GetWindow());
    }
}