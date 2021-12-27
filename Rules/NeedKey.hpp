#pragma once

template<bool request>
class NeedKey{
    bool hasKey;
    public:
    NeedKey(){
        this->hasKey = false;
    };
    bool isCompleted(){
        if(request){
            if(hasKey)
                return true;
            return false;
        }
        return true;
    }
    void setHasKeyTrue(){
        this->hasKey = true;
    }
};