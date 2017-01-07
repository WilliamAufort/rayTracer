# We first give mandatory global information
#
# The hash character is used to handle ((very) simple) comments
#
# Camera position, direction to look, and up direction
Lookat (0,0,55) (0,0,-1) (1,0,0)

# The fov of the camera in degrees
CameraFov 60

# The dimensions of the output image
OutputImage 500 500

# The light source (position and intensity)
LightSource (-10,20,40) 2000

# Build a sphere
BeginSphere
	Center (0,0,0)
	Radius 10
	# rgb color
	Color (1,1,1)
	BeginMaterial
		# The materials are given with their arguments
		Specular
		Transparent n
		Diffuse (coeff in [0,1], 1 is no coefficient provided)
		Emissive (intensity, mandatory but recommended)
	EndMaterial
EndSphere
