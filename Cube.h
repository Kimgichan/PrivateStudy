#pragma once

class Cube
{
public:
	Cube();
	~Cube();

	//------------------------------
	const float* GetVertexBuffer();
	const float* GetColorBuffer();
	int Size();

private:
	float *g_vertex_buffer_data;
	float *g_color_buffer_data;
};

