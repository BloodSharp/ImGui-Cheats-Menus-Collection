#include "IGCMC-Precompiled.h"

#define WAIT_FOR_KEY(wait)\
else if (ImGui::IsKeyDown(wait)) *keynum = (int)wait;
#define WAIT_FOR_KEY_SETTING_VALUE(wait, assign)\
else if (ImGui::IsKeyDown(wait)) *keynum = (int)assign;

static void WaitForPressKey(int* keynum)
{
	if(0){}
	WAIT_FOR_KEY(ImGuiKey_F1)
	WAIT_FOR_KEY(ImGuiKey_F2)
	WAIT_FOR_KEY(ImGuiKey_F3)
	WAIT_FOR_KEY(ImGuiKey_F4)
	WAIT_FOR_KEY(ImGuiKey_F5)
	WAIT_FOR_KEY(ImGuiKey_F6)
	WAIT_FOR_KEY(ImGuiKey_F7)
	WAIT_FOR_KEY(ImGuiKey_F8)
	WAIT_FOR_KEY(ImGuiKey_F9)
	WAIT_FOR_KEY(ImGuiKey_F10)
	WAIT_FOR_KEY(ImGuiKey_F11)
	WAIT_FOR_KEY(ImGuiKey_F12)
	WAIT_FOR_KEY(ImGuiKey_0)
	WAIT_FOR_KEY(ImGuiKey_1)
	WAIT_FOR_KEY(ImGuiKey_2)
	WAIT_FOR_KEY(ImGuiKey_3)
	WAIT_FOR_KEY(ImGuiKey_4)
	WAIT_FOR_KEY(ImGuiKey_5)
	WAIT_FOR_KEY(ImGuiKey_6)
	WAIT_FOR_KEY(ImGuiKey_7)
	WAIT_FOR_KEY(ImGuiKey_8)
	WAIT_FOR_KEY(ImGuiKey_9)
	WAIT_FOR_KEY(ImGuiKey_Insert)
	WAIT_FOR_KEY(ImGuiKey_End)
	WAIT_FOR_KEY(ImGuiKey_DownArrow)
	WAIT_FOR_KEY(ImGuiKey_PageDown)
	WAIT_FOR_KEY(ImGuiKey_LeftArrow)
	//WAIT_FOR_KEY(VK_NUMPAD5, K_KP_5);
	WAIT_FOR_KEY(ImGuiKey_RightArrow)
	WAIT_FOR_KEY(ImGuiKey_Home)
	WAIT_FOR_KEY(ImGuiKey_UpArrow)
	WAIT_FOR_KEY(ImGuiKey_PageUp)
	WAIT_FOR_KEY(ImGuiKey_Space)
	WAIT_FOR_KEY(ImGuiKey_Enter)
	WAIT_FOR_KEY(ImGuiKey_Tab)
	//WAIT_FOR_KEY(VK_UP, K_UPARROW);
	//WAIT_FOR_KEY(VK_DOWN, K_DOWNARROW);
	//WAIT_FOR_KEY(VK_LEFT, K_LEFTARROW);
	//WAIT_FOR_KEY(VK_RIGHT, K_RIGHTARROW);
	WAIT_FOR_KEY(ImGuiKey_LeftAlt)
	WAIT_FOR_KEY(ImGuiKey_RightAlt)
	WAIT_FOR_KEY(ImGuiKey_LeftCtrl)
	WAIT_FOR_KEY(ImGuiKey_RightCtrl)
	WAIT_FOR_KEY(ImGuiKey_CapsLock)
	//WAIT_FOR_KEY(34, K_PGDN);
	//WAIT_FOR_KEY(33, K_PGUP);
	//WAIT_FOR_KEY(VK_HOME, K_HOME);
	WAIT_FOR_KEY(ImGuiKey_End)
	WAIT_FOR_KEY(ImGuiKey_A)
	WAIT_FOR_KEY(ImGuiKey_B)
	WAIT_FOR_KEY(ImGuiKey_C)
	WAIT_FOR_KEY(ImGuiKey_D)
	WAIT_FOR_KEY(ImGuiKey_E)
	WAIT_FOR_KEY(ImGuiKey_F)
	WAIT_FOR_KEY(ImGuiKey_G)
	WAIT_FOR_KEY(ImGuiKey_H)
	WAIT_FOR_KEY(ImGuiKey_I)
	WAIT_FOR_KEY(ImGuiKey_J)
	WAIT_FOR_KEY(ImGuiKey_K)
	WAIT_FOR_KEY(ImGuiKey_L)
	WAIT_FOR_KEY(ImGuiKey_M)
	WAIT_FOR_KEY(ImGuiKey_N)
	WAIT_FOR_KEY(ImGuiKey_O)
	WAIT_FOR_KEY(ImGuiKey_P)
	WAIT_FOR_KEY(ImGuiKey_Q)
	WAIT_FOR_KEY(ImGuiKey_R)
	WAIT_FOR_KEY(ImGuiKey_S)
	WAIT_FOR_KEY(ImGuiKey_T)
	WAIT_FOR_KEY(ImGuiKey_U)
	WAIT_FOR_KEY(ImGuiKey_V)
	WAIT_FOR_KEY(ImGuiKey_W)
	WAIT_FOR_KEY(ImGuiKey_X)
	WAIT_FOR_KEY(ImGuiKey_Y)
	WAIT_FOR_KEY(ImGuiKey_Z)
	WAIT_FOR_KEY(ImGuiKey_LeftBracket)
	WAIT_FOR_KEY(ImGuiKey_RightBracket)
	WAIT_FOR_KEY(ImGuiKey_Comma)
	WAIT_FOR_KEY(ImGuiKey_Period)
	WAIT_FOR_KEY(ImGuiKey_MouseLeft)
	WAIT_FOR_KEY(ImGuiKey_MouseRight)
	WAIT_FOR_KEY(ImGuiKey_MouseMiddle)
	//WAIT_FOR_KEY(VK_XBUTTON1, K_MOUSE4)
	//WAIT_FOR_KEY(VK_XBUTTON2, K_MOUSE5)
	WAIT_FOR_KEY_SETTING_VALUE(ImGuiKey_Escape, -1)
	WAIT_FOR_KEY_SETTING_VALUE(ImGuiKey_Backspace, -1)
}

void ImGui::Spacing_HPPv6(int count)
{
	for (int i = 0; i < count; i++)
		ImGui::Spacing();
}

bool ImGui::BeginChildCustomEx_HPPv6(const char* name, ImGuiID id, const ImVec2& size_arg, bool border, ImGuiWindowFlags flags)
{
	ImGuiContext& g = *GImGui;
	ImGuiWindow* parent_window = g.CurrentWindow;

	flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_ChildWindow;
	flags |= (parent_window->Flags & ImGuiWindowFlags_NoMove);  // Inherit the NoMove flag

	// Size
	const ImVec2 content_avail = GetContentRegionAvail();
	ImVec2 size = ImFloor(size_arg);
	const int auto_fit_axises = ((size.x == 0.0f) ? (1 << ImGuiAxis_X) : 0x00) | ((size.y == 0.0f) ? (1 << ImGuiAxis_Y) : 0x00);
	if (size.x <= 0.0f)
		size.x = ImMax(content_avail.x + size.x, 4.0f); // Arbitrary minimum child size (0.0f causing too much issues)
	if (size.y <= 0.0f)
		size.y = ImMax(content_avail.y + size.y, 4.0f);
	SetNextWindowSize(size);

	const float backup_border_size = g.Style.ChildBorderSize;
	if (!border)
		g.Style.ChildBorderSize = 0.0f;
	bool ret = Begin(name, NULL, flags);//BeginCustom(name, NULL, flags);
	g.Style.ChildBorderSize = backup_border_size;

	ImGuiWindow* child_window = g.CurrentWindow;
	child_window->ChildId = id;
	//child_window->AutoFitChildAxises = auto_fit_axises;

	// Set the cursor to handle case where the user called SetNextWindowPos()+BeginChild() manually.
	// While this is not really documented/defined, it seems that the expected thing to do.
	if (child_window->BeginCount == 1)
		parent_window->DC.CursorPos = child_window->Pos;

	// Process navigation-in immediately so NavInit can run on first frame
	if (g.NavActivateId == id && !(flags & ImGuiWindowFlags_NavFlattened)) //&& (child_window->DC.NavLayerActiveMask != 0 || child_window->DC.NavHasScroll))
	{
		FocusWindow(child_window);
		NavInitWindow(child_window, false);
		SetActiveID(id + 1, child_window); // Steal ActiveId with a dummy id so that key-press won't activate child item
		//g.ActiveIdSource = ImGuiInputSource_Nav;
	}
	return ret;
}

