#include "Material.h" 
#include "DX12Helper.h"

Material::Material(Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState, XMFLOAT3 colorTint, XMFLOAT2 uvScale, XMFLOAT2 uvOffset) :
	pipelineState(pipelineState), colorTint(colorTint), uvScale(uvScale), uvOffset(uvOffset)
{
	finalized = false;

	//textureSRVsBySlot[4];
}

void Material::AddTexture(D3D12_CPU_DESCRIPTOR_HANDLE srv, int slot)
{
	if (slot < 0 || slot >= 4)
		return;

	textureSRVsBySlot[slot] = srv;
}

void Material::FinalizeMaterial()
{
	if (!finalized)
		return;

	DX12Helper& dx12Helper = DX12Helper::GetInstance();
	finalGPUHandleForSRVs = dx12Helper.HeapSRVsToDescHeap(4, textureSRVsBySlot[0]);
}

XMFLOAT3 Material::GetColorTint()
{
	return colorTint;
}

XMFLOAT2 Material::GetuvScale()
{
	return uvScale;
}

XMFLOAT2 Material::GetuvOffset()
{
	return uvOffset;
}

bool Material::GetFinalized()
{
	return finalized;
}
