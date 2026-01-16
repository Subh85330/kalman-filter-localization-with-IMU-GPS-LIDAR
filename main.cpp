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
        disp->setDrawColor(0, 0, 0, 0);
        robot.render(disp);
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
                    robot.setVelocity(robot.getVelocity() + 0.1);
                    break;
                case SDLK_DOWN:
                    robot.setVelocity(robot.getVelocity() - 0.1);
                    break;
                case SDLK_RIGHT:
                    robot.setSteering(robot.getSteering() + 0.1);
                    break;
                case SDLK_LEFT:
                    robot.setSteering(robot.getSteering() - 0.1);
                    break;

                default:
                    break;
                }
            }
        }
    }

    return 0;
}