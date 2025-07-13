#include "Tgame.h"
#include <iostream>

#include "Core.h"
#include "Renderer.h"

Tyr3D::Renderer renderer;

int main()
{
    std::cout << "Quick test: Tyr3D_Game is running!" << std::endl;
    Tyr3D::Core core;
    //Tyr3D::Core::CreateWindow(800, 600, "T-Racing");
    core.Run();
    //renderer.Draw();
}