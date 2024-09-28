#pragma once
#include "Script.h"
#include "MessageBox.h"
class ZakoScript :
    public Script
{
private:
    E_Message get_sensai;
    bool mouse_focus;
public:
    ZakoScript();
    void start(GameObject* me);
    void update(GameObject* me);
    Script* instance() override;
    void on_click(GameObject* me);
};

