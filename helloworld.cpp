#include <iostream>
#include <vector>
int main()
{
	std::vector<int> myvec;

	for(int i=0;i<10;++i)
	{
		myvec.push_back(i);
	}
	std::cout<<"myvec size : "<< myvec.size()<<std::endl;
	for(auto iter=myvec.cbegin();iter!=myvec.cend();++iter)
	{
		std::cout<<*iter<<std::endl;
	}

	return 0;
}

