#include <iostream>
#include "src/plotting/Display.hpp"
#include <thread>
#include "src/robot/Robot.hpp"
void AtExit()
{
    std::cout << "End Of Program!!!!\n";
}

int main()
{
    std::atexit(AtExit);
    auto robot = Robot();
    std::shared_ptr<Display> disp = std::make_shared<Display>();
    
    while (disp->getIsRunning())
    {
        robot.update(0.1);
        disp->resetDisplay();
        disp->setDrawColor(0,0,0,0);
        robot.render(disp);
        disp->showDisplay();
        disp->processInput();
    }

    return 0;
}