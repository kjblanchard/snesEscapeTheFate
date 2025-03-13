
#include <snes.h>

t_objs *marioobj;  // pointer to mario object
u16 marioid;	   // marios id maybe
// u16 *marioox;	   // obj x location ptr
// u16 *mariooy;	   // obj ylocation ptr
u16 *marioox, *mariooy;
u16 mariox, marioy;
u8 mariofidx, marioflp, flip;  // to manage sprite display
u16 pad0;					   // pad variable
extern unsigned char sprmario;

void marioinit(u16 xp, u16 yp, u16 type, u16 minx, u16 maxx) {
	// prepare new object
	if (objNew(type, xp, yp) == 0)
		// no more space, get out
		return;

	// Init some vars for snes sprite (objgetid is the current object id)
	objGetPointer(objgetid);
	marioid = objgetid;
	marioobj = &objbuffers[objptr - 1];
	marioobj->width = 32;
	marioobj->height = 32;

	// grab the coordinates & velocity pointers
	marioox = (u16 *)&(marioobj->xpos + 1);
	mariooy = (u16 *)&(marioobj->ypos + 1);

	// update some variables for mario
	mariofidx = 0;
	marioflp = 0;
	marioobj->action = ACT_WALK;
	// prepare dynamic sprite object
	oambuffer[0].oamx = xp;
	oambuffer[0].oamy = yp;
	oambuffer[0].oamframeid = 0;
	oambuffer[0].oamrefresh = 1;
	// 16x16 is likely cause it's the "large" in this oamInitDynamicSprite(0x0000, 0x1000, 0, 0, OBJ_SIZE8_L16);
	// So it would be 32/32 for me since that's what I chose
	oambuffer[0].oamattribute = 0x20 | (0 << 1);  // palette 0 of sprite and sprite 32x32 and priority 2
	oambuffer[0].oamgraphics = &sprmario;
}

void marioupdate(u8 idx) {
	objbuffers[0].sprnum;
	// Get pad and update camera regarding pad
	pad0 = padsCurrent(0);
	// go to the left & right
	if (pad0 & KEY_LEFT) {
		(*marioox) -= 2;
	}
	if (pad0 & KEY_RIGHT) {
		(*marioox) += 2;
	}
	if (pad0 & KEY_DOWN) {
		(*mariooy) += 2;
	}
	if (pad0 & KEY_UP) {
		(*mariooy) -= 2;
	}
	// update the object x y
	objUpdateXY(idx);

	mariox = *marioox;
	marioy = *mariooy;
	// change sprite display
	mariox = *marioox;
	marioy = *mariooy;
	oambuffer[0].oamx = mariox - x_pos;
	oambuffer[0].oamy = marioy - y_pos;
	oamDynamic32Draw(0);
	// update camera regarding mario object
	mapUpdateCamera(mariox, marioy);
}
