# Description
This project is a small 2D game with [MLX42](https://github.com/codam-coding-college/MLX42). It's a part of 42 Core curriculum.

The program accepts a map as an input and creates a 2D game based on it.
### Input
```
1111111111111
10010000000C1
1000011111111
1P0011E000001
1111111111111
```
### Output
![Screenshot 2024-10-12 at 14 16 59](https://github.com/user-attachments/assets/7f33308f-ffea-429d-8642-8502ac8b4e79)
## Map
The map has to be constructed with 3 components: walls, collectibles, and free
space.

The map can be composed of only these 5 characters:
- 0 for an empty space,
- 1 for a wall,
- C for a collectible,
- E for a map exit,
- P for the player’s starting position.

`/maps` folder already contains many pre-created maps

# Usage
1. Clone the repo
2. Inside the repo run `make` to create an executable (aka the game)
3. Run `./so_long [map]` to open a game with a pre-created map OR `./so_long` where you can write your own map to stdin
