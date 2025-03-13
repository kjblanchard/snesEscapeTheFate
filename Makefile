ifeq ($(strip $(PVSNESLIB_HOME)),)
$(error "Please create an environment variable PVSNESLIB_HOME by following this guide: https://github.com/alekmaul/pvsneslib/wiki/Installation")
endif

include ${PVSNESLIB_HOME}/devkitsnes/snes_rules

.PHONY: bitmaps all

#---------------------------------------------------------------------------------
# ROMNAME is used in snes_rules file
export ROMNAME := hello_world

all: bitmaps $(ROMNAME).sfc

clean: cleanBuildRes cleanRom cleanGfx

#---------------------------------------------------------------------------------
pvsneslibfont.pic: pvsneslibfont.png
	@echo convert font with no tile reduction ... $(notdir $@)
	$(GFXCONV) -s 8 -o 16 -u 16 -p -e 0 -i $<

sprites.pic: assets/aseprite/player1.bmp
	@echo convert character bitmap ... $(notdir $@)
	$(GFXCONV) -s 32 -o 16 -u 16 -t bmp -i $<

tileslevel1.pic: assets/tiled/tiles.png
	@echo convert map tileset ... $(notdir $@)
	$(GFXCONV) -s 8 -o 16 -u 16 -p -m -i $<

BG1.m16: assets/tiled/tiled.tmj tileslevel1.pic
	@echo convert map tiled ... $(notdir $@)
	$(TMXCONV) $< assets/tiled/tiles.map

bitmaps : pvsneslibfont.pic sprites.pic BG1.m16 tileslevel1.pic

