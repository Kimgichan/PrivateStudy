#include "Cube.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
const int BUFFER_COUNT = 36;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

Cube::Cube()
{
	g_vertex_buffer_data = new float[BUFFER_COUNT*3];
	g_color_buffer_data = new float[BUFFER_COUNT*3];

	ifstream in("Cube.txt");
	string line;

	for (int i = 0; i < BUFFER_COUNT; i++) {
		getline(in, line);
		vector<string> token = split(line, ',');
		for (int num = 0; num < 3; num++) 
			g_vertex_buffer_data[3 * i + num] = stof(token[num]);
	}
	for (int i = 0; i < BUFFER_COUNT; i++) {
		getline(in, line);
		vector<string> token = split(line, ',');
		for (int num = 0; num < 3; num++)
			g_color_buffer_data[3 * i + num] = stof(token[num]);
	}
}


Cube::~Cube()
{
	delete[] g_vertex_buffer_data;
	delete[] g_color_buffer_data;
}

const float * Cube::GetVertexBuffer()
{
	return g_vertex_buffer_data;
}

const float * Cube::GetColorBuffer()
{
	return g_color_buffer_data;
}

int Cube::Size()
{
	return BUFFER_COUNT;
}
