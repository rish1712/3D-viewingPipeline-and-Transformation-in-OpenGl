# 3D-viewingPipeline-and-Transformation-in-OpenGl
Understanding openGL transformations, matrix stack operations, and 3D viewing pipeline by using primitive and Blender objects.
# A Road Side View
Created a road side scene by using simple primitives such as cubes,cylinders etc.Objects like benches, buildings etc were made in openGL by using the fundamental concepts of matrix stack operations, perspective projection, 3-d transformations to obtain the desired result. Objects like trees were made in blender and were imported with the help of mesh classes.To make the scene interactive some basic function of pan,zoom,translate were added. Few animations were added to objects like seesaw,car,a stick person.
## Importing Blender Objects
Blender has an inbuilt function which creates a file containing the coordinates of vertices and faces in .txt format. The blenderToOpenGl class reads the above file and then makes the appropriate triangles between the verices. The above process ables the openGl libraries to make the blender object.
## Dependencies
We would require Open GL library-glut-3.7.6-bin

Link to download the required libraries-https://www.transmissionzero.co.uk/software/freeglut-devel/
