# This is pong
My plan for this pong game are:
1. Create window +
2. Draw a triangle +
3. Make a game subfolder +
4. Use Engine backend to render 2 squares and a ball
5. Implement Collision Detection in Engine
6. Implement Collision Logic in Game
7. Implement ball physics in Game
8. Implement score counting in Game


## 03.02.2026:
* I realized something. My plans were make this engine rendering api agnostic.
But to do that I realized I need to fight glfw to do this.
Quote from GLFW website itself
```
GLFW is an Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan development on the desktop.
```

I looked it up and technically i can make it work but
it clearly did not designed this way.

So my plan is continue development `BUT` and this is a`BIG BUT`
In no curcumstances i will use any system from glfw from now on.
If i need another system to interact Operating system specific things i will transition to SDL project.
SDL project is not a `GLFW: An OpenGL library`(PS it is what Page Title says) .
In `https://wiki.libsdl.org/SDL3/FrontPage` 
section `What is it?`
```
Simple DirectMedia Layer is a cross-platform development
library designed to provide low level access to audio
keyboard, mouse, joystick, and graphics hardware via
OpenGL/Direct3D/Metal/Vulkan.
```

So SDL thinks directx and metal as a first class citizen
as much as Vulkan and OpenGL.
I presume Playstation,XBOX and Nintendo rendering apis can be used with sdl too.

PS. [Yeah it does](https://wiki.libsdl.org/SDL3/READMEs). But when you are under nda

Yeah thats it. continue in glfw until you hit a roadblock

