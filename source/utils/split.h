/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-03 13:28:37
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 13:30:06
 */
#include <stdint.h>

#ifndef __SPLIT_H__
#define __SPLIT_H__
#include <vector>
#include <string>

namespace xviewer::utils
{
    inline std::vector<std::string> split(const std::string &str, char delimiter = '\n')
    {
        std::vector<std::string> lines;
        size_t start = 0;
        size_t end = 0;
        while ((end = str.find(delimiter, start)) != std::string::npos)
        {
            lines.push_back(str.substr(start, end - start));
            start = end + 1;
        }
        lines.push_back(str.substr(start));
        return lines;
    }

    inline std::vector<std::string> split_lines(const std::string &str)
    {
        return split(str, '\n');
    }

    inline std::string trim(std::string str)
    {
        str.erase(0, str.find_first_not_of(" \n\r\t"));
        str.erase(str.find_last_not_of(" \n\r\t") + 1);
        return str;
    }
}

#endif /* __SPLIT_H__ */
