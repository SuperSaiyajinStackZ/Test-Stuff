/*
*   This file is part of Text-Stuff
*   Copyright (C) 2019 VoltZ
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

#include "gui.hpp"

C3D_RenderTarget* top;
C3D_RenderTarget* bottom;

	// Initialize all that stuff.
Result Gui::initialize() {
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();

		// Create screens.
	top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
	return 0;
}

	// Draw just a base for now.
void Gui::DrawBase(void) {
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(top, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
	C2D_SceneBegin(top);
	C2D_DrawRectSolid(0, 0, 0.5f, 400, 240, C2D_Color32(198, 198, 198, 255));
	C2D_SceneBegin(bottom);
	C2D_DrawRectSolid(0, 0, 0.5f, 320, 240, C2D_Color32(132, 132, 132, 255));
	C3D_FrameEnd(0);
}

	// Deinit libs.
Result Gui::deinitialize() {
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}