#include "MousePos.h"
MousePos* MousePos::mousepos = nullptr;
std::mutex MousePos::mpos_mutex;
double MousePos::x;
double MousePos::y;
MousePos* MousePos::getinstance()
{
    if (mousepos == nullptr) {
        std::lock_guard<std::mutex> m(mpos_mutex);
        if (mousepos == nullptr) {
            mousepos = new MousePos();
        }
    }
    return mousepos;
}

void MousePos::update(GLFWwindow*& window)
{
    glfwGetCursorPos(window, &x, &y);
}
