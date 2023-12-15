#include "raylib.h"
#include "raymath.h"
#include "graphics.h"

Camera3D camera;

void InitCamera(void) {
    camera = (Camera3D) { 
        { 0.0f, 100.0f, 0.0f }, // Position
        { 0.0f, 0.0f, 0.0f },    // Target
        { 0.0f, 0.1f, 0.0f }, // Up rotation
        45.0f,                // FOV
        CAMERA_PERSPECTIVE    // Projection
    };
}

void BeginMode(void) {
    BeginMode3D(camera);
}

void EndMode(void) {
    EndMode3D();
}

void SetCameraPosition(float x, float y) {
    camera.position.x = x;
    camera.position.z = y + 200;
    camera.target.x = x;
    camera.target.z = y;
}

void DrawPlayer(Rectangle player) {
    DrawCube((Vector3){player.x, 0, player.y}, player.width, 100.0f, player.height, RED);
}

void DrawFarm(Rectangle* farm, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++)
        {
            //DrawCube((Vector3){(farm + i * height)[j].x, 0, (farm + i * height)[j].y}, (farm + i * height)[j].width, 0.1f, (farm + i * height)[j].height, GREEN);
            DrawCubeWires((Vector3){(farm + i * height)[j].x, 0, (farm + i * height)[j].y}, (farm + i * height)[j].width, 0.1f, (farm + i * height)[j].height, BROWN);
        }
    }
}
