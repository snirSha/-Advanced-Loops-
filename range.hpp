#pragma once
#include <iostream>
#include <string>

using namespace std;
namespace itertools{

	template <class T> class range {
		private:
    			T p_begin;
    			T p_end;

    			class iterator {
    				private:
        				T variable;

    				public:
        				iterator(T x) : variable(x) { }

        		    range::iterator &operator++(){
             				   ++variable;
             				   return *this;
            		}

        				auto operator*() const { return variable; }

        				bool operator!=(range::iterator const &next) const {
            				return variable != next.variable;
        				}
    			};


		public:
    			auto begin() const { return range::iterator(p_begin); }
    			auto end()   const { return range::iterator(p_end  ); }

    			range(T range_begin, T range_end)
        		: p_begin(range_begin), p_end(range_end)
        		{}

	/*		string toString(){
				string s="";
				for(auto i:*this)
					s+=to_string(i)+" ";
				return s;
			}*/
	};


}
