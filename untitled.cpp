glPushMatrix();
	{
		glScalef(2,2,2);
		glCallList(3);
	}
	glPopMatrix();

	/* The right arm */
	glPushMatrix();
	{
		glScalef(0.5,0.5,0.5);

		glTranslatef(0.8,0.65,0.0);
		glRotatef(-csX75::rightShoulderAngle,0,0,1.0);

		glPushMatrix(); 
		{
			glCallList(1);
		}
		glPopMatrix();

		glTranslatef(0.9,0,0);
		glRotatef(-csX75::rightElbowAngle,0, 0.0,1.0);
		glCallList(2);
	}
	glPopMatrix();

	/* The left arm */
	glPushMatrix();
	{
		glScalef(0.5,0.5,0.5);

		glTranslatef(-0.8,0.65,0.0);
		glRotatef(-180,0,0,1);
		glRotatef(csX75::leftShoulderAngle,0,0,1.0);

		glPushMatrix(); 
		{
			glCallList(2);
		}
		glPopMatrix();

		glTranslatef(0.9,0,0);
		glRotatef(csX75::leftElbowAngle,0, 0.0,1.0);
		glCallList(2);
	}
	glPopMatrix();
	

	glPushMatrix();
	{
		glScalef(0.5,0.5,0.5);

		glTranslatef(-0.4,-0.65,0.0);
		glRotatef(90,0,0,1);
		glRotatef(csX75::leftThighAngle,0.0,1.0,0.0);

		glPushMatrix(); 
		{
			glCallList(4);
		}
		glPopMatrix();

		glTranslatef(-1,0,0);
		glRotatef(csX75::leftLegAngle,0, 1.0,0.0);
		glCallList(5);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glScalef(0.5,0.5,0.5);

		glTranslatef(+0.4,-0.65,0.0);
		glRotatef(90,0,0,1);
		glRotatef(csX75::rightThighAngle,0.0,1.0,0.0);

		glPushMatrix(); 
		{
			glCallList(4);
		}
		glPopMatrix();

		glTranslatef(-1,0,0);
		glRotatef(csX75::rightLegAngle,0.0,1.0,0.0);
		glCallList(5);
	}
	glPopMatrix();