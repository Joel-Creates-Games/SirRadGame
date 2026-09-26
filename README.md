# SirRad - Custom 2D C++ Physics Engine & Skateboarding Game

**SirRad** is a custom-built 2D skateboarding game and proprietary physics engine developed entirely from scratch in C++ and SDL2. 

This project was developed under a university brief: *"Create a 90-second C++ game using SDL where the music directly ties into the game mechanics."*

To solve this, I designed an optimized 2D skateboarding game where the custom soundtrack lyrics explicitly teach the player the controls, announce new mechanics, and cue the moments enemy types spawn into the screen over the 90-second runtime. 

## ⚙️ Core Architecture & Optimizations

Because the game relies on fast-moving physics and momentum 60 FPS was the primary engineering goal. To achieve this without relying on a commercial engine, I built several low-level systems from scratch:

### 1. O(1) Spatial Hash Partitioning
To prevent the physics step from bottlenecking during high-entity moments, I made a custom Spatial Hash Grid. 
* Rather than checking every entity against every other entity—which causes an O(n^2) performance crash—the grid maps colliders to spatial coordinates.
* This reduces the collision pipeline time complexity to O(n) by utilizing O(1) coordinate hashing, ensuring the engine only checks for collisions between objects occupying the same physical sector of the screen.

### 2. Zero-Allocation Object Pooling
To prevent memory fragmentation and ensure the 60Hz physics tick rate never drops due to heap allocations, I implemented Object Pool containers.
* Enemies, projectiles, and environmental hazards are pre-allocated at runtime startup.
* The engine actively recycles memory blocks for spawned/destroyed entities, removing `new` and `delete` calls during the 90-second gameplay loop.

### 3. Deterministic Custom Physics
* Developed a custom 2D physics pipeline specifically tuned for skateboarding mechanics (momentum, gravity, and velocity retention).
* The physics and collision response systems are decoupled from the rendering loop, running on a fixed 60Hz tick rate to ensure consistent momentum regardless of visual framerate.

## 🛠️ Tech Stack
* **Language:** C++
* **Framework:** SDL2 (Simple DirectMedia Layer)
* **Architecture:** Data Encapsulation, Object Pooling, Spatial Hashing, Fixed-Step Physics

## 🚀 How to Run
Play it on my portfolio website! After university I used Emscripten to allow the game to be played in browser.
https://joelcarter.online/projects/SirRad.html
you may need to click onto the window in order for the controls to start registering, beware the game begins to run the moment the page loads.
