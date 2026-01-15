#include <iostream>
#include "src/plotting/Display.h"
#include <thread>

void AtExit()
{
    std::cout << "Make Sure all memory are freed!!!!!!!!\n";
}

int main()
{
    std::atexit(AtExit);
    std::shared_ptr<Display> disp = std::make_shared<Display>();
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetRenderDrawColor(disp->getRenderer(), 255,255,255,255);
    SDL_RenderClear(disp->getRenderer());
    SDL_RenderPresent(disp->getRenderer());
    std::this_thread::sleep_for(std::chrono::seconds(1));


    return 0;
}