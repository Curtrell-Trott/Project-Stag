# Project-Stag

## Game Engine from Scratch Project   
This is a 2D game engine that is written in C++ using SDL, OpenGL, and ImGui. Created for a game idea I had called Project "S.T.A.G" or Sword To A Gunfight. A horizontal (yoko) "Shoot 'em up" style game where all you have is a sword and a shield.
![showcase image](./assets/Showcase.gif)

## Current Features
* **Game Loop:**            
  * the algorithm that keeps the logic constantly running at a consistent rate.
* **Sprite Rendering:**     
  * a rendering pipeline using an opengl and shaders to draw images on screen.
* **Dropshadow:**           
  * A visual element option for every entity. Created by re-drawing the sprite under the original, setting the colors to black and to a lower opacity, and rendering it at an offset position.
* **ImGui Implementation:** 
  * a GUI library added to create a debugging interface
* **Performance Tracker:**  
  * window that uses ImGui to display the framerate of the game in real-time 
* **Makefile:**             
  * script only compiles the new or changed code and builds the executable file. 

## WIP features
* **AABB Collision:** 
  * method of collision detection I started implementing but is not functional quite yet.
* **Animation System:** 
  * a dedicated Frame by Frame system for switching between sprites for full-fledge animations

## How to Run
Run the `main.exe` file
```
.\build\main.exe
```
## Controls
'WASD' keys - move <br />
'O' key 		- attack
