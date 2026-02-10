# This is pong
My plan for this pong game are:
1. Create window +
2. Draw a triangle
3. Make a game subfolder
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

## 10.02.2026

So i took a break from feature branch to opengl branch because i felt stuck. I felt like i was cornering myself with unusable unmaintanable code. So i just read and did what [openglBook](https://learnopengl.com/Getting-started/Hello-Triangle) said and drew a trianlge for accomplishment feelings. I asked around for help about designing a game engine (Nobody in my Department works on graphics. Not even 1 assistant.) i got nowhere. And one of my friend said "Bro making a game engine is a huge project. You need to grasp concept of OOP beforehand. Read design patters book." And i took his advice and did not read the book :D. I read Head first OOAD first because i lack basic concepts for OOP i think. And with that i will port my opengl branch to feature branch. If its possible.

