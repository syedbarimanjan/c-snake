#include <stdio.h>
#include <raylib.h>

#define SCALE 0.75

#define BASE_WIDTH 1920
#define BASE_HEIGHT 1080
#define WINDOW_WIDTH ((int)(BASE_WIDTH * SCALE))
#define WINDOW_HEIGHT ((int)(BASE_HEIGHT * SCALE))
#define GAME_WIDTH ((int)(BASE_WIDTH / 2)) // 960
#define GAME_HEIGHT ((int)(BASE_HEIGHT / 2))

#define ROWS 14
#define COLUMNS 26
#define TILE_SIZE 32
#define TILE_SPACING 4

typedef enum {
  EMPTY_TILE,
  VISITED_TILE,
} TileState;

typedef struct {
  TileState state;
} Tile;

typedef struct {
  Tile tileGrid[ROWS][COLUMNS];
} Game;

Game game;

void InitTileGrid(void) {
  for (int row = 0; row < ROWS; row++) {
    for (int column = 0; column < COLUMNS; column++) {
      Tile *tile = &game.tileGrid[row][column];
      tile->state = EMPTY_TILE;
    }
  }
}

void InitGame(void) {
  InitTileGrid();
}

Color GetTileColor(TileState state) {
  switch (state) {
  case EMPTY_TILE:
    return (Color) {20,20,20,255};
  case VISITED_TILE:
    return (Color) {50,50,50,255};
  }
}

void DrawTileGrid(void) {
  for (int row = 0; row < ROWS; row++) {
    for (int column = 0; column < COLUMNS; column++) {
      Tile *tile = &game.tileGrid[row][column];

      float drawX = column * (TILE_SIZE + TILE_SPACING);
      float drawY = row * (TILE_SIZE + TILE_SPACING);

      Vector2 position = (Vector2){
        .x = drawX,
        .y = drawY,
      };
      Vector2 size = (Vector2){
        .x = TILE_SIZE,
        .y = TILE_SIZE,
      };
      Color color = GetTileColor(tile->state);
      
      DrawRectangleV(position, size, color);
    }
  }
}


int main(void) {

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "c-snake");

  SetTargetFPS(60);

  RenderTexture2D target = LoadRenderTexture(GAME_WIDTH,GAME_HEIGHT);

  InitGame();

  while (!WindowShouldClose())
  {
    BeginTextureMode(target);
      ClearBackground(BLACK);
      DrawTileGrid();

    EndTextureMode();

    BeginDrawing();

      ClearBackground(BLACK);

      DrawTexturePro(
        target.texture,
        (Rectangle) {0,0, GAME_WIDTH, -GAME_HEIGHT},
        (Rectangle) {0,0, WINDOW_WIDTH, WINDOW_HEIGHT},
        (Vector2)   {0},
        0,
        WHITE
      );

    EndDrawing();
  }

  CloseWindow();

  return 0;
  
}