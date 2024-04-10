#version 330 core
in vec2 TexCoords;
out vec4 color;

uniform sampler2D image;
uniform vec3 spriteColor;
uniform bool enableTexture;

void main()
{
    if(enableTexture == true){
        color = vec4(spriteColor, 1.0) * texture(image, TexCoords);
    }
    else{
        color = vec4(spriteColor, 1.0);
    }
    
}