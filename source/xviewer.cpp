/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-01 21:38:52
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 09:30:01
 */
#include "xviewer.h"

#include "component/document.h"
#include "basis/logger.h"
#include "app_window/app_window.h"
#include "app_window/app_window_presenter.h"
#include "imgui/imgui_manager.h"
#include "imgui/imgui_presenter.h"

#include <GLFW/glfw3.h>
#include "basis/xdefines.h"
namespace xviewer
{

    XViewer::XViewer() : m_pDocument(new Document())
    {
        m_initialized = false;
    }

    XViewer::~XViewer()
    {
        if (m_pDocument != nullptr)
        {
            delete m_pDocument;
            m_pDocument = nullptr;
        }
        LOG_INFO("Destructor");
    }

    bool XViewer::Init()
    {
        m_pDocument->Add(std::make_unique<app_window::AppWindow>("Xviewer"));
        m_pDocument->Add(std::make_unique<imgui::ImGuiManager>());
        m_pDocument->Add(std::make_unique<imgui::ImGuiPresenter>());
        m_pDocument->Add(std::make_unique<app_window::AppWindowPresenter>());
        m_pDocument->Initialize();
        m_initialized = true;
        LOG_INFO("Initialize");
        return true;
    }

    void XViewer::Run()
    {
        CHECK_RETURN(!m_initialized);
        LOG_INFO("Application Run");
        while (!m_pDocument->Get<app_window::AppWindow>()->GetWindowShouldClose())
        {
            this->Update();
        }
    }

    void XViewer::Shutdown()
    {
        if (m_initialized)
        {
            m_pDocument->Get<app_window::AppWindow>()->SetWindowShouldClose(true);
            m_initialized = false;
        }
    }

    bool XViewer::IsRunning() const
    {
        return m_initialized;
    }

    void XViewer::Update()
    {
        CHECK_RETURN(!m_initialized);
        m_initialized = !m_pDocument->Get<app_window::AppWindow>()->GetWindowShouldClose();
        CHECK_RETURN(m_pDocument->Get<app_window::AppWindow>()->GetWindowShouldClose());
        static double s_lastTime = glfwGetTime();
        const double glfwTime = glfwGetTime();
        const float deltaTime = (float)(glfwTime - s_lastTime);
        s_lastTime = glfwTime;
        m_pDocument->Update(deltaTime);
    }

}
