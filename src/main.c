#include "raylib.h"
#include "raymath.h"
#include "graphics.h"

#ifndef GRAPHICS3D
#define GRAPHICS2D
#endif

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 600

#define PLAYER_WIDTH 30
#define PLAYER_HEIGHT 30
#define PLAYER_SPEED 0.2

#define FARM_WIDTH 15
#define FARM_HEIGHT 10
#define FARM_PLOT_WIDTH 40
#define FARM_PLOT_HEIGHT 40

enum Direction {
    DIR_NONE,
    DIR_UP,
    DIR_RIGHT,
    DIR_DOWN,
    DIR_LEFT
};

Vector2 GetMoveDir(void);

int main(void) { 

    Rectangle player = {0, 0, PLAYER_WIDTH, PLAYER_HEIGHT};
    Vector2 playerMovement;  // Movement of player this tick

    Rectangle farm[FARM_WIDTH][FARM_HEIGHT];
    for (int i = 0; i < FARM_WIDTH; i++)
    {
        for (int j = 0; j < FARM_HEIGHT; j++)
        {
            farm[i][j] = (Rectangle) {
                j * FARM_PLOT_WIDTH,
                i * FARM_PLOT_HEIGHT,
                FARM_PLOT_WIDTH,
                FARM_PLOT_HEIGHT
            };
        }
    }
    
    float lastTickTime = 0; // Time when last tick started

    InitCamera();
    Camera3D camera = (Camera3D) { 
        { 0.0f, 10.0f, 10.0f }, // Position
        { 0.0f, 0.0f, 0.0f },    // Target
        { 0.0f, 1.0f, 0.0f }, // Up rotation
        45.0f,                // FOV
        CAMERA_PERSPECTIVE    // Projection
    };

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Farming Game");

    while (!WindowShouldClose()) {
        // Calculate physics every 60 seconds
        if( GetTime() - lastTickTime > 1 / 60) { 
            lastTickTime = GetTime();

            // Update player direction based on keyPress
            Vector2 playerMovement = GetMoveDir();
            playerMovement = Vector2ClampValue(playerMovement, PLAYER_SPEED, PLAYER_SPEED);

            player.x += playerMovement.x;
            player.y += playerMovement.y;

            #ifdef GRAPHICS2D
            SetCameraPosition(player.x + player.width / 2 - WINDOW_WIDTH / 2, 
                              player.y + player.height / 2 - WINDOW_HEIGHT / 2);
            #else 
            SetCameraPosition(player.x, 
                              player.y);
            #endif
        }
        
        // Draw everything
        BeginDrawing();
            ClearBackground(WHITE);
            BeginMode();
                DrawFarm((Rectangle*)farm, FARM_WIDTH, FARM_HEIGHT);
                DrawPlayer(player);
            EndMode();
            DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}

Vector2 GetMoveDir(void) {
    Vector2 dir = {0};
    if (IsKeyDown(KEY_W)) {
        dir.y -= 1;
    } 
    if (IsKeyDown(KEY_S)) {
        dir.y += 1;
    } 
    if (IsKeyDown(KEY_D)) {
        dir.x += 1;
    } 
    if (IsKeyDown(KEY_A)) {
        dir.x -= 1;
    } 

    return dir;
}
