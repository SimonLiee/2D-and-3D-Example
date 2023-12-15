#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "raylib.h"

// Init camera
void InitCamera(void);
// Set camera position
void SetCameraPosition(float x, float y);
// Begin draw mode for camera
void BeginMode(void);
// End draw mode for camera
void EndMode(void);

// Draw player
void DrawPlayer(Rectangle player);
// Draw Farm
void DrawFarm(Rectangle* farm, int width, int height);

#endif
