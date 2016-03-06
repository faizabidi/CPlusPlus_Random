#include <iostream>
#include <stack>

void display (std::stack <int> &stackname)
{
	unsigned int size = stackname.size ();
	//std::cout << "Size of stack is " << size << std::endl;
	while (size > 0)
	{	
		std::cout << stackname.top () << " ";
		stackname.pop ();
		size--;
	}
	std::cout << std::endl;
}

void moveTopTo (std::std <int> stackname)
{
	
}

void TowersOfHannoi (unsigned int disks, std::stack <int> &src, std::stack <int> &dest, std::stack <int> &buffer)
{
	if (disks == 1)
	{
		int item = src.top ();
		src.pop ();
		std::cout << "Source contains ";
		display (src);
		
		dest.push (item);
		std::cout << "Destination contains ";
		display (dest);

		std::cout << "Buffer contains ";
		display (buffer);
		//std::cout << "Move disk 1 from " << src << " to " << dest << std::endl;
		return;
	}
	TowersOfHannoi (disks - 1, source, buffer, dest);
	
	std::cout << "Move disk " << disks << " from " << source << " to " << dest << std::endl;
	TowersOfHannoi (disks - 1, buffer, dest, source);
}

int main ()
{
	std::cout << "Enter number of disks: ";
	unsigned int n;
	std::cin >> n;
	std::stack <int> src;
	std::stack <int> dest;
	std::stack <int> buffer;

	//fill up the source stack
	for (unsigned int i = 0; i < n; i++)
		src.push(i);

	/*if (n == 1)
	{
		int item = src.top ();
		src.pop ();
		std::cout << "Source contains ";
		display (src);
		
		dest.push (item);
		std::cout << "Destination contains ";
		display (dest);
		//std::cout << "Move disk 1 from " << src << " to " << dest << std::endl;
		//return;
	}*/
	
	//std::cout << "Size of source stack is " << src.size () << std::endl;

	//std::cout << "Source stack contains the following elements: "; 
	//display (src);
	
	TowersOfHannoi (n, src, dest, buffer);
	//display (src);

	return 0;
}