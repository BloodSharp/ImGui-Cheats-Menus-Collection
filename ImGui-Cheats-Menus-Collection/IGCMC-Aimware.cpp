#include "IGCMC-Precompiled.h"

/*
Source downloaded and modified from https://corsair.wtf/topic/17511-imgui-menu/?do=findComment&comment=81320
*/

#include "AimwareV5/logo.h"
#include "AimwareV5/legitbot.h"
#include "AimwareV5/skull.h"
#include "AimwareV5/eye.h"
#include "AimwareV5/wrench.h"
#include "AimwareV5/gear.h"

typedef struct AimwareV5_Context_s
{
    int tabs;
    int subtabs;
    ImFont* info = nullptr;
    ImFont* two = nullptr;
    ImFont* three = nullptr;
    ImFont* tabsf = nullptr;
    ImFont* ee = nullptr;
    ImVec2 pos;
    ImDrawList* draw;
    GLuint logggo = 0;
    GLuint legit = 0;
    GLuint skul = 0;
    GLuint glazz = 0;
    GLuint wrr = 0;
    GLuint grr = 0;
}AimwareV5_Context_t;

AimwareV5_Context_t aimware_v5_context;

namespace ImGui
{
    bool Checkbox_AimwareV5(const char* label, bool* v)
    {
        ImGuiWindow* window = GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const ImGuiID id = window->GetID(label);
        const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
        const float square_sz = ImGui::GetFrameHeight();
        const ImVec2 pos = window->DC.CursorPos;
        const ImRect total_bb(pos, pos + ImVec2(square_sz + (style.ItemInnerSpacing.x + label_size.x + 0), 0 + label_size.y + style.FramePadding.y * 2));
        ItemSize(total_bb, style.FramePadding.y);
        ItemAdd(total_bb, id);

        bool hovered, held;
        bool pressed = ButtonBehavior(total_bb, id, &hovered, &held);

        if (hovered || held)
            ImGui::SetMouseCursor(7);

        if (pressed)
            *v = !(*v);

        window->DrawList->AddRectFilled(ImVec2(total_bb.Min.x + 0, total_bb.Min.y + 0), ImVec2(total_bb.Min.x + 18, total_bb.Min.y + 18), ImColor(58, 56, 59, 255), 4);

        if (*v)
        {
            const float pad = ImMax(1.0f, IM_FLOOR(square_sz / 6.0f));
            RenderCheckMark(window->DrawList, total_bb.Min + ImVec2(pad, pad), ImColor(255, 255, 255), square_sz - pad * 2.0f);
        }
        else
        {
            window->DrawList->AddRectFilled(ImVec2(total_bb.Min.x + 0, total_bb.Min.y + 0), ImVec2(total_bb.Min.x + 18, total_bb.Min.y + 18), ImColor(58, 56, 59, 255), 4);
        }

        ImGui::PushFont(aimware_v5_context.info);
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(229 / 255.f, 229 / 255.f, 229 / 255.f, 255 / 255.f));
        ImGui::RenderText(ImVec2(total_bb.Min.x + style.ItemInnerSpacing.x + 20, total_bb.Min.y + style.FramePadding.y + 0), label);
        ImGui::PopStyleColor();
        ImGui::PopFont();
        return pressed;
    }

    bool tab1_AimwareV5(const char* label, bool selected)
    {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const ImGuiID id = window->GetID(label);
        const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

        ImVec2 pos = window->DC.CursorPos;
        ImVec2 size = ImGui::CalcItemSize(ImVec2(105, 40), label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

        const ImRect bb(pos, pos + size);
        ImGui::ItemSize(size, style.FramePadding.y);
        if (!ImGui::ItemAdd(bb, id))
            return false;

        bool hovered, held;
        bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, NULL);

        if (hovered || held)
            ImGui::SetMouseCursor(7);

        if (selected)
        {
            window->DrawList->AddRectFilled(ImVec2(bb.Min.x - 3, bb.Min.y - 1), ImVec2(bb.Max.x + 3, bb.Max.y + 0), ImColor(220, 60, 40, 255), 8, ImDrawFlags_RoundCornersAll);
        }
        else
        {
            if (!hovered)
            {
                window->DrawList->AddRectFilled(ImVec2(bb.Min.x + 0, bb.Min.y + 0), ImVec2(bb.Max.x + 0, bb.Max.y + 0), ImColor(160, 30, 30, 255), 8, ImDrawFlags_RoundCornersAll);
            }
            else
            {
                window->DrawList->AddRectFilled(ImVec2(bb.Min.x + 0, bb.Min.y + 0), ImVec2(bb.Max.x + 0, bb.Max.y + 0), ImColor(190, 45, 35, 255), 8, ImDrawFlags_RoundCornersAll);
            }
        }


        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(229 / 255.f, 229 / 255.f, 229 / 255.f, 255 / 255.f));
        ImGui::RenderText(ImVec2(bb.Min.x + 0 + (105 / 2 - label_size.x / 3), bb.Min.y + style.FramePadding.y + 12), label);
        ImGui::PopStyleColor();

        return pressed;
    }

    bool tab2_AimwareV5(const char* label, bool selected)
    {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const ImGuiID id = window->GetID(label);
        const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

        ImVec2 pos = window->DC.CursorPos;
        ImVec2 size = ImGui::CalcItemSize(ImVec2(105, 40), label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

        const ImRect bb(pos, pos + size);
        ImGui::ItemSize(size, style.FramePadding.y);
        if (!ImGui::ItemAdd(bb, id))
            return false;

        bool hovered, held;
        bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, NULL);

        if (hovered || held)
            ImGui::SetMouseCursor(7);

        if (selected)
        {
            window->DrawList->AddRectFilled(ImVec2(bb.Min.x - 3, bb.Min.y - 1), ImVec2(bb.Max.x + 3, bb.Max.y + 0), ImColor(220, 60, 40, 255), 8, ImDrawFlags_RoundCornersAll);
        }
        else
        {
            if (!hovered)
            {
                window->DrawList->AddRectFilled(ImVec2(bb.Min.x + 0, bb.Min.y + 0), ImVec2(bb.Max.x + 0, bb.Max.y + 0), ImColor(160, 30, 30, 255), 8, ImDrawFlags_RoundCornersAll);
            }
            else
            {
                window->DrawList->AddRectFilled(ImVec2(bb.Min.x + 0, bb.Min.y + 0), ImVec2(bb.Max.x + 0, bb.Max.y + 0), ImColor(190, 45, 35, 255), 8, ImDrawFlags_RoundCornersAll);
            }
        }


        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(229 / 255.f, 229 / 255.f, 229 / 255.f, 255 / 255.f));
        ImGui::RenderText(ImVec2(bb.Min.x + 0 + (105 / 2 - label_size.x / 3), bb.Min.y + style.FramePadding.y + 12), label);
        ImGui::PopStyleColor();

        return pressed;
    }

    bool tab_AimwareV5(const char* label, bool selected)
    {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const ImGuiID id = window->GetID(label);
        const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

        ImVec2 pos = window->DC.CursorPos;
        ImVec2 size = ImGui::CalcItemSize(ImVec2(105, 40), label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

        const ImRect bb(pos, pos + size);
        ImGui::ItemSize(size, style.FramePadding.y);
        if (!ImGui::ItemAdd(bb, id))
            return false;

        bool hovered, held;
        bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, NULL);

        if (hovered || held)
            ImGui::SetMouseCursor(7);

        if (selected)
        {
            window->DrawList->AddRectFilled(ImVec2(bb.Min.x - 3, bb.Min.y - 1), ImVec2(bb.Max.x + 3, bb.Max.y + 0), ImColor(220, 60, 40, 255), 8, ImDrawFlags_RoundCornersAll);
        }
        else
        {
            if (!hovered)
            {
                window->DrawList->AddRectFilled(ImVec2(bb.Min.x + 0, bb.Min.y + 0), ImVec2(bb.Max.x + 0, bb.Max.y + 0), ImColor(160, 30, 30, 255));
            }
            else
            {
                window->DrawList->AddRectFilled(ImVec2(bb.Min.x + 0, bb.Min.y + 0), ImVec2(bb.Max.x + 0, bb.Max.y + 0), ImColor(190, 45, 35, 255));
            }
        }


        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(229 / 255.f, 229 / 255.f, 229 / 255.f, 255 / 255.f));
        ImGui::RenderText(ImVec2(bb.Min.x + 0 + (105 / 2 - label_size.x / 3), bb.Min.y + style.FramePadding.y + 12), label);
        ImGui::PopStyleColor();

        return pressed;
    }

    bool sub_AimwareV5(const char* label, bool selected)
    {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const ImGuiID id = window->GetID(label);
        const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
        ImDrawList* draw = ImGui::GetWindowDrawList();

        ImVec2 pos = window->DC.CursorPos;
        ImVec2 size = ImGui::CalcItemSize(ImVec2(157, 40), label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

        const ImRect bb(pos, pos + size);
        ImGui::ItemSize(size, style.FramePadding.y);
        if (!ImGui::ItemAdd(bb, id))
            return false;

        bool hovered, held;
        bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, NULL);

        if (hovered || held)
            ImGui::SetMouseCursor(7);

        if (selected)
        {
            window->DrawList->AddRectFilled(ImVec2(bb.Min.x - 3, bb.Min.y - 1), ImVec2(bb.Max.x + 3, bb.Max.y + 0), ImColor(43, 43, 40, 255));
            draw->AddRectFilled(ImVec2(bb.Min.x - 0, bb.Min.y - 1), ImVec2(bb.Max.x - 147, bb.Max.y + 0), ImColor(200, 45, 35));
        }
        else
        {
            if (!hovered)
            {
                window->DrawList->AddRectFilled(ImVec2(bb.Min.x + 0, bb.Min.y + 0), ImVec2(bb.Max.x + 0, bb.Max.y + 0), ImColor(32, 31, 32, 0));
            }
            else
            {
                window->DrawList->AddRectFilled(ImVec2(bb.Min.x + 0, bb.Min.y + 0), ImVec2(bb.Max.x + 0, bb.Max.y + 0), ImColor(32, 31, 32, 255));
            }
        }

        if (selected)
        {
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(200 / 255.f, 45 / 255.f, 35 / 255.f, 255 / 255.f));
            ImGui::RenderText(ImVec2(bb.Min.x + 0 + (105 / 2 - label_size.x / 2), bb.Min.y + style.FramePadding.y + 10), label);
            ImGui::PopStyleColor();
        }
        else
        {
            if (!hovered)
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(255 / 255.f, 255 / 255.f, 255 / 255.f, 255 / 255.f));
                ImGui::RenderText(ImVec2(bb.Min.x + 0 + (105 / 2 - label_size.x / 2), bb.Min.y + style.FramePadding.y + 10), label);
                ImGui::PopStyleColor();
            }
            else
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(255 / 255.f, 255 / 255.f, 255 / 255.f, 255 / 255.f));
                ImGui::RenderText(ImVec2(bb.Min.x + 0 + (105 / 2 - label_size.x / 2), bb.Min.y + style.FramePadding.y + 10), label);
                ImGui::PopStyleColor();
            }
        }
        return pressed;

    }
}