bool ImGui::BeginChildCustom_HPPv6(const char* str_id, const ImVec2& size_arg, bool border, ImGuiWindowFlags extra_flags)
{
	ImGuiWindow* window = GetCurrentWindow();
	return BeginChildCustomEx_HPPv6(str_id, window->GetID(str_id), size_arg, border, extra_flags);
}

void ImGui::EndChildCustom_HPPv6()
{
	ImGuiContext& g = *GImGui;
	ImGuiWindow* window = g.CurrentWindow;

	IM_ASSERT(window->Flags & ImGuiWindowFlags_ChildWindow);   // Mismatched BeginChild()/EndChild() callss

	ImVec2 window_pos = GImGui->CurrentWindow->Pos;
	ImVec2 window_size = GImGui->CurrentWindow->Size;

	ImVec2 min_top = window_pos;
	ImVec2 max_top = min_top + ImVec2(window_size.x, std::min(window->Scroll.y, 20.f));
	ImVec2 min_bottom = min_top + ImVec2(0, window_size.y - std::min(window->ScrollMax.y - window->Scroll.y, 20.f));
	ImVec2 max_bottom = min_bottom + ImVec2(window_size.x, 20);

	if (window->ScrollbarY)
	{
		ImColor color_windowbg = GetStyleColorVec4(ImGuiCol_ChildBg);

		ImColor color_top = color_windowbg;
		ImColor color_bottom = color_top;
		color_bottom.Value.w = 0.00f;

		if (window->Scroll.y > 1.0f)
			window->DrawList->AddRectFilledMultiColor(min_top, max_top, color_top, color_top, color_bottom, color_bottom);

		if ((GetScrollMaxY() - window->Scroll.y) > 1.f)
			window->DrawList->AddRectFilledMultiColor(min_bottom, max_bottom, color_bottom, color_bottom, color_top, color_top);
	}

	const ImFont* pFont = ImGui::GetFont();
	const char* szWindowName = ImGui::GetCurrentWindow()->Name;
	const ImVec2 text_size = pFont->CalcTextSizeA(pFont->FontSize, FLT_MAX, 0, szWindowName, FindRenderedTextEnd(szWindowName));
	RenderText(ImVec2(window->Pos.x + 18.f, window->Pos.y - text_size.y * 0.5f), szWindowName, NULL, true);

	if (window->BeginCount > 1)
	{
		End();
	}
	else
	{
		ImVec2 sz = window->Size;
		/*
		TODO: Fix this...
		if (window->AutoFitChildAxises & (1 << ImGuiAxis_X)) // Arbitrary minimum zero-ish child size of 4.0f causes less trouble than a 0.0f
			sz.x = ImMax(4.0f, sz.x);
		if (window->AutoFitChildAxises & (1 << ImGuiAxis_Y))
			sz.y = ImMax(4.0f, sz.y);
		*/
		End();

		ImGuiWindow* parent_window = g.CurrentWindow;
		ImRect bb(parent_window->DC.CursorPos, parent_window->DC.CursorPos + sz);
		ItemSize(sz);
		// TODO: Fix this...
		//if ((window->DC.NavLayerActiveMask != 0 || window->DC.NavHasScroll) && !(window->Flags & ImGuiWindowFlags_NavFlattened))
		if (!(window->Flags & ImGuiWindowFlags_NavFlattened))
		{
			ItemAdd(bb, window->ChildId);
			RenderNavHighlight(bb, window->ChildId);

			// When browsing a window that has no activable items (scroll only) we keep a highlight on the child
			// TODO: Fix this...
			//if (window->DC.NavLayerActiveMask == 0 && window == g.NavWindow)
			if (window == g.NavWindow)
				RenderNavHighlight(ImRect(bb.Min - ImVec2(2, 2), bb.Max + ImVec2(2, 2)), g.NavId, ImGuiNavHighlightFlags_TypeThin);
		}
		else
		{
			// Not navigable into
			ItemAdd(bb, 0);
		}
	}

	RectangleShadowSettings_HPPv6 shadow_settings;

	ImGui::DrawRectangleShadowVerticesAdaptive_HPPv6(shadow_settings, window_pos, window_size);

	RenderText(ImVec2(min_top.x + 18.f, min_top.y - text_size.y * 0.5f), szWindowName, NULL, true);
	RenderText(ImVec2(min_top.x + 18.f, min_top.y - text_size.y * 0.5f), szWindowName, NULL, true);
}

ImVec4 ImGui::BoxGaussianIntegral_HPPv6(ImVec4 x)
{
	ImVec4 s = ImVec4(x.x > 0 ? 1.0f : -1.0f, x.y > 0 ? 1.0f : -1.0f, x.z > 0 ? 1.0f : -1.0f, x.w > 0 ? 1.0f : -1.0f);
	ImVec4 a = ImVec4(fabsf(x.x), fabsf(x.y), fabsf(x.z), fabsf(x.w));
	ImVec4 res = a * (((a * a) * 0.078108f + 0.230389f) * a + 0.278393f) + 1.0f;
	ImVec4 resSquared = res * res;
	return s - s / (resSquared * resSquared);
}

ImVec4 ImGui::BoxLinearInterpolation_HPPv6(ImVec4 x)
{
	const float maxClamp = 1.0f;
	const float minClamp = -1.0f;
	return ImVec4(x.x > maxClamp ? maxClamp : x.x < minClamp ? minClamp : x.x,
		x.y > maxClamp ? maxClamp : x.y < minClamp ? minClamp : x.y,
		x.z > maxClamp ? maxClamp : x.z < minClamp ? minClamp : x.z,
		x.w > maxClamp ? maxClamp : x.w < minClamp ? minClamp : x.w);
}

float ImGui::BoxShadow_HPPv6(ImVec2 lower, ImVec2 upper, ImVec2 point, float sigma, bool linearInterpolation)
{
	ImVec2 pointLower = point - lower;
	ImVec2 pointUpper = point - upper;
	ImVec4 query = ImVec4(pointLower.x, pointLower.y, pointUpper.x, pointUpper.y);
	ImVec4 pointToSample = query * (sqrtf(0.5f) / sigma);
	ImVec4 integral = linearInterpolation ? BoxLinearInterpolation_HPPv6(pointToSample) * 0.5f + 0.5f : BoxGaussianIntegral_HPPv6(pointToSample) * 0.5f + 0.5f;
	return (integral.z - integral.x) * (integral.w - integral.y);
}

