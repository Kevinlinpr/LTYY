#include "frame_displayer.h"

// static 
FrameDisplayer& FrameDisplayer::Get() {
    static FrameDisplayer frame_displayer;
    return frame_displayer;
}

FrameDisplayer::FrameDisplayer() : current_active_position_(wxDefaultPosition) {}

int FrameDisplayer::GetQuadrant() {
    int result = quadrant_;
    ++quadrant_;
    if(quadrant_ >= 4){
        quadrant_ = 0;
    }
    return result;
}

wxPoint FrameDisplayer::GetNextPosition(){
    int quadrant = GetQuadrant();
    wxPoint point;
    if(quadrant == 0){
        point.x = current_active_position_.x - 100;
        point.y = current_active_position_.y + 100;
    }else if(quadrant == 1){
        point.x = current_active_position_.x + 100;
        point.y = current_active_position_.y + 100;
    }else if(quadrant == 2){
        point.x = current_active_position_.x + 100;
        point.y = current_active_position_.y - 100;
    }else if(quadrant == 3){
        point.x = current_active_position_.x - 100;
        point.y = current_active_position_.y - 100;
    }
    return point;
}

void FrameDisplayer::SetCurrentActivePosition(wxPoint point){
    current_active_position_.x = point.x;
    current_active_position_.y = point.y;
}