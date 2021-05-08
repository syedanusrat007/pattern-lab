#version 330
layout( location = 0 ) in vec3 vert_modelSpace;

uniform mat4 MVP;
uniform vec3 inputColor;

out vec3 interpolateColor;

void main()
{
	gl_Position = MVP * vec4( vert_modelSpace, 1.0 );
	interpolateColor = (vert_modelSpace +vec3(1.0f+1.0f+1.0f))/3.0;
}
