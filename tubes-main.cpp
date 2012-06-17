/*
Kelompok 9
Kelas IF-9
Nama:
     1. 10107286 - Restiana Ayunita 
     2. 10108431 - Luthfiana Adityarini
     3. 10108439 - R. Adzie Ramadani Kusumah
     4. 10108445 - Alfiyah 
*/

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <windows.h>
#include <ctype.h> 
enum {
   DARATAN, LAUT, VILLA, ZAMRUD, SLATE, KAWAH_GUNUNG, POHON, KOLAM, BERJEMUR, KEBUN, LINGKARAN, LINGKARAN_NYALA, ALAS,KURSI,KAKI_KURSI,JENDELA,BORDER,TIANG,BATANG,PAYUNG,MEJA
   
} MaterialType;

GLint stencilBits;
static float viewx = 10;
static float viewy = 10;
static float viewz = 10;
static float zoomx  = 0;
static float zoomy  = 0;
static float zoomz  = 0;
static float zoomin = 0;
int putar = 1;
static int lampu = 10;
GLUquadricObj * qobj;

GLfloat spin = 0.0;
GLfloat cahaya[] ={1.0, 1.0, 1.0, 1.0};  

const GLfloat light_ambient[]  = { 2.7f, 2.7f, 2.7f, 1.0f };
const GLfloat light_diffuse[]  = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 0.0f, 1.0f };
const GLfloat light_position[] = { 1.0f, 1.0f, 1.0f, 1.0f };

const GLfloat light_ambient2[]  = { 0.3f, 0.3f, 0.3f, 0.0f };
const GLfloat light_diffuse2[]  = { 0.3f, 0.3f, 0.3f, 0.0f };

