#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr): quadrotor_ptr(quadrotor_ptr) {}

/**
 * TODO: Improve visualizetion
 * 1. Transform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen
 * 2. Use more shapes to represent quadrotor (e.x. try replicate http://underactuated.mit.edu/acrobot.html#section3 or do something prettier)
 * 3. Animate proppelers (extra points)
 */



void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer> &gRenderer) {
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    float q_x, q_y, q_theta;

    /* x, y, theta coordinates */
    //q_x = state[0];
    //q_y = state[1];
    //q_theta = state[2];

    int screenWidth, screenHeight;
    SDL_GetRendererOutputSize(gRenderer.get(), &screenWidth, &screenHeight);
    float centerX = screenWidth / 2.0f;
    float centerY = screenHeight / 2.0f;

    q_x = centerX - (30 / 2.0f); 
    q_y = centerY - (30 / 2.0f); 

    // Zdefiniuj rozmiar drona
    int droneWidth = 250;
    int droneHeight = 30;

    // Oblicz pozycję lewego górnego rogu drona
    float droneX = centerX - (droneWidth / 2.0f);
    float droneY = centerY - (droneHeight / 2.0f);

    //Rozmiar Skrzydeł
    int WingWidth = 15;
    int WingHeight = 60;

    //Lewe Skrzydło
    float LWingX = centerX - (droneWidth / 2.0f) + 10;
    float LWingY = centerY - WingHeight - (droneHeight / 2.0f);

    //Prawe Skyrzdło
    float RWingX = centerX + (droneWidth / 2.0f) - 10 - WingWidth;
    float RWingY = centerY - WingHeight - (droneHeight / 2.0f);
    

    // Narysuj prostokąt z obramowaniem i wypełnieniem
    SDL_Rect droneRect = { static_cast<int>(droneX), static_cast<int>(droneY), droneWidth, droneHeight };
    SDL_Rect LWingRect = { static_cast<int>(LWingX), static_cast<int>(LWingY), WingWidth, WingHeight };
    SDL_Rect RWingRect = { static_cast<int>(RWingX), static_cast<int>(RWingY), WingWidth, WingHeight };

    SDL_SetRenderDrawColor(gRenderer.get(), 0x00, 0x00, 0x00, 0xFF); // Czarny
    SDL_RenderDrawRect(gRenderer.get(), &droneRect);
    SDL_SetRenderDrawColor(gRenderer.get(), 0x80, 0x80, 0x80, 0xFF); // Szary
    SDL_RenderFillRect(gRenderer.get(), &droneRect);

    SDL_SetRenderDrawColor(gRenderer.get(), 0x00, 0x00, 0x00, 0xFF); // Czarny
    SDL_RenderDrawRect(gRenderer.get(), &LWingRect);
    SDL_SetRenderDrawColor(gRenderer.get(), 0, 118, 191, 0xFF); // Blekitny
    SDL_RenderFillRect(gRenderer.get(), &LWingRect);

    SDL_SetRenderDrawColor(gRenderer.get(), 0x00, 0x00, 0x00, 0xFF); // Czarny
    SDL_RenderDrawRect(gRenderer.get(), &RWingRect);
    SDL_SetRenderDrawColor(gRenderer.get(), 0, 118, 191, 0xFF); // Blekitny
    SDL_RenderFillRect(gRenderer.get(), &RWingRect);

    //SDL_SetRenderDrawColor(gRenderer.get(), 0xFF, 0x00, 0x00, 0xFF);
    //filledCircleColor(gRenderer.get(), q_x, q_y, 30, 0xFF0000FF);
}