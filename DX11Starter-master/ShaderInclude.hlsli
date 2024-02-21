struct VertexToPixel
{
	// Data type
	//  |
	//  |   Name          Semantic
	//  |    |                |
	//  v    v                v
    float4 screenPosition	: SV_POSITION;
    float3 worldPosition    : POSITION;
    float3 normal			: NORMAL;
    float3 tangent			: TANGENT;
    float2 uv				: TEXCOORD;
};