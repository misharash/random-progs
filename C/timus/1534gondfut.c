#include <stdio.h>
long long imax(long long a, long long b) {
	if (a>b)
		return a;
	return b;
}
long long imin(long long a, long long b) {
	if (a<b)
		return a;
	return b;
}
int main() {
	long long k,l,n,maxo,mino,v1,v2;
	scanf("%lld %lld %lld",&k,&l,&n);
	//printf("%d %d\n",k,l+n);
	if (k>=l+n)
		maxo=3*n;//можно всё выиграть без вариантов
	else {//проиграть всё на одном бою, остальные выиграть/ничьи или сыграть все выигрыши/ничьи
		v1=n-1+2*imin(n-1,k);
		if (k>=l)
			v2=n+2*imin(n,k-l);
		else
			v2=0;
		//printf("maxo %lld %lld\n",v1,v2);
		maxo=imax(v1,v2);
	}
	//printf("%d %d\n",l,k+n);
	if (l>=k+n)
		mino=0;//можно всё проиграть без вариантов
	else {//выиграть всё на одном бою, остальные проиграть/ничьи или сыграть все проигрыши/ничьи
		v1=n+2-imin(n-1,l);
		if (l>=k)
			v2=n-imin(n,l-k);
		else
			v2=3*n;
		//printf("mino %lld %lld\n",v1,v2);
		mino=imin(v1,v2);
	}
	printf("%lld %lld\n",maxo,mino);
	return 0;
}

