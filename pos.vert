#version 330

in vec3 Position;
out vec4 color;
void main(void){

    gl_Position = vec4( Position.x, Position.y, Position.z, 1.0);
    color = gl_Position;
}
