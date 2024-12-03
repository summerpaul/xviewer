/**
 * @Author: Xia Yunkai
 * @Date:   2024-06-30 22:15:17
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 09:28:58
 */

#include "imgui_manager.h"
#include "app_window/app_window.h"
#include "basis/logger.h"
#include "IconsFontAwesome6.h"
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <imgui.h>
#include <imgui_internal.h>
#include <assert.h>
namespace xviewer::imgui
{

    ImGuiManager::ImGuiManager() {}
    void ImGuiManager::Initialize()
    {
        InitializeImGui();

        LOG_INFO("ImGuiManager::Initialize");
    }

    void ImGuiManager::Update(float deltaTime)
    {

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiManager::InitializeImGui()
    {
        IMGUI_CHECKVERSION();
        // 创建上下文
        ImGui::CreateContext();
        auto window = Get<app_window::AppWindow>()->GetWindow();
        assert(window != nullptr);
        InitializeStyle();
        InitializeFonts();
        bool ret = false;
        ret = ImGui_ImplGlfw_InitForOpenGL(window, true);
        assert(ret);
        ret = ImGui_ImplOpenGL3_Init("#version 330");
        assert(ret);
    }
    void ImGuiManager::InitializeStyle()
    {
        ImGui::GetStyle().FrameRounding = 2.0f;
        ImGui::GetStyle().GrabRounding = 2.0f;
        ImGui::GetStyle().AntiAliasedFill = true;
        ImGui::GetStyle().AntiAliasedLines = true;
        ImGui::GetStyle().AntiAliasedLinesUseTex = true;
        ImGui::StyleColorsDark();
        // ImGui::GetStyle().

        ImVec4 *colors = ImGui::GetStyle().Colors;
        colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
        colors[ImGuiCol_TextDisabled] = ImVec4(0.36f, 0.42f, 0.47f, 1.00f);
        colors[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
        colors[ImGuiCol_ChildBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
        colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
        colors[ImGuiCol_Border] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
        colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
        colors[ImGuiCol_FrameBgHovered] = ImVec4(0.12f, 0.20f, 0.28f, 1.00f);
        colors[ImGuiCol_FrameBgActive] = ImVec4(0.09f, 0.12f, 0.14f, 1.00f);
        colors[ImGuiCol_TitleBg] = ImVec4(0.09f, 0.12f, 0.14f, 0.65f);
        colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
        colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
        colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
        colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.39f);
        colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
        colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.18f, 0.22f, 0.25f, 1.00f);
        colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.09f, 0.21f, 0.31f, 1.00f);
        colors[ImGuiCol_CheckMark] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
        colors[ImGuiCol_SliderGrab] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
        colors[ImGuiCol_SliderGrabActive] = ImVec4(0.37f, 0.61f, 1.00f, 1.00f);
        colors[ImGuiCol_Button] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
        colors[ImGuiCol_ButtonHovered] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
        colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
        colors[ImGuiCol_Header] = ImVec4(0.20f, 0.25f, 0.29f, 0.55f);
        colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
        colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
        colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
        colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
        colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
        colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
        colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
        colors[ImGuiCol_Tab] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
        colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
        colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
        colors[ImGuiCol_TabUnfocused] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
        colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
        colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
        colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
        colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
        colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
        colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
        colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
        colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
        colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
        colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
    }

    void ImGuiManager::InitializeFonts()
    {
        ImGuiIO &io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
        float baseFontSize = 18.0f;

        const char *fontPath = nullptr;

        const char *fontPath1 = "resources/font/msyh.ttf";

        const char *fontPath2 = "../resources/font/msyh.ttf";

        const char *iconPath = nullptr;

        const char *iconPath1 = "resources/icon/fa-solid-900.ttf";

        const char *iconPath2 = "../resources/icon/fa-solid-900.ttf";

        FILE *file1 = nullptr;
        FILE *file2 = nullptr;
        FILE *file3 = nullptr;
        FILE *file4 = nullptr;
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
        fopen_s(&file1, fontPath1, "rb");
        fopen_s(&file2, fontPath2, "rb");

        fopen_s(&file3, iconPath1, "rb");
        fopen_s(&file4, iconPath2, "rb");
#else

        file1 = fopen(fontPath1, "rb");
        file2 = fopen(fontPath2, "rb");
        file3 = fopen(iconPath1, "rb");
        file4 = fopen(iconPath2, "rb");
#endif
        if (file1)
        {
            fontPath = fontPath1;
            fclose(file1);
        }

        if (file2)
        {
            fontPath = fontPath2;
            fclose(file2);
        }

        if (file3)
        {
            iconPath = iconPath1;
            fclose(file3);
        }

        if (file4)
        {
            iconPath = iconPath2;
            fclose(file4);
        }

        if (fontPath)
        {
            io.Fonts->AddFontFromFileTTF(
                fontPath,
                baseFontSize,
                NULL,
                io.Fonts->GetGlyphRangesChineseFull());
        }
        else
        {
            LOG_WARN("failed to load font");
        }

        if (iconPath)
        {
            float iconFontSize = baseFontSize;
            static const ImWchar icons_ranges[] = {ICON_MIN_FA, ICON_MAX_16_FA, 0};
            ImFontConfig icons_config;
            icons_config.MergeMode = true;
            icons_config.PixelSnapH = true;
            icons_config.GlyphMinAdvanceX = iconFontSize;
            io.Fonts->AddFontFromFileTTF(
                iconPath,
                iconFontSize,
                &icons_config,
                icons_ranges);
        }
        else
        {
            LOG_WARN("failed to load icon");
        }
    }

}
