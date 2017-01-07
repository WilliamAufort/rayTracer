Lookat (0,0,55) (0,0,-1) (1,0,0)

CameraFov 60

OutputImage 500 500

LightSource (-10,20,40) 500

#Central Sphere
BeginSphere
	Center (0,0,15)
	Radius 10
	Color (1,1,1)
	BeginMaterial
		Diffuse
		Emissive
	EndMaterial
EndSphere

#Sphere behind
BeginSphere
	Center (0,0,1000)
	Radius 940
	Color (1,0.784,0.576)
	BeginMaterial
		Emissive
	EndMaterial
EndSphere

#Sphere in front
BeginSphere
	Center (0,0,-1000)
	Radius 940
	Color (0,1,0)
	BeginMaterial
		Emissive
	EndMaterial
EndSphere

#Sphere above
BeginSphere
	Center (0,1000,0)
	Radius 940
	Color (1,0,0)
	BeginMaterial
		Emissive
	EndMaterial
EndSphere

#Sphere below
BeginSphere
	Center (0,-1000,0)
	Radius 990
	Color (0,0,1)
	BeginMaterial
		Emissive
	EndMaterial
EndSphere

#Sphere left
BeginSphere
	Center (1000,0,0)
	Radius 950
	Color (1,1,0)
	BeginMaterial
		Emissive
	EndMaterial
EndSphere

#Sphere right
BeginSphere
	Center (-1000,0,0)
	Radius 950
	Color (1,1,1)
	BeginMaterial
		Emissive
	EndMaterial
EndSphere
