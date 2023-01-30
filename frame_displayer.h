#ifndef LTYY_FRAME_DISPLAYER_H_
#define LTYY_FRAME_DISPLAYER_H_
#include <wx/gdicmn.h>

class FrameDisplayer {
public:
    FrameDisplayer(const FrameDisplayer&) = delete;
    FrameDisplayer& operator=(const FrameDisplayer&) = delete;

    static FrameDisplayer& Get();

    void SetCurrentActivePosition(wxPoint point);

    wxPoint GetNextPosition();

    ~FrameDisplayer() = default;
private:
    FrameDisplayer();

    int GetQuadrant();

    int quadrant_;

    wxPoint current_active_position_;

};


#endif // LTYY_FRAME_DISPLAYER_H_