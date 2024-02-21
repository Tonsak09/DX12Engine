#include "ShaderInclude.hlsli"

Texture2D Albedo : register(t0);
Texture2D NormalMap : register(t1);
Texture2D RoughnessMap : register(t2);
Texture2D MetalnessMap : register(t3);

float4 main(VertexToPixel input) : SV_TARGET
{
    return float4(1, 1, 1, 1);
}