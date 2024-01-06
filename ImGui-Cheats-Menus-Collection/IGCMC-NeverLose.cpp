#include "IGCMC-Precompiled.h"

/*
Source downloaded and modified from https://corsair.wtf/topic/14610-neverpivo-v2-imgui-csgo-hack/
Uploaded by "rgb to hex"
Password: 123
*/

#include "NeverLose/aa.h"
#include "NeverLose/configs.h"
#include "NeverLose/grenades.h"
#include "NeverLose/inventory.h"
#include "NeverLose/legit.h"
#include "NeverLose/main.h"
#include "NeverLose/players.h"
#include "NeverLose/rage.h"
#include "NeverLose/scripts.h"
#include "NeverLose/soufiw.h"
#include "NeverLose/view.h"
#include "NeverLose/weapons.h"
#include "NeverLose/world.h"

ImFont* tolstiy = nullptr;
ImFont* ne_takoi_tolstiy = nullptr;
ImFont* ne_takoi_tolstiy2 = nullptr;
GLuint r = 0;
GLuint a = 0;
GLuint l = 0;
GLuint p = 0;
GLuint w = 0;
GLuint g = 0;
GLuint wo = 0;
GLuint v = 0;
GLuint m = 0;
GLuint i = 0;
GLuint s = 0;
GLuint c = 0;
GLuint soufiww = 0;

int tabs = 0;
float animspeed;
bool customize = false;

void ImDrawList_AddCircleImageFilled(ImTextureID user_texture_id, const ImVec2& centre, float radius, ImU32 col, int num_segments)
{
    auto window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return;

    ImGuiContext& g = *GImGui;
    window->DrawList->PathClear();

    if ((col & IM_COL32_A_MASK) == 0 || num_segments <= 2)
        return;


    const bool push_texture_id = window->DrawList->_TextureIdStack.empty() || user_texture_id != window->DrawList->_TextureIdStack.back();
    if (push_texture_id)
        window->DrawList->PushTextureID(user_texture_id);

    int vert_start_idx = window->DrawList->VtxBuffer.Size;
    const float a_max = IM_PI * 2.0f * ((float)num_segments - 1.0f) / (float)num_segments;
    window->DrawList->PathArcTo(centre, radius, 0.0f, a_max, num_segments - 1);
    window->DrawList->PathFillConvex(col);
    int vert_end_idx = window->DrawList->VtxBuffer.Size;

    ImGui::ShadeVertsLinearUV(window->DrawList, vert_start_idx, vert_end_idx, ImVec2(centre.x - radius, centre.y - radius), ImVec2(centre.x + radius, centre.y + radius), ImVec2(0, 0), ImVec2(1, 1), true);

    if (push_texture_id)
        window->DrawList->PopTextureID();
}

namespace ImGui
{
    bool NeverLoseCheckbox(const char* label, bool* v)
    {
        bool bClicked = false;
        ImVec2 p = ImGui::GetCursorScreenPos();
        ImDrawList* draw_list = ImGui::GetWindowDrawList();

        float height = ImGui::GetFrameHeight();
        float width = height * 1.50f;
        float radius = height * 0.50f;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        const ImGuiID id = window->GetID(label);
        const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

        const float square_sz = GetFrameHeight();
        const ImVec2 pos = window->DC.CursorPos;
        const ImRect total_bb(pos, pos + ImVec2(square_sz + (label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f), label_size.y + style.FramePadding.y * 2.0f));
        if (!ItemAdd(total_bb, id))
            return bClicked;


        ImGui::InvisibleButton(label, ImVec2(190 + width, height));
        if (ImGui::IsItemClicked())
        {
            *v = !*v;
            bClicked = true;
        }

        float t = *v ? 1.0f : 0.0f;

        if (customize == true)
        {
        }
        else
        {
            animspeed = 0.30f;
        }
        if (g.LastActiveId == g.CurrentWindow->GetID(label))
        {
            float t_anim = ImSaturate(g.LastActiveIdTimer / animspeed);
            t = *v ? (t_anim) : (1.f - t_anim);
        }

        ImU32 col_bg;
        ImU32 col_bg2;
        if (ImGui::IsItemHovered())
        {
            col_bg = ImGui::GetColorU32(ImLerp(ImColor(0, 0, 0), ImVec4(0.01f, 0.09f, 0.17f, 1.f), t));
            col_bg2 = ImGui::GetColorU32(ImLerp(ImColor(84, 83, 89, 255), ImVec4(0.3f, 0.6f, 1.f, 1.f), t));
        }
        else
        {
            col_bg = ImGui::GetColorU32(ImLerp(ImColor(0, 0, 0), ImVec4(0.01f, 0.09f, 0.17f, 1.f), t));
            col_bg2 = ImGui::GetColorU32(ImLerp(ImColor(84, 83, 89, 255), ImVec4(0.3f, 0.6f, 1.f, 1.f), t));
        }

        draw_list->AddRectFilled(ImVec2(p.x + 203, p.y + 4), ImVec2(p.x + 227, p.y + 15), col_bg, height * 0.5f);
        draw_list->AddCircleFilled(ImVec2(200 + p.x + radius + t * (width - radius * 2.0f), p.y + radius), radius - 2.5f, col_bg2);

        if (label_size.x > 0.0f)
        {
            ImGui::PushFont(ne_takoi_tolstiy2);
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 1.f, 1.f, 1.f));
            RenderText(ImVec2((p.x + width) - 35, (p.y + height) - 16), label);
            ImGui::PopStyleColor(1);
            ImGui::PopFont();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
        }
        return bClicked;
    }
}

