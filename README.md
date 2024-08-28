# 42 Schools Cube3D
## Overview

Cube3D is a captivating 3D cube simulation built entirely in C, utilizing the Codam 42MinilibX for graphics rendering. This project showcases advanced graphics programming concepts, including camera orientation, collision detection, and real-time minimap functionality. Developed for Linux, Cube3D demonstrates the power of C programming and the flexibility of the MinilibX library in creating interactive 3D environments.

<p align="center">
  <a href="https://www.youtube.com/watch?v=u0BOMz-P6uA" target="_blank" rel="noopener noreferrer">
    <img src="https://img.youtube.com/vi/u0BOMz-P6uA/hqdefault.jpg" alt="Watch the video" style="width: 40%; height: auto; border: none;">
  </a>
</p>






## Features

- **3D Cube Rendering**: Real-time rendering of a 3D cube with smooth rotations and transformations.
- **Camera Orientation via Mouse Control**: Provides intuitive camera movement by capturing mouse input, allowing users to freely explore the 3D environment.
- **Wall Collision Detection**: Prevents the camera from passing through the cube's walls, creating a more immersive and realistic experience.
- **Minimap with Direction and Impact Point**: A dynamic minimap that displays the player’s orientation and the exact point where the camera’s view intersects with the environment.
- **Game Icon in Toolbar**: A custom game icon appears in the Linux toolbar, enhancing the user interface and overall experience.

## Installation

To get started with 4Cube3D, follow the steps below:

### Prerequisites

- A Linux-based system
- GCC compiler

### Compilation

1. Clone the repository:

  ```bash
    git clone https://github.com/BorisMichaelRandebrock/cube3D.git
    cd 42s_Cube3D
  ```

2. Compile the program using the provided Makefile:
  
  ```bash  
    make
  ```


### Run the program

To run the program, use:
  
  ```bash  
    make run
  ```
  
or 

   ```bash
    ./bin/cub3D ./res/level_peninsula.cub
   ```
you can also load any other map.cub you create (or have)....

## Usage

### Mouse Controls

- Move the mouse right or left to change the camera orientation.
- Explore the 3D cube environment by rotating the camera.
- Click the x to exit the program.

### Keyboard Controls

- `W`, `A`, `S`, `D` to move forward, strafe-left, backward, and strafe-right, respectively.
- `Q` and `E` to rotate the camera left and right.
- Right and Left arrow keys to rotate the camera.
- `Esc` to exit the program.

### Minimap

- The minimap in the left top corner of the screen displays the players current situation & orientation.
- It also shows the impact point of your view when it intersects with the environment.

## Bonus Features

### Camera Orientation via Mouse Control

This feature allows for a more immersive experience by enabling smooth camera movement using the mouse. You can explore the 3D environment intuitively by simply moving the mouse right or left, making navigation within the cube seamless and responsive.

### Wall Collision Detection

The cube environment includes realistic wall collision detection. The camera will stop when it encounters a wall, preventing the user from passing through the cube's surfaces. This adds a layer of realism and enhances the overall user experience.

### Minimap with Direction and Impact Point

The minimap is a standout feature that not only shows your current orientation within the 3D space but also displays the exact point where your camera's view intersects with the cube's environment. This is especially useful for navigation and adds depth to the user interaction.

## Technical Details

- **Rendering**: The 3D cube is rendered using basic graphics primitives provided by the Codam 42MinilibX.
- **Camera Control**: Implemented by capturing mouse movement and translating it into camera orientation changes within the 3D space.
- **Collision Detection**: Achieved through mathematical checks that determine if the camera's position intersects with the cube's surfaces.
- **Minimap**: A 2D representation of the 3D environment, updated in real-time to reflect the camera's orientation and view impact points.

## Acknowledgments

This project is a testament to the power and simplicity of the C programming language and the Codam 42MinilibX. Special thanks to the 42 Network for providing an innovative and inspiring learning environment that encourages creative and technical growth.

<a href="https://www.youtube.com/watch?v=u0BOMz-P6uA" target="_blank">
    <img src="https://img.youtube.com/vi/u0BOMz-P6uA/hqdefault.jpg" alt="cube3D in action" style="width: 100%; height: auto; display: block;">
    <img src="https://img.icons8.com/ios-filled/50/000000/play--v1.png" alt="Play Button" style="position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%); width: 50px;">
  </a>





<!---
[![Watch the video](https://img.youtube.com/vi/u0BOMz-P6uA/hqdefault.jpg)](https://www.youtube.com/watch?v=u0BOMz-P6uA)
https://www.youtube.com/watch?v=u0BOMz-P6uA
[![Watch the video](https://img.youtube.com/vi/u0BOMz-P6uA/hqdefault.jpg)](https://www.youtube.com/watch?v=u0BOMz-P6uA)

[![ Cube in action](https://img.youtube.com/vi/u0BOMz-P6uA/hqdefault.jpg)](https://www.youtube.com/watch?v=u0BOMz-P6uA)
     --->