const GLfloat mat_ambient[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 0.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

GLfloat 
cahaya_kanan[] ={-1.0, 0.0, 1.0, 1.0}, 
cahaya_kiri[] ={1.0, 0.0, 1.0, 0.0};

GLUquadricObj *quadObj;
static float lmodel_twoside[] =
{GL_TRUE};
static float lmodel_oneside[] =
{GL_FALSE};

int a=2,b=3;

GLfloat
lingkaran[] = {0.0, 0.0, 0.0},
lingkaran_plastic_diffuse[] = {0.7, 0.7, 0.7},
lingkaran_plastic_specular[] = {0.7, 0.6, 0.6},
lingkaran_plastic_shininess = 30.0;

GLfloat
lingkaran_nyala[] = {1.0, 1.0, 1.0},
lingkaran_nyala_plastic_diffuse[] = {1.0, 1.0, 0.0},
lingkaran_nyala_plastic_specular[] = {0.7, 0.6, 0.6},
lingkaran_nyala_plastic_shininess = 32.0;

GLfloat
laut[] = {0.0, 0.0, 0.0},
laut_diffuse[] = {0.1, 0.2, 6.5},
laut_specular[] = {0.7, 0.6, 0.6}, 
laut_shininess = 32.0;

GLfloat
daratan_ambient[] = {0.33, 0.22, 0.03, 1.0},
daratan_diffuse[] = {0.0, 0.4, 0.2},
daratan_specular[] = {0.99, 0.91, 0.81, 1.0},
daratan_shininess = 27.8;

GLfloat
pohon[] = {0.33, 0.22, 0.03, 1.0},
pohon_diffuse[] = {0.1, 0.8, 0.1},
pohon_specular[] = {0.99, 0.91, 0.89, 1.0},
pohon_shininess = 27.8;

GLfloat
kawah_gunung[] = {0.33, 0.22, 0.03, 1.0},
kawah_gunung_diffuse[] = {0.0, 0.4, 0.2},
kawah_gunung_specular[] = {0.99, 0.91, 0.81, 1.0},
kawah_gunung_shininess = 27.8;

GLfloat
villa[] = {0.0, 0.0, 0.0},
villa_plastic_diffuse[] = {0.7, 0.7, 0.3},
villa_plastic_specular[] = {0.7, 0.6, 0.6},
villa_plastic_shininess = 32.0;

GLfloat
tiang[] = {1.0, 1.0, 1.0},
tiang_plastic_diffuse[] = {0.0, 0.0, 0.0},
tiang_plastic_specular[] = {0.0, 0.0, 0.0},
tiang_plastic_shininess = 32.0;

GLfloat
jendela[] = {0.0, 0.0, 0.0},
jendela_plastic_diffuse[] = {0.0, 0.0, 0.0},
jendela_plastic_specular[] = {0.7, 0.6, 0.6},
jendela_plastic_shininess = 32.0;

GLfloat
border[] = {0.0, 0.0, 0.0},
border_plastic_diffuse[] = {1.0, 0.0, 0.0},
border_plastic_specular[] = {0.7, 0.6, 0.6},
border_plastic_shininess = 32.0;

GLfloat
kolam[] = {0.0, 0.0, 0.0},
kolam_diffuse[] = {0.2, 1.0, 2.8},
kolam_specular[] = {0.7, 0.6, 0.6},
kolam_shininess = 32.0;

GLfloat
kebun[] = {0.0, 0.0, 0.0},
kebun_diffuse[] = {0.3, 0.3, 0.3},
kebun_specular[] = {0.7, 0.6, 0.6},
kebun_shininess = 32.0;

GLfloat
berjemur[] = {0.0, 0.0, 0.0},
berjemur_diffuse[] = {0.3, 0.3, 0.3},
berjemur_specular[] = {0.7, 0.6, 0.6},
berjemur_shininess = 32.0;

GLfloat
kursi[] = {0.0, 0.0, 0.0},
kursi_diffuse[] = {0.65, 0.6, 1.35},
kursi_specular[] = {0.65, 0.6, 0.35},
kursi_shininess = 32.0;

GLfloat
kaki_kursi[] = {0.0, 0.0, 0.0},
kaki_kursi_diffuse[] = {0.0, 0.0, 5.0},
kaki_kursi_specular[] = {0.7, 0.6, 0.6},
kaki_kursi_shininess = 32.0;

GLfloat
alas[] = {0.0, 0.0, 0.0},
alas_diffuse[] = {0.5, 0.5, 0.5},
alas_specular[] = {0.7, 0.6, 0.6},
alas_shininess = 32.0;


GLfloat
batang[] = {0.0, 0.0, 0.0},
batang_diffuse[] = {0.5, 0.5, 0.5},
batang_specular[] = {6.5, 0.6, 3.5},
batang_shininess = 32.0;

GLfloat
payung[] = {0.0, 0.0, 0.0},
payung_diffuse[] = {0.50, 0.0, 0.0},
payung_specular[] = {1.0, 0.0, 0.0},
payung_shininess = 32.0;

GLfloat
meja[] = {0.0, 0.0, 0.0},
meja_diffuse[] = {0.1, 0.2, 6.5},
meja_specular[] = {0.0, 0.0, 1.0},
meja_shininess = 32.0;

int shade_model = GL_SMOOTH;
char *daratan_material,*laut_material,*torus_material,*torus2_material,*pohon_material,*kawah_gunung_material,*villa_material,*kolam_material,*berjemur_material,*kebun_material,*alas_material,*kursi_material,*kaki_kursi_material,*jendela_material,*border_material,*tiang_material,*batang_material,*payung_material,*meja_material; 


void muter(void)
{
spin = spin + 0.1;
if (spin > 360.0)
spin = spin - 360.0;
glutPostRedisplay();
}

void 
display(void)
{
             
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  if (putar == 0){
          
        glPushMatrix();
        glRotatef(viewx, 1.0, 0.0, 0.0);    
        glRotatef(viewy+spin, 0.0, 1.0, 0.0);
        glRotatef(viewz, 0.0, 0.0, 1.0);
        glTranslatef(zoomx, zoomy, zoomz);
        
  } else {
         glPushMatrix();
         glRotatef(viewx, 1.0, 0.0, 0.0);    
         glRotatef(viewy, 0.0, 1.0, 0.0);
         glRotatef(viewz, 0.0, 0.0, 1.0);
         glTranslatef(zoomx, zoomy, zoomz);      
  }
     

  
  float skala=zoomin+0.06;

  glPushMatrix();
  glScalef(skala,skala,skala);
  glPushMatrix();
  glTranslatef(0.0, -0.15, 0.0);
  glCallList(5);
  glRotatef(90, 1.0, 0.0, 0.0);
  glRotatef(-90, 0.0, 0.0, 1.0);
  glScalef(0.8,0.47,0.001);                                     //laut
  glutSolidCube(40);
  glPopMatrix();
  glPopMatrix();

  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(0.0, 0.2, 8.1);
  glCallList(2);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(37.3,1.0,32);                                    // daratan
  glutSolidCube(0.5);
  glPopMatrix();
  glPopMatrix();

 
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(0.0, 4.22, 12.5);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(1,1.3,0.8);                                    // villa utama
  glutSolidCube(6.0);
  glPopMatrix();
  glPopMatrix();
  

  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(0.0, 2.1, 10.1);
  glCallList(14);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(-1.3,1.8,0.05);                                    // Jendela kanan Border bawah
  glutSolidCube(1.7);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(0.0, 2.1, 10);
  glCallList(3);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(1,1.4,0.03);                                    // Jendela kanan bawah
  glutSolidCube(1.9);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-4.3, 2, 11.4);
  glCallList(3);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(1,1.3,0.1);                                    // Jendela kiri bawah
  glutSolidCube(1.5);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-4.3, 2, 11.5);
  glCallList(14);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(-1.3,1.8,0.1);                                    // Jendela kiri Border
  glutSolidCube(1.3);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-4.3, 6, 11.4);
  glCallList(3);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(1.1,1.0,0.1);                                    // Jendela kiri Atas
  glutSolidCube(1.5);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-4.3, 6, 11.5);
  glCallList(14);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(1,1.0,0.1);                                    // Jendela Border kiri Atas
  glutSolidCube(1.8);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(0.1, 6, 10);
  glCallList(3);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(1.1,1.0,0.03);                                    // Jendela kanan Atas
  glutSolidCube(1.5);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(0.1, 6, 10.1);
  glCallList(14);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(1.1,1.0,0.05);                                    // Jendela Border kanan Atas
  glutSolidCube(1.8);
  glPopMatrix();
  glPopMatrix();
  
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-4.35, 4.3, 13.24);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(1.1,2.2,0.95);                                    // villa kiri
  glutSolidCube(3.5);
  glPopMatrix();
  glPopMatrix();
  

  int i;
  for(i=0;i<20;i++){
      glPushMatrix();
      glScalef(skala,skala,skala);  
      glPushMatrix();
      glTranslatef(9.2, 5.5, 15.5-i);
      glCallList(15);
      glRotatef(90, 1.0, 0.0, 0.0);
      glScalef(1,1,1);
      GLUquadricObj * qobj;
      qobj = gluNewQuadric();
      gluQuadricDrawStyle(qobj,GLU_LINE);                 // tiang kanan
      gluCylinder(qobj,0.2,0.2,5.0,50,8);
      glPopMatrix();
      glPopMatrix();
      i=i+4;
  }
  
  for(i=0;i<20;i++){
      glPushMatrix();
      glScalef(skala,skala,skala);  
      glPushMatrix();
      glTranslatef(-9.2, 5.5, 15.5-i);
      glCallList(15);
      glRotatef(90, 1.0, 0.0, 0.0);
      glScalef(1,1,1);                                    // Tiang kiri
      GLUquadricObj * qobj;
      qobj = gluNewQuadric();
      gluQuadricDrawStyle(qobj,GLU_LINE);
      gluCylinder(qobj,0.2,0.2,5.0,50,8);
      glPopMatrix();
      glPopMatrix();
      i=i+4;
  }

  float j;
  int h;
  for(h=0;h<4;h++){
      glPushMatrix();
      glScalef(skala,skala,skala);  
      glPushMatrix();
      glTranslatef(2.8, 6.5, 9.8-j);
      glCallList(15);
      glRotatef(90, 1.0, 0.0, 0.0);
      glScalef(0.2,0.2,0.2);                                    // Pagar kanan
      GLUquadricObj * qobj;
      qobj = gluNewQuadric();
      gluQuadricDrawStyle(qobj,GLU_LINE);
      gluCylinder(qobj,0.2,0.2,6.3,50,8);
      glPopMatrix();
      glPopMatrix();
      

      glPushMatrix();
      glScalef(skala,skala,skala);  
      glPushMatrix();
      glTranslatef(-2.8, 6.5, 9.9-j);
      glCallList(15);
      glRotatef(90, 1.0, 0.0, 0.0);
      glScalef(0.2,0.2,0.2);                                    // Pagar kiri
      //GLUquadricObj * qobj;
      qobj = gluNewQuadric();
      gluQuadricDrawStyle(qobj,GLU_LINE);
      gluCylinder(qobj,0.2,0.2,6.3,50,8);
      glPopMatrix();
      glPopMatrix();
      
      j=j+0.4;
}  


  for(i=0;i<20;i++){
      glPushMatrix();
      glScalef(skala,skala,skala);  
      glPushMatrix();
      glTranslatef(9.2, 5.8, 15.5-i);
      glCallList(lampu);
      glRotatef(0, 0.0, 1.0, 0.0);
      glScalef(2.0,2.0,2.0);                                    // lampu kanan
      glutSolidSphere(0.2,100,50);
      glPopMatrix();
      glPopMatrix();
      i=i+4;
  }
  
  for(i=0;i<16;i++){
      glPushMatrix();
      glScalef(skala,skala,skala);  
      glPushMatrix();
      glTranslatef(-9.2, 5.8, 15.5-i);
      glCallList(lampu);
      glRotatef(0, 0.0, 1.0, 0.0);
      glScalef(2.0,2.0,2.0);                                    // lampu kiri
      glutSolidSphere(0.2,100,50);
      glPopMatrix();
      glPopMatrix();
      i=i+4;
  }
    
    
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-2.2, 2.8, 8.0);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(0.5,1.8,0.2);                                    // villa penyangga depan kiri
  glutSolidCube(3.0);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-5.95, 6.5, 10.9);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(0.2,1.0,0.5);                                    // villa penyangga samping kiri atas
  glutSolidCube(3.0);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-5.95, 2.5, 10.9);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(0.2,1.37,0.5);                                    // villa penyangga samping kiri bawah
  glutSolidCube(3.0);
  glPopMatrix();
  glPopMatrix();
  
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(2.2, 2.8, 8.0);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(0.5,1.8,0.2);                                    // villa penyangga depan kanan
  glutSolidCube(3.0);
  glPopMatrix();
  glPopMatrix();
  
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(0.0, 5.3, 8.0);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(2.0,0.7,0.2);                                    // villa penyangga depan atas
  glutSolidCube(3.0);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(0.0, 4.8,9.2);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(2.0,0.3,0.6);                                    // villa atap depan
  glutSolidCube(3.0);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-4.6, 7.7,10.9);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(1.1,0.3,0.5);                                    // villa atap kiri atas
  glutSolidCube(3.0);
  glPopMatrix();
  glPopMatrix();

  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-4.6, 4.8,10.9);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(1.1,0.3,0.5);                                    // villa atap kiri bawah
  glutSolidCube(3.0);
  glPopMatrix();
  glPopMatrix();  
  
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(0.0, 0.6, 4.0);
  glCallList(7);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(0.8,0.05,1.5);                                    // kolam
  glutSolidCube(3.5);
  glPopMatrix();
  glPopMatrix();

  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(5.5, 0.6, 12);
  glCallList(9);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(0.8,0.05,1.5);                                    // kebun
  glutSolidCube(4.0);
  glPopMatrix();
  glPopMatrix();

  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-4.7, 0.6, 4.0);
  glCallList(8);
  glRotatef(-0.5, 0.0, 1.0, 0.0);
  glScalef(0.8,0.05,1.5);                                    // tempat berjemur
  glutSolidCube(3.5);
  glPopMatrix();
  glPopMatrix();
  
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-4.2, 1, 4.5);
  glCallList(13);
  glRotatef(-0.5, 0.0, 1.0, 0.0);
  glScalef(0.8,0.05,1.5);                                    // kursi 1 kanan
  glutSolidCube(0.6);
  glPopMatrix();
  glPopMatrix();
  
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-4.2, 1, 5.0);
  glCallList(13);
  glRotatef(-40, 1, 0, 0);
  glScalef(0.8,0.05,1.5);                                    // kursi sandaran kanan
  glutSolidCube(0.5);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-5.2, 1, 5.0);
  glCallList(13);
  glRotatef(-40, 1, 0, 0);
  glScalef(0.8,0.05,1.5);                                    // kursi sandaran kiri
  glutSolidCube(0.5);
  glPopMatrix();
  glPopMatrix();
  
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-5.2, 1, 4.5);
  glCallList(13);
  glRotatef(-0.5, 0.0, 1.0, 0.0);
  glScalef(0.8,0.05,1.5);                                    // kursi 2 kiri
  glutSolidCube(0.6);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-4.7, 1.8, 5.0);
  glCallList(17);                                               // payung
  glScalef(0.9,0.5,0.5);
  glRotated(-90,1,0,0);
  glutSolidCone(0.8, 1.0, 10, 5);
  glPopMatrix();
  glPopMatrix();
  
   glPushMatrix();
   glScalef(skala,skala,skala);  
   glPushMatrix();
   glTranslatef(-4.7, 1.8, 5.0);
   glCallList(15);
   glRotatef(90, 1.0, 0.0, 0.0);
   glScalef(0.3,0.2,0.2);                                    // Tiang Payung
   qobj = gluNewQuadric();
   gluQuadricDrawStyle(qobj,GLU_LINE);
   gluCylinder(qobj,0.2,0.2,5.0,50,8);
   glPopMatrix();
   glPopMatrix();
   
   glPushMatrix();
   glScalef(skala,skala,skala);  
   glPushMatrix();
   glTranslatef(-4.6, 1, 2.8);
   glCallList(18);
   glRotatef(-0.5, 0.0, 1.0, 0.0);
   glScalef(0.8,0.05,1.3);                                    // meja
   glutSolidCube(0.6);
   glPopMatrix();
   glPopMatrix();
  
   glPushMatrix();
   glScalef(skala,skala,skala);  
   glPushMatrix();
   glTranslatef(-4.8, 1.0, 3.1);
   glCallList(15);
   glRotatef(90, 1.0, 0.0, 0.0);
   glScalef(0.2,0.2,0.2);                                    // kaki meja kiri bagian belakang sebelah kiri
   qobj = gluNewQuadric();
   gluQuadricDrawStyle(qobj,GLU_LINE);
   gluCylinder(qobj,0.2,0.2,5.0,50,8);
   glPopMatrix();
   glPopMatrix();

   
   glPushMatrix();
   glScalef(skala,skala,skala);  
   glPushMatrix();
   glTranslatef(-4.8, 1.0, 2.5);
   glCallList(15);
   glRotatef(90, 1.0, 0.0, 0.0);
   glScalef(0.2,0.2,0.2);                                    // kaki meja kiri bagian depan sebelah kiri
   qobj = gluNewQuadric();
   gluQuadricDrawStyle(qobj,GLU_LINE);
   gluCylinder(qobj,0.2,0.2,5.0,50,8);
   glPopMatrix();
   glPopMatrix();   
   
  

   glPushMatrix();
   glScalef(skala,skala,skala);  
   glPushMatrix();
   glTranslatef(-4.5, 1.0, 3.1);
   glCallList(15);
   glRotatef(90, 1.0, 0.0, 0.0);
   glScalef(0.2,0.2,0.2);                                    // kaki meja kanan bagian belakang sebelah kanan
   qobj = gluNewQuadric();
   gluQuadricDrawStyle(qobj,GLU_LINE);
   gluCylinder(qobj,0.2,0.2,5.0,50,8);
   glPopMatrix();
   glPopMatrix();
  

   glPushMatrix();
   glScalef(skala,skala,skala);  
   glPushMatrix();
   glTranslatef(-4.5, 1.0, 2.5);
   glCallList(15);
   glRotatef(90, 1.0, 0.0, 0.0);
   glScalef(0.2,0.2,0.2);                                    // kaki meja kanan bagian depan sebelah kanan
   qobj = gluNewQuadric();
   gluQuadricDrawStyle(qobj,GLU_LINE);
   gluCylinder(qobj,0.2,0.2,5.0,50,8);
   glPopMatrix();
   glPopMatrix();
  

  
   glPushMatrix();
   glScalef(skala,skala,skala);  
   glPushMatrix();
   glTranslatef(-5.0, 1.0, 4.2);
   glCallList(15);
   glRotatef(90, 1.0, 0.0, 0.0);
   glScalef(0.2,0.2,0.2);                                    // kaki kursi kiri bagian depan sebelah kanan
   qobj = gluNewQuadric();
   gluQuadricDrawStyle(qobj,GLU_LINE);
   gluCylinder(qobj,0.2,0.2,5.0,50,8);
   glPopMatrix();
   glPopMatrix();

   glPushMatrix();
   glScalef(skala,skala,skala);  
   glPushMatrix();
   glTranslatef(-5.4, 1.0, 4.2);
   glCallList(15);
   glRotatef(90, 1.0, 0.0, 0.0);
   glScalef(0.2,0.2,0.2);                                    // kaki kursi kiri bagian depan sebelah kiri
   qobj = gluNewQuadric();
   gluQuadricDrawStyle(qobj,GLU_LINE);
   gluCylinder(qobj,0.2,0.2,5.0,50,8);
   glPopMatrix();
   glPopMatrix();

   glPushMatrix();
   glScalef(skala,skala,skala);  
   glPushMatrix();
   glTranslatef(-5.0, 1.0, 5.0);
   glCallList(15);
   glRotatef(90, 1.0, 0.0, 0.0);
   glScalef(0.2,0.2,0.2);                                    // kaki kursi kiri bagian belakang sebelah kanan
   qobj = gluNewQuadric();
   gluQuadricDrawStyle(qobj,GLU_LINE);
   gluCylinder(qobj,0.2,0.2,5.0,50,8);
   glPopMatrix();
   glPopMatrix();

   glPushMatrix();
   glScalef(skala,skala,skala);  
   glPushMatrix();
   glTranslatef(-5.4, 1.0, 5.0);
   glCallList(15);
   glRotatef(90, 1.0, 0.0, 0.0);
   glScalef(0.2,0.2,0.2);                                    // kaki kursi kiri bagian belakang sebelah kiri
   qobj = gluNewQuadric();
   gluQuadricDrawStyle(qobj,GLU_LINE);
   gluCylinder(qobj,0.2,0.2,5.0,50,8);
   glPopMatrix();
   glPopMatrix();

   glPushMatrix();
   glScalef(skala,skala,skala);  
   glPushMatrix();
   glTranslatef(-4.0, 1.0, 4.2);
   glCallList(15);
   glRotatef(90, 1.0, 0.0, 0.0);
   glScalef(0.2,0.2,0.2);                                    // kaki kursi kanan bagian depan sebelah kanan
   qobj = gluNewQuadric();
   gluQuadricDrawStyle(qobj,GLU_LINE);
   gluCylinder(qobj,0.2,0.2,5.0,50,8);
   glPopMatrix();
   glPopMatrix();
   
   glPushMatrix();
   glScalef(skala,skala,skala);  
   glPushMatrix();
   glTranslatef(-4.4, 1.0, 4.2);
   glCallList(15);
   glRotatef(90, 1.0, 0.0, 0.0);
   glScalef(0.2,0.2,0.2);                                    // kaki kursi kanan bagian depan sebelah kiri
   qobj = gluNewQuadric();
   gluQuadricDrawStyle(qobj,GLU_LINE);
   gluCylinder(qobj,0.2,0.2,5.0,50,8);
   glPopMatrix();
   glPopMatrix();
   
   glPushMatrix();
   glScalef(skala,skala,skala);  
   glPushMatrix();
   glTranslatef(-4.0, 1.0, 5.0);
   glCallList(15);
   glRotatef(90, 1.0, 0.0, 0.0);
   glScalef(0.2,0.2,0.2);                                    // kaki kursi kanan bagian belakng sebelah kanan
   qobj = gluNewQuadric();
   gluQuadricDrawStyle(qobj,GLU_LINE);
   gluCylinder(qobj,0.2,0.2,5.0,50,8);
   glPopMatrix();
   glPopMatrix();
   
   glPushMatrix();
   glScalef(skala,skala,skala);  
   glPushMatrix();
   glTranslatef(-4.4, 1.0, 5.0);
   glCallList(15);
   glRotatef(90, 1.0, 0.0, 0.0);
   glScalef(0.2,0.2,0.2);                                    // kaki kursi kanan bagian belakng sebelah kiri
   qobj = gluNewQuadric();
   gluQuadricDrawStyle(qobj,GLU_LINE);
   gluCylinder(qobj,0.2,0.2,5.0,50,8);
   glPopMatrix();
   glPopMatrix();

  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-1.8, 0.6, 4.0);
  glCallList(11);
  glRotatef(-0.5, 0.0, 1.0, 0.0);
  glScalef(2.2,0.02,1.5);                                    // alas
  glutSolidCube(4.3);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(5.9, 1.9, -13.0);
  glCallList(12);                                             // bukit kanan
  glScalef(7.0,4.0,6);
  glRotated(-90,1,0,0);
  glutSolidCube(1);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(-5.9, 1.9, -13);
  glCallList(12);                                             // bukit kiri
  glScalef(7.0,4.0,6);
  glRotated(-90,1,0,0);
  glutSolidCube(1);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(1.0, 1.0, -13.15);
  glCallList(12);                                             // bukit tengah
  glScalef(7.0,2.0,5.7);
  glRotated(-90,1,0,0);
  glutSolidCube(1);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);
  glPushMatrix();
  glTranslatef(0.0, 2.2, -13.15);
  glCallList(5);
  glRotatef(90, 1.0, 0.0, 0.0);
  glScalef(0.6,0.715,0.05);                                     //laut2
  glutSolidCube(8);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);
  glPushMatrix();
  glTranslatef(0.0, 1.1, -10.2);
  glCallList(5);
  glRotatef(80, 1.0, 0.0, 0.0);
  glScalef(0.68,0.02,0.38);                                     //laut3
  glutSolidCube(7);
  glPopMatrix();
  glPopMatrix();
    

   float p,k;
  for(p=0;p<5;p++){
      for(k=0;k<7;k++){
                       
          glPushMatrix();
          glScalef(skala,skala,skala);  
          glPushMatrix();
          glTranslatef(3.0+k, 5.5, -10.8-p);
          glCallList(6);                                    // pohon 1 kanan
          glScalef(0.4,0.5,0.5);
          glRotated(-90,1,0,0);
          glutSolidCone(0.5, 3.7, 10, 5);
          glPopMatrix();
          glPopMatrix();
        
          glPushMatrix();
          glScalef(skala,skala,skala);  
          glPushMatrix();
          glTranslatef(3.0+k, 5.1, -10.8-p);
          glCallList(6);                                    // pohon 2 kanan
          glScalef(0.4,0.5,0.5);
          glRotated(-90,1,0,0);
          glutSolidCone(0.5, 3.7, 10, 5);
          glPopMatrix();
          glPopMatrix();
        
          glPushMatrix();
          glScalef(skala,skala,skala);  
          glPushMatrix();
          glTranslatef(3.0+k, 4.5, -10.8-p);
          glCallList(6);                                    // pohon 3 kanan
          glScalef(0.4,0.5,0.5);
          glRotated(-90,1,0,0);
          glutSolidCone(0.5, 3.7, 10, 5);
          glPopMatrix();
          glPopMatrix();
          
          glPushMatrix();
          glScalef(skala,skala,skala);  
          glPushMatrix();
          glTranslatef(3.0+k, 4.5, -10.8-p);
          glCallList(16);
          glRotatef(90, 1.0, 0.0, 0.0);
          glScalef(0.2,0.2,0.2);                                    // Batang Pohon kanan
          qobj = gluNewQuadric();
          gluQuadricDrawStyle(qobj,GLU_LINE);
          gluCylinder(qobj,0.2,0.2,6.3,50,8);
          glPopMatrix();
          glPopMatrix();
          
          k=k+0.5;
      }
      p=p+0.5;
  }
  
  
  float m,l;
  for(m=0;m<5;m++){
      for(l=0;l<7;l++){
  
          glPushMatrix();
          glScalef(skala,skala,skala);  
          glPushMatrix();
          glTranslatef(-3.0-l, 5.5, -10.8-m);
          glCallList(6);                                    // pohon 1 kiri
          glScalef(0.4,0.5,0.5);
          glRotated(-90,1,0,0);
          glutSolidCone(0.5, 3.7, 10, 5);
          glPopMatrix();
          glPopMatrix();


          glPushMatrix();
          glScalef(skala,skala,skala);  
          glPushMatrix();
          glTranslatef(-3.0-l, 5.1, -10.8-m);
          glCallList(6);                                    // pohon 2 kiri
          glScalef(0.4,0.5,0.5);
          glRotated(-90,1,0,0);
          glutSolidCone(0.5, 3.7, 10, 5);
          glPopMatrix();
          glPopMatrix();
               
          glPushMatrix();
          glScalef(skala,skala,skala);  
          glPushMatrix();
          glTranslatef(-3.0-l, 4.5, -10.8-m);
          glCallList(6);                                    // pohon 3 kiri
          glScalef(0.4,0.5,0.5);
          glRotated(-90,1,0,0);
          glutSolidCone(0.5, 3.7, 10, 5);
          glPopMatrix();
          glPopMatrix();
          
          glPushMatrix();
          glScalef(skala,skala,skala);  
          glPushMatrix();
          glTranslatef(-3.0-l, 4.5, -10.8-m);
          glCallList(16);
          glRotatef(90, 1.0, 0.0, 0.0);
          glScalef(0.2,0.2,0.2);                                    // Batang Pohon kiri
          qobj = gluNewQuadric();
          gluQuadricDrawStyle(qobj,GLU_LINE);
          gluCylinder(qobj,0.2,0.2,6.3,50,8);
          glPopMatrix();
          glPopMatrix();
          
          l=l+0.5;
      }
      m=m+0.5;
  }

  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(7.8, 2.0, 8.0);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(0.6,1.8,0.2);                                    // villa penyangga depan kanan garasi
  glutSolidCube(2.0);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(7.8, 2.0, 15.2);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(0.6,1.8,0.2);                                    // villa penyangga belakang kanan garasi
  glutSolidCube(2.0);
  glPopMatrix();
  glPopMatrix();
  
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(4.1, 2.0, 8.0);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(0.5,1.8,0.2);                                    // villa penyangga samping kiri garasi
  glutSolidCube(2.0);
  glPopMatrix();
  glPopMatrix();
  
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(4.1, 2.0, 15.1);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(0.5,1.8,0.2);                                    // villa penyangga belakang kiri garasi
  glutSolidCube(2.0);
  glPopMatrix();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(6.0, 2.0, 15.1);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(0.5,1.8,0.2);                                    // villa penutup belakang garasi
  glutSolidCube(2.0);
  glPopMatrix();
  glPopMatrix();
  
  
  
  glPushMatrix();
  glScalef(skala,skala,skala);  
  glPushMatrix();
  glTranslatef(6.0, 4.0, 11.6);
  glCallList(1);
  glRotatef(0, 0.0, 1.0, 0.0);
  glScalef(2.4,0.5,3.8);                                    // villa penyangga depan atas garasi
  glutSolidCube(2.0);
  glPopMatrix();
  glPopMatrix();

  
  glPopMatrix(); 
  glutSwapBuffers();
  glFlush();
}

