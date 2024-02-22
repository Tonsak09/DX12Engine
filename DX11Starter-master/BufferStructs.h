#pragma once
#include <DirectXMath.h>
#include "Lights.h"

struct VertexShaderExternalData
{
	DirectX::XMFLOAT4X4 world, worldInvTranspose, view, projection;
};

struct PixelShaderExternalData
{
	DirectX::XMFLOAT2 uvScale, uvOffset;
	DirectX::XMFLOAT3 cameraPosition;
	int lightCount;
	Light lights[MAX_LIGHTS];
};