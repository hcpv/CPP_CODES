#include<bits/stdc++.h>
using namespace std;

struct cmplx{
	float a;
	float b;

};

cmplx add(cmplx *p1,cmplx *p2){
	struct cmplx p3;
	p3.a=(p1->a)+(p2->a);
	p3.b=(p1->b)+(p2->b);
	return p3;
}

cmplx multiply(cmplx *p1,cmplx *p2){
	cmplx p3;
	p3.a=((p1->a)*(p2->a))-((p1->b)*(p2->b));
	p3.b=((p1->a)*(p2->b))+((p1->b)*(p2->a));
	return p3;
}

cmplx divide(cmplx *p1,cmplx *p2){
	cmplx p3;
	p3.a=(((p1->a)*(p2->a))+((p1->b)*(p2->b)))/(((p2->a)*(p2->a))+((p2->b)*(p2->b)));
	p3.b=(((p1->b)*(p2->a))-((p1->a)*(p2->b)))/(((p2->a)*(p2->a))+((p2->b)*(p2->b)));
	return p3;
}

cmplx negation(cmplx *p){
	cmplx p1;	
	p1.a=p->a;
	p1.b=-(p->b);
	return p1;
}

void display(struct cmplx &p){
	cout<<p.a<<"+i("<<p.b<<")";
}

int main(){
	struct cmplx p1,p2,p3;
	struct cmplx *ptr1=&p1,*ptr2=&p2;
	cout<<"Enter first complex number : ";
	cin>>p1.a>>p1.b;
	cout<<"\nEnter second complex number : ";
	cin>>p2.a>>p2.b;
	p3 = add(ptr1,ptr2);
	cout<<"\n\nAddition is : ";
	display(p3);
	p3 = multiply(ptr1,ptr2);
	cout<<"\n\nMultiplication is : ";
	display(p3);
	p3 = divide(ptr1,ptr2);
	cout<<"\n\nComplex1/complex2 is : ";
	display(p3);
	p3 = negation(ptr1);
	cout<<"\n\nConjugate of Complex1 is : ";
	display(p3);
	p3 = negation(ptr2);
	cout<<"\n\nConjugate of Complex2 is : ";
	display(p3);
	return 0;
}