void decorations_AimwareV5()
{
    aimware_v5_context.pos = ImGui::GetWindowPos();
    ImDrawList* draw = ImGui::GetWindowDrawList();
    draw->AddRectFilled(ImVec2(aimware_v5_context.pos.x + 0, aimware_v5_context.pos.y + 0), ImVec2(aimware_v5_context.pos.x + 800, aimware_v5_context.pos.y + 600), ImColor(8, 8, 8, 200), 12, ImDrawFlags_RoundCornersAll);
    //
    //
    draw->AddRectFilled(ImVec2(aimware_v5_context.pos.x + 0, aimware_v5_context.pos.y + 0), ImVec2(aimware_v5_context.pos.x + 800, aimware_v5_context.pos.y + 50), ImColor(187, 37, 38), 12, ImDrawFlags_RoundCornersTop);
    //
    //
    draw->AddRectFilled(ImVec2(aimware_v5_context.pos.x + 0, aimware_v5_context.pos.y + 575), ImVec2(aimware_v5_context.pos.x + 800, aimware_v5_context.pos.y + 600), ImColor(187, 37, 38), 12, ImDrawFlags_RoundCornersBottom);
    //
    //
    draw->AddRectFilled(ImVec2(aimware_v5_context.pos.x + 0, aimware_v5_context.pos.y + 50), ImVec2(aimware_v5_context.pos.x + 160, aimware_v5_context.pos.y + 575), ImColor(0, 0, 0, 150));
    //
    //
    draw->AddText(aimware_v5_context.info, 13.f, ImVec2(aimware_v5_context.pos.x + 12, aimware_v5_context.pos.y + 580), ImColor(255, 255, 255), "V5");
    draw->AddText(aimware_v5_context.info, 13.f, ImVec2(aimware_v5_context.pos.x + 35, aimware_v5_context.pos.y + 580), ImColor(255, 255, 255), "for Counter-Strike: Global Offensive");
    draw->AddText(aimware_v5_context.info, 13.f, ImVec2(aimware_v5_context.pos.x + 710, aimware_v5_context.pos.y + 580), ImColor(255, 255, 255), "website.com");
    //
    //
    draw->AddRectFilled(ImVec2(aimware_v5_context.pos.x + 0, aimware_v5_context.pos.y + 50), ImVec2(aimware_v5_context.pos.x + 800, aimware_v5_context.pos.y + 52), ImColor(220, 60, 40));
    //
    //
    ImGui::SetCursorPos(ImVec2(10, 10));
    ImGui::Image((void*)(intptr_t)aimware_v5_context.logggo, ImVec2(36, 36));
    //
    draw->AddRectFilled(ImVec2(aimware_v5_context.pos.x + 595, aimware_v5_context.pos.y + 15), ImVec2(aimware_v5_context.pos.x + 785, aimware_v5_context.pos.y + 35), ImColor(220, 220, 220), 5);
    draw->AddText(aimware_v5_context.ee, 13.f, ImVec2(aimware_v5_context.pos.x + 600, aimware_v5_context.pos.y + 18), ImColor(136, 136, 134), "search features");
    //
}

