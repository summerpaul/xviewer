/**
 * @Author: Xia Yunkai
 * @Date:   2024-12-01 21:38:38
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-03 09:16:07
 */

#ifndef __XVIEWER_H__
#define __XVIEWER_H__

class Document;
namespace xviewer
{

    class XViewer
    {
    public:
        XViewer();

        ~XViewer();

        bool Init();

        void Run();

        void Shutdown();

        bool IsRunning() const;

        void Update();

    protected:
        Document *m_pDocument;
        bool m_initialized;
    };
}

#endif /* __XVIEWER_H__ */
