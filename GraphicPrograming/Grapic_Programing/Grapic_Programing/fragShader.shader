#version 330 core
out vec4 FragColor;


in vec3 color;
in vec2 uv;


uniform sampler2D diffuseSampler;

void main() {

	vec4 diffuseSampler = texture(diffuseSampler, uv);
	FragColor = diffuseSampler;;

}