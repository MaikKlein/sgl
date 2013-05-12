
#include "shader.h"

#include <glm/glm.hpp>

#include <GL/glfw.h>
#include <iostream>
#include "filereader.h"

#include <glload/gl_core.h>
#include <glload/gll.h>

int main( void ) {
    /* Initialize the library */
    if ( !glfwInit() )
        return -1;
    /* Create a windowed mode window and its OpenGL context */
    if ( !glfwOpenWindow( 640, 480, 8, 8, 8, 0, 24, 0, GLFW_WINDOW ) )
        return -1;


    if(LoadFunctions() == LS_LOAD_FAILED){

    }
    glm::vec3 Vertices[5];
    Vertices[0] = glm::vec3( -1.0f, -1.0f, -1.0f );
    Vertices[1] = glm::vec3( 1.0f, -1.0f, -1.0f );
    Vertices[2] = glm::vec3( 1.0f, -1.0f, 1.0f );
    Vertices[3] = glm::vec3( -1.0f, -1.0f, 1.0f );
    Vertices[4] = glm::vec3( 0.0f, 1.0f, 0.0f );
    VertexBuffer vbo;
    vbo.bind( GL_ARRAY_BUFFER );
    vbo.setBufferData( GL_ARRAY_BUFFER,sizeof( Vertices ),Vertices,GL_STATIC_DRAW );

    unsigned int indices[] = {
    0,1,4
    };
    VertexBuffer ibo;
    ibo.bind( GL_ELEMENT_ARRAY_BUFFER );
    ibo.setBufferData( GL_ELEMENT_ARRAY_BUFFER,sizeof( indices ),indices,GL_STATIC_DRAW );
    VertexShader v;
    FileReader r("/home/maik/sgl/pos.vert");
    FileReader r1("/home/maik/sgl/color.frag");

    v.CreateShader( r.get() );
    FragmentShader f;;
    f.CreateShader( r1.get() );
    ShaderProgram p;
    p.AttachShader( v );
    p.AttachShader( f );
    p.Link();
    p.Use();
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    /* Loop until the user closes the window */
    while ( glfwGetWindowParam( GLFW_OPENED ) ) {
        glClear( GL_COLOR_BUFFER_BIT );
        glEnableVertexAttribArray( 0 );
        vbo.bind( GL_ARRAY_BUFFER );
        glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0 );
        ibo.bind( GL_ELEMENT_ARRAY_BUFFER );
        glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,0);
        glDisableVertexAttribArray( 0 );
        glfwSwapBuffers();
    }
    return 0;
}

