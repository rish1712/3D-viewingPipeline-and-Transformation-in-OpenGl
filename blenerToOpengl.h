#include<stdlib.h>
#ifndef READER_H
#define READER_H

#define MAX_VERT 100000

class Render {

    public:
        /*!this is the constructor of the class
        */
        Render();
        /*!This function loads the vertices of the bleneder object the return type is void
            this function takes the arguments as a character pointer.
        */
        void load(char* filename);
        /*!This function loads the faces of the bleneder object the return type is void
            this function takes the arguments as a character pointer.
        */
        void draw1(char* filename);
        /*!This function scale the bleneder object the return type is void
            this function takes the arguments as a float which is a factor of scaling.
        */
        void draw2(float);
        /*! this function deletes the memory to free up space.the return type as well as the arguments are void
        */
        void deletememory(void);


};

#endif
