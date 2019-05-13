#include <iostream>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
#define COMMA ,


using namespace std;
using namespace itertools;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {
		int n = 0;
			for (int i : range(0, 9))
			{
				testcase.CHECK_EQUAL(i, n);
				n++;
			}
////////////////////////RANGE/////////////////////////////////////////////////////////////////////
		std::stringstream intExample, charExample, doubleExample, double2,char2,int2;
		for(int a: range(56,59))
			intExample<<a<<" ";
		for(int a: range(10213,10220))
			int2<<a<<" ";
		for (char c : range('A', 'D'))
			charExample << c;	    	
        	for (double d : range(13.5, 16.5))
			doubleExample << d << " ";
	        for (double d : range(32.2, 38.2))
			double2 << d << " ";
		for(char c:range('z','~'))
			char2 << c;


        	testcase.setname("Range-Tests")

		.CHECK_OUTPUT(intExample.str(),"56 57 58 ")
		.CHECK_OUTPUT(int2.str(),"10213 10214 10215 10216 10217 10218 10219 ")
		.CHECK_OUTPUT(charExample.str(), "ABC")
		.CHECK_OUTPUT(doubleExample.str(), "13.5 14.5 15.5 ")
	 	.CHECK_OUTPUT(double2.str(), "32.2 33.2 34.2 35.2 36.2 37.2 ")
		.CHECK_OUTPUT(char2.str(),"z{|}")
		;
////////////////////////CHAIN/////////////////////////////////////////////////////////////////////
		
		std::stringstream iR,iR2,dR,dR2,cR,cR2,SS;
		for(int a:chain(range(1,5),range(5,9)))
			iR<< a<<" ";
		for(int b:chain(range(105,112),range(1,5)))
			iR2<< b<<" ";       
 		for (char c : chain(range('r', 'u'), string("???")))
			cR << c;
 		for (char d : chain(range('(', '+'), range(':','>')))
			cR2 << d<<" ";
		for(double e:chain(range(8.5,11.5),range(7.1,9.1)))
			dR<< e<<" ";   
		for(double f:chain(range(136.25,138.25),range(0.14,2.14)))
			dR2<< f<<" ";
		for(char g:chain(string("kill"),string("me")))
			SS<< g<<" ";

        	testcase.setname("Chain-Tests")
		
		.CHECK_OUTPUT(iR.str(),"1 2 3 4 5 6 7 8 ")
		.CHECK_OUTPUT(iR2.str(),"105 106 107 108 109 110 111 1 2 3 4 ")
		.CHECK_OUTPUT(cR.str(), "rst???")
		.CHECK_OUTPUT(cR2.str(), "( ) * : ; < = ")
		.CHECK_OUTPUT(dR.str(), "8.5 9.5 10.5 7.1 8.1 ")
		.CHECK_OUTPUT(dR2.str(), "136.25 137.25 0.14 1.14 ")
		.CHECK_OUTPUT(SS.str(), "k i l l m e ")
		;

///////////////////////ZIP//////////////////////////////////////////////////////////////////////////
		std::stringstream iZ,iZ2,dZ,dZ2,cZ,cZ2,SSZ,isZ;
		for(auto a:zip(range(-5,0),range(3,8)))
			iZ<< a<<" ";
		for(auto a:zip(range(18,25),range(223,230)))
			iZ2<< a<<" ";
		for(auto b:zip(range(1.3,5.3),range(2.23,6.23)))
			dZ<< b<<" ";
		for(auto b:zip(range(25.3,28.3),string("zip")))
			dZ2<< b<<" ";
		for(auto c:zip(range('F','J'),range('f','j')))
			cZ<< c<<" ";
		for(auto c:zip(string("chair"),range('.','3')))
			cZ2<< c<<" ";
		for(auto d:zip(string("mad"),string("max")))
			SSZ<< d<<" ";
		for(auto d:zip(string("ttttt"),range(-5,0)))
			isZ<< d<<" ";

        	testcase.setname("Zip-Tests")

		.CHECK_OUTPUT(iZ.str(),"-5,3 -4,4 -3,5 -2,6 -1,7 ")				
		.CHECK_OUTPUT(iZ2.str(),"18,223 19,224 20,225 21,226 22,227 23,228 24,229 ")
		.CHECK_OUTPUT(dZ.str(),"1.3,2.23 2.3,3.23 3.3,4.23 4.3,5.23 ")
		.CHECK_OUTPUT(dZ2.str(),"25.3,z 26.3,i 27.3,p ")
		.CHECK_OUTPUT(cZ.str(),"F,f G,g H,h I,i ")				
		.CHECK_OUTPUT(cZ2.str(),"c,. h,/ a,0 i,1 r,2 ")				
		.CHECK_OUTPUT(SSZ.str(),"m,m a,a d,x ")
		.CHECK_OUTPUT(isZ.str(),"t,-5 t,-4 t,-3 t,-2 t,-1 ")		
		;

/////////////////////PRODUCT///////////////////////////////////////////////////////////////////
		std::stringstream iP,iP2,dP,dP2,cP,cP2,sss;
		for(auto a:product(range(1,3),range(12,14)))
			iP<< a<<" ";	
		for(auto a:product(range(23,24),string("MOM")))
			iP2<< a<<" ";	
		for(auto b:product(range(5.6,8.6),range(1.2,3.2)))
			dP<< b<<" ";
		for(auto b:product(range(100.2,103.2),string("why")))
			dP2<< b<<" ";
		for(auto b:product(range('a','g'),range(50,51)))
			cP<< b<<" ";
		for(auto b:product(range('?','A'),string("!!!")))
			cP2<< b<<" ";
		for(auto s:product(string("wax"),string("nil")))
			sss<< s<<" ";

        	testcase.setname("Product-Tests")
		
		.CHECK_OUTPUT(iP.str(),"1,12 1,13 2,12 2,13 ")				
		.CHECK_OUTPUT(iP2.str(),"23,M 23,O 23,M ")			
		.CHECK_OUTPUT(dP.str(),"5.6,1.2 5.6,2.2 6.6,1.2 6.6,2.2 7.6,1.2 7.6,2.2 ")
		.CHECK_OUTPUT(dP2.str(),"100.2,w 100.2,h 100.2,y 101.2,w 101.2,h 101.2,y 102.2,w 102.2,h 102.2,y ")
		.CHECK_OUTPUT(cP.str(),"a,50 b,50 c,50 d,50 e,50 f,50 ")
		.CHECK_OUTPUT(cP2.str(),"?,! ?,! ?,! @,! @,! @,! ")
		.CHECK_OUTPUT(sss.str(),"w,n w,i w,l a,n a,i a,l x,n x,i x,l ")
					
		;		
	
/////////////////////POWER-SET///////////////////////////////////////////////////////////////
		std::stringstream iPS,dPS,cPS,sPS;
		for(auto a:powerset(range(5,8)))//3 sets
			iPS<<a<<" ";
		for(auto a:powerset(range(2.1,4.1)))//2 sets
			dPS<<a<<" ";
		for(auto a:powerset(range('h','l')))//4 sets
			cPS<<a<<" ";
		for(auto a:powerset(string("table")))//5 sets
			sPS<<a<<" ";


        	testcase.setname("Power Set-Tests")

		.CHECK_OUTPUT(iPS.str(),"{} {5} {6} {5,6} {7} {5,7} {6,7} {5,6,7} ")
		.CHECK_OUTPUT(dPS.str(),"{} {2.1} {3.1} {2.1,3.1} ")
		.CHECK_OUTPUT(cPS.str(),"{} {h} {i} {h,i} {j} {h,j} {i,j} {k} {h,k} {i,k} {j,k} {h,i,j} {h,i,k} {h,j,k} {i,j,k} {h,i,j,k} ")
		.CHECK_OUTPUT(iPS.str(),"{} {t} {a} {t,a} {b} {t,b} {a,b} {l} {t,l} {a,l} {b,l} {e} {t,e} {a,e} {b,e} {l,e} {t,a,b} {t,a,l} {t,a,e} {t,b,l} {t,b,e} {t,l,e} {a,b,l} {a,b,e} {a,l,e} {b,l,e} {t,a,b,l} {t,a,b,e} {t,a,l,e} {t,b,l,e} {a,b,l,e} {t,a,b,l,e} ")
		;

/////////////////////powerset+chain+range/////////////////////////////////////////////////////
		std::stringstream all1,all2,all3,all4;
		for (auto s: powerset(chain(range(1,3),range(3,4))))//123
			all1<<s;
		for (auto s: powerset(chain(range('a','c'),range('c','d'))))//abc
			all2<<s;	
		for (auto s: powerset(chain(range(5.1,7.1),range('x','z'))))//5.16.1xy
			all3<<s;

        	testcase.setname("All together-Tests")
		
		.CHECK_OUTPUT(all1.str(),"{}{1}{2}{1,2}{3}{1,3}{2,3}{1,2,3}")
		.CHECK_OUTPUT(all2.str(),"{}{a}{b}{a,b}{c}{a,c}{b,c}{a,b,c}")
		.CHECK_OUTPUT(all2.str(),"{}{5.1}{6.1}{5.1,6.1}{x}{5.1,x}{6.1,x}{y}{5.1,y}{6.1,y}{x,y}{5.1,6.1,x}{5.1,6.1,y}{5.1,x,y}{6.1,x,y}{5.1,6.1,x,y}")

		;

/////////////////////////////////////////////////////////////////////////////////////////////

    grade = testcase.grade();
  }else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
