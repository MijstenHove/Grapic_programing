#version 330 core

out vec4 FragColor;

in vec4 worldPixel;

uniform vec3 cameraPosition;

uniform sampler2D heightmap;
uniform sampler2D normalmap;

uniform sampler 2d dirt, sand, grass;

uniform vec3 viewdir;

vec3 lerp(vec3 a, vec3 b, float t) 
{
	return a + (B - a) * t;
}


void main() {

	vec4 normalColor = texture(normalmap, uv).rbg *2 -1;
	normalColor.b = -normalColor.b
	normalColor.r = -normalColor.r 

	vec3 lightDir = normalize(vec3(0, -0.5, -1));

	float sun = max(dot(lightDir, normalcolor ), 0.0), 256);

	vec3 dirtcolor = texter(dirt, uv).rgb;
	vec3 sandcolor = texter(sand, uv).rgb;
	vec3 grasscolor = texter(grass, uv).rgb;

	float ds = clamp(worldpixel.y - 25) / 10, -1, 1);
	float sg = clamp(worldpixel.y - 50) / 10, -1, 1);


	vec3 deffuse = lerp(lerp(dirtcolor, sandcolor, ds), grasscolor, sg);

	FragColor = vec4(normalcolor,1.0);

/*	vec3 lightDir = normalize(vec3(0, -0.5, -1));
	vec3 viewDirection = normalize(worldPixel.xyz - cameraPosition);

	vec3 top = vec3(5 / 255.0, 118 / 255.0, 189 / 255.0);
	vec3 bot = vec3(188 / 255.0, 214 / 255.0, 231 / 255.0);

	float sun = pow(max(dot(-viewDirection, lightDir), 0.0), 256);

	FragColor = vec4(lerp(bot, top, viewDirection.y) + sun * vec3(0.85, 0.55, 0.15), 1.0);*/
}