void tabss_AimwareV5()
{
    ImGui::PushFont(aimware_v5_context.tabsf);
    ImGui::SetCursorPos(ImVec2(165, 10));
    if (ImGui::tab_AimwareV5("Ragebot", 1 == aimware_v5_context.tabs))
        aimware_v5_context.tabs = 1;
    ImGui::SetCursorPos(ImVec2(270, 10));
    if (ImGui::tab_AimwareV5("Visuals", 2 == aimware_v5_context.tabs))
        aimware_v5_context.tabs = 2;
    ImGui::SetCursorPos(ImVec2(375, 10));
    if (ImGui::tab_AimwareV5("Misc", 3 == aimware_v5_context.tabs))
        aimware_v5_context.tabs = 3;
    ImGui::SetCursorPos(ImVec2(480, 10));
    if (ImGui::tab2_AimwareV5("Settings", 4 == aimware_v5_context.tabs))
        aimware_v5_context.tabs = 4;
    ImGui::SetCursorPos(ImVec2(60, 10));
    if (ImGui::tab1_AimwareV5("Legitbot", 0 == aimware_v5_context.tabs))
        aimware_v5_context.tabs = 0;

    ImGui::SetCursorPos(ImVec2(70, 17));
    ImGui::Image((void*)(intptr_t)aimware_v5_context.legit, ImVec2(22, 25));

    ImGui::SetCursorPos(ImVec2(175, 20));
    ImGui::Image((void*)(intptr_t)aimware_v5_context.skul, ImVec2(20, 22));

    ImGui::SetCursorPos(ImVec2(275, 25));
    ImGui::Image((void*)(intptr_t)aimware_v5_context.glazz, ImVec2(26, 13));

    ImGui::SetCursorPos(ImVec2(380, 17));
    ImGui::Image((void*)(intptr_t)aimware_v5_context.wrr, ImVec2(26, 26));

    ImGui::SetCursorPos(ImVec2(485, 17));
    ImGui::Image((void*)(intptr_t)aimware_v5_context.grr, ImVec2(24, 24));

    ImGui::PopFont();
}