#if defined(_WIN32)
    #define BASE_FONT_DIR "C:\\Windows\\Fonts\\"
#elif defined(__EMSCRIPTEN__)
    #define BASE_FONT_DIR "/FileSystem/Fonts/"
#endif

void IGCMC::Interfaces::Cheats::NeverLoseV2::Setup(bool* pbIsInitialized)
{
	if (!*pbIsInitialized)
	{
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        tolstiy = io.Fonts->AddFontFromFileTTF(BASE_FONT_DIR "ariblk.ttf", 40.0f);
        ne_takoi_tolstiy = io.Fonts->AddFontFromFileTTF(BASE_FONT_DIR "arialbd.ttf", 13.0f);
        ne_takoi_tolstiy2 = io.Fonts->AddFontFromFileTTF(BASE_FONT_DIR "arialbd.ttf", 15.0f);

        int width = 15, height = 15;
        IGCMC::Utils::LoadTextureFromMemory(rage, sizeof(rage), &r, &width, &height);
        IGCMC::Utils::LoadTextureFromMemory(antiaim, sizeof(antiaim), &a, &width, &height);
        width = 13;
        IGCMC::Utils::LoadTextureFromMemory(legit, sizeof(legit), &l, &width, &height);
        width = 15;
        IGCMC::Utils::LoadTextureFromMemory(players, sizeof(players), &p, &width, &height);
        height = 13;
        IGCMC::Utils::LoadTextureFromMemory(weapons, sizeof(weapons), &w, &width, &height);
        IGCMC::Utils::LoadTextureFromMemory(grenades, sizeof(grenades), &g, &width, &height);
        height = 15;
        IGCMC::Utils::LoadTextureFromMemory(world, sizeof(world), &wo, &width, &height);
        IGCMC::Utils::LoadTextureFromMemory(view, sizeof(view), &v, &width, &height);
        IGCMC::Utils::LoadTextureFromMemory(mmain, sizeof(mmain), &m, &width, &height);
        IGCMC::Utils::LoadTextureFromMemory(inventory, sizeof(inventory), &i, &width, &height);
        IGCMC::Utils::LoadTextureFromMemory(scripts, sizeof(scripts), &s, &width, &height);
        IGCMC::Utils::LoadTextureFromMemory(configs, sizeof(configs), &c, &width, &height);
        IGCMC::Utils::LoadTextureFromMemory(soufiw, sizeof(soufiw), &soufiww, &width, &height);

        *pbIsInitialized = tolstiy && ne_takoi_tolstiy && ne_takoi_tolstiy2 &&
            r && a && l && p && w && g && wo && v && m && i && s && c && soufiww;
	}
}

void IGCMC::Interfaces::Cheats::NeverLoseV2::Destroy(bool* pbIsInitialized)
{
	if (*pbIsInitialized)
	{

	}
}

