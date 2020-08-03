//reader.cpp
#include <GL/freeglut.h>
#include <fstream>
#include<iostream>
#include "blenerToOpengl.h"

using namespace std;
/*!this is the constructor of the class
*/
Render::Render()
{

}
int f=0, face1[6000],face2[6000],face3[6000];
float vertexx[10000],vertexy[10000],vertexz[10000];
/*!This function loads the vertices of the bleneder object the return type is void
    this function takes the arguments as a character pointer.
*/

void Render::load(char* filename)
{
    ifstream file;
    file.open(filename,ios::in);

    string str;

    if(!(file.is_open()))
        cout<<1;

    while(!file.eof()) //while we are still in the file
    {
        getline(file,str); //move one line down
        if(str[0] == 'v') break; //if we have a vertex line, stop
    }

    int v = 0;

    while(str[0] == 'v') {

        int i = 0;

        while(true)
        {
            while(str[i] == ' ' )
            {
                i++; //move a space over
            }
            i++;
            i++;
            int j = i, k = i;
            while(str[i] != ' ') {
                i++;
                k = i;
            }
            vertexx[v] = atof(str.substr(j, k-j).c_str());

            //moving on to the y coord

            while(str[i] == ' ' ) {
                i++;
            }

            int q = i, w = i;
            while(str[i] != ' ' ) {
                i++;
                w = i;
            }
            vertexy[v] = atof(str.substr(q, w-q).c_str());

            while(str[i] == ' ' ) {
                i++;
            }

            int a = i, s = i;
            while(str[i] != '\0' ) {
                i++;
                s = i;
            }
            vertexz[v] = atof(str.substr(a, s-a).c_str());

            break;
        }
        v++;
        getline(file, str);
    }
}

 /*!This function loads the faces of the bleneder object the return type is void
    this function takes the arguments as a character pointer.
 */

void Render::draw1(char *filename)
{
    ifstream file2;
    file2.open(filename);

    string str;

    while(true)
    {
        getline(file2, str);
        if(str[0] == 'f' ) {
            break;
        }
    }

    int i = 0,j=0,k=0;


	    while(str[0]=='f')
	    {

	       	while(str[i] == 'f') i++;


	        while(str[i] == ' ') i++;
	        j = i, k = i;

	        while(str[i] != ' ') {
	            i++;
	            k = i;
	        }

	       int one = atof(str.substr(j, k - j).c_str());

	        i +=1;

	        j = i;
	        k = i;

	        while(str[i] != ' ') {
	            i++;
	            k = i;
	        }

			int two = atof(str.substr(j, k - j).c_str());

	        i+=1;

	        j = i;
	        k = i;

	        while(str[i] != '\0') {
	            i++;
	            k = i;
	        }

	        int three = atof(str.substr(j, k - j).c_str());

		//	cout<<one<<" "<<two<<" "<<three<<"\n";

			face1[f] = one;
			face2[f] = two;
			face3[f] = three;

	        f++;

	        getline(file2, str);
	        i = 0;
	    }
}
/*! This function scale the bleneder object the return type is void
    this function takes the arguments as a float which is a factor of scaling.
*/
void Render::draw2(float scale)
{
	for(int i=0;i<f;i++)
	{
		glBegin(GL_TRIANGLES);
		glVertex3f(scale*vertexx[face1[i] - 1], scale*vertexy[face1[i] - 1], scale*vertexz[face1[i] - 1]);
		glVertex3f(scale*vertexx[face2[i] - 1], scale*vertexy[face2[i] - 1], scale*vertexz[face2[i] - 1]);
		glVertex3f(scale*vertexx[face3[i] - 1], scale*vertexy[face3[i] - 1], scale*vertexz[face3[i] - 1]);
		glEnd();
	}
}
/*! this function deletes the memory to free up space.the return type as well as the arguments are void
*/

void Render::deletememory()
{
    free(vertexx);
    free(vertexy);
    free(vertexz);

    free(face1);
    free(face2);
    free(face3);
}