void ImGui::DrawRectangleShadowVerticesAdaptive_HPPv6(RectangleShadowSettings_HPPv6& settings, ImVec2 pos, ImVec2 size)
{
	const int    samplesSpan = settings.samplesPerCornerSide * settings.spacingBetweenSamples;
	const int    halfWidth = static_cast<int>(size.x / 2);
	const int    numSamplesInHalfWidth = (halfWidth / settings.spacingBetweenSamples) == 0 ? 1 : halfWidth / settings.spacingBetweenSamples;
	const int    numSamplesWidth = samplesSpan > halfWidth ? numSamplesInHalfWidth : settings.samplesPerCornerSide;
	const int    halfHeight = static_cast<int>(size.y / 2);
	const int    numSamplesInHalfHeight = (halfHeight / settings.spacingBetweenSamples) == 0 ? 1 : halfHeight / settings.spacingBetweenSamples;
	const int    numSamplesHeight = samplesSpan > halfHeight ? numSamplesInHalfHeight : settings.samplesPerCornerSide;
	const int    numVerticesInARing = numSamplesWidth * 4 + numSamplesHeight * 4 + 4;
	const ImVec2 whiteTexelUV = ImGui::GetIO().Fonts->TexUvWhitePixel;
	const ImVec2 rectangleTopLeft = pos;
	const ImVec2 rectangleBottomRight = rectangleTopLeft + size;
	const ImVec2 rectangleTopRight = rectangleTopLeft + ImVec2(size.x, 0);
	const ImVec2 rectangleBottomLeft = rectangleTopLeft + ImVec2(0, size.y);

	ImColor shadowColor = settings.shadowColor;
	settings.totalVertices = numVerticesInARing * settings.rings;
	settings.totalIndices = 6 * (numVerticesInARing) * (settings.rings - 1);

	ImDrawList* drawList = ImGui::GetWindowDrawList();
	drawList->PrimReserve(settings.totalIndices, settings.totalVertices);
	const ImDrawVert* shadowVertices = drawList->_VtxWritePtr;
	ImDrawVert* vertexPointer = drawList->_VtxWritePtr;

	for (int r = 0; r < settings.rings; ++r)
	{
		const float  adaptiveScale = (r / 2.5f) + 1;
		const ImVec2 ringOffset = ImVec2(adaptiveScale * r * settings.spacingBetweenRings, adaptiveScale * r * settings.spacingBetweenRings);
		for (int j = 0; j < 4; ++j)
		{
			ImVec2      corner;
			ImVec2      direction[2];
			const float spacingBetweenSamplesOnARing = static_cast<float>(settings.spacingBetweenSamples);
			switch (j)
			{
			case 0:
				corner = rectangleTopLeft + ImVec2(-ringOffset.x, -ringOffset.y);
				direction[0] = ImVec2(1, 0) * spacingBetweenSamplesOnARing;
				direction[1] = ImVec2(0, 1) * spacingBetweenSamplesOnARing;
				for (int i = 0; i < numSamplesWidth; ++i)
				{
					const ImVec2 point = corner + direction[0] * (float)(numSamplesWidth - i);
					shadowColor.Value.w = BoxShadow_HPPv6(rectangleTopLeft, rectangleBottomRight, point - settings.shadowOffset, settings.sigma, settings.linear);
					vertexPointer->pos = point;
					vertexPointer->uv = whiteTexelUV;
					vertexPointer->col = shadowColor;
					vertexPointer++;
				}

				shadowColor.Value.w = BoxShadow_HPPv6(rectangleTopLeft, rectangleBottomRight, corner - settings.shadowOffset, settings.sigma, settings.linear);
				vertexPointer->pos = corner;
				vertexPointer->uv = whiteTexelUV;
				vertexPointer->col = shadowColor;
				vertexPointer++;

				for (int i = 0; i < numSamplesHeight; ++i)
				{
					const ImVec2 point = corner + direction[1] * (float)(i + 1);
					shadowColor.Value.w = BoxShadow_HPPv6(rectangleTopLeft, rectangleBottomRight, point - settings.shadowOffset, settings.sigma, settings.linear);
					vertexPointer->pos = point;
					vertexPointer->uv = whiteTexelUV;
					vertexPointer->col = shadowColor;
					vertexPointer++;
				}
				break;
			case 1:
				corner = rectangleBottomLeft + ImVec2(-ringOffset.x, +ringOffset.y);
				direction[0] = ImVec2(1, 0) * spacingBetweenSamplesOnARing;
				direction[1] = ImVec2(0, -1) * spacingBetweenSamplesOnARing;
				for (int i = 0; i < numSamplesHeight; ++i)
				{
					const ImVec2 point = corner + direction[1] * (float)(numSamplesHeight - i);
					shadowColor.Value.w = BoxShadow_HPPv6(rectangleTopLeft, rectangleBottomRight, point - settings.shadowOffset, settings.sigma, settings.linear);
					vertexPointer->pos = point;
					vertexPointer->uv = whiteTexelUV;
					vertexPointer->col = shadowColor;
					vertexPointer++;
				}

				shadowColor.Value.w = BoxShadow_HPPv6(rectangleTopLeft, rectangleBottomRight, corner - settings.shadowOffset, settings.sigma, settings.linear);
				vertexPointer->pos = corner;
				vertexPointer->uv = whiteTexelUV;
				vertexPointer->col = shadowColor;
				vertexPointer++;

				for (int i = 0; i < numSamplesWidth; ++i)
				{
					const ImVec2 point = corner + direction[0] * (float)(i + 1);
					shadowColor.Value.w = BoxShadow_HPPv6(rectangleTopLeft, rectangleBottomRight, point - settings.shadowOffset, settings.sigma, settings.linear);
					vertexPointer->pos = point;
					vertexPointer->uv = whiteTexelUV;
					vertexPointer->col = shadowColor;
					vertexPointer++;
				}
				break;
			case 2:
				corner = rectangleBottomRight + ImVec2(+ringOffset.x, +ringOffset.y);
				direction[0] = ImVec2(-1, 0) * spacingBetweenSamplesOnARing;
				direction[1] = ImVec2(0, -1) * spacingBetweenSamplesOnARing;
				for (int i = 0; i < numSamplesWidth; ++i)
				{
					const ImVec2 point = corner + direction[0] * (float)(numSamplesWidth - i);
					shadowColor.Value.w = BoxShadow_HPPv6(rectangleTopLeft, rectangleBottomRight, point - settings.shadowOffset, settings.sigma, settings.linear);
					vertexPointer->pos = point;
					vertexPointer->uv = whiteTexelUV;
					vertexPointer->col = shadowColor;
					vertexPointer++;
				}

				shadowColor.Value.w = BoxShadow_HPPv6(rectangleTopLeft, rectangleBottomRight, corner - settings.shadowOffset, settings.sigma, settings.linear);
				vertexPointer->pos = corner;
				vertexPointer->uv = whiteTexelUV;
				vertexPointer->col = shadowColor;
				vertexPointer++;

				for (int i = 0; i < numSamplesHeight; ++i)
				{
					const ImVec2 point = corner + direction[1] * (float)(i + 1);
					shadowColor.Value.w = BoxShadow_HPPv6(rectangleTopLeft, rectangleBottomRight, point - settings.shadowOffset, settings.sigma, settings.linear);
					vertexPointer->pos = point;
					vertexPointer->uv = whiteTexelUV;
					vertexPointer->col = shadowColor;
					vertexPointer++;
				}
				break;
			case 3:
				corner = rectangleTopRight + ImVec2(+ringOffset.x, -ringOffset.y);
				direction[0] = ImVec2(-1, 0) * spacingBetweenSamplesOnARing;
				direction[1] = ImVec2(0, 1) * spacingBetweenSamplesOnARing;
				for (int i = 0; i < numSamplesHeight; ++i)
				{
					const ImVec2 point = corner + direction[1] * (float)(numSamplesHeight - i);
					shadowColor.Value.w = BoxShadow_HPPv6(rectangleTopLeft, rectangleBottomRight, point - settings.shadowOffset, settings.sigma, settings.linear);
					vertexPointer->pos = point;
					vertexPointer->uv = whiteTexelUV;
					vertexPointer->col = shadowColor;
					vertexPointer++;
				}

				shadowColor.Value.w = BoxShadow_HPPv6(rectangleTopLeft, rectangleBottomRight, corner - settings.shadowOffset, settings.sigma, settings.linear);
				vertexPointer->pos = corner;
				vertexPointer->uv = whiteTexelUV;
				vertexPointer->col = shadowColor;
				vertexPointer++;

				for (int i = 0; i < numSamplesWidth; ++i)
				{
					const ImVec2 point = corner + direction[0] * (float)(i + 1);
					shadowColor.Value.w = BoxShadow_HPPv6(rectangleTopLeft, rectangleBottomRight, point - settings.shadowOffset, settings.sigma, settings.linear);
					vertexPointer->pos = point;
					vertexPointer->uv = whiteTexelUV;
					vertexPointer->col = shadowColor;
					vertexPointer++;
				}
				break;
			}
		}
	}

	ImDrawIdx idx = (ImDrawIdx)drawList->_VtxCurrentIdx;

	for (int r = 0; r < settings.rings - 1; ++r)
	{
		const ImDrawIdx startOfRingIndex = idx;
		for (int i = 0; i < numVerticesInARing - 1; ++i)
		{
			drawList->_IdxWritePtr[0] = idx + 0;
			drawList->_IdxWritePtr[1] = idx + 1;
			drawList->_IdxWritePtr[2] = idx + numVerticesInARing;
			drawList->_IdxWritePtr[3] = idx + 1;
			drawList->_IdxWritePtr[4] = idx + numVerticesInARing + 1;
			drawList->_IdxWritePtr[5] = idx + numVerticesInARing;

			idx += 1;
			drawList->_IdxWritePtr += 6;
		}

		drawList->_IdxWritePtr[0] = idx + 0;
		drawList->_IdxWritePtr[1] = startOfRingIndex + 0;
		drawList->_IdxWritePtr[2] = startOfRingIndex + numVerticesInARing;
		drawList->_IdxWritePtr[3] = idx + 0;
		drawList->_IdxWritePtr[4] = startOfRingIndex + numVerticesInARing;
		drawList->_IdxWritePtr[5] = idx + numVerticesInARing;

		drawList->_IdxWritePtr += 6;
		idx += 1;
	}
	drawList->_VtxCurrentIdx += settings.totalVertices;
	GImGui->CurrentWindow->DrawList->AddRect(pos - 1, pos + size + 1, ImColor(0, 0, 0, 15), GImGui->Style.WindowRounding);
}