void 
light_select(GLenum which)
{
  glEnable(which);  
  glLightfv(which, GL_DIFFUSE, cahaya); 
  glutPostRedisplay();
}

void 
material(int dlist, GLfloat * ambient, GLfloat * diffuse,
  GLfloat * specular, GLfloat shininess)
{
  glNewList(dlist, GL_COMPILE);
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
  glMaterialf(GL_FRONT, GL_SHININESS, shininess);
  glEndList();
}

char *material_select(int object, int value)
{
  glutPostRedisplay();
  switch (value) {
  case DARATAN:
    material(object, daratan_ambient,
      daratan_diffuse, daratan_specular, daratan_shininess);
    return "daratan";
  case VILLA:
    material(object, villa, villa_plastic_diffuse,
      villa_plastic_specular, villa_plastic_shininess);
    return "villa";
  case JENDELA:
    material(object, jendela, jendela_plastic_diffuse,
      jendela_plastic_specular, jendela_plastic_shininess);
    return "jendela";
  case BORDER:
    material(object, border, border_plastic_diffuse,
      border_plastic_specular, border_plastic_shininess);
    return "border";
  case TIANG:
    material(object, tiang, tiang_plastic_diffuse,
      tiang_plastic_specular, tiang_plastic_shininess);
    return "tiang";
  case POHON:
    material(object, pohon, pohon_diffuse,
      pohon_specular, pohon_shininess);
    return "pohon";
  case BATANG:
    material(object, batang, batang_diffuse,
      batang_specular, batang_shininess);
    return "batang"; 
  case KAWAH_GUNUNG:
    material(object, kawah_gunung, kawah_gunung_diffuse,
      kawah_gunung_specular, kawah_gunung_shininess);
    return "kawah_gunung";
  case KOLAM:
    material(object, kolam, kolam_diffuse,
      kolam_specular, kolam_shininess);
    return "kolam";
  case BERJEMUR:
    material(object, berjemur, berjemur_diffuse,
      berjemur_specular, berjemur_shininess);
    return "berjemur";
  case KURSI:
    material(object, kursi, kursi_diffuse,
      kursi_specular, kursi_shininess);
    return "kursi";
  case ALAS:
    material(object, alas, alas_diffuse,
      alas_specular, alas_shininess);
    return "alas";
  case KEBUN:
    material(object, kebun, kebun_diffuse,
      kebun_specular, kebun_shininess);
    return "kebun";
  case LINGKARAN:
    material(object, lingkaran, lingkaran_plastic_diffuse,
      lingkaran_plastic_specular, lingkaran_plastic_shininess);
    return "lingkaran";
  case LINGKARAN_NYALA:
    material(object, lingkaran_nyala, lingkaran_nyala_plastic_diffuse,
      lingkaran_nyala_plastic_specular, lingkaran_nyala_plastic_shininess);
    return "lingkaran";
  case LAUT:
    material(object, laut, laut_diffuse,
      laut_specular, laut_shininess);
    return "laut";
  case PAYUNG:
    material(object, payung, payung_diffuse,
      payung_specular, payung_shininess);
    return "payung";
  case MEJA:
    material(object, meja, meja_diffuse,
      meja_specular, meja_shininess);
    return "meja";
  }
    return NULL;
}

