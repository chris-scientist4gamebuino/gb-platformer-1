// author: chris-scientist
// created at: 30/01/2019

#ifndef PLATFORMER_PLATFORM
#define PLATFORMER_PLATFORM

struct Platform {
  int x; // ................ position x du début de la plateforme (centre de la première plateforme)
  int y; // ................ position y de la plateforme (centre de la plateforme)
  int lengthPlatform; // ... longueur de la plateforme en bloc (doit être au minimum égale à 2), un bloc fait 5 pixels sur 5
};

void initPlatforms(Platform * aSet);
Platform buildPlatform(int aX, int aY, int aLength);

#endif