bool ImGui::ButtonTabsNormal_HPPv6(const char* label, const ImVec2& size_arg)
{
	return ButtonTabsEx2_HPPv6(label, size_arg, 0);
}

bool ImGui::ButtonTabsEx2_HPPv6(const char* label, const ImVec2& size_arg, ImGuiButtonFlags flags)
{
	ImGuiWindow* window = GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = CalcTextSize(label, NULL, true);

	ImVec2 pos = window->DC.CursorPos;
	if ((flags & ImGuiButtonFlags_AlignTextBaseLine) && style.FramePadding.y < window->DC.CurrLineTextBaseOffset) // Try to vertically align buttons that are smaller/have no padding so that text baseline matches (bit hacky, since it shouldn't be a flag)
		pos.y += window->DC.CurrLineTextBaseOffset - style.FramePadding.y;
	ImVec2 size = CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

	const ImRect bb(pos, pos + size);
	ItemSize(size, style.FramePadding.y);
	if (!ItemAdd(bb, id))
		return false;

	/*
	TODO: Fix this
	if (window->DC.ItemFlags & ImGuiItemFlags_ButtonRepeat)
		//flags |= ImGuiButtonFlags_Repeat;
	*/
	bool hovered, held;
	bool pressed = ButtonBehavior(bb, id, &hovered, &held, flags);

	const ImU32 col = GetColorU32((held && hovered) ? ImGuiCol_ButtonActive : hovered ? ImGuiCol_ButtonHovered : ImGuiCol_Button);

	ImColor color_top = col;
	color_top.Value.w *= 0.6f;
	ImColor color_bottom = col;

	// Render   
	RenderNavHighlight(bb, id);
	//RenderFrame(bb.Min, bb.Max, col, true, style.FrameRounding);
	window->DrawList->AddRectFilledMultiColor(bb.Min, bb.Max, color_top, color_top, color_bottom, color_bottom);
	RenderTextClipped(bb.Min + style.FramePadding, bb.Max - style.FramePadding, label, NULL, &label_size, style.ButtonTextAlign, &bb);

	// Automatically close popups
	//if (pressed && !(flags & ImGuiButtonFlags_DontClosePopups) && (window->Flags & ImGuiWindowFlags_Popup))
	//    CloseCurrentPopup();

	IMGUI_TEST_ENGINE_ITEM_INFO(id, label, window->DC.LastItemStatusFlags);
	return pressed;
}

// frame_padding < 0: uses FramePadding from style (default)
// frame_padding = 0: no framing
// frame_padding > 0: set framing size
// The color used are the button colors.
bool ImGui::ImageButtonTab_HPPv6(ImTextureID user_texture_id, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, int frame_padding, const ImVec4& bg_col, const ImVec4& tint_col)
{
	ImGuiWindow* window = GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;

	// Default to using texture ID as ID. User can still push string/integer prefixes.
	// We could hash the size/uv to create a unique ID but that would prevent the user from animating UV.
	PushID((void*)(intptr_t)user_texture_id);
	const ImGuiID id = window->GetID("#image");
	PopID();

	const ImVec2 padding = (frame_padding >= 0) ? ImVec2((float)frame_padding, (float)frame_padding) : style.FramePadding;
	const ImRect bb(window->DC.CursorPos, window->DC.CursorPos + size);
	const ImRect image_bb(window->DC.CursorPos + size * 0.5f - ImVec2(18, 18), window->DC.CursorPos + size * 0.5f + ImVec2(18, 18));
	ItemSize(bb);
	if (!ItemAdd(bb, id))
		return false;

	bool hovered, held;
	bool pressed = ButtonBehavior(bb, id, &hovered, &held);

	// Render
	const ImU32 col = GetColorU32((held && hovered) ? ImGuiCol_ButtonActive : hovered ? ImGuiCol_ButtonHovered : ImGuiCol_Button);

	RenderNavHighlight(bb, id);
	RenderFrame(bb.Min, bb.Max, col, true, ImClamp((float)ImMin(padding.x, padding.y), 0.0f, 2.f));
	if (bg_col.w > 0.0f)
		window->DrawList->AddRectFilled(image_bb.Min, image_bb.Max, GetColorU32(bg_col));
	const auto alpha = GetStyleColorVec4(ImGuiCol_Text).w;
	window->DrawList->AddImage(user_texture_id, image_bb.Min, image_bb.Max, uv0, uv1, ImColor(1.00f, 1.00f, 1.00f, alpha));

	return pressed;
}

