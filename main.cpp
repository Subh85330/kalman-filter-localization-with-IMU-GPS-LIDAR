#include <iostream>
#include "src/plotting/Display.hpp"
#include <thread>
// #include "src/robot/Robot.hpp"
#include "src/robot/Simulation.hpp"
void AtExit()
{
    std::cout << "End Of Program!!!!\n";
}

int main()
{
    std::atexit(AtExit);
    auto sim = std::make_shared<Simulation>();
    std::shared_ptr<Display> disp = std::make_shared<Display>();

    while (disp->getIsRunning())
    {
        sim->update();
        disp->resetDisplay();
        disp->renderGrid(0,0);
        disp->setDrawColor(0, 0, 0, 255);
        sim->render(disp);
        disp->showDisplay();
        // disp->processInput();

        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                disp->setIsRunning(false);
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    disp->setIsRunning(false);
                    break;
                case SDLK_i:
                    break;
                case SDLK_UP:
                    sim->setVelocity(sim->getVelocity() + 0.1);
                    break;
                case SDLK_DOWN:
                    sim->setVelocity(sim->getVelocity() - 0.1);
                    break;
                case SDLK_RIGHT:
                    sim->setSteering(sim->getSteering() + 0.05);
                    break;
                case SDLK_LEFT:
                    sim->setSteering(sim->getSteering() - 0.05);
                    break;
                case SDLK_SPACE:
                    sim->togglePause();
                    break;
                case SDLK_s:
                    // to stop vehicle
                    sim->setVelocity(0);
                    sim->setSteering(0);
                    break;
                case SDLK_MINUS:
                    sim->decreaseViewSize();
                    break;
                case SDLK_EQUALS:
                    sim->increaseViewSize();
                    break;

                default:
                    break;
                }
            }
        }
    }

    return 0;
}