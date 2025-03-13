### Escape The Fate SNES

## Recreation of escape the fate with snes limitations

## Tools
- PVSNESLib - programming in C, and a bunch of library functions to do things easily in snes
- Color reducer - https://onlinepngtools.com/decrease-png-color-count
- Tileset Extractor - https://portabledev.com/pvsneslib/tilesetextractor/

## Background
- In ETF, backgrounds were made with multiple tilesets and have a large amount of colors in tiled
- Using PVSNESLIB, we are limited for most features to SNES mode 1, which has 16 colors (15 including transparency)
- Also, you can only have 64x64 map size, which would work except we are limited to 8x8 tiles, so we could be bigger than that, so we also have to trim down the maps as needed.
- To hit this limit without doing a lot of work, just used a online tool to reduce the colors (usually ~75 colors down to 15)
- this could cause issues with same sprite looking different on different maps, since this is mostly a demo, this is fine
- So, workflow is to just reuse the tiled map for ETF, export it as an image, run through the tool to reduce colors, and then run through the pvsnes tiled tool
- Then, add in the solid tiles


## Sprites
- In ETF, sprites were made and animated in aseprite with no limit on colors
- We will export the same sprite, and reduce the colors with the same tool as background, usually to a much lesser degree

## Developer Notes

# .asm files
hdr.asm - Header, contains info about the game
data.asm - Tells information about where things are at, mostly the files loaded in the build process that are created when converting.

# Background
- We will utilize BG1 for the map using pvsnes map/tiled/object functionality
- We will utilize BG2 for hud elements (Menu Screen?)
- We will utilize BG3 for Text