bool ImGui::KeyButton_HPPv6(const char* label, void* v, bool owned)
{
	static int keynum;

	int* bind = reinterpret_cast<int*>(v);

	ImGuiWindow* window = GetCurrentWindow();
	if (window->SkipItems)
		return false;

	//std::string keystring = Game::KeynumToString(bind[0]);
	std::string keystring = ImGui::GetKeyName((ImGuiKey)bind[0]);
	std::string popup_label = label;
	popup_label.append("##KeyAssignment");

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = CalcTextSize(label, NULL, true);

	ImVec2 pos = window->DC.CursorPos;

	const ImRect total_bb(pos - 4, pos + ImVec2(window->Size.x - (pos.x - window->Pos.x) * 2.f, owned ? g.FontSize + 1.f : 17) + 4);
	ItemSize(total_bb, style.FramePadding.y);
	if (!ItemAdd(total_bb, id))
		return false;

	bool hovered, held;
	bool pressed = ButtonBehavior(total_bb, id, &hovered, &held);

	RenderFrame(total_bb.Min, total_bb.Max, GetColorU32(ImGuiCol_Border), true, 2.f);

	ImRect check_bb;

	if (owned)
	{
		check_bb = ImRect(pos, pos + ImVec2(window->Size.x - (pos.x - window->Pos.x) * 2.f, g.FontSize + 1.f));
	}
	else
	{
		check_bb = ImRect(ImVec2(pos.x + window->Size.x * 0.5f, pos.y), ImVec2(pos.x + window->Size.x * 0.5f, pos.y) +
			ImVec2(window->Size.x * 0.5f - (pos.x - window->Pos.x) * 2.f, 17));
	}

	if (label_size.x > 0.0f && !owned)
		RenderText(ImVec2(total_bb.Min.x + 4, total_bb.Min.y + 4 + 1), label);

	const ImU32 col = GetColorU32((held && hovered) ? ImGuiCol_ButtonHovered : hovered ? ImGuiCol_ButtonHovered : ImGuiCol_Button);

	RenderNavHighlight(check_bb, id);
	RenderFrame(check_bb.Min, check_bb.Max, GetColorU32(ImGuiCol_FrameBg), true, 2.f);
	RenderTextClipped(check_bb.Min, check_bb.Max, keystring.c_str(), NULL, NULL, style.ButtonTextAlign, &check_bb);

	if (pressed)
		ImGui::OpenPopup(popup_label.c_str());

	ImGui::SetNextWindowSize(ImVec2(250, 92));

	const auto flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize;

	ImVec4 backup_popupbg = g.Style.Colors[ImGuiCol_PopupBg];
	g.Style.Colors[ImGuiCol_PopupBg] = g.Style.Colors[ImGuiCol_ChildBg];

	if (ImGui::BeginPopupModal(popup_label.c_str(), nullptr, flags | ImGuiWindowFlags_NoBackground))
	{
		ImGui::Spacing_HPPv6(2);
		ImGui::SameLine(WINDOW_PADDING_SAMELINE);
		ImGui::BeginGroup();

		if (keynum)
		{
			std::string message = "Choose key type";

			const float item_width = GImGui->CurrentWindow->Size.x - WINDOW_PADDING_SAMELINE * 2.f;
			ImVec2 text_size = GImGui->Font->CalcTextSizeA(GImGui->Font->FontSize, item_width, 0, message.c_str());

			ImGui::SameLine((item_width - text_size.x) * 0.5f);
			ImGui::Text(message.c_str());

			ImGui::Spacing();

			ImGui::PushStyleColor(ImGuiCol_Border, ImVec4());

			if (ImGui::Button("On Press", ImVec2(106, 20)))
				bind[1] = 1;

			ImGui::SameLine();

			if (ImGui::Button("Toggle", ImVec2(106, 20)))
				bind[1] = 2;

			ImGui::PopStyleColor();

			if (bind[1])
			{
				keynum = 0;
				ImGui::CloseCurrentPopup();
			}
		}
		else
		{
			std::string message = "Press any key";

			const float item_width = GImGui->CurrentWindow->Size.x - WINDOW_PADDING_SAMELINE * 2.f;
			ImVec2 text_size = GImGui->Font->CalcTextSizeA(GImGui->Font->FontSize, item_width, 0, message.c_str());

			ImGui::SameLine((item_width - text_size.x) * 0.5f);
			ImGui::Text(message.c_str());

			ImGui::Spacing();

			ImGui::PushStyleColor(ImGuiCol_Border, ImVec4());

			if (ImGui::Button("Delete", ImVec2(106, 20)))
			{
				keynum = 0;
				memset(bind, 0, sizeof(int) * 2);
				ImGui::CloseCurrentPopup();
			}

			ImGui::SameLine();

			if (ImGui::Button("Cancel", ImVec2(106, 20)))
				ImGui::CloseCurrentPopup();

			ImGui::PopStyleColor();

			WaitForPressKey(&keynum);

			if (keynum == ImGuiKey_MouseLeft || keynum == ImGuiKey_MouseRight)
				keynum = ImGuiKey_None;

			if (keynum)
			{
				memset(bind, 0, sizeof(int) * 2);
				bind[0] = keynum;
			}
		}

		ImRect window_rect = ImRect(GImGui->CurrentWindow->Pos, GImGui->CurrentWindow->Size);

		GImGui->CurrentWindow->DrawList->PushClipRectFullScreen();

		RectangleShadowSettings_HPPv6 shadow_settings;
		shadow_settings.shadowColor = GImGui->Style.Colors[ImGuiCol_BorderShadow];
		ImGui::DrawRectangleShadowVerticesAdaptive_HPPv6(shadow_settings, window_rect.Min, window_rect.Max);

		ImGui::EndGroup();
		ImGui::EndPopup();
	}

	g.Style.Colors[ImGuiCol_PopupBg] = backup_popupbg;

	return pressed;
}

bool ImGui::ButtonTabs_HPPv6(const char* label, const ImVec2& size_arg)
{
	return ButtonTabsEx_HPPv6(label, size_arg, 0);
}

bool ImGui::ButtonTabsEx_HPPv6(const char* label, const ImVec2& size_arg, ImGuiButtonFlags flags)
{
	ImGuiWindow* window = GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = CalcTextSize(label, NULL, true);

	ImVec2 pos = window->DC.CursorPos;
	if ((flags & ImGuiButtonFlags_AlignTextBaseLine) && style.FramePadding.y < window->DC.CurrLineTextBaseOffset) // Try to vertically align buttons that are smaller/have no padding so that text baseline matches (bit hacky, since it shouldn't be a flag)
		pos.y += window->DC.CurrLineTextBaseOffset - style.FramePadding.y;
	ImVec2 size = CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

	const ImRect bb(pos, pos + size);
	ItemSize(size, style.FramePadding.y);
	if (!ItemAdd(bb, id))
		return false;

	//if (window->DC.ItemFlags & ImGuiItemFlags_ButtonRepeat)
	if (ImGui::GetItemFlags() & ImGuiItemFlags_ButtonRepeat)
		flags |= ImGuiButtonFlags_Repeat;
	bool hovered, held;
	bool pressed = ButtonBehavior(bb, id, &hovered, &held, flags);

	const ImU32 col = GetColorU32((held && hovered) ? ImGuiCol_ButtonActive : hovered ? ImGuiCol_ButtonHovered : ImGuiCol_Button);

	ImColor color_top = col;
	ImColor color_bottom = ImColor(color_top.Value.x * 0.500f, color_top.Value.y * 0.500f, color_top.Value.z * 0.500f, color_top.Value.w);
	ImColor color_border = ImColor(0.039f, 0.039f, 0.039f, color_top.Value.w);

	// Render   
	RenderNavHighlight(bb, id);
	RenderFrame(bb.Min, bb.Max, col, true, style.FrameRounding);
	//window->DrawList->AddRectFilledMultiColor(bb.Min, bb.Max, color_top, color_top, color_bottom, color_bottom);
	RenderTextClipped(bb.Min + style.FramePadding, bb.Max - style.FramePadding, label, NULL, &label_size, style.ButtonTextAlign, &bb);

	// Automatically close popups
	//if (pressed && !(flags & ImGuiButtonFlags_DontClosePopups) && (window->Flags & ImGuiWindowFlags_Popup))
	//    CloseCurrentPopup();

	IMGUI_TEST_ENGINE_ITEM_INFO(id, label, window->DC.LastItemStatusFlags);
	return pressed;
}

