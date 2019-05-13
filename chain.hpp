#pragma once
#include <iostream>
#include "range.hpp"

namespace itertools{

	template <class R,class S> class Chain{
		
		private:
			R iter1;
			S iter2;
			
			template <typename T1,typename T2> class iterator{
				public:				
					T1 first;
					T2 second;
					bool stillInFirst;
					
					iterator(T1 A, T2 B):first(A),second(B),stillInFirst(true){}//constructor
					
					//operator *
					decltype(*first) operator*() const{
						if(stillInFirst)
							return *first;
						else 
							return *second;				
	
					}
					//operator ++						
					iterator<T1,T2>& operator++(){
						if(stillInFirst)
							++first;
						else
							++second;
						return *this;
					}
					//operator !=						
					bool operator!=(const iterator<T1,T2>& next){
						if(!(first!=next.first) && stillInFirst)
							stillInFirst=false;
						if(stillInFirst)
							return first!=next.first;
						else
							return second!=next.second;
					}
										
			};
		public: 
			Chain(R from,S to): iter1(from), iter2(to){}
			
			auto begin(){
				typedef decltype(iter1.begin()) T1;
				typedef decltype(iter2.begin()) T2;
				return iterator<T1,T2> {iter1.begin(),iter2.begin()};
			}
			auto end() {
				typedef decltype(iter1.end()) T1;
				typedef decltype(iter2.end()) T2;
				return iterator<T1,T2> {iter1.end(),iter2.end()};
			}
	};
	template <typename X,typename Y> Chain<X,Y> chain(X varX, Y varY){return Chain(varX,varY);}
	
}
