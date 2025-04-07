#include <chrono>
#include <iostream>
#include <thread>
#include <Windows.h>

void clickMouse() {
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(input));
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(input));
}
void autoClick() {
    using namespace std::chrono;
    std::this_thread::sleep_for(seconds(1));

    const steady_clock::time_point start_time = steady_clock::now();

    while (std::chrono::duration_cast<milliseconds>(steady_clock::now() - start_time).count() < 1100) { // Change 1.1 seconds for depending CPS test
        clickMouse();
        std::this_thread::sleep_for(microseconds(1));
    }
}
int main() {
    clickMouse();
    autoClick();
    return 0;
}
