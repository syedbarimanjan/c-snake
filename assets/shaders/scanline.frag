#version 330 core

uniform sampler2D texture0;
uniform float time;

in vec2 fragTexCoord;

out vec4 FragColor;

void main() {
  float distortion = sin(fragTexCoord.y * 2304978 * fract(time)) * 0.0007;
  vec2 distortedCoord = vec2(fragTexCoord.x + distortion, fragTexCoord.y);
  float scanline = cos((fract((fragTexCoord.y + time * 0.005) * 150 + 0.5) -0.5) * 3.14); 
  vec4 color = texture(texture0,distortedCoord);

  float flicker = 0.95 + 0.05 * sin(time * 10);
  FragColor = vec4(mix(color.rgb, vec3(scanline), 0.1) * flicker, 1.0);
}