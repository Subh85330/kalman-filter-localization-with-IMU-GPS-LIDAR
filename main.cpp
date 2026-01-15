#include <iostream>
#include "src/plotting/Display.hpp"
#include <thread>
#include "src/robot/Robot.hpp"
void AtExit()
{
    std::cout << "Make Sure all memory are freed!!!!!!!!\n";
}

int main()
{
    std::atexit(AtExit);
    auto robot = Robot();
    
    std::shared_ptr<Display> disp = std::make_shared<Display>();
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetRenderDrawColor(disp->getRenderer(), 255,255,255,255);
    SDL_RenderClear(disp->getRenderer());
    SDL_SetRenderDrawColor(disp->getRenderer(),0,0,0,0);
    robot.render(disp);
    
    SDL_RenderPresent(disp->getRenderer());
    
    std::this_thread::sleep_for(std::chrono::seconds(5));


    return 0;
}