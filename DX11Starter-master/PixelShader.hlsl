#include "ShaderInclude.hlsli"

Texture2D Albedo : register(t0);
Texture2D NormalMap : register(t1);
Texture2D RoughnessMap : register(t2);
Texture2D MetalnessMap : register(t3);

SamplerState texSampler : register(s0);

// MUST match with lights.h 
#define MAX_LIGHTS 5

// Alignment matters!!!
cbuffer ExternalData : register(b0)
{
    float2 uvScale;
    float2 uvOffset;
    float3 cameraPosition;
    int lightCount;
    Light lights[MAX_LIGHTS];
}


float2 GetUV(VertexToPixel input)
{
    return input.uv;
}

float4 main(VertexToPixel input) : SV_TARGET
{
    //return (float4(input.uv, 0.0f, 1.0f));
    return NormalMap.Sample(texSampler, GetUV(input));
}