#pragma once
#include <iostream>

namespace itertools{

template <typename R, typename S> class zip{

	private: 
		R iter1;
		S iter2; 

	template <typename T1,typename T2> class iterator{
		public: 
			T1 first;
			T2 second;

			iterator (T1 A,T2 B): first(A), second(B){}

			//operator *
			std::pair<decltype(*first),decltype(*second)> operator*() const{
				return std::pair<decltype(*first),decltype(*second)> (*first,*second);
			}
			//operator ++
			zip::iterator<T1,T2> &operator++(){
				++first;
				++second;
				return *this;			
			}
			//operator !=
			bool operator!=(zip::iterator<T1,T2> const &next){
				return ((first!=next.first)&&(second!=next.second));
			}
	};	

	public: 
		zip(R start ,S end): iter1(start),iter2(end){}

		auto begin() const{
			return zip::iterator<decltype(iter1.begin()),decltype(iter2.begin())>(iter1.begin(),iter2.begin());
		}
		auto end() const{
			return zip::iterator<decltype(iter1.end()),decltype(iter2.end())>(iter1.end(),iter2.end());
		}
		
};

//print pair
template <typename T1,typename T2> std::ostream &operator<<(std::ostream &os,const std::pair<T1,T2> &str){
os<<str.first<<','<<str.second;
return os;
}

}
