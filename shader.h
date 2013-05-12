#ifndef SHADER_H
#define SHADER_H
#include "filereader.h"
#include <string>
#include <iostream>
#include <glload/gll.h>
#include <glload/gl_3_3.h>
#include <memory>
#include <stdexcept>

class ShaderCompileException : public std::runtime_error {
    public:
        ShaderCompileException( std::string s ) : std::runtime_error( s ) { }
};


class Handle {
        GLuint handle_;
    protected:
        void SetHandle( GLuint i ) {
            handle_ = i;
        }

    public:
        GLuint GetHandle() const {
            return handle_;
        }
};

class BaseShader : public Handle {

    public:
         void CreateShader( std::string source );
        ~BaseShader() {
            glDeleteShader( GetHandle() );
        }
        virtual GLenum GetShadertype() = 0;

};
class VertexShader : public BaseShader {
    public:

        GLenum GetShadertype() {
            return GL_VERTEX_SHADER;
        }
};
class FragmentShader : public BaseShader {
    public:


        GLenum GetShadertype() {
            return GL_FRAGMENT_SHADER;
        }
};
class ComputeShader : public BaseShader {
    public:

        GLenum GetShadertype() {
            return GL_COMPUTE_SHADER;
        }
};
class TesselationControlShader : public BaseShader {
    public:

        GLenum GetShadertype() {
            return GL_TESS_CONTROL_SHADER;
        }
};

class TesselationEvaluationShader : public BaseShader {
    public:

        GLenum GetShadertype() {
            return GL_TESS_EVALUATION_SHADER;
        }
};


class ShaderProgram : public Handle {
    public:
        ShaderProgram();
        void AttachShader( const BaseShader &s );
        void Link();
        void Use();
};


class VertexBuffer : public Handle {
    public:

        VertexBuffer();
        ~VertexBuffer() {}
        void bind( GLenum );
        void setBufferType( GLenum );
        void setBufferData( GLenum target, GLsizeiptr size, const GLvoid*data, GLenum usage );

};

#endif // SHADER_H
