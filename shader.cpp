#include "shader.h"

/*#############################
  BaseShader
##############################*/

void BaseShader::CreateShader(std::string source) {

    SetHandle( glCreateShader( GetShadertype() ) );


    GLint length[1];
    length[0] = source.size();
    const GLchar* p[1];
    p[0] = source.c_str();
    glShaderSource( GetHandle(),1,p,length );
    glCompileShader( GetHandle() );
    GLint success;
    glGetShaderiv( GetHandle(), GL_COMPILE_STATUS, &success );
    if ( !success ) {
        GLchar ErrorLog[1024] = { 0 };
        glGetShaderInfoLog(GetHandle(), sizeof(ErrorLog), NULL, ErrorLog);
        std::string errorlog_string(ErrorLog);
        throw ShaderCompileException(errorlog_string);
    }

}


/*#############################
  ShaderProgram
##############################*/

void ShaderProgram::AttachShader( const BaseShader &s ) {
    glAttachShader( ShaderProgram::GetHandle(), s.GetHandle() );
}
void ShaderProgram::Use() {
    glUseProgram( GetHandle() );
}
void ShaderProgram::Link() {
    glLinkProgram( GetHandle() );
}
ShaderProgram::ShaderProgram() {
    Handle();
    SetHandle( glCreateProgram() );
}

/*#############################
  VertexBuffer
##############################*/
void VertexBuffer::bind( GLenum buffertype ) {
    glBindBuffer( buffertype, GetHandle() );
}
VertexBuffer::VertexBuffer() {
    GLuint handle;
    glGenBuffers( 1,&handle );
    SetHandle( handle );
}
void VertexBuffer::setBufferData(GLenum target, GLsizeiptr s,const GLvoid * data, GLenum usage ) {
    glBufferData( target, s, data, usage );
}



