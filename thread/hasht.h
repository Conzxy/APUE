/*
 * @version: 2021-5-22
 * @author: Conzxy
 * simple Concurrent Hash table
 * hash conflict policy: separate list 
 */
#ifndef _HASHT_H
#define _HASHT_H

#include "common.h"

using zxy::MutexLock;
using zxy::MutexException;

struct foo{
	int count;
	MutexLock lock;
	int id;
	foo* next;

};

constexpr auto hash_fun(int id, int nums){
	return (unsigned long)id % nums;
}

class ConHashTable{
public:
	using value_type = foo;
	using pointer    = foo*;
private:
	static constexpr int nums_ = 29;

	MutexLock hashlock_;
	pointer table_[nums_];

public:
	ConHashTable(){}
	~ConHashTable(){}
	
	pointer insert(int id){
		foo* fp;
		try{
			MutexLock m{};
			fp = new foo();

			fp->id = id;
			fp->count = 1;
			fp->next = nullptr;
		}catch(MutexException const& me){
			printf("%s", me.what());
			delete fp;
			return nullptr;
		}catch(std::bad_alloc const& be){
			printf("%s", be.what());
			delete fp;
			return nullptr;
		}
		
		//new successfully
		auto idx = hash_fun(id, nums_);
		hashlock_.lock();
		fp->next = table_[idx];
		table_[idx] = fp;
		fp->lock.lock();
		hashlock_.unlock();
		//continue initialization
		fp->lock.unlock();
		
		return fp;
	}
	
	void foo_hold(foo* fp){
		fp->lock.lock();
		fp->count++;
		fp->lock.unlock();
	}

	pointer find(int id){
		hashlock_.lock();

		for(auto fp = table_[hash_fun(id, nums_)]; fp != nullptr; fp = fp->next){
			if(fp->id == id){
				foo_hold(fp);
				hashlock_.unlock();
				return fp;
			}
		}

		return nullptr;
	}

	void foo_rele(foo* fp){
		fp->lock.lock();
		if(fp->count == 1){
			fp->lock.unlock();
			hashlock_.lock();
			fp->lock.lock();
			//need recheck
			if(fp->count != 1){
				fp->count--;
				fp->lock.unlock();
				hashlock_.unlock();
				return ;
			}

			//only one
			auto idx = hash_fun(fp->id, nums_);
			auto tmp = table_[idx];

			if(tmp == fp){
				table_[idx] = tmp->next;
			}else{
				while(tmp->next != fp)
					tmp = tmp->next;

				tmp->next = fp->next;
			}

			fp->lock.unlock();
			hashlock_.unlock();

			delete fp;
		}else{
			fp->count--;
			fp->lock.unlock();
		}
	
	}
};

#endif
