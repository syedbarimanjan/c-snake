#version 330 core

uniform sampler2D texture0;
uniform float time;

in vec2 fragTexCoord;

out vec4 FragColor;

void main() {
  float scanline = cos((fract((fragTexCoord.y + time * 0.005) * 150 + 0.5) -0.5) * 3.14); 
  vec4 color = texture(texture0,fragTexCoord);
  FragColor = vec4(mix(color.rgb, vec3(scanline), 0.1), 1.0);
}