// frame_padding < 0: uses FramePadding from style (default)
// frame_padding = 0: no framing
// frame_padding > 0: set framing size
// The color used are the button colors.
bool ImGui::ImageButtonBySize_HPPv6(ImTextureID user_texture_id, const ImVec2& size, const ImVec2 image_size, const ImVec2& uv0, const ImVec2& uv1, const ImVec4& bg_col)
{
	ImGuiWindow* window = GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;

	// Default to using texture ID as ID. User can still push string/integer prefixes.
	// We could hash the size/uv to create a unique ID but that would prevent the user from animating UV.
	PushID((void*)(intptr_t)user_texture_id);
	const ImGuiID id = window->GetID("#image");
	PopID();

	const ImVec2 padding = (size - image_size) * 0.5f;
	const ImRect bb(window->DC.CursorPos, window->DC.CursorPos + size);
	const ImRect image_bb(window->DC.CursorPos + padding, window->DC.CursorPos + padding + image_size);
	ItemSize(bb);
	if (!ItemAdd(bb, id))
		return false;

	bool hovered, held;
	bool pressed = ButtonBehavior(bb, id, &hovered, &held);

	const ImU32 col = GetColorU32((held && hovered) ? ImGuiCol_ButtonActive : hovered ? ImGuiCol_ButtonHovered : ImGuiCol_Button);

	// Render   
	RenderNavHighlight(bb, id);
	RenderFrame(bb.Min, bb.Max, col, true, 2.f);
	if (bg_col.w > 0.0f)
		window->DrawList->AddRectFilled(image_bb.Min, image_bb.Max, GetColorU32(bg_col));
	const auto alpha = GetStyleColorVec4(ImGuiCol_Text).w;
	window->DrawList->AddImage(user_texture_id, image_bb.Min, image_bb.Max, uv0, uv1, GetColorU32(ImVec4(1.00f, 1.00f, 1.00f, alpha)));

	return pressed;
}

void ImGui::Separator_HPPv6(int count)
{
	while (count--) { ImGui::Separator(); }
}

bool ImGui::MultiCombo_HPPv6(const char* name, const char** displayName, bool* data, int dataSize)
{
	ImGui::PushID(name);

	char previewText[1024] = { 0 };
	char buf[1024] = { 0 };
	char buf2[1024] = { 0 };
	int currentPreviewTextLen = 0;
	float multicomboWidth = GImGui->CurrentWindow->Size.x - (GImGui->CurrentWindow->DC.CursorPos.x - GImGui->CurrentWindow->Pos.x) * 2.f;

	for (int i = 0; i < dataSize; i++) {

		if (data[i] == true) {

			if (currentPreviewTextLen == 0)
				sprintf(buf, "%s", displayName[i]);
			else
				sprintf(buf, ", %s", displayName[i]);

			strcpy(buf2, previewText);
			sprintf(buf2 + currentPreviewTextLen, buf);
			ImVec2 textSize = ImGui::CalcTextSize(buf2);

			if (textSize.x > multicomboWidth) {

				sprintf(previewText + currentPreviewTextLen, "...");
				currentPreviewTextLen += (int)strlen("...");
				break;
			}

			sprintf(previewText + currentPreviewTextLen, buf);
			currentPreviewTextLen += (int)strlen(buf);
		}
	}

	if (currentPreviewTextLen > 0)
		previewText[currentPreviewTextLen] = NULL;

	bool isDataChanged = false;

	ImGui::PushStyleColor(ImGuiCol_Header, GetColorU32(ImGuiCol_HeaderActive));

	if (ImGui::BeginCombo(name, previewText)) {

		for (int i = 0; i < dataSize; i++) {

			sprintf(buf, displayName[i]);

			ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8, 8));

			if (ImGui::Selectable3_HPPv6(buf, data[i], ImGuiSelectableFlags_DontClosePopups)) {

				data[i] = !data[i];
				isDataChanged = true;
			}
			ImGui::PopStyleVar();

		}

		ImGui::EndCombo();
	}

	ImGui::PopStyleColor();

	ImGui::PopID();
	return isDataChanged;
}

bool ImGui::Selectable3_HPPv6(const char* label, bool selected, ImGuiSelectableFlags flags, const ImVec2& size_arg)
{
	return ImGui::Selectable(label, selected, flags, size_arg);
	/*
	ImGuiWindow* window = GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;

	if ((flags & ImGuiSelectableFlags_SpanAllColumns) && window->DC.CurrentColumns) // FIXME-OPT: Avoid if vertically clipped.
		PushColumnsBackground();

	ImGuiID id = window->GetID(label);
	ImVec2 label_size = CalcTextSize(label, NULL, true);
	ImVec2 size(size_arg.x != 0.0f ? size_arg.x : label_size.x, size_arg.y != 0.0f ? size_arg.y : label_size.y);
	ImVec2 pos = window->DC.CursorPos;
	pos.y += window->DC.CurrLineTextBaseOffset;
	ImRect bb_inner(pos, pos + size);
	ItemSize(size);

	// Fill horizontal space.
	ImVec2 window_padding = window->WindowPadding;
	float max_x = (flags & ImGuiSelectableFlags_SpanAllColumns) ? GetWindowContentRegionMax().x : GetContentRegionMax().x;
	float w_draw = ImMax(label_size.x, window->Pos.x + max_x - window_padding.x - pos.x);
	ImVec2 size_draw((size_arg.x != 0 && !(flags & ImGuiSelectableFlags_DrawFillAvailWidth)) ? size_arg.x : w_draw, size_arg.y != 0.0f ? size_arg.y : size.y);
	ImRect bb(pos, pos + size_draw);
	if (size_arg.x == 0.0f || (flags & ImGuiSelectableFlags_DrawFillAvailWidth))
		bb.Max.x += window_padding.x;

	// Selectables are tightly packed together so we extend the box to cover spacing between selectable.
	const float spacing_x = style.ItemSpacing.x;
	const float spacing_y = style.ItemSpacing.y;
	const float spacing_L = (float)(int)(spacing_x * 0.50f);
	const float spacing_U = (float)(int)(spacing_y * 0.50f);
	bb.Min.x -= spacing_L;
	bb.Min.y -= spacing_U;
	bb.Max.x += (spacing_x - spacing_L);
	bb.Max.y += (spacing_y - spacing_U);

	bool item_add;
	if (flags & ImGuiSelectableFlags_Disabled)
	{
		//ImGuiItemFlags backup_item_flags = window->DC.ItemFlags;
		//window->DC.ItemFlags |= ImGuiItemFlags_Disabled | ImGuiItemFlags_NoNavDefaultFocus;
		//item_add = ItemAdd(bb, id);
		//window->DC.ItemFlags = backup_item_flags;
		ImGuiItemFlags backup_item_flags = ImGui::GetItemFlags();
		ImGuiItemFlags current_item_flags = backup_item_flags;
		current_item_flags |= ImGuiItemFlags_Disabled | ImGuiItemFlags_NoNavDefaultFocus;
		ImGui::PushItemFlag(current_item_flags, true);
		item_add = ItemAdd(bb, id);
		ImGui::PopItemFlag();
	}
	else
	{
		item_add = ItemAdd(bb, id);
	}
	if (!item_add)
	{
		if ((flags & ImGuiSelectableFlags_SpanAllColumns) && window->DC.CurrentColumns)
			PopColumnsBackground();
		return false;
	}

	// We use NoHoldingActiveID on menus so user can click and _hold_ on a menu then drag to browse child entries
	ImGuiButtonFlags button_flags = 0;
	if (flags & ImGuiSelectableFlags_NoHoldingActiveID) button_flags |= ImGuiButtonFlags_NoHoldingActiveId;
	if (flags & ImGuiSelectableFlags_PressedOnClick) button_flags |= ImGuiButtonFlags_PressedOnClick;
	if (flags & ImGuiSelectableFlags_PressedOnRelease) button_flags |= ImGuiButtonFlags_PressedOnRelease;
	if (flags & ImGuiSelectableFlags_Disabled) button_flags |= ImGuiButtonFlags_Disabled;
	if (flags & ImGuiSelectableFlags_AllowDoubleClick) button_flags |= ImGuiButtonFlags_PressedOnClickRelease | ImGuiButtonFlags_PressedOnDoubleClick;
	if (flags & ImGuiSelectableFlags_AllowItemOverlap) button_flags |= ImGuiButtonFlags_AllowItemOverlap;

	if (flags & ImGuiSelectableFlags_Disabled)
		selected = false;

	const bool was_selected = selected;
	bool hovered, held;
	bool pressed = ButtonBehavior(bb, id, &hovered, &held, button_flags);
	// Hovering selectable with mouse updates NavId accordingly so navigation can be resumed with gamepad/keyboard (this doesn't happen on most widgets)
	if (pressed || hovered)
		if (!g.NavDisableMouseHover && g.NavWindow == window && g.NavLayer == window->DC.NavLayerCurrent)
		{
			g.NavDisableHighlight = true;
			SetNavID(id, window->DC.NavLayerCurrent);
		}
	if (pressed)
		MarkItemEdited(id);

	if (flags & ImGuiSelectableFlags_AllowItemOverlap)
		SetItemAllowOverlap();

	// In this branch, Selectable() cannot toggle the selection so this will never trigger.
	if (selected != was_selected) //-V547
		window->DC.LastItemStatusFlags |= ImGuiItemStatusFlags_ToggledSelection;

	// Render
	if (held && (flags & ImGuiSelectableFlags_DrawHoveredWhenHeld))
		hovered = true;
	if (hovered)
	{
		const ImU32 col = GetColorU32((held && hovered) ? ImGuiCol_HeaderActive : hovered ? ImGuiCol_HeaderHovered : ImGuiCol_Header);
		RenderFrame(bb.Min, bb.Max, col, false, 0.0f);
		RenderNavHighlight(bb, id, ImGuiNavHighlightFlags_TypeThin | ImGuiNavHighlightFlags_NoRounding);
	}

	//const float square_sz = g.FontSize + 1.f//GetFrameHeight();
	const float square_sz = g.FontSize + 1.f;

	const ImRect check_bb(bb_inner.Min, pos + ImVec2(square_sz, square_sz));
	RenderNavHighlight(check_bb, id);
	RenderFrame(check_bb.Min, check_bb.Max, selected ? GetColorU32(ImGuiCol_CheckMark) : GetColorU32(ImGuiCol_FrameBg), true, 2.f);

	if ((flags & ImGuiSelectableFlags_SpanAllColumns) && window->DC.CurrentColumns)
	{
		PopColumnsBackground();
		bb.Max.x -= (GetContentRegionMax().x - max_x);
	}

	if (flags & ImGuiSelectableFlags_Disabled) PushStyleColor(ImGuiCol_Text, style.Colors[ImGuiCol_TextDisabled]);
	RenderTextClipped(ImVec2(check_bb.Max.x + 5, bb_inner.Min.y), bb_inner.Max, label, NULL, &label_size, style.SelectableTextAlign, &bb);
	if (flags & ImGuiSelectableFlags_Disabled) PopStyleColor();

	// Automatically close popups
	if (pressed && (window->Flags & ImGuiWindowFlags_Popup) && !(flags & ImGuiSelectableFlags_DontClosePopups) && !(window->DC.ItemFlags & ImGuiItemFlags_SelectableDontClosePopup))
		CloseCurrentPopup();

	IMGUI_TEST_ENGINE_ITEM_INFO(id, label, window->DC.ItemFlags);
	return pressed;
	*/
}