void sub_tabs_AimwareV5()
{
    ImGui::PushFont(aimware_v5_context.tabsf);
    ImGui::SetCursorPos(ImVec2(0, 53));
    if (ImGui::sub_AimwareV5("Aimbot", 0 == aimware_v5_context.subtabs))
        aimware_v5_context.subtabs = 0;
    ImGui::SetCursorPos(ImVec2(0, 93));
    if (ImGui::sub_AimwareV5("Triggerbot", 1 == aimware_v5_context.subtabs))
        aimware_v5_context.subtabs = 1;
    ImGui::SetCursorPos(ImVec2(0, 133));
    if (ImGui::sub_AimwareV5("Weapon", 2 == aimware_v5_context.subtabs))
        aimware_v5_context.subtabs = 2;
    ImGui::SetCursorPos(ImVec2(0, 173));
    if (ImGui::sub_AimwareV5("Other", 3 == aimware_v5_context.subtabs))
        aimware_v5_context.subtabs = 3;
    ImGui::SetCursorPos(ImVec2(0, 213));
    if (ImGui::sub_AimwareV5("Semirage", 4 == aimware_v5_context.subtabs))
        aimware_v5_context.subtabs = 4;

    ImGui::PopFont();
}

void IGCMC::Interfaces::Cheats::AimwareV5::Setup(bool* pbIsInitialized)
{
	if (!*pbIsInitialized)
	{
        ImFontConfig font_config;
        font_config.OversampleH = 1; //or 2 is the same
        font_config.OversampleV = 1;
        font_config.PixelSnapH = 1;

        static const ImWchar ranges[] =
        {
            0x0020, 0x00FF, // Basic Latin + Latin Supplement
            0x0400, 0x044F, // Cyrillic
            0,
        };

        ImGuiIO& io = ImGui::GetIO(); (void)io;
        aimware_v5_context.tabsf = io.Fonts->AddFontFromFileTTF(BASE_FONT_DIR "arialbd.ttf", 12.0f);
        aimware_v5_context.info = io.Fonts->AddFontFromFileTTF(BASE_FONT_DIR "arial.ttf", 13.0f);
        aimware_v5_context.ee = io.Fonts->AddFontFromFileTTF(BASE_FONT_DIR "arial.ttf", 13.0f, &font_config, ranges);
        aimware_v5_context.two = io.Fonts->AddFontFromFileTTF(BASE_FONT_DIR "arialbd.ttf", 13.0f);
        aimware_v5_context.three = io.Fonts->AddFontFromFileTTF(BASE_FONT_DIR "arialbd.ttf", 15.0f);

        int width = 36, height = 36;
        IGCMC::Utils::LoadTextureFromMemory(logo, sizeof(logo), &aimware_v5_context.logggo, &width, &height);
        width = 22, height = 25;
        IGCMC::Utils::LoadTextureFromMemory(lb, sizeof(lb), &aimware_v5_context.legit, &width, &height);
        width = 20, height = 22;
        IGCMC::Utils::LoadTextureFromMemory(skulll, sizeof(skulll), &aimware_v5_context.skul, &width, &height);
        width = 26, height = 13;
        IGCMC::Utils::LoadTextureFromMemory(glaz, sizeof(glaz), &aimware_v5_context.glazz, &width, &height);
        width = 26, height = 26;
        IGCMC::Utils::LoadTextureFromMemory(wrrr, sizeof(wrrr), &aimware_v5_context.wrr, &width, &height);
        width = 24, height = 24;
        IGCMC::Utils::LoadTextureFromMemory(grrr, sizeof(grrr), &aimware_v5_context.grr, &width, &height);

        *pbIsInitialized = aimware_v5_context.tabsf && aimware_v5_context.info && aimware_v5_context.ee && aimware_v5_context.two && aimware_v5_context.three &&
            aimware_v5_context.logggo && aimware_v5_context.legit && aimware_v5_context.skul && aimware_v5_context.glazz && aimware_v5_context.wrr && aimware_v5_context.grr;
	}
}

