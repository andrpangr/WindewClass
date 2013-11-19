#include "WindowClass.h"

int main()
{
    OpenGLWindow Window( 600 , 800 );

    bool done = false ;

    float theta = 0 ;

    while(!done){

        if (PeekMessage(&Window.msg, NULL, 0, 0, PM_REMOVE))
        {
            if (Window.msg.message == WM_QUIT)
            {
                done = true ;
            }
            else
            {
                TranslateMessage(&Window.msg);
                DispatchMessage(&Window.msg);

                Window.ReSizeGLScene();
            }
        }else{

            glClear( GL_COLOR_BUFFER_BIT );
            glClearColor( 0 , 0 ,0, 0 );

            glBegin( GL_LINES );

                glVertex2f( -1,-theta );
                glVertex2f( 1 , theta+= 0.001f );

            glEnd();

            SwapBuffers( Window.hDC );

        }
    }

    return 0;
}

