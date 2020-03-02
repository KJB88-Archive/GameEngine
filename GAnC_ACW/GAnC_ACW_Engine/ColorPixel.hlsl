struct PixelInputType
{
	float4 position: SV_POSITION;
	float4 color : COLOR;
};

// Simple colour passthrough
float4 PShader(PixelInputType input) : SV_TARGET
{
	return input.color;
}