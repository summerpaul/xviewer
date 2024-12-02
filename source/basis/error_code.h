/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-02 09:18:24
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-02 11:23:28
 */
#include <stdint.h>

#ifndef __ERROR_CODE_H__
#define __ERROR_CODE_H__

namespace xviewer::basis
{
    enum ErrorCode
    {
        NoError = 0,
        ConfigError = 100,
        IllegalInput = 200,
        MemoryError = 300,
        TimeoutError = 400,
        NetworkError = 500,
        UnknownError = 600
    };
}
#endif /* __ERROR_CODE_H__ */