void IGCMC::Interfaces::Cheats::AimwareV5::Destroy(bool* pbIsInitialized)
{
	if (*pbIsInitialized)
	{
	}
}

void IGCMC::Interfaces::Cheats::AimwareV5::Render(bool* pbMustOpenThisMenu)
{
	if (*pbMustOpenThisMenu)
	{
        ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 1.f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 1.f);
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(4, 3));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8, 8));
        ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, ImVec2(4, 4));
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8, 4));
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
        ImGui::PushStyleColor(ImGuiCol_Button, ImColor(160, 30, 30, 255).Value);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor(190, 45, 35, 255).Value);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor(220, 60, 40, 255).Value);

        if (ImGui::Begin("##AIMWARE v5", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar))
        {
            aimware_v5_context.pos = ImGui::GetWindowPos();
            ImDrawList* draw = ImGui::GetWindowDrawList();

            ImGui::SetWindowSize(ImVec2(800, 600));

            decorations_AimwareV5();
            tabss_AimwareV5();
            sub_tabs_AimwareV5();

            static bool a;
            if (aimware_v5_context.tabs == 0)
            {
                if (aimware_v5_context.subtabs == 0)
                {
                    draw->AddRectFilled(ImVec2(aimware_v5_context.pos.x + 175, aimware_v5_context.pos.y + 65), ImVec2(aimware_v5_context.pos.x + 470, aimware_v5_context.pos.y + 380), ImColor(0, 0, 0, 150), 10);
                    ImGui::SetCursorPos(ImVec2(180, 70));
                    ImGui::BeginGroup();
                    {
                        ImGui::Checkbox_AimwareV5("TEST", &a);
                    }
                    ImGui::EndGroup();
                }
            }
        }
        ImGui::End();

        ImGui::PopStyleColor(12);
        ImGui::PopStyleVar(9);
	}
}