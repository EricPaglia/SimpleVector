#include <iostream>
#include "SimpleVector.h"
//return #of elements currently in vector
int SimpleVector::size()
{
	return _numElements;
}

//increase size of array by 1 and set integer x to last element
void SimpleVector::push_back(int x)
{
	_numElements++;

	//check if capacity needs to be increased
	if (_numElements > _capacity)
	{
		extend(); //double capacity
	}
	_array[_numElements - 1] = x;
}

//Reverse the order of the array
void SimpleVector::reverse()
{
	int temp;

	if (_numElements % 2 != 0) //If number is odd, perform one less swap to avoid swapping the same number in the end
	{
		for (int i = 0; i < (_numElements / 2) - 1; i++) //
		{
			temp = _array[i];//store first variable as temp
			_array[i] = _array[_numElements - i - 1]; //replace first position with last position
			_array[_numElements - i - 1] = temp; //replace last position with first position using the value stored in temp
		}
	}
	else
	{
		for (int i = 0; i < _numElements / 2; i++) //
		{
			temp = _array[i];//store first variable as temp
			_array[i] = _array[_numElements - i - 1]; //replace first position with last position
			_array[_numElements - i - 1] = temp; //replace last position with first position using the value stored in temp
		}
	}
}

//overwrite position i with integer x 
void SimpleVector::set(int x, int i)
{
	//Check to see if index is within bounds 
	if (i < 0 || i == _numElements)
	{
		std::cout << "Index out of bounds \n";
	}
	else
	{
		_array[i] = x; //set element at position i equal to x 
	}
}

//Remove all elements of the array
void SimpleVector::clear()
{
	//delete _array;
	//_array = NULL;
	_numElements = 0;    // Don't want t o delete array because the array has actual size _capacity, not _numElements
}

//Check to see if the array is empty
int SimpleVector::empty()
{
	if (_numElements == 0)
	{
		std::cout << "The vector is empty \n";
		return 1;
	}
	else
	{
		std::cout << "The vector is not empty \n";
		return 0;
	}
}

void SimpleVector::pop_back()
{
	std::cout << _numElements << " ";
	if (_numElements == 0)
	{
		std::cout << "Pop back does nothing  because _numElements is 0...Do nothing \n";
	}
	else
	{
		_array[_numElements - 1] = NULL;
		_numElements--;
		//set last element to NUll and decrease size of of array by 1
	}
}

int SimpleVector::insert(int x, int i)
{
	//int temp = _array[_numElements - 1];
	std::cout << _numElements << "#Elements \n";
	//check to see if position i is within array 
	if (i < 0 || i >_numElements - 1)
	{
		std::cout << "Index out of bounds \n";
		std::cout << _array[i] << " \n";
		return 1;
	}

	push_back(x); //increase array size and increase capacity if necessary

				  //Shift all numbers in position >= i up
	for (int j = _numElements; j >= i; j--)
	{
		_array[_numElements] = _array[_numElements - 1];
	}

	_array[i] = x; //insert integer x into position i
	//std::cout << _array[i] << " again \n";
	return 0;
}

void SimpleVector::print()
{
	for (int i = 0; i < _numElements; i++)
	{
		std::cout << _array[i] << " ";
	}
}


int &SimpleVector::operator[](int i)
{
	if (i < 0 || i >= _numElements) {
		std::cout << "Index out of bounds" << std::endl;
		return _array[0];
	}
	return _array[i];
}