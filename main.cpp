#include <iostream>
#include "src/plotting/Display.hpp"
#include <thread>
// #include "src/utility.hpp"
// #include "src/robot/Robot.hpp"
#include "src/robot/Simulation.hpp"
void AtExit()
{
    std::cout << "End Of Program!!!!\n";
}
int GRID_SIZE = 600;
int GRID_SPACEING = 50;

int main()
{
    std::atexit(AtExit);
    std::cout << __cplusplus << std::endl;
    auto sim = std::make_shared<Simulation>();
    std::shared_ptr<Display> disp = std::make_shared<Display>();

    
    while (disp->getIsRunning())
    {
        sim->update();
        disp->resetDisplay();
        // Draw Background Grid
        disp->setDrawColor(0, 0, 0,255);
        for (int x = -GRID_SIZE; x <= GRID_SIZE; x += GRID_SPACEING)
        {
            disp->drawLine(Point2D(x, -GRID_SIZE), Point2D(x, GRID_SIZE));
        }
        for (int y = -GRID_SIZE; y <= GRID_SIZE; y += GRID_SPACEING)
        {
            disp->drawLine(Point2D(-GRID_SIZE, y), Point2D(GRID_SIZE, y));
        }

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