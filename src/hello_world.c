/*---------------------------------------------------------------------------------


	 map example with tiled conversion
	-- alekmaul


---------------------------------------------------------------------------------*/
#include <snes.h>

#include "player.h"

// Graphics available outside the file
extern char tileset, tilesetend, tilesetpal;  // for map & tileset of map
extern char mapkungfu, tilesetdef, tilesetatt;
extern char tilesetobj;
extern char palsprite;	// for all sprites

// s16 mapscx;	 // camera x variable
// s16 mapscy;	 // camera x variable

//---------------------------------------------------------------------------------
int main(void) {
	// Init layer with tiles and init also map length 0x6800 is mandatory for map engine
	bgInitTileSet(0, &tileset, &tilesetpal, 0, (&tilesetend - &tileset), 16 * 2 * 3, BG_16COLORS, 0x2000);
	// bgSetMapPtr(0, 0x6800, SC_64x64);
	bgSetMapPtr(0, 0x6800, SC_64x32);
	// Now Put in 16 color mode and disable Bgs except current, since we only have one
	setMode(BG_MODE1, 0);
	bgSetDisable(1);
	bgSetDisable(2);
	setPalette(&palsprite, 128 + 0 * 16, 16 * 2);
	// Init sprite engine (0x0000 for large, 0x1000 for small)
	oamInitDynamicSprite(0x0000, 0x1000, 0, 0, OBJ_SIZE16_L32);

	// Object engine activate
	objInitEngine();

	objInitFunctions(0, &marioinit, &marioupdate, NULL);
	objLoadObjects((char *)&tilesetobj);

	// Screen activated
	setScreenOn();

	// Load map in memory and update it regarding current location of the sprite
	mapLoad((u8 *)&mapkungfu, (u8 *)&tilesetdef, (u8 *)&tilesetatt);

	// generic playing loop
	// mapscx = 16 * 8;  // middle of screen
	// mapscy = 0;
	while (1) {
		// Update the map regarding the camera
		mapUpdate();

		// update camera regarding scrolling
		// mapUpdateCamera(mapscx, mapscy);
		objUpdateAll();	 // update all objects

		oamInitDynamicSpriteEndFrame();
		// Wait vblank and display map on screen
		WaitForVBlank();
		mapVblank();
		oamVramQueueUpdate();
	}
	return 0;
}
