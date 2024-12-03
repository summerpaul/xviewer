/**
 * @Author: Xia Yunkai
 * @Date:   2024-06-30 22:15:08
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 09:30:10
 */
#ifndef __IMGUI_MANAGER_H__
#define __IMGUI_MANAGER_H__

#include "component/component.h"
// 用于初始化与imgui ::Begin
namespace xviewer::imgui
{
    class ImGuiManager final : public Component
    {
    public:
        ImGuiManager();
        virtual void Initialize() override;
        virtual void Update(float deltaTime) override;

    private:
        void InitializeImGui();
        void InitializeStyle();
        void InitializeFonts();
    };

}

#endif /* __IMGUI_MANAGER_H__ */
