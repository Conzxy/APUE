#ifndef _SORT_H
#define _SORT_H

#include <algorithm>
#include <cmath>
#include <iterator>
#include <type_traits>
#include <functional>

/*
 * @brief: merge result of sort per threads
 * @para: first1, head of source range
 *		  last1 , tail of source range
 *		  first2, head of destination range
 * @requires: the size of destination range is greater than or equals the source range
 *			  before call this function, you should sort per threads at first  
 * @return: void
 */
template<
		 std::size_t numthread = 1, typename RI1, typename RI2, typename BinaryPred,
		 typename V = typename std::iterator_traits<RI1>::value_type
		>
void merge_impl(RI1 first1, RI1 last1,
				RI2 first2,
				BinaryPred pred)
{
	int num = last1 - first1;
	int numperthread = num / numthread;

	int idx[numthread];
	//idx: record the first element index of sorted range
	for(int i = 0; i < numthread; ++i){
		idx[i] = i * numperthread;
	}

	//ridx:result index 
	for(int ridx = 0; ridx != num; ++ridx){
		/*int min_element = INT_MAX;
		int min_idx = 0;

		for(int tidx = 1; tidx != numthread; ++tidx){
			if((idx[tidx] < (tidx + 1) * numperthread) && (pred(*(first1 + idx[tidx]), min_element))){
				min_element = *(first1 + idx[tidx]);
				min_idx = tidx;
			}
		}

		
		*(first2 + ridx) = *(first1 + idx[min_idx]);
		++idx[min_idx];*/

		int sz = 0;
		V minarr[numthread];

		for(int tidx = 0; tidx != numthread; ++tidx){
			if((idx[tidx] < (tidx + 1) * numperthread)){
				minarr[sz++] = *(first1 + idx[tidx]);
			}
		}

		auto min_iter = std::min_element(minarr, minarr + sz);

		*(first2 + ridx) = *min_iter;
		++idx[min_iter - minarr];
	}
}

template<
		 std::size_t numthread = 1, typename RI1, typename RI2, 
	     typename V = typename std::iterator_traits<RI1>::value_type,
		 typename BinaryPred = std::less<V>
		>
void mymerge(RI1 first1, RI1 last1, 
		   RI2 first2,
		   BinaryPred pred = {})
{
	using V1 = typename std::iterator_traits<RI1>::value_type;
	using V2 = typename std::iterator_traits<RI2>::value_type;
	
	static_assert(std::is_convertible<V1, V2>::value || std::is_convertible<V2, V1>::value, 
				  " value_type doesn't convertible\n");


	merge_impl<numthread>(first1, last1, 
						  first2, 
						  pred);
}

#endif
