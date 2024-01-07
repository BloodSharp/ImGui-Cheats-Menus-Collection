#include "IGCMC-Precompiled.h"

CRenderer::CRenderer()
{
	/*
	if (!ImGui::CreateContext())
	{
		Utils::TraceLog(V("> %s: ImGui::CreateContext() failed to initialize.\n"), V(__FUNCTION__));

		g_pGlobals->m_bIsUnloadingLibrary = true;

		return;
	}

	if (!ImGui_ImplWin32_Init(g_pGlobals->m_hWnd))
	{
		Utils::TraceLog(V("> %s: ImGui_ImplWin32_Init() failed to initialize.\n"), V(__FUNCTION__));

		g_pGlobals->m_bIsUnloadingLibrary = true;

		return;
	}

	ImGui_ImplOpenGL2_Init();
	*/
}

CRenderer::~CRenderer()
{
	/*
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	*/
}

static void BeginScene()
{
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4());
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2());

	ImGui::SetNextWindowPos(ImVec2(), ImGuiCond_Always);
	ImGui::SetNextWindowSize(GImGui->IO.DisplaySize, ImGuiCond_Always);

	ImGui::Begin("##renderscene", nullptr, /*ImVec2(), 0,*/ ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoFocusOnAppearing);

	ImGui::PopStyleColor();
	ImGui::PopStyleVar(2);
}

static void EndScene()
{
	//GImGui->CurrentWindow->DrawList->PushClipRectFullScreen();
	ImGui::GetCurrentWindow()->DrawList->PushClipRectFullScreen();

	ImGui::End();
}

void CRenderer::RenderScene(void(*RenderFn)(void*), void* hDeviceContext)
{
	BeginScene();

	RenderFn(hDeviceContext);

	/*
	if (!m_add_image_list.empty())
	{
		for (auto& data : m_add_image_list)
			AddImage(data.user_texture_id, data.a, data.b, data.uv_a, data.uv_b, data.col);

		m_add_image_list.clear();
	}

	if (!m_add_quad_filled_list.empty())
	{
		for (auto& data : m_add_quad_filled_list)
			AddQuadFilled(data.a, data.b, data.c, data.d, data.col);

		m_add_quad_filled_list.clear();
	}

	if (!m_add_rect_filled_list.empty())
	{
		for (auto& data : m_add_rect_filled_list)
			AddRectFilled(data.a, data.b, data.col, data.rounding, data.rounding_corners_flags);

		m_add_rect_filled_list.clear();
	}

	if (!m_add_rect_filled_multi_color_list.empty())
	{
		for (auto& data : m_add_rect_filled_multi_color_list)
			AddRectFilledMultiColor(data.a, data.c, data.col_upr_left, data.col_upr_right, data.col_bot_right, data.col_bot_left);

		m_add_rect_filled_multi_color_list.clear();
	}

	if (!m_add_triangle_filled_list.empty())
	{
		for (auto& data : m_add_triangle_filled_list)
			AddTriangleFilled(data.a, data.b, data.c, data.col);

		m_add_triangle_filled_list.clear();
	}

	if (!m_add_circle_filled_list.empty())
	{
		for (auto& data : m_add_circle_filled_list)
			AddCircleFilled(data.centre, data.radius, data.col, data.num_segments);

		m_add_circle_filled_list.clear();
	}

	if (!m_add_quad_list.empty())
	{
		for (auto& data : m_add_quad_list)
			AddQuad(data.a, data.b, data.c, data.d, data.col, data.thickness);

		m_add_quad_list.clear();
	}

	if (!m_add_rect_list.empty())
	{
		for (auto& data : m_add_rect_list)
			AddRect(data.a, data.b, data.col, data.outline, data.rounding, data.rounding_corners_flags);

		m_add_rect_list.clear();
	}

	if (!m_add_rect_corner_list.empty())
	{
		for (auto& data : m_add_rect_corner_list)
			AddRectCorner(data.a, data.b, data.col, data.outline);

		m_add_rect_corner_list.clear();
	}

	if (!m_add_triangle_list.empty())
	{
		for (auto& data : m_add_triangle_list)
			AddTriangle(data.a, data.b, data.c, data.col, data.thickness);

		m_add_triangle_list.clear();
	}

	if (!m_add_circle_list.empty())
	{
		for (auto& data : m_add_circle_list)
			AddCircle(data.centre, data.radius, data.col, data.num_segments, data.thickness);

		m_add_circle_list.clear();
	}

	if (!m_add_line_list.empty())
	{
		for (auto& data : m_add_line_list)
			AddLine(data.a, data.b, data.col);

		m_add_line_list.clear();
	}

	if (!m_add_text_list.empty())
	{
		for (auto& data : m_add_text_list)
			AddText(data.pos, data.col, data.flags, data.fmt.c_str());

		m_add_text_list.clear();
	}

	if (!m_add_text_wrapped_list.empty())
	{
		for (auto& data : m_add_text_wrapped_list)
			AddTextWrapped(data.pos, data.col, data.wrap_width, data.flags, data.fmt.c_str());

		m_add_text_wrapped_list.clear();
	}
	*/

	EndScene();
}

std::unique_ptr<CRenderer> g_pRenderer;