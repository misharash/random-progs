#include <stdio.h>
#include <math.h>
#define ED 6875;
typedef struct {
	int deg,min,sec;
	char dir;
} geoc;
typedef struct {
	double x,y,z;
} vect;
double rval(geoc c) {
	double r=M_PI*(c.deg+(double)c.min/60+(double)c.sec/3600)/180;
	if (c.dir<'P')
		return -r;
	//printf("rval: %lf\n",r);
	return r;
}
vect mkvec(geoc lat,geoc lon) {
	double lt=rval(lat),lng=rval(lon);
	vect r;
	r.x=cos(lt)*cos(lng);
	r.y=cos(lt)*sin(lng);
	r.z=sin(lt);
	return r;
}
double scpvec(vect a,vect b) {
	//printf("scpvec: %lf\n",a.x*b.x+a.y*b.y+a.z*b.z);
	return a.x*b.x+a.y*b.y+a.z*b.z;
}
int main() {
	geoc titlt,titln,icelt,iceln;
	char s[100];
	gets(s);
	//scanf("Message #%*d.");
	gets(s);
	//scanf("Received at %*d:%*d:%*d%*c");
	gets(s);
	//scanf("Current ship's coordinates are");
	gets(s);
	sscanf(s,"%d^%d'%d\" %cL",&titlt.deg,&titlt.min,&titlt.sec,&titlt.dir);
	gets(s);
	sscanf(s,"and %d^%d'%d\" %cL.",&titln.deg,&titln.min,&titln.sec,&titln.dir);
	gets(s);
	//scanf("An iceberg was noticed at");
	gets(s);
	sscanf(s,"%d^%d'%d\" %cL",&icelt.deg,&icelt.min,&icelt.sec,&icelt.dir);
	gets(s);
	sscanf(s,"and %d^%d'%d\" %cL.",&iceln.deg,&iceln.min,&iceln.sec,&iceln.dir);
	gets(s);
	//scanf("===");
	double d=acos(scpvec(mkvec(titlt,titln),mkvec(icelt,iceln)))/2*ED;
	printf("The distance to the iceberg: %0.2lf miles.\n",d);
	if (d<99.995)
		printf("DANGER!\n");
	return 0;
}
