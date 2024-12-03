/**
 * @Author: Xia Yunkai
 * @Date:   2024-06-30 22:32:14
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 09:28:29
 */
#ifndef __IMGUI_PRESENTER_H__
#define __IMGUI_PRESENTER_H__

#include "component/component.h"
namespace xviewer::imgui
{
    class ImGuiPresenter final : public Component
    {

    public:
        void Update(float deltaTime) override;
        virtual void Initialize() override;
    };
}
#endif /* __IMGUI_PRESENTER_H__ */
