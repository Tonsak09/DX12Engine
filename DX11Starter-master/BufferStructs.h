#pragma once
#include <DirectXMath.h>

struct VertexShaderExternalData
{
	DirectX::XMFLOAT4X4 world, worldInvTranspose, view, projection;
};