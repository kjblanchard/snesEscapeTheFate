.include "hdr.asm"

.section ".rodata1" superfree

tileset:
.incbin "assets/tiled/tiles.pic"
tilesetend:

tilesetpal:
.incbin "assets/tiled/tiles.pal"
.ends

.section ".rodata2" superfree

mapkungfu:
.incbin "assets/tiled/BG1.m16"

tilesetatt:
.incbin "assets/tiled/tiled.b16"

tilesetdef:
.incbin "assets/tiled/tiled.t16"

tilesetobj:
.incbin "assets/tiled/tiled.o16"

sprmario:
.incbin "assets/aseprite/player1.pic"

palsprite:
.incbin "assets/aseprite/player1.pal"

.ends
