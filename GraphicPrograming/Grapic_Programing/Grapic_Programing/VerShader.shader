#version 330 core\n

layout(location =0) in vec3 vPos;
layout(location=1) in vec4 vColor;
layout(location=2) in vec4 uv;
out vec4 color;
out vec2 TexCoord;
	
void main(){
 gl_Position = vec4(vPos, 1.0f);
 color = vColor; 
 }