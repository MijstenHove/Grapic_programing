#version 330 core
out vec4 FragColor;


in vec3 color;
in vec2 uv;
in vec3 normal;
in vec4 worldPixel;


uniform sampler2D diffuseSampler;

void main() {
	//vec3 lightDirection = reflect(lightDir, normal);
	
	vec3 lightDir = normalize(vec3(0, -1, -1));
	vec3 camPos = vec3(0, 3, -3);
	vec3 viewDir = normalize(worldPixel.xyz - camPos);
	
	
	
	vec3 lightReflect = normalize(reflect(-lightDir, normal));
	float specular = pow(max(dot(lightReflect, viewDir), 0.0), 180);

	vec4 diffuseColor = texture(diffuseSampler, uv);

	
	float light = max(dot(-lightDir, normal),0.25);
	
	FragColor = diffuseColor * light + specular;

}