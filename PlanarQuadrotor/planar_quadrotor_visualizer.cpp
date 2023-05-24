#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr): quadrotor_ptr(quadrotor_ptr) {}

/**
 * TODO: Improve visualizetion
 * 1. Transform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen
 * 2. Use more shapes to represent quadrotor (e.x. try replicate http://underactuated.mit.edu/acrobot.html#section3 or do something prettier)
 * 3. Animate proppelers (extra points)
 */



void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer>& gRenderer) {
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    float q_x, q_y, q_theta;

    /* x, y, theta coordinates */
    q_x = state[0];
    q_y = state[1];
    q_theta = state[2];

    

    Sint16 vx[4];
    Sint16 vy[4];

    int l=100;
    int h=10;

    float x1, x2, y1, y2;

    x1 = q_x + cos(q_theta) * (l / 2);
    x2 = q_x - cos(q_theta) * (l / 2);
    y1 = q_y - sin(q_theta) * (l / 2);
    y2 = q_y + sin(q_theta) * (l / 2);
    vx[0] = x1 - sin(q_theta) * (h / 2);
    vx[1] = x1 + sin(q_theta) * (h / 2);
    vx[2] = x2 + sin(q_theta) * (h / 2);
    vx[3] = x2 - sin(q_theta) * (h / 2);
    vy[0] = y1 - cos(q_theta) * (h / 2);
    vy[1] = y1 + cos(q_theta) * (h / 2);
    vy[2] = y2 + cos(q_theta) * (h / 2);
    vy[3] = y2 - cos(q_theta) * (h / 2);

    filledPolygonColor(gRenderer.get(), vx, vy, 4, 0xff98aaaa);
}   
