/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-03 13:26:50
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 13:36:58
 */

#ifndef __RECENT_FILES_H__
#define __RECENT_FILES_H__
#include <deque>
#include <vector>
#include <string>
namespace xviewer::utils
{
    class RecentFiles
    {
    public:
        RecentFiles();
        RecentFiles(const std::string &tag, int max_history = 10);
        ~RecentFiles();

        void clear();
        void push(const std::string &filename);
        void push(const std::vector<std::string> &filenames);

        bool empty() const;
        size_t size() const;

        std::string most_recent() const;
        std::string fullpath(size_t i) const;
        std::string filename(size_t i) const;

    public:
        void read();
        void write();

    private:
        bool updated;
        std::string tag;
        int max_history;

        std::deque<std::string> recent_files;
    };
}
#endif /* __RECENT_FILES_H__ */
