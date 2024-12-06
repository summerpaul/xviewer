/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-03 21:37:57
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 21:55:30
 */
#include <iostream>

#include "dock_space_manager.h"
#include "basis/logger.h"

#include <GLFW/glfw3.h>
#include <IconsFontAwesome6.h>
#include <imgui.h>
#include <imgui_internal.h>
#include <implot.h>

namespace xviewer::ui
{

    std::vector<BaseLayer::Ptr> DockSpaceManager::s_layers;

    DockSpaceManager::DockSpaceManager() {}

    DockSpaceManager::~DockSpaceManager()
    {
        for (auto &layer : s_layers)
        {
            layer->Shutdown();
        }
        ImPlot::DestroyContext();
        LOG_INFO("destruct");
    }
    void DockSpaceManager::Initialize()
    {
        m_dockSpaceDocument.SetParent(m_pDocument);
        ImPlot::CreateContext();
        ImGui::StyleColorsDark();
        ImPlot::StyleColorsLight();
        m_dockSpaceDocument.Initialize();
        m_pRingbufferSink = std::make_shared<spdlog::sinks::ringbuffer_sink_mt>(1000);
        auto logger = spdlog::default_logger();
        logger->sinks().emplace_back(m_pRingbufferSink);
        logger->set_level(spdlog::level::trace);
        logger->set_pattern("%Y-%m-%d %H:%M:%S.%e [%l] [%s %#] %v");
        RegisterUiCallback("logger", create_logger_ui(m_pRingbufferSink));
        LOG_INFO("Initialize");
    }

    void DockSpaceManager::Update(float deltaTime)
    {
        InitializeDocks();
        m_dockSpaceDocument.Update(deltaTime);
        UpdateSublayers(deltaTime);
        UpdateCallbacks();
    }

    void DockSpaceManager::RegisterUiCallback(const std::string &name,
                                              const VOID_CALLBACK &callback)
    {
        if (!callback)
        {
            m_uiCallbacks.erase(name);
            return;
        }

        m_uiCallbacks[name] = callback;
    }

    void DockSpaceManager::DropCallback(GLFWwindow *window, int count, const char **paths)
    {
        for (auto &layer : s_layers)
        {
            layer->FilesDropCallback(count, paths);
        }
    }
    void DockSpaceManager::InitializeDocks()
    {
        static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
        ImGuiWindowFlags window_flags =
            ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        const ImGuiViewport *viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                        ImGuiWindowFlags_NoBringToFrontOnFocus |
                        ImGuiWindowFlags_NoNavFocus;
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::Begin("DockSpace Demo", NULL, window_flags);
        ImGui::PopStyleVar(3);
        ImGuiIO &io = ImGui::GetIO();
        if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
        {
            ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
            ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
        }
        DrawMenuBar();
        ImGui::End();
    }
    void DockSpaceManager::DrawMenuBar()
    {
        if (ImGui::BeginMenuBar())
        {

            const float fps = ImGui::GetIO().Framerate;
            ImGui::Text(" %.2f fps", fps);
            ImGui::Separator();

            ImGui::EndMenuBar();
        }
    }

    void DockSpaceManager::UpdateSublayers(float deltaTime)
    {
        for (auto &layer : s_layers)
        {
            layer->Update(deltaTime);
        }
    }
    void DockSpaceManager::UpdateCallbacks()
    {
        std::vector<const std::function<void()> *> callbacks;

        for (const auto &callback : m_uiCallbacks)
        {

            callbacks.emplace_back(&callback.second);
        }

        for (const auto &callback : callbacks)
        {
            (*callback)();
        }
    }
}