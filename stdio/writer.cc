#include "/home/conzxy/zxy/IO/myio.h"
#include <memory>
#include <noncopyable.h>
#include <vector>

using namespace zxy;

struct A : public noncopyable{
	A(){}
};

int main()
{
	auto pw = std::make_unique<FileWriter>("file");
	std::vector<FileWriter> vec{};
	vec.emplace_back("file");
	std::vector<A> vec2{};
	vec2.emplace_back();
}