void Tabss()
{
    ImVec2 pos;
    ImDrawList* draw;

    pos = ImGui::GetWindowPos();
    draw = ImGui::GetWindowDrawList();

    /*
    ImVec4* colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_Button] = ImColor(35, 35, 45, 0);
    colors[ImGuiCol_ButtonActive] = ImColor(63, 63, 60, 255);
    colors[ImGuiCol_ButtonHovered] = ImColor(63, 63, 60, 255);
    */
    ImGui::PushStyleColor(ImGuiCol_Button, ImColor(35, 35, 45, 0).Value);
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor(63, 63, 60, 255).Value);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor(63, 63, 60, 255).Value);
    ImGui::PushFont(ne_takoi_tolstiy);
    ImGui::SetCursorPos(ImVec2(12, 94));
    if (ImGui::Button("##rage", ImVec2(172, 31)))
        tabs = 0;
    ImGui::SetCursorPos(ImVec2(12, 130));
    if (ImGui::Button("##aa", ImVec2(172, 31)))
        tabs = 1;
    ImGui::SetCursorPos(ImVec2(12, 166));
    if (ImGui::Button("##legit", ImVec2(172, 31)))
        tabs = 2;
    ImGui::SetCursorPos(ImVec2(12, 234));
    if (ImGui::Button("##players", ImVec2(172, 31)))
        tabs = 3;
    ImGui::SetCursorPos(ImVec2(12, 270));
    if (ImGui::Button("##weapon", ImVec2(172, 31)))
        tabs = 4;
    ImGui::SetCursorPos(ImVec2(12, 306));
    if (ImGui::Button("##grenades", ImVec2(172, 31)))
        tabs = 5;
    ImGui::SetCursorPos(ImVec2(12, 342));
    if (ImGui::Button("##world", ImVec2(172, 31)))
        tabs = 6;
    ImGui::SetCursorPos(ImVec2(12, 378));
    if (ImGui::Button("##view", ImVec2(172, 31)))
        tabs = 7;
    ImGui::SetCursorPos(ImVec2(12, 433));
    if (ImGui::Button("##main", ImVec2(172, 31)))
        tabs = 8;
    ImGui::SetCursorPos(ImVec2(12, 469));
    if (ImGui::Button("##inventory", ImVec2(172, 31)))
        tabs = 9;
    ImGui::SetCursorPos(ImVec2(12, 505));
    if (ImGui::Button("##scripts", ImVec2(172, 31)))
        tabs = 10;
    ImGui::SetCursorPos(ImVec2(12, 541));
    if (ImGui::Button("##config", ImVec2(172, 31)))
        tabs = 11;

    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 101), ImColor(255, 255, 255), "Ragebot");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 137), ImColor(255, 255, 255), "Anti Aim");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 173), ImColor(255, 255, 255), "Legitbot");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 241), ImColor(255, 255, 255), "Players");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 277), ImColor(255, 255, 255), "Weapon");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 313), ImColor(255, 255, 255), "Grenades");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 349), ImColor(255, 255, 255), "World");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 385), ImColor(255, 255, 255), "View");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 440), ImColor(255, 255, 255), "Main");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 476), ImColor(255, 255, 255), "Inventory");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 512), ImColor(255, 255, 255), "Scripts");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 548), ImColor(255, 255, 255), "Configs");

    ImGui::SetCursorPos(ImVec2(25, 102));
    ImGui::Image((void*)(intptr_t)r, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 138));
    ImGui::Image((void*)(intptr_t)a, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 174));
    ImGui::Image((void*)(intptr_t)l, ImVec2(13, 15));

    ImGui::SetCursorPos(ImVec2(25, 242));
    ImGui::Image((void*)(intptr_t)p, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 278));
    ImGui::Image((void*)(intptr_t)w, ImVec2(15, 13));

    ImGui::SetCursorPos(ImVec2(25, 314));
    ImGui::Image((void*)(intptr_t)g, ImVec2(15, 13));

    ImGui::SetCursorPos(ImVec2(25, 350));
    ImGui::Image((void*)(intptr_t)wo, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 386));
    ImGui::Image((void*)(intptr_t)v, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 441));
    ImGui::Image((void*)(intptr_t)m, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 477));
    ImGui::Image((void*)(intptr_t)i, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 513));
    ImGui::Image((void*)(intptr_t)s, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 549));
    ImGui::Image((void*)(intptr_t)c, ImVec2(15, 15));
    ImGui::PopFont();
    ImGui::PopStyleColor(3);
}

