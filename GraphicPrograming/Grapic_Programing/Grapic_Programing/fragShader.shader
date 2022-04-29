#version 330 core
out vec4 FragColor;
in vec4 color;
in vec2 TexCoord;

void main() {
FragColor = vec4(color.rgb,1.0f);
FragColor = texture(vec4(color.rgb,1.0f), TexCoord);
}