bool ImGui::KeyButtonToggle_HPPv6(const char* label, void* v, bool owned)
{
	static int keynum;

	int* bind = reinterpret_cast<int*>(v);

	ImGuiWindow* window = GetCurrentWindow();
	if (window->SkipItems)
		return false;

	//std::string keystring = Game::KeynumToString(bind[0]);
	std::string keystring = ImGui::GetKeyName((ImGuiKey)bind[0]);
	std::string popup_label = label;
	popup_label.append("##KeyAssignment");

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = CalcTextSize(label, NULL, true);

	ImVec2 pos = window->DC.CursorPos;

	const ImRect total_bb(pos - 4, pos + ImVec2(window->Size.x - (pos.x - window->Pos.x) * 2.f, owned ? g.FontSize + 1.f : 17) + 4);
	ItemSize(total_bb, style.FramePadding.y);
	if (!ItemAdd(total_bb, id))
		return false;

	bool hovered, held;
	bool pressed = ButtonBehavior(total_bb, id, &hovered, &held);

	RenderFrame(total_bb.Min, total_bb.Max, GetColorU32(ImGuiCol_Border), true, 2.f);

	ImRect check_bb;

	if (owned)
	{
		check_bb = ImRect(pos, pos + ImVec2(window->Size.x - (pos.x - window->Pos.x) * 2.f, g.FontSize + 1.f));
	}
	else
	{
		check_bb = ImRect(ImVec2(pos.x + window->Size.x * 0.5f, pos.y), ImVec2(pos.x + window->Size.x * 0.5f, pos.y) +
			ImVec2(window->Size.x * 0.5f - (pos.x - window->Pos.x) * 2.f, 17));
	}

	if (label_size.x > 0.0f && !owned)
		RenderText(ImVec2(total_bb.Min.x + 4, total_bb.Min.y + 4 + 1), label);

	const ImU32 col = GetColorU32((held && hovered) ? ImGuiCol_ButtonHovered : hovered ? ImGuiCol_ButtonHovered : ImGuiCol_Button);

	RenderNavHighlight(check_bb, id);
	RenderFrame(check_bb.Min, check_bb.Max, GetColorU32(ImGuiCol_FrameBg), true, 2.f);
	RenderTextClipped(check_bb.Min, check_bb.Max, keystring.c_str(), NULL, NULL, style.ButtonTextAlign, &check_bb);

	if (pressed)
		ImGui::OpenPopup(popup_label.c_str());

	ImGui::SetNextWindowSize(ImVec2(250, 92));

	const auto flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize;

	ImVec4 backup_popupbg = g.Style.Colors[ImGuiCol_PopupBg];
	g.Style.Colors[ImGuiCol_PopupBg] = g.Style.Colors[ImGuiCol_ChildBg];

	if (ImGui::BeginPopupModal(popup_label.c_str(), nullptr, flags | ImGuiWindowFlags_NoBackground))
	{
		ImGui::Spacing_HPPv6(2);
		ImGui::SameLine(WINDOW_PADDING_SAMELINE);
		ImGui::BeginGroup();

		if (keynum)
		{
			bind[1] = 2;
			keynum = 0;
			ImGui::CloseCurrentPopup();
		}
		else
		{
			std::string message = "Press any key";

			const float item_width = GImGui->CurrentWindow->Size.x - WINDOW_PADDING_SAMELINE * 2.f;
			ImVec2 text_size = GImGui->Font->CalcTextSizeA(GImGui->Font->FontSize, item_width, 0, message.c_str());

			ImGui::SameLine((item_width - text_size.x) * 0.5f);
			ImGui::Text(message.c_str());

			ImGui::Spacing();

			ImGui::PushStyleColor(ImGuiCol_Border, ImVec4());

			if (ImGui::Button("Delete", ImVec2(106, 20)))
			{
				keynum = 0;
				memset(bind, 0, sizeof(int) * 2);
				ImGui::CloseCurrentPopup();
			}

			ImGui::SameLine();

			if (ImGui::Button("Cancel", ImVec2(106, 20)))
				ImGui::CloseCurrentPopup();

			ImGui::PopStyleColor();

			WaitForPressKey(&keynum);

			if (keynum == ImGuiKey_MouseLeft || keynum == ImGuiKey_MouseRight)
				keynum = ImGuiKey_None;

			if (keynum)
			{
				memset(bind, 0, sizeof(int) * 2);
				bind[0] = keynum;
			}
		}

		ImRect window_rect = ImRect(GImGui->CurrentWindow->Pos, GImGui->CurrentWindow->Size);

		GImGui->CurrentWindow->DrawList->PushClipRectFullScreen();

		RectangleShadowSettings_HPPv6 shadow_settings;
		shadow_settings.shadowColor = GImGui->Style.Colors[ImGuiCol_BorderShadow];
		ImGui::DrawRectangleShadowVerticesAdaptive_HPPv6(shadow_settings, window_rect.Min, window_rect.Max);

		ImGui::EndGroup();
		ImGui::EndPopup();
	}

	g.Style.Colors[ImGuiCol_PopupBg] = backup_popupbg;

	return pressed;
}

