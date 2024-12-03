/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-02 13:38:20
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-02 13:39:28
 */

#include "base_module.h"
namespace xviewer::basis
{

    Status BaseModule::Run()
    {
        m_started = false;
        Status errSts = Init();
        if (!errSts.IsOK())
        {
            std::string errMsg = Name() + " Init failed: " + errSts.Message();
            LOG_FATAL("%s", errMsg.c_str());
            return Status(errSts.Code(), errMsg);
        }

        errSts = Start();
        if (!errSts.IsOK())
        {
            std::string errMsg = Name() + " Start failed: " + errSts.Message();
            LOG_FATAL("%s", errMsg.c_str());
            return Status(errSts.Code(), errMsg);
        }
        m_started = true;
        return Status::OK();
    }
}
