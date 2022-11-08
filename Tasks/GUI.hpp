#pragma once

#define IMGUI_DEFINE_MATH_OPERATORS

#include "ImGui/imgui_internal.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx9.h"
#include "imgui/imgui_impl_win32.h"

#include <d3d9.h>
#include <d3dx9.h>
#include <tchar.h>

#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

#include "ByteData.hpp"
#include "Manager.hpp"

// Data
static LPDIRECT3D9              g_pD3D = NULL;
static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp = {};

extern ImFont* BiggerFont;
extern ImFont* MenuFont;

void RenderGUI();

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void ResetDevice();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);