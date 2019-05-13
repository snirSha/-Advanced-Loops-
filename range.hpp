#pragma once
#include <iostream>
#include <string>

using namespace std;
namespace itertools{

	template <class T> class Range {
		private:
    			T p_begin;
    			T p_end;

    			class iterator {
    				private:
        				T variable;

    				public:
        				iterator(T x) : variable(x) { }

        		                Range::iterator &operator++(){
             				   ++variable;
             				   return *this;
            				}

        				const T& operator*() const { return variable; }

        				bool operator!=(Range::iterator const &next) const {
            				return variable != next.variable;
        				}
    			};


		public:
    			Range::iterator begin() const { return Range::iterator(p_begin); }
    			Range::iterator end()   const { return Range::iterator(p_end  ); }

    			Range(T range_begin, T range_end)
        		: p_begin(range_begin), p_end(range_end)
        		{}

			string toString(){
				string s="";
				for(auto i:*this)
					s+=to_string(i)+" ";
				return s;
			}
	};
	template<typename T> Range<T> range(T A,T B){
		return Range<T>(A,B);
	} 

}
