/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-03 09:18:24
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 09:25:56
 */
#include <iostream>
#include "xviewer.h"
using namespace std;

int main(int argc, char const *argv[])
{
    xviewer::XViewer viewer;
    if (!viewer.Init())
    {
        return 1;
    }

    while (viewer.IsRunning())
    {
        viewer.Update();
    }

    return 0;
}
