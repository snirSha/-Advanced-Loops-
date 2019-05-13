#pragma once

#include <iostream>
#include <set>
#include <cmath>

namespace itertools{

	template<class T> class Powerset{
		private:
			T iter;
		template <typename T1> class iterator{
			public:
				T1 first;
				iterator(T1 x):first(x){}
		
		};
		public:
			Powerset(T start): iter(start){}
			
			auto begin() { 
    				return iter.begin(); 
    			} 
    			auto end()  { 
    				return iter.end();
			} 	
	};

	template <typename T> Powerset<T> powerset(T A){
		return Powerset<T>(A);
	}
	template <typename T> std::ostream &operator<<(std::ostream &os,std::set<T> &Set){
		return os;
	}
}
