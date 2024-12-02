/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-02 09:24:14
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-02 09:39:48
 */

#ifndef __STATUS_H__
#define __STATUS_H__
#include <string>
#include "error_code.h"

namespace xviewer
{
    class Status
    {
    public:
        Status() : m_code(NoError), m_msg("") {}

        Status(ErrorCode code, const std::string &msg)
            : m_code(code), m_msg(msg) {}

        explicit Status(ErrorCode code)
            : m_code(code), m_msg("") {}

        static Status OK() { return Status(); }

        bool IsOK() const { return m_code == NoError; }

        ErrorCode Code() const { return m_code; }

        const std::string &Message() const { return m_msg; }

        std::string ToString() const
        {
            if (IsOK())
            {
                return "OK";
            }
            return ToStr(m_code) + ": " + m_msg;
        }

    private:
        std::string ToStr(ErrorCode code) const
        {
            return "ErrorCode: " + std::to_string(static_cast<int>(code));
        }

    private:
        ErrorCode m_code;
        std::string m_msg;
    };
}

#endif /* __STATUS_H__ */
