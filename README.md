# rayTracer

A M2 mini-projet whose goal is to implement a simple ray tracer dealing with spheres and a static camera.

# Compile the projet

You will need not too old version of Flex and Bison to compile this project.

Once you checked all that, get the code of the project and compile it make:

	git clone https://github.com/WilliamAufort/rayTracer.git
	cd rayTracer
	make

# Run the program

After compiling the project, to run the program, use:

	./rayTracer

With the appropriate options. To have more precisions, use:

	./rayTracer -h

# Scene files

The project reads .sc extension files containing the scene to represent. Please refers to the "pattern.sc" file in the "scenes" folder for more information.
Note: there is still some bugs in the parser (mostly on the comments and the order of the materials options) I didn't have time to correct. I'm sorry for that. So, use it carefully.

# Documents

You can also find in the "docs" folder my LaTeX report about the project required by my school. You can compile it using simply:

	make

