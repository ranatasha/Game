#pragma once

template<int deathGoal>
class EnemyGoal{
    int value;
    public:
    EnemyGoal(){
        this->value = 0;
    }
    bool isCompleted(){
        if(value >= deathGoal)
            return true;
        return false;
    }
    void addValue(){this->value += 1;}
    void restoreValue(int value){this->value = value;}
};