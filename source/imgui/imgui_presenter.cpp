/**
 * @Author: Xia Yunkai
 * @Date:   2024-06-30 22:32:37
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 09:28:35
 */

#include "imgui_presenter.h"
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "basis/logger.h"
#include <GLFW/glfw3.h>
namespace xviewer::imgui
{

    void ImGuiPresenter::Initialize()
    {
        LOG_INFO("ImGuiPresenter::Initialize");
    }
    void ImGuiPresenter::Update(float deltaTime)
    {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        ImGuiIO &io = ImGui::GetIO();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }
}