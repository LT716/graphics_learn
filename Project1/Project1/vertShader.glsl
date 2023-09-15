#version 430 
uniform float offset;

mat4 buildRotateX(float rad)
{
	mat4 xrot = mat4(1.0, 0.0, 0.0, 0.0,
					 0.0, cos(rad), -sin(rad), 0.0,
					 0.0, sin(rad), cos(rad), 0.0,
					 0.0, 0.0, 0.0, 1.0);
	return xrot;
}

mat4 buildRotateY(float rad)
{
	mat4 yrot = mat4(cos(rad), 0.0, sin(rad), 0.0,
					 0.0, 1.0, 0.0, 0.0,
					 -sin(rad), 0.0, cos(rad), 0.0,
					 0.0, 0.0, 0.0, 1.0);
	return yrot;
}

mat4 buildRotateZ(float rad)
{
	mat4 zrot = mat4(cos(rad), -sin(rad), 0.0, 0.0,
					 sin(rad), cos(rad), 0.0, 0.0,
					 0.0, 0.0, 1.0, 0.0,
					 0.0, 0.0, 0.0, 1.0);
	return zrot;
}


void main(void)
{ 
	//gl_Position = vec4(0.0,0.0,0.0,1.0);

	float edge = 1;
	float pos1 = 0.25;
	float pos2 = pos1 + edge;
	float pos3 = pos1 + edge * 0.5;
	float h = sqrt(3) * 0.5 * edge;
	if(gl_VertexID == 0) gl_Position = vec4(pos1+offset,-0.25,0.0,1.0) * buildRotateZ(30);
	else if(gl_VertexID==1) gl_Position = vec4(pos2+offset,-0.25,0.0,1.0) * buildRotateZ(30);
	else gl_Position = vec4(pos3+offset,h,0.0,1.0) * buildRotateZ(30);
}
