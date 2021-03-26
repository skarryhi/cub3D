<h1 align="center">My first RayCaster with miniLibX cub3D 🎮  </h1>

This project is inspired by the world-famous eponymous 90's game, which was the first FPS ever.
It will enabled me to explore ray-casting. My goal will was to make a dynamic view inside a maze,
in which you’ll have to find your way.
#### Written on pure C 98 ♻️
#### Created for the MacOS platform 🖥
#
### install cub3D ✅
```sh
git clone https://github.com/skarryhi/cub3D && cd cub3D && make
```
#### start game engine 🚹
```sh
./cub.3D map.cub
```
#### take a screenshot 📸

```sh
./cub.3D map.cub --save
```

## Control keys 🕹
#### The left and right arrow keys of the keyboard allow you to look left and right
#### The W, A, S and D keys allow you to move the point of view through the maze
#### Pressing ESC close the window
#
## Map parameters (file map.cub) 🧭

- Resolution: R 1920 1080
- North texture: NO ./path_to_the_north_texture
- South texture: SO ./path_to_the_south_texture
- West texture: WE ./path_to_the_west_texture
- East texture: EA ./path_to_the_east_texture
- Sprite texture: S ./path_to_the_sprite_texture
- Floor color: F 220,100,0
- Ceilling color: C 225,30,0
- The map must be composed of only 4 possible characters: 0 for an empty space, 1 for a wall, 2 for an item and N, S, E or W for the player’s start position and spawning orientation
#
##### 👩🏻‍💼 **[Skarryhi](https://github.com/skarryhi/)**

##### 🏠 [Homepage](https://github.com/skarryhi/cub3D)


