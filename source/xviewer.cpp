/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-01 21:38:52
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-02 11:26:29
 */
#include "xviewer.h"

namespace xviewer
{

    XViewer::XViewer() : basis::BaseModule("XViewer") {}

    XViewer::~XViewer() {}

    basis::Status XViewer::Init()
    {
        return basis::Status::OK();
    }

    basis::Status XViewer::Start()
    {
        return basis::Status::OK();
    }

    void XViewer::Stop()
    {
    }
}