bool ImGui::KeyButtonPress_HPPv6(const char* label, void* v, bool owned)
{
	static int keynum;

	int* bind = reinterpret_cast<int*>(v);

	ImGuiWindow* window = GetCurrentWindow();
	if (window->SkipItems)
		return false;

	//std::string keystring = Game::KeynumToString(bind[0]);
	std::string keystring = ImGui::GetKeyName((ImGuiKey)bind[0]);
	std::string popup_label = label;
	popup_label.append("##KeyAssignment");

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = CalcTextSize(label, NULL, true);

	ImVec2 pos = window->DC.CursorPos;

	const ImRect total_bb(pos - 4, pos + ImVec2(window->Size.x - (pos.x - window->Pos.x) * 2.f, owned ? g.FontSize + 1.f : 17) + 4);
	ItemSize(total_bb, style.FramePadding.y);
	if (!ItemAdd(total_bb, id))
		return false;

	bool hovered, held;
	bool pressed = ButtonBehavior(total_bb, id, &hovered, &held);

	RenderFrame(total_bb.Min, total_bb.Max, GetColorU32(ImGuiCol_Border), true, 2.f);

	ImRect check_bb;

	if (owned)
	{
		check_bb = ImRect(pos, pos + ImVec2(window->Size.x - (pos.x - window->Pos.x) * 2.f, g.FontSize + 1.f));
	}
	else
	{
		check_bb = ImRect(ImVec2(pos.x + window->Size.x * 0.5f, pos.y), ImVec2(pos.x + window->Size.x * 0.5f, pos.y) +
			ImVec2(window->Size.x * 0.5f - (pos.x - window->Pos.x) * 2.f, 17));
	}

	if (label_size.x > 0.0f && !owned)
		RenderText(ImVec2(total_bb.Min.x + 4, total_bb.Min.y + 4 + 1), label);

	const ImU32 col = GetColorU32((held && hovered) ? ImGuiCol_ButtonHovered : hovered ? ImGuiCol_ButtonHovered : ImGuiCol_Button);

	RenderNavHighlight(check_bb, id);
	RenderFrame(check_bb.Min, check_bb.Max, GetColorU32(ImGuiCol_FrameBg), true, 2.f);
	RenderTextClipped(check_bb.Min, check_bb.Max, keystring.c_str(), NULL, NULL, style.ButtonTextAlign, &check_bb);

	if (pressed)
		ImGui::OpenPopup(popup_label.c_str());

	ImGui::SetNextWindowSize(ImVec2(250, 92));

	const auto flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize;

	ImVec4 backup_popupbg = g.Style.Colors[ImGuiCol_PopupBg];
	g.Style.Colors[ImGuiCol_PopupBg] = g.Style.Colors[ImGuiCol_ChildBg];

	if (ImGui::BeginPopupModal(popup_label.c_str(), nullptr, flags | ImGuiWindowFlags_NoBackground))
	{
		ImGui::Spacing_HPPv6(2);
		ImGui::SameLine(WINDOW_PADDING_SAMELINE);
		ImGui::BeginGroup();

		if (keynum)
		{
			bind[1] = 1;
			keynum = 0;
			ImGui::CloseCurrentPopup();
		}
		else
		{
			std::string message = "Press any key";

			const float item_width = GImGui->CurrentWindow->Size.x - WINDOW_PADDING_SAMELINE * 2.f;
			ImVec2 text_size = GImGui->Font->CalcTextSizeA(GImGui->Font->FontSize, item_width, 0, message.c_str());

			ImGui::SameLine((item_width - text_size.x) * 0.5f);
			ImGui::Text(message.c_str());

			ImGui::Spacing();

			ImGui::PushStyleColor(ImGuiCol_Border, ImVec4());

			if (ImGui::Button("Delete", ImVec2(106, 20)))
			{
				keynum = 0;
				memset(bind, 0, sizeof(int) * 2);
				ImGui::CloseCurrentPopup();
			}

			ImGui::SameLine();

			if (ImGui::Button("Cancel", ImVec2(106, 20)))
				ImGui::CloseCurrentPopup();

			ImGui::PopStyleColor();

			WaitForPressKey(&keynum);

			if (keynum == ImGuiKey_MouseLeft || keynum == ImGuiKey_MouseRight)
				keynum = ImGuiKey_None;

			if (keynum)
			{
				memset(bind, 0, sizeof(int) * 2);
				bind[0] = keynum;
			}
		}

		ImRect window_rect = ImRect(GImGui->CurrentWindow->Pos, GImGui->CurrentWindow->Size);

		GImGui->CurrentWindow->DrawList->PushClipRectFullScreen();

		RectangleShadowSettings_HPPv6 shadow_settings;
		shadow_settings.shadowColor = ImGui::GetStyleColorVec4(ImGuiCol_BorderShadow);
		ImGui::DrawRectangleShadowVerticesAdaptive_HPPv6(shadow_settings, window_rect.Min, window_rect.Max);

		ImGui::EndGroup();
		ImGui::EndPopup();
	}

	g.Style.Colors[ImGuiCol_PopupBg] = backup_popupbg;

	return pressed;
}

// Getter for the old Combo() API: const char*[]
static bool Items_ArrayGetter_HPPv6(void* data, int idx, const char** out_text)
{
	const char* const* items = (const char* const*)data;
	if (out_text)
		*out_text = items[idx];
	return true;
}

// Combo box helper allowing to pass an array of strings.
bool ImGui::Combo_HPPv6(const char* label, int* current_item, const char* const items[], int items_count, int height_in_items, bool owned)
{
	const bool value_changed = Combo(label, current_item, Items_ArrayGetter_HPPv6, (void*)items, items_count, height_in_items);
	return value_changed;
}

// Old API, prefer using BeginCombo() nowadays if you can.
/*
bool ImGui::Combo_HPPv6(const char* label, int* current_item, bool (*items_getter)(void*, int, const char**), void* data, int items_count, int popup_max_height_in_items, bool owned)
{
	ImGuiContext& g = *GImGui;

	// Call the getter to obtain the preview string which is a parameter to BeginCombo()
	const char* preview_value = NULL;
	if (*current_item >= 0 && *current_item < items_count)
		items_getter(data, *current_item, &preview_value);

	// The old Combo() API exposed "popup_max_height_in_items". The new more general BeginCombo() API doesn't have/need it, but we emulate it here.
	if (popup_max_height_in_items != -1 && !(g.NextWindowData.Flags & ImGuiNextWindowDataFlags_HasSizeConstraint))
		SetNextWindowSizeConstraints(ImVec2(0, 0), ImVec2(FLT_MAX, CalcMaxPopupHeightFromItemCount(popup_max_height_in_items)));

	if (!BeginCombo(label, preview_value, ImGuiComboFlags_None, owned))
		return false;

	// Display items
	// FIXME-OPT: Use clipper (but we need to disable it on the appearing frame to make sure our call to SetItemDefaultFocus() is processed)
	bool value_changed = false;
	for (int i = 0; i < items_count; i++)
	{
		PushID((void*)(intptr_t)i);
		const bool item_selected = (i == *current_item);
		const char* item_text;
		if (!items_getter(data, i, &item_text))
			item_text = "*Unknown item*";
		if (Selectable(item_text, item_selected))
		{
			value_changed = true;
			*current_item = i;
		}
		if (item_selected)
			SetItemDefaultFocus();
		PopID();
	}

	EndCombo();
	return value_changed;
}
*/