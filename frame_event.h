#ifndef LTYY_FRAME_EVENT_H_
#define LTYY_FRAME_EVENT_H_

class FramePositionEvent {
public:
    virtual void OnActiveEvent(wxEvent& event) = 0;
};

#endif // LTYY_FRAME_EVENT_H_