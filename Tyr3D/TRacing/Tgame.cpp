#include "Tgame.h"
#include <iostream>

#include "Core.h"
#include "Renderer.h"
#include "GameObject.h"
#include "RenderComponent.h"

//#include "TransformComponent.h"


int main()
{
    std::cout << "Quick test: Tyr3D_Game is running!" << std::endl;
    Tyr3D::Core core;

    //test code
   core.CreateWindow(800, 600, "Game");

    float triangleVerts[] = {
        //  pos.x, pos.y,    u,   v
         0.0f,  0.5f,0.0f,     0.5f, 1.0f,  // top
        -0.5f, -0.5f, 0.0f ,     0.0f, 0.0f,  // bottom left
         0.5f, -0.5f, 0.0f ,     1.0f, 0.0f   // bottom right
    };
    unsigned int triangleIndices[] = { 0, 1, 2 };

    // Create the game object and attach components
    //Tyr3D::GameObject triangleGO;
    //Tyr3D::RenderComponent rcomp;
    // Pass raw data pointer and total byte size for verts, and index count

    Tyr3D::Renderer rd;
    auto* rc = new Tyr3D::RenderComponent(triangleVerts,
        sizeof triangleVerts,
        triangleIndices,
        3);

    
    Tyr3D::renderer.AddComponents(rc);
   //triangleGO.AddComponent<TransformComponent>();


    core.Run();
}