# Cub3D

## Overview

The `cub3D` project is a 3D game inspired by Wolfenstein 3D, created using the MinilibX library. The objective was to explore and implement ray-casting and not so much to create a real game, thus this is just an empty maze.

## Features

- 3D rendering using raycasting
- Player movement and rotation
- Textured walls and sprites
- Collision detection

## Controls

- `W`: Move forward
- `A`: Move left
- `S`: Move backward
- `D`: Move right
- `Left Arrow`: Rotate left
- `Right Arrow`: Rotate right
- `ESC`: Exit the game

## Usage

### Compiling

To compile the project, run:

```sh
make
```

This will generate the executable: `cub3D`.

### Running the Game

To start the game, run:

```sh
./cub3D [map_file]
```

Example:

```sh
    ./cub3D map.cub
```

## Map File

The map file should be a `.cub` file containing the layout of the game level, the texture path for each faces (`NO`, `SO`, `WE`, `EA`) and the RGB decimal color for the floor ans ceiling (`F`, `C`). The map should be closed and composed of the following characters:

- `1`: Wall
- `0`: Empty space
- `N`, `S`, `E`, `W`: Player start position and orientation (North, South, East, West)

Example map file (`map.cub`):

```
C 0,0,0

F 56,62,64

NO ./imgs/crate_1.xpm

SO ./imgs/crate_2.xpm

WE ./imgs/tech_1.xpm

EA ./imgs/tech_2.xpm

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000W00000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
1100000111010101111101111000111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## Resources

- [MinilibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
