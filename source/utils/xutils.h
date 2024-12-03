/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-03 13:31:59
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 13:33:13
 */
#include <stdint.h>

#ifndef __XUTILS_H__
#define __XUTILS_H__

#include <string>
#include <chrono>
#include <ctime>
#include <fstream>
#include <algorithm>
namespace xviewer::utils
{

    inline std::string FormatDoubleValue(double val, int fixed)
    {
        std::string str = std::to_string(val);
        return str.substr(0, str.find('.') + fixed + 1);
    }

    inline std::string FormatFloatValue(float val, int fixed)
    {
        std::string str = std::to_string(val);
        return str.substr(0, str.find('.') + fixed + 1);
    }

    inline std::string GetFileTag(const std::string &file)
    {
        return file.substr(file.find_last_of('.') + 1);
    }

    inline std::string GetFileName(const std::string &file)
    {
        std::string::size_type iPos = (file.find_last_of('\\') + 1) == 0 ? file.find_last_of('/') + 1 : file.find_last_of('\\') + 1;
        std::string fileName = file.substr(iPos, file.length() - iPos);
        return fileName.substr(0, fileName.rfind('.'));
    }

    inline std::string GetFilePath(const std::string &file)
    {
        std::string::size_type iPos = (file.find_last_of('\\') + 1) == 0 ? file.find_last_of('/') + 1 : file.find_last_of('\\') + 1;
        return file.substr(0, iPos);
    }

    template <typename T>
    inline T RandomRange(T min, T max)
    {
        T scale = rand() / (T)RAND_MAX;
        return min + scale * (max - min);
    }

    inline bool ReadFileAsString(const std::string &filepath, std::string &result)
    {
        bool ret = false;
        std::ifstream in(filepath, std::ios::in | std::ios::binary);
        if (in)
        {
            in.seekg(0, std::ios::end);
            result.resize((size_t)in.tellg());
            in.seekg(0, std::ios::beg);
            in.read(&result[0], result.size());
            in.close();
            ret = true;
        }
        return ret;
    }

    static int GetBinarySearchIndex(const std::vector<double> &sortedArray, const double &targetValue)
    {
        int id = -1;
        auto lower = std::lower_bound(sortedArray.begin(), sortedArray.end(), targetValue);
        if (lower == sortedArray.end())
        {
            id = -1;
        }
        else
        {
            id = int(std::distance(sortedArray.begin(), lower) - 1);
        }
        return id;
    }

} // namespace basis

#endif /* __XUTILS_H__ */