void IGCMC::Interfaces::Cheats::NeverLoseV2::Render(bool* pbMustOpenThisMenu)
{
    if (*pbMustOpenThisMenu)
    {
        ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 1.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 1.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(4.f, 3.f));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8.f, 8.f));
        ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, ImVec2(4.f, 4.f));
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8.f, 4.f));
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.f);
        ImGui::PushStyleVar(ImGuiStyleVar_ScrollbarSize, 2.f);
        ImGui::PushStyleVar(ImGuiStyleVar_ScrollbarRounding, 12.f);

        ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(24, 29, 59, 0).Value);
        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.07f, 0.07f, 0.11f, 0.50f));
        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImColor(25, 25, 33, 255).Value);
        ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImColor(25, 25, 33, 255).Value);
        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImColor(25, 25, 33, 255).Value);
        ImGui::PushStyleColor(ImGuiCol_Header, ImColor(25, 25, 33, 255).Value);
        ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImColor(28, 28, 36, 255).Value);
        ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImColor(30, 30, 38, 255).Value);
        ImGui::PushStyleColor(ImGuiCol_PopupBg, ImColor(35, 35, 45, 255).Value);

        bool bMenuIsOpen = ImGui::Begin("##NEVERPIVO", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar);

        if (bMenuIsOpen)
        {
            ImVec2 pos;
            ImDrawList* draw;

            pos = ImGui::GetWindowPos();
            draw = ImGui::GetWindowDrawList();

            ImGui::SetWindowSize(ImVec2(810, 675));

            draw->AddRectFilled(ImVec2(pos.x + 190, pos.y + 0), ImVec2(pos.x + 807, pos.y + 657), ImColor(8, 8, 8), 8.f, ImDrawFlags_RoundCornersAll);
            draw->AddRectFilled(ImVec2(pos.x + 0, pos.y + 0), ImVec2(pos.x + 197, pos.y + 657), ImColor(8, 8, 8, 230), 10.f, ImDrawFlags_RoundCornersAll);

            draw->AddText(tolstiy, 35.f, ImVec2(pos.x + 16, pos.y + 26), ImColor(65, 186, 217), "NEVERPIVO");
            draw->AddText(tolstiy, 35.f, ImVec2(pos.x + 17, pos.y + 26), ImColor(255, 255, 255), "NEVERPIVO");

            draw->AddLine(ImVec2(pos.x + 0, pos.y + 593), ImVec2(pos.x + 190, pos.y + 594), ImColor(32, 32, 30));
            draw->AddLine(ImVec2(pos.x + 190, pos.y + 70), ImVec2(pos.x + 807, pos.y + 71), ImColor(32, 32, 30));

            draw->AddText(ne_takoi_tolstiy, 13.f, ImVec2(pos.x + 21, pos.y + 74), ImColor(55, 55, 55), "Aimbot");
            draw->AddText(ne_takoi_tolstiy, 13.f, ImVec2(pos.x + 21, pos.y + 214), ImColor(55, 55, 55), "Visuals");
            draw->AddText(ne_takoi_tolstiy, 13.f, ImVec2(pos.x + 21, pos.y + 412), ImColor(55, 55, 55), "Miscellaneous");

            Tabss();

            ImGui::SetCursorPos(ImVec2(100, 100));
            ImDrawList_AddCircleImageFilled((void*)(intptr_t)soufiww, ImVec2(pos.x + 39, pos.y + 626), 23.f, ImColor(255, 255, 255), 360);
            draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 70, pos.y + 606), ImColor(255, 255, 255), "Putin");
            draw->AddText(ne_takoi_tolstiy, 13.f, ImVec2(pos.x + 70, pos.y + 630), ImColor(55, 55, 55), "Till:");
            draw->AddText(ne_takoi_tolstiy, 13.f, ImVec2(pos.x + 95, pos.y + 630), ImColor(22, 162, 240), "01.01.2100");

            ImGui::PushFont(ne_takoi_tolstiy);
            static bool te = false, te1 = false;
            if (tabs == 0)
            {
            }

            if (tabs == 1)
            {
            }

            if (tabs == 2)
            {
            }

            if (tabs == 3)
            {
                //ESP
                ImGui::BeginGroup();
                draw->AddRectFilled(ImVec2(pos.x + 210, pos.y + 90), ImVec2(pos.x + 490, pos.y + 450), ImColor(13, 11, 16));
                draw->AddLine(ImVec2(pos.x + 210, pos.y + 120), ImVec2(pos.x + 490, pos.y + 121), ImColor(32, 32, 30));
                draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 218, pos.y + 98), ImColor(255, 255, 255), "ESP");

                ImGui::SetCursorPos(ImVec2(230, 130));
                ImGui::NeverLoseCheckbox("test", &te);

                ImGui::EndGroup();
                //

                //CHAMS
                ImGui::BeginGroup();
                draw->AddRectFilled(ImVec2(pos.x + 506, pos.y + 90), ImVec2(pos.x + 786, pos.y + 450), ImColor(13, 11, 16));
                draw->AddLine(ImVec2(pos.x + 506, pos.y + 120), ImVec2(pos.x + 786, pos.y + 121), ImColor(32, 32, 30));
                draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 516, pos.y + 98), ImColor(255, 255, 255), "Chams");

                ImGui::SetCursorPos(ImVec2(527, 130));
                ImGui::NeverLoseCheckbox("test1", &te1);


                ImGui::EndGroup();
                //
            }

            if (tabs == 4)
            {
            }

            if (tabs == 5)
            {
            }

            if (tabs == 6)
            {
            }

            if (tabs == 7)
            {
            }

            if (tabs == 8)
            {
            }

            if (tabs == 9)
            {
            }

            if (tabs == 10)
            {
            }

            if (tabs == 11)
            {
            }
            ImGui::PopFont();
        }
        ImGui::End();

        ImGui::PopStyleColor(9);
        ImGui::PopStyleVar(9);
    }
}