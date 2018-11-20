#version 130

// Vertex structure
// Set order of vertex structure (position, color)
// Search in C++ code funciton GL20Mesh::Render()
// glVertexAttribPointer(0, ...) // this is "position"
// glVertexAttribPointer(1, ...) // this is "color"
attribute vec3 position;
attribute vec4 color;

// Shader parameters
// Search in C++ code functions like "glUniform4"
// i.e. functions: glUniform4fv(), glUniformMatrix4fv().
// These functions pass to shader parameters listed below
uniform vec4 constColor;
uniform mat4 matrixWorldViewProjT;
uniform vec4 time;

void main()
{
//    float speedCoeff = 1.5;
//	float curTime = time[0];
//	float sinTime = sin(curTime*speedCoeff);
//	float cosTime = cos(curTime*speedCoeff);


//    vec3 newPosition = position;
//	float angle = (position.y + 1.0) * (sinTime * 3.14159 / 2.0);
//	float cosa = cos(angle);
//	float sina = sin(angle);
//	newPosition.x = newPosition.x * cosa - newPosition.z * sina;
//	newPosition.z = newPosition.z * cosa + newPosition.x * sina;

//	vec3 scale = newPosition;
//	scale.x *= (abs(position.y) + 0.5) / 1.5;
//	scale.z *= (abs(position.y) + 0.5) / 1.5;

//	gl_Position = vec4(mix(newPosition, scale, abs(sinTime)), 1.0) * matrixWorldViewProjT;

	//gl_Position = vec4(newPosition, 1.0) * matrixWorldViewProjT;

//	gl_FrontColor = color * constColor;

}