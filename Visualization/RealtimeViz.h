/**
 * @file    RealtimeViz
 * @author  Jonas Schlagenhauf <pho3nyx@web.de>
 * @version 0.1.0
 *
 * @copyright Copyright 6 March 2014 Jonas Schlagenhauf
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 * A SDL Renderer which constantly renders an image to screen.
 * It spawns its own thread to avoid a collision of the visualization with the
 * computation of the image.
 * The window can be closed with the ESC key.
 *
 * COMPATIBILITY: This program uses pthread, thus is limited to Linux.
 *
 * REMARK:
 * The functionality is only properly tested with 32bit color depth images.
 * Even though it should work with different parameters, you probably have to
 * adjust the color field masks. Crashes can occur.
 */


#ifndef REALTIME_VIZ_
#define REALTIME_VIZ_

#include <algorithm>
#include <inttypes.h>
#include <pthread.h>
#include <cassert>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

using namespace std;

/*
 * The image data and properties which are passed to the thread,
 * bundled nicely.
 */
struct DrawData
{
  uint32_t* image;
  int32_t width;
  int32_t height;
  int32_t depth;
  int32_t pitch;
  uint32_t rMask;
  uint32_t gMask;
  uint32_t bMask;
  uint32_t aMask;

  SDL_Surface* screen;
};

class RealtimeViz
{
  private:
    pthread_t thr;
    DrawData data;

  public:
    // spawns a thread, which loops around and draws
    void init(uint32_t* image, int32_t width, int32_t height, int32_t depth);
    // float to uint32 rgb conversion
    static inline uint32_t float2uint32(float r, float g, float b);
    // quits the thread and sdl window
    void quit();

  private:
    // the actual drawing
    static void* draw(void* ptr);
};

/*
 * Initializes the SDL framework, sets all image parameters and spawns a render
 * thread.
 *
 * @param image Pointer to an unsigned integer array of size width*height. This
 * array has to be filled by what ever application writes an image.
 * @param width Width of the image
 * @param height Height of the image
 * @param depth Color depth in BITS
 */
void RealtimeViz::init(uint32_t* image, int32_t width, int32_t height, int32_t depth)
{
  printf("Starting SDL realtime visualization...\n");
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return;

  data.screen = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE);
  data.image = image;
  data.width = width;
  data.height = height;
  data.depth = depth;
  data.pitch = width * 4;
  data.rMask = 0xFF000000;
  data.gMask = 0x00FF0000;
  data.bMask = 0x0000FF00;
  data.aMask = 0x00000000;

  assert(pthread_create(&thr, NULL, RealtimeViz::draw, (void*) &data) == 0);
}

/*
 * Helper function in case you have three floats as pixel values. Note that the
 * value range is 0.f-255.f
 *
 * @param r Red color value
 * @param g Green color value
 * @param b Blue color value
 * @return Unsigned integer containing the pixel rgb value
 */
inline uint32_t RealtimeViz::float2uint32(float r, float g, float b)
{
  uint32_t iR = max(r, 0.f);
  uint32_t iG = max(g, 0.f);
  uint32_t iB = max(b, 0.f);
  return (iR *256*256*256 + iG *256*256 + iB *256);
}

/*
 * Waits for the thread to finish (press ESC to end the rendering) and closes
 * the SDL window.
 */
void RealtimeViz::quit()
{
  assert(pthread_join(thr, NULL) == 0);
  SDL_Quit();
}

/*
 * The rendering function. Don't call this manually (haha you can't, it's private!)
 *
 * @param ptr Pointer to a DrawData structure
 */
void* RealtimeViz::draw(void* ptr)
{
  DrawData* data = (DrawData*) ptr;
  bool running = true;
  SDL_Event event;
  while (running)
  {
    while(SDL_PollEvent(&event))
      if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
        running = false;

    SDL_Surface* surf = SDL_CreateRGBSurfaceFrom(data->image, data->width, data->height,
        data->depth, data->pitch, data->rMask, data->gMask, data->bMask, data->aMask);

    SDL_BlitSurface(surf, NULL, data->screen, NULL);
    SDL_Flip(data->screen);
  }
  return NULL;
}

#endif // REALTIME_VIZ_
