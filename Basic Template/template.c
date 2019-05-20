
/**
 * 
 * You can find more about GLUT and OPENGL here :
 * https://www.opengl.org/resources/libraries/glut/
 * 
*/  

#include <GL/gl.h> // Here for the advance project with Open GL .. 
#include <gl/glut.h>
#include <windows.h> // Here is for more compatible with windows .. 

// ___ ALL GLOBAL DATA ___ // 

// Const Values .. 
#define __WIDTH__ 600
#define __HEIGHT__ 600
#define __TITLE_OF_WINDOW__ "3imed jaberi <imed_jebari@hotmail.fr> | https://github.com/3imed-jaberi "
#define __RED__ 0
#define __GREEN__ 0
#define __BLUE__ 0
#define __ALPHA__ 0
#define __CLEAR_THE_BUFFER__ GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT
#define __VIEW_MODE_DISPALY__ GL_MODELVIEW
#define __VIEW_MODE_RESHAPE__ GL_PROJECTION

// Var Values .. 
float tx = 0.0F ;
float ty = 0.0F ;
float rx = 20.0;


void dispaly (){

  /**
   * clear the window ..
   * @param __CLEAR_THE_BUFFER__ : clear the buffer ( re-init ) 
   */
  glClear(__CLEAR_THE_BUFFER__);
  /**
   * put the camera in your position you want .. 
   */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1.0,1.0,2.0,0.0,0.0,0.0,0.0,1.0,0.0);

      /*
          ===================================================================
                    Your Custom Code ==> Sphere , Polygon ..etc <==           
          ===================================================================
     */
      
      // BASIC EXAMPLE : 
      // Here is a Basic Example of Sphere Object .. 
      // push & pop matrix => for fix the object movement when you have more than one .. 
          glPushMatrix();         
            glTranslatef(tx,ty,0.0F); // navigate movement
            glRotatef(rx,0,1,0); // rotation movement
            glColor3f(1,0,0); // object color 
            glutWireSphere(0.5,10,10); // object func
          glPopMatrix();
  
  /**
   * refrech the memoire ( better performance ) .. 
   * */   
  glFlush(); 

}

void reshape () {
    // define the projection transformation
    glMatrixMode(__VIEW_MODE_RESHAPE__);
    glLoadIdentity();
    gluPerspective(60,1,1,100);
}

void special(int key , int x , int y ) {
  switch(key) {
    case GLUT_KEY_UP    : { ty=ty+0.1; break; }
    case GLUT_KEY_DOWN  : { ty=ty-0.1; break; }  
    case GLUT_KEY_LEFT  : { tx=tx-0.1; break; }
    case GLUT_KEY_RIGHT : { tx=tx+0.1; break; } 
  }                     
  glutPostRedisplay();
}
                          
void key(unsigned char key , int x , int y ) {
  switch(key) {
    case 'a' : { rx=rx+20; break ; } 
    case 'z' : { rx=rx-20; break ; }   
  }
  glutPostRedisplay();
}

void main(){
  
  /**
   * Init the size of the windows of the program .. 
   * @param __WIDTH__ : width of the windows in pixel
   * @param __HEIGHT__ : height of the windows in pixel
   */
  glutInitWindowSize(__WIDTH__,__HEIGHT__);
  /**
   * You can init the type of color , depth and much other with this function from glut .. 
   * ==> glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
   */

  /**
   * create the windows of the program .. 
   * @param __TITLE_OF_WINDOW__ : title of the window 
   */
  glutCreateWindow(__TITLE_OF_WINDOW__);

  /**
   * set the background color ..
   * @param __RED__ : red color of the rgb | the value is between 0 and 1 
   * @param __GREEN__ : green color of the rgb | the value is between 0 and 1 
   * @param __BLUE__ : blue color of the rgb | the value is between 0 and 1
   * @param __ALPHA__ : opacity  of the result color 
   */ 
  glClearColor(__RED__,__GREEN__,__BLUE__,__ALPHA__); // background color : rgba ( alpha : opacity ) 
  /**
   * execute the display function ( what you want to see ! ) .. 
   * @param dispaly : function of the show  
   */ 
  glutDisplayFunc(dispaly);

  /**
   * setting for the display mode .. 
   * @param reshape : function of all setting 
   */ 
  glutReshapeFunc(reshape);

  /**
   * you can execute any special action .. 
   * @param special : the special function 
   */
  glutSpecialFunc(special);

  /**
   * you can execute any key action .. 
   * @param key : function of the keys actions 
   */
  glutKeyboardFunc(key);

  /**
   * For display callback over and over ( wait for events ) ..
   */
  glutMainLoop(); 

}