static void keyboard (int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_UP:         viewx--; break;
        case GLUT_KEY_DOWN:       viewx++; break;
        case GLUT_KEY_RIGHT:      viewy++; break;
        case GLUT_KEY_LEFT:       viewy--; break;
        case GLUT_KEY_F1:         viewz++; break;
        case GLUT_KEY_F2:         viewz--; break;
        case GLUT_KEY_F3:         zoomx=zoomx+0.01; break;
        case GLUT_KEY_F4:         zoomx=zoomx-0.01; break;
        case GLUT_KEY_F5:         zoomy=zoomy+0.01; break;
        case GLUT_KEY_F6:         zoomy=zoomy-0.01; break;
        case GLUT_KEY_F7:         zoomz=zoomz+0.01; break;
        case GLUT_KEY_F8:         zoomz=zoomz-0.01; break;
        case GLUT_KEY_F9:         zoomin=zoomin+0.01; break;
        case GLUT_KEY_F10:        zoomin=zoomin-0.01; break;    
        default:break;
    }
}

static void keyboard2(unsigned char key, int x, int y)
{
       
    switch (toupper(key))
    {
    case '1':       if (putar==1){putar=0; spin=0;}else{putar=1; viewy=viewy+spin;} break;
    case '2':       if (lampu==10){lampu=19;}else{lampu=10;} break;
        
    default:
        break;
    }
}


 
int main(int argc, char **argv)
{
  quadObj = gluNewQuadric();
  glutInitWindowSize(1000, 600);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
  glutCreateWindow("Tugas Besar kelompok 9");
  glutSpecialFunc(keyboard);
  glutKeyboardFunc(keyboard2);
  glutDisplayFunc(display);
  glClearColor(0.3, 0.7, 1.0, 0.0);
  
   
  glLightfv(GL_LIGHT0, GL_POSITION, cahaya_kiri);
  glLightfv(GL_LIGHT1, GL_POSITION, cahaya_kanan);
  
  glLightfv(GL_LIGHT0, GL_SPECULAR, cahaya);  
  glLightfv(GL_LIGHT1, GL_SPECULAR, cahaya);
  
  light_select(GL_LIGHT0);          
  light_select(GL_LIGHT1);          

  villa_material = material_select(1, VILLA);
  daratan_material = material_select(2, DARATAN);
  jendela_material = material_select(3, JENDELA);
  kaki_kursi_material = material_select(4, KAKI_KURSI);
  laut_material = material_select(5, LAUT);
  pohon_material = material_select(6, POHON);
  kolam_material = material_select(7, KOLAM);
  berjemur_material = material_select(8, BERJEMUR);
  kebun_material = material_select(9, KEBUN);
  torus_material = material_select(10, LINGKARAN);
  alas_material = material_select(11, ALAS);
  kawah_gunung_material = material_select(12, KAWAH_GUNUNG);
  kursi_material = material_select(13, KURSI);
  border_material = material_select(14, BORDER);
  tiang_material = material_select(15, TIANG);
  batang_material = material_select(16, BATANG);
  payung_material = material_select(17, PAYUNG);
  meja_material = material_select(18, MEJA);
  torus2_material = material_select(19, LINGKARAN_NYALA);
  
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  glMatrixMode(GL_PROJECTION);
  gluPerspective(45.0, 1.0, 1.0, 10.0); 
  glMatrixMode(GL_MODELVIEW);
  glutIdleFunc(muter);
  gluLookAt(0.0, 2.0, 2.0,  
    0.0, 0.0, 0.0,      
    0.0, 1.0, 0.0);      
  
  glutMainLoop();
  return 0;     
}

