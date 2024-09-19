#ifndef DEFINITONS_H

#define DEFINITONS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_stdinc.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_NAME "En-Chess" 
#define __ASSETS__ "src/assets/" 

typedef char Board[8][8];

typedef struct {
  SDL_Texture *tex;
  int width;
  int height;
} Image;

typedef enum { PLAYER = 1, COMPUTER = 0 } Turn;

typedef struct {
  Turn turn;
  SDL_bool isReversed;
} GameData;

typedef struct {
   SDL_bool isRunning; 
   struct {
      unsigned int w;
      unsigned int h;
      const char *name;
      SDL_Window *window;
      SDL_Renderer *renderer;
   } screen;

   void (*init)(void);
   void (*quit)(void);
} GameInstance;

extern GameData gameData;
extern GameInstance Game;
extern Board boardInfo;

Image 
  lightSquare, lightPawn, lightQueen, lightKing, lightKnight, lightRook, lightBishop, 
  darkSquare, darkPawn, darkQueen, darkKing, darkKnight, darkRook, darkBishop;

void init(void);
void quit(void);
void render(void);

/*void renderSVG(Image image, int x, int y);*/
/*
 * Render an SVG image in a x, y position
 */

Image svg2Tex(char *fileName, int width, int height);
/*
 * Convert svg to a texture for rendering 
 */

void renderChessBoard(int width, int height);
/*
 *  
 */

void renderImage(Image image, int x, int y);


void loadTextures();

#endif
