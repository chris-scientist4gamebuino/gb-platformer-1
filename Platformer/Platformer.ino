// author: chris-scientist
// created at: 29/01/2019
// updated at: 03/02/2019

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Commands.h"
#include "Display.h"
#include "PhysicsEngine.h"
#include "Interactions.h"
#include "Character.h"
#include "Platform.h"
#include "Object.h"

// Création du personnage
Character hero;
Platform setOfPlatforms[NB_OF_PLATFORMS];
Object setOfObjects[NB_OF_OBJECTS];
int stateOfGame = HOME_STATE;

void setup() {
  // initialiser la gamebuino
  gb.begin();

  initPlatforms(setOfPlatforms);

  /*
  // debug
  gb.display.clear();
  for(int i=0 ; i < NB_OF_PLATFORMS ; i++) {
    Platform zPlatform = setOfPlatforms[i];
    gb.display.printf("%d, %d : %d", zPlatform.x, zPlatform.y, zPlatform.lengthPlatform);
    gb.display.println("");
  }
  delay(10000);*/
}

void loop() {
  // boucle d'attente
  while(!gb.update());

  gb.display.clear();

  if(stateOfGame == HOME_STATE) {
    // Ecran d'accueil
    
    paintHomeScreen();
    initCharacter(hero); // ......... on réinitialise la position du personnage
    initObjects(setOfObjects); // ... on réinitialise les objets
    stateOfGame = manageCommandsForHome();
  } else {
    // Partie en cours...

    if(hero.state == ON_THE_PLATFORM_STATE) {
      stateOfGame = manageCommands(hero);
    }
    
    if(hero.state != JUMP_STATE && hero.state != PUSH_FOR_JUMP_STATE) {
      gravity(hero, setOfPlatforms);
    } else if(hero.state == JUMP_STATE || hero.state == PUSH_FOR_JUMP_STATE) {
      jump(hero, setOfPlatforms);
    }
    
    interactionsWithWorld(hero, setOfObjects);

    paint(hero, setOfPlatforms, setOfObjects);
    /*gb.display.setColor(BLACK);
    gb.display.printf("(%d, %d)",hero.x, hero.y); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    delay(500);*/
  }
}
