#pragma once
#include <utility>
#include <assert.h>
#include <iostream>

namespace itertools{

	bool emptyProduct=false;

	template <typename R,typename S> class product{
		private:
			R iter1;
			S iter2;

		template <typename T1,typename T2> class iterator{
			public:
				T1 first;
				T2 second;
				T2 tempOfSecond;//save the position of "second" iterator
				bool ans;

				iterator(T1 A,T2 B): first(A), second(B), tempOfSecond(second),ans(false){}

				//operator *
				auto operator*() const{
					return std::pair<decltype(*first),decltype(*second)> (*first,*second);
				}
				//operator ++
				iterator& operator++(){
					if(!ans)
						++second;
					return *this;
				}
				//operator !=
				bool operator!= (iterator const & next){
				//if iterator "first" is bigger then iterator "second" (in length), start "second" from the beginning
					if((first!=next.first) && !(second!=next.second)){
						ans=true;
					}
					if(ans){
						second=tempOfSecond;
						++first;
						ans=false;
					}
					return (first!=next.first&&(!emptyProduct));
				}

		};
		public:
			product(R start,S end): iter1(start), iter2(end){
				emptyProduct=false;
				if(!(end.begin()!=end.end()))
					emptyProduct=true;
			}

			auto begin() const{
				return iterator<decltype(iter1.begin()),decltype(iter2.begin())> (iter1.begin(),iter2.begin());
			}
			auto end() const{
				return iterator<decltype(iter1.end()),decltype(iter2.end())> (iter1.end(),iter2.end());
			}
	};


}
