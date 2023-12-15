#include "raylib.h"
#include "raymath.h"
#include "graphics.h"

Camera2D camera;

void InitCamera(void) {
    camera = (Camera2D) {
        (Vector2) {0, 0}, // Offset
        (Vector2) {0, 0}, // Target
        (float) 0,        // Rotation
        (float) 1,        // Zoom
    };
}

void BeginMode(void) {
    BeginMode2D(camera);
}

void EndMode(void) {
    EndMode2D();
}

void SetCameraPosition(float x, float y) {
    camera.target.x = x;
    camera.target.y = y;
}

void DrawPlayer(Rectangle player) {
    DrawRectangleRec(player, BLACK);
}

void DrawFarm(Rectangle* farm, int width, int height) {
    // DrawFarm(farm, width, height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
        {
            DrawRectangleRec((farm + i * height)[j], BROWN);
            DrawRectangleLinesEx((farm + i * height)[j], 1, YELLOW); 
        }
    }
}
