/**
 * @Author: Xia Yunkai
 * @Date:   2024-07-05 11:07:57
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 09:09:25
 */

#ifndef __APP_WINDOW_PRESENTER_H__
#define __APP_WINDOW_PRESENTER_H__
#include "component/component.h"

namespace xviewer::app_window
{
    class AppWindowPresenter final : public Component
    {
    public:
        void Initialize() override;
        void Update(float deltaTime) override;
    };
}
#endif /* __APP_WINDOW_PRESENTER_H__ */
