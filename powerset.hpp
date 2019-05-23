#pragma once

#include <iostream>
#include <set>
#include <cmath>
#include <vector>

using namespace std;

namespace itertools{

	template<class T> class powerset{
		private:
			T tank;

		public:
			powerset(const T ob): tank(ob){}

			template<typename E> class iterator{
			private:
						E start;
						E last;
						size_t setLength;
						uint index;

			public:
						iterator(E s,E l):start(s),last(l),setLength(0),index(0){
							size_t counter=0;
							E temp=start;
							while(temp!=last){
								++counter;
								++temp;
							}
							setLength=pow(2,counter);//there are 2^tank.length sets
						}

						//operator *
						auto operator* () const{
							std::vector<typename std::remove_const<typename std::remove_reference<decltype(*start)>::type>::type> Set;
							E temp=start;
							uint i=index;
							while(temp!=last&&i!=0){
								if(i%2==1){//1 insert element, 0 end of Set
									Set.emplace_back(*temp);
								}
								i>>=1;//shift left
								++temp;
							}
							return Set;
						}

						//operator ++
						auto operator++ (){
							++index;
							return *this;
						}

						//operator !=
						auto operator!=(iterator<E> const &next) const{
							return (setLength-index!=next.setLength-next.index-1);
						}
			};

			auto begin() const{
    				return iterator<decltype(tank.begin())>(tank.begin(),tank.end());
    	}
    	auto end() const{
    				return iterator<decltype(tank.end())>(tank.end(),tank.end());
			}
	};


	template <typename T> std::ostream &operator<<(std::ostream &os,const std::vector<T> &printSet){
		os<<"{";
		auto it=printSet.begin();
		if(it!=printSet.end()){
			os<<*it;
			++it;
		}
		while(it!=printSet.end()){
			os<<','<<*it;
			++it;
		}
		os<<"}";
		return os;
	}
}
