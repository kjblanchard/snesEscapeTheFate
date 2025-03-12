#include <snes.h>
extern char tilfont, palfont;

int main(void) {
	// Initialize text console with our font
	consoleSetTextMapPtr(0x6800);
	consoleSetTextGfxPtr(0x3000);
	consoleSetTextOffset(0x0100);
	consoleInitText(0, 16 * 2, &tilfont, &palfont);
	// Init background
	bgSetGfxPtr(0, 0x2000);
	bgSetMapPtr(0, 0x6800, SC_32x32);
	// Now Put in 16 color mode and disable Bgs except current
	setMode(BG_MODE1, 0);
	bgSetDisable(1);
	bgSetDisable(2);
	consoleDrawText(10, 10, "Hello World snes!");
	consoleDrawText(6, 14, "Escape The Fate!");
	consoleDrawText(3, 18, "https://supergoon.com");
	setScreenOn();
	while (1) {
		WaitForVBlank();
	}
	return 0;
